// Regression harness for the TDZ crash: "Cannot access 'tokenScopes' before
// initialization" fired when a token was already saved in localStorage.
const fs = require("fs");
const path = require("path");
const vm = require("vm");

const html = fs.readFileSync(path.join(__dirname, "index.html"), "utf8");
const blocks = [...html.matchAll(/<script>([\s\S]*?)<\/script>/g)];
const code = blocks[blocks.length - 1][1];
const ids = new Set([...html.matchAll(/\sid="([^"]+)"/g)].map((m) => m[1]));

function makeEl(tag, id) {
  const el = {
    tagName: String(tag).toUpperCase(), id: id || "", className: "",
    style: { setProperty() {} }, children: [], textContent: "",
    value: "", title: "", href: "", disabled: false,
    selectionStart: 0, selectionEnd: 0,
    classList: {
      _s: new Set(),
      add(...c) { c.forEach((x) => this._s.add(x)); },
      remove(...c) { c.forEach((x) => this._s.delete(x)); },
      toggle(c, on) {
        const want = on === undefined ? !this._s.has(c) : !!on;
        if (want) this._s.add(c); else this._s.delete(c);
        return want;
      },
      contains(c) { return this._s.has(c); },
    },
    appendChild(c) { this.children.push(c); return c; },
    insertBefore(c) { this.children.unshift(c); return c; },
    removeChild() {}, remove() {},
    setAttribute(k, v) { this[k] = v; },
    getAttribute(k) { return this[k]; },
    addEventListener(t, fn) { if (t === "click") (this._c = this._c || []).push(fn); },
    removeEventListener() {}, dispatchEvent() {},
    querySelector() { return null; }, querySelectorAll() { return []; },
    closest() { return null; }, focus() {}, blur() {},
    click() { return Promise.all((this._c || []).map((f) => f({}))); },
    setRangeText() {},
    getBoundingClientRect() { return { top: 0, left: 0, width: 0, height: 0 }; },
  };
  let _h = "";
  Object.defineProperty(el, "innerHTML", {
    get() { return _h; },
    set(v) { _h = String(v); if (v === "") el.children.length = 0; },
  });
  return el;
}
const elements = new Map();
for (const id of ids) elements.set(id, makeEl("div", id));

const document = {
  body: makeEl("body"), documentElement: makeEl("html"), activeElement: null,
  getElementById(id) {
    if (!elements.has(id)) elements.set(id, makeEl("div", id));
    return elements.get(id);
  },
  querySelector: () => null, querySelectorAll: () => [],
  createElement: (t) => makeEl(t),
  createDocumentFragment: () => ({ appendChild(c) { return c; }, children: [] }),
  createTreeWalker: () => ({ nextNode: () => null }),
  createTextNode: (t) => ({ nodeValue: t, parentElement: null }),
  addEventListener() {}, removeEventListener() {},
};

// The exact condition from the bug report: a token is already saved.
const store = new Map([["gh_token", "ghp_savedtoken123"]]);
const localStorage = {
  getItem: (k) => (store.has(k) ? store.get(k) : null),
  setItem: (k, v) => store.set(k, String(v)),
  removeItem: (k) => store.delete(k),
};

const userCalls = [];
const sandbox = {
  document, localStorage,
  window: {
    addEventListener() {}, removeEventListener() {},
    matchMedia: () => ({ matches: false, addEventListener() {} }),
    location: { href: "http://localhost/", origin: "http://localhost" },
  },
  navigator: { onLine: true, clipboard: { writeText: async () => {} } },
  console, setTimeout, clearTimeout, setInterval, clearInterval,
  TextEncoder, TextDecoder, AbortController,
  URL: { createObjectURL: () => "blob:x", revokeObjectURL() {} },
  Blob: class {},
  Prism: { plugins: { autoloader: { languages_path: "" } }, highlightElement() {} },
  atob: (s) => Buffer.from(s, "base64").toString("binary"),
  btoa: (s) => Buffer.from(s, "binary").toString("base64"),
  fetch: async (url) => {
    userCalls.push(url);
    return {
      ok: true, status: 200,
      headers: { get: (h) => (h === "x-oauth-scopes" ? "repo, read:user" : null) },
      json: async () => (url.endsWith("/user") ? { id: 1, login: "k", name: "K", email: null } : []),
      text: async () => "",
    };
  },
};
sandbox.window.document = document;
sandbox.globalThis = sandbox;
sandbox.self = sandbox;

const ctx = vm.createContext(sandbox);
let loadError = null;
try {
  vm.runInContext(code, ctx, { filename: "index.html:script" });
} catch (e) {
  loadError = e;
}

console.log("");
if (loadError) {
  console.log(`[FAIL] script loads with a saved token => ${loadError.name}: ${loadError.message}`);
  process.exitCode = 1;
} else {
  console.log("[PASS] script loads with a saved token => no ReferenceError");
  const run = (s) => vm.runInContext(s, ctx);
  const probe = (n, f) => {
    try { console.log(`[PASS] ${n} => ${JSON.stringify(f())}`); }
    catch (e) { console.log(`[FAIL] ${n} => ${e.message}`); process.exitCode = 1; }
  };
  probe("token loaded from storage", () => run("githubToken"));
  probe("tokenScopes initialized (was TDZ)", () => run("JSON.stringify(tokenScopes)"));
  probe("hasWriteAccess() with repo scope", () => run('tokenScopes=["repo"]; hasWriteAccess()'));
  probe("saveToken() with a NEW token (sync path)", () => {
    run('tokenInput.value="ghp_new"; saveToken()');
    return run("JSON.stringify([githubToken, tokenScopes])");
  });
  probe("saveToken() clearing the token", () => {
    run('tokenInput.value=""; saveToken()');
    return run("JSON.stringify([githubToken, hasWriteAccess()])");
  });
  probe("saveToken() re-entering a token", () => {
    run('tokenInput.value="ghp_again"; saveToken()');
    return run("JSON.stringify([githubToken, tokenScopes])");
  });
  probe("fine-grained token path", () => {
    run('tokenInput.value="github_pat_abc"; saveToken()');
    return run("JSON.stringify(tokenScopes)");
  });
  probe("/user was probed for scopes", () => userCalls.some((u) => u.endsWith("/user")));
  probe("write buttons visible after auto-verify", () =>
    run('tokenInput.value="ghp_x"; saveToken(); [!newFileBtn.classList.contains("hidden"), !editBtn.classList.contains("hidden")].join(",")'));
}
