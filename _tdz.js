// Regression harness for the TDZ crash: "Cannot access 'tokenScopes' before
// initialization" fired when a token was already saved in localStorage.
const fs = require("fs");
const path = require("path");
const vm = require("vm");

const html = fs.readFileSync(path.join(__dirname, "index.html"), "utf8");
const blocks = [...html.matchAll(/<script>([\s\S]*?)<\/script>/g)];
const code = blocks[blocks.length - 1][1];
const ids = new Set([...html.matchAll(/\sid="([^"]+)"/g)].map((m) => m[1]));

// Guard the encoding: this file must stay clean UTF-8 with no BOM.
{
  const buf = fs.readFileSync(path.join(__dirname, "index.html"));
  if (buf[0] === 0xef && buf[1] === 0xbb && buf[2] === 0xbf) {
    console.log("[FAIL] index.html starts with a UTF-8 BOM");
    process.exitCode = 1;
  }
  if (/[\u00C2\u00E2\u00C3][\s\S]/.test(html)) {
    console.log("[FAIL] index.html contains mojibake (double-encoded UTF-8)");
    process.exitCode = 1;
  } else {
    console.log("[PASS] encoding clean: no BOM, no mojibake");
  }
}

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

  // ---- 401 self-heal: a rejected token must not break folder browsing ----
  (async () => {
    const wait = (ms) => new Promise((r) => setTimeout(r, ms));
    run('githubToken="ghp_bad"; tokenScopes=["repo"]; githubUser={login:"x"};');
    const store2 = new Map();
    store2.set("gh_token", "ghp_bad");
    let attempt = 0;
    const seen = [];
    sandbox.fetch = async (url, opts = {}) => {
      const authed = !!(opts.headers && opts.headers.Authorization);
      seen.push(authed ? "auth" : "anon");
      // First authenticated call 401s (the reported failure); the retry is anon.
      if (authed) {
        attempt++;
        return {
          ok: false, status: 401, headers: { get: () => null },
          json: async () => ({ message: "Bad credentials" }), text: async () => "",
        };
      }
      return {
        ok: true, status: 200, headers: { get: () => null },
        json: async () => [{ type: "dir", name: "07 Stack", path: "07 Stack" }],
        text: async () => "",
      };
    };

    const t = (n, f) => {
      try { console.log(`[PASS] ${n} => ${JSON.stringify(f())}`); }
      catch (e) { console.log(`[FAIL] ${n} => ${e.message}`); process.exitCode = 1; }
    };

    t("ghFetch clears a rejected token and retries anonymously", async () => "pending");
    let data = null, err = null;
    try { data = await run('ghFetch("")'); } catch (e) { err = e; }
    if (err) {
      console.log(`[FAIL] ghFetch with a bad token still errored => ${err.message}`);
      process.exitCode = 1;
    } else {
      console.log(`[PASS] ghFetch recovered and returned data => ${JSON.stringify(data)}`);
    }
    t("token was cleared from memory", () => run('githubToken === ""'));
    t("cached scopes + identity were cleared", () =>
      run('JSON.stringify([tokenScopes, githubUser])'));
    t("only the first attempt was authenticated", () =>
      JSON.stringify(seen) === '["auth","anon"]');
    t("write buttons fell back to locked", () =>
      run('refreshWriteAffordances(); newFileBtn.classList.contains("locked")'));
    t("token input was cleared for the user to retype", () =>
      run('tokenInput.value === ""'));
    await wait(50);
  })();
}
