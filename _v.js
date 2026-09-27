
    Prism.plugins.autoloader.languages_path =
      "https://cdn.jsdelivr.net/npm/prismjs@1.29.0/components/";
    
    // ---- Config ----
    const OWNER = "kartikcodes26";
    const REPO = "DSA_Journey";
    const BRANCH_FALLBACK = "main";
    const FETCH_TIMEOUT_MS = 15000;
    
    // ---- Write (create / edit / delete + commit) config ----
    // Commits are authored as the token owner; this identity is only used as a
    // fallback for the `committer` field when no GitHub profile is available.
    const COMMITTER_NAME_FALLBACK = "DSA Journey";
    const COMMITTER_EMAIL_FALLBACK = "dsa-journey@users.noreply.github.com";
    // The branch new commits are written to (falls back to the default branch
    // of the repo when it can't be resolved).
    const BRANCH_WRITE = BRANCH_FALLBACK;
    // ----------------
    
    const HIDDEN_PATTERNS = [
      /^\./,
      /^tempCodeRunnerFile/,
      /^index\.html$/,
      /^README\.md$/,
    ];
    // ----------------
    
    // ---- Feather-style utility icons ----
    const ICON_PATHS = {
      back: '<line x1="19" y1="12" x2="5" y2="12"/><polyline points="12 19 5 12 12 5"/>',
      external: '<path d="M18 13v6a2 2 0 0 1-2 2H5a2 2 0 0 1-2-2V8a2 2 0 0 1 2-2h6"/><polyline points="15 3 21 3 21 9"/><line x1="10" y1="14" x2="21" y2="3"/>',
      file: '<path d="M13 2H6a2 2 0 0 0-2 2v16a2 2 0 0 0 2 2h12a2 2 0 0 0 2-2V9z"/><polyline points="13 2 13 9 20 9"/>',
      chevron: '<polyline points="9 18 15 12 9 6"/>',
      copy: '<rect x="9" y="9" width="13" height="13" rx="2" ry="2"/><path d="M5 15H4a2 2 0 0 1-2-2V4a2 2 0 0 1 2-2h9a2 2 0 0 1 2 2v1"/>',
      download: '<path d="M21 15v4a2 2 0 0 1-2 2H5a2 2 0 0 1-2-2v-4"/><polyline points="7 10 12 15 17 10"/><line x1="12" y1="15" x2="12" y2="3"/>',
      check: '<polyline points="20 6 9 17 4 12"/>',
      x: '<line x1="18" y1="6" x2="6" y2="18"/><line x1="6" y1="6" x2="18" y2="18"/>',
      alert: '<path d="M10.29 3.86L1.82 18a2 2 0 0 0 1.71 3h16.94a2 2 0 0 0 1.71-3L13.71 3.86a2 2 0 0 0-3.42 0z"/><line x1="12" y1="9" x2="12" y2="13"/><line x1="12" y1="17" x2="12.01" y2="17"/>',
      wifiOff: '<line x1="1" y1="1" x2="23" y2="23"/><path d="M16.72 11.06A10.94 10.94 0 0 1 19 12.55"/><path d="M5 12.55a10.94 10.94 0 0 1 5.17-2.39"/><path d="M10.71 5.05A16 16 0 0 1 22.58 9"/><path d="M1.42 9a15.91 15.91 0 0 1 4.7-2.88"/><path d="M8.53 16.11a6 6 0 0 1 6.95 0"/><line x1="12" y1="20" x2="12.01" y2="20"/>',
      search: '<circle cx="11" cy="11" r="8"/><line x1="21" y1="21" x2="16.65" y2="16.65"/>',
      refresh: '<polyline points="23 4 23 10 17 10"/><polyline points="1 20 1 14 7 14"/><path d="M3.51 9a9 9 0 0 1 14.85-3.36L23 10"/><path d="M20.49 15a9 9 0 0 1-14.85 3.36L1 14"/>',
      plus: '<line x1="12" y1="5" x2="12" y2="19"/><line x1="5" y1="12" x2="19" y2="12"/>',
      edit: '<path d="M11 4H4a2 2 0 0 0-2 2v14a2 2 0 0 0 2 2h14a2 2 0 0 0 2-2v-7"/><path d="M18.5 2.5a2.12 2.12 0 0 1 3 3L12 15l-4 1 1-4 9.5-9.5z"/>',
      trash: '<polyline points="3 6 5 6 21 6"/><path d="M19 6l-1 14a2 2 0 0 1-2 2H8a2 2 0 0 1-2-2L5 6"/><path d="M10 11v6"/><path d="M14 11v6"/><path d="M9 6V4a1 1 0 0 1 1-1h4a1 1 0 0 1 1 1v2"/>',
      git: '<circle cx="18" cy="6" r="3"/><circle cx="6" cy="6" r="3"/><circle cx="6" cy="18" r="3"/><path d="M6 9v6"/><path d="M18 9a9 9 0 0 1-9 9"/>',
      key: '<path d="M21 2l-2 2"/><path d="M15.5 8.5l3-3"/><circle cx="8" cy="16" r="5"/><path d="M11.5 12.5L21 3"/>',
      loader: '<line x1="12" y1="2" x2="12" y2="6"/><line x1="12" y1="18" x2="12" y2="22"/><line x1="4.93" y1="4.93" x2="7.76" y2="7.76"/><line x1="16.24" y1="16.24" x2="19.07" y2="19.07"/><line x1="2" y1="12" x2="6" y2="12"/><line x1="18" y1="12" x2="22" y2="12"/><line x1="4.93" y1="19.07" x2="7.76" y2="16.24"/><line x1="16.24" y1="7.76" x2="19.07" y2="4.93"/>',
    };
    
    function icon(name, size = 18) {
      if (name === "folder" || name === "emptyFolder") {
        return faFolderIcon(size);
      }
      return `<svg class="icon-svg" width="${size}" height="${size}" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round">${ICON_PATHS[name]}</svg>`;
    }
    
    // Font Awesome "Classic Solid" folder icon (filled), colored via currentColor
    function faFolderIcon(size = 18) {
      return `<svg class="icon-svg" width="${size}" height="${size}" viewBox="0 0 512 512" fill="currentColor"><path d="M64 480H448c35.3 0 64-28.7 64-64V160c0-35.3-28.7-64-64-64H272L232 32H64C28.7 32 0 60.7 0 96V416c0 35.3 28.7 64 64 64z"/></svg>`;
    }
    
    // ---- Unique per-language file badges (letter-mark, minimal, one color each) ----
    const LANG_INFO = {
      cpp: { label: "c++", color: "#6ea8d8" },
      cc: { label: "c++", color: "#6ea8d8" },
      h: { label: "h", color: "#6ea8d8" },
      hpp: { label: "hpp", color: "#6ea8d8" },
      c: { label: "c", color: "#6ea8d8" },
      py: { label: "py", color: "#5fa8d3" },
      js: { label: "js", color: "#d9c25f" },
      jsx: { label: "jsx", color: "#6fc2d0" },
      ts: { label: "ts", color: "#5b8fd9" },
      tsx: { label: "tsx", color: "#5b8fd9" },
      java: { label: "jv", color: "#d98f4e" },
      html: { label: "<>", color: "#d98058" },
      htm: { label: "<>", color: "#d98058" },
      css: { label: "css", color: "#5fa8d8" },
      json: { label: "{}", color: "#9a9ba3" },
      md: { label: "md", color: "#8891e0" },
      sh: { label: "sh", color: "#7cbf6d" },
      bash: { label: "sh", color: "#7cbf6d" },
      yml: { label: "yml", color: "#c77aa3" },
      yaml: { label: "yml", color: "#c77aa3" },
      sql: { label: "sql", color: "#c9a35a" },
      kt: { label: "kt", color: "#b285d6" },
      swift: { label: "sw", color: "#d97a52" },
      go: { label: "go", color: "#66c2ce" },
      rs: { label: "rs", color: "#c98764" },
      rb: { label: "rb", color: "#c9605f" },
      php: { label: "php", color: "#8285b0" },
      cs: { label: "c#", color: "#7c9ed9" },
      txt: { label: "txt", color: "#86878f" },
      gitignore: { label: "git", color: "#86878f" },
      png: { label: "img", color: "#5fc9b8" },
      jpg: { label: "img", color: "#5fc9b8" },
      jpeg: { label: "img", color: "#5fc9b8" },
      gif: { label: "img", color: "#5fc9b8" },
      svg: { label: "img", color: "#5fc9b8" },
      webp: { label: "img", color: "#5fc9b8" },
      bmp: { label: "img", color: "#5fc9b8" },
      ico: { label: "img", color: "#5fc9b8" },
    };
    const DEFAULT_LANG = { label: "•", color: "#86878f" };
    
    // Image file extensions that should open in the image viewer
    const IMAGE_EXTENSIONS = new Set([
      "png",
      "jpg",
      "jpeg",
      "gif",
      "svg",
      "webp",
      "bmp",
      "ico",
    ]);
    
    const SEARCHABLE_EXT = new Set([
      "cpp",
      "cc",
      "c",
      "h",
      "hpp",
      "py",
      "java",
      "js",
      "jsx",
      "ts",
      "tsx",
      "go",
      "rs",
      "rb",
      "php",
      "cs",
      "kt",
      "swift",
      "txt",
      "md",
    ]);
    
    function rawFileUrl(path) {
      return `https://raw.githubusercontent.com/${OWNER}/${REPO}/${BRANCH_FALLBACK}/${path
          .split("/")
          .map(encodeURIComponent)
          .join("/")}`;
    }
    
    function langBadgeSvg(label, color, sizePx = 34) {
      const fontSize = label.length > 3 ? 8.5 : label.length === 3 ? 9.5 : 11;
      return `<svg class="icon-svg" width="${sizePx}" height="${sizePx}" viewBox="0 0 34 34">
          <rect x="0.5" y="0.5" width="33" height="33" rx="9" fill="${color}22" stroke="${color}44" stroke-width="1"/>
          <text x="17" y="17" text-anchor="middle" dominant-baseline="central"
            font-family="'JetBrains Mono', ui-monospace, monospace" font-weight="600"
            font-size="${fontSize}" fill="${color}" letter-spacing="-0.3">${label}</text>
        </svg>`;
    }
    
    function fileIconHtml(name) {
      const ext = name.includes(".") ?
        name.split(".").pop().toLowerCase() :
        name.replace(/^\./, "").toLowerCase();
      const info = LANG_INFO[ext] || DEFAULT_LANG;
      return langBadgeSvg(info.label, info.color);
    }
    
    function formatDate(iso) {
      if (!iso) return null;
      const d = new Date(iso);
      if (isNaN(d)) return null;
      return d.toLocaleDateString("en-US", {
        year: "numeric",
        month: "short",
        day: "numeric",
      });
    }
    
    function formatBytes(bytes) {
      if (bytes == null) return "";
      if (bytes < 1024) return `${bytes} B`;
      return `${(bytes / 1024).toFixed(1)} KB`;
    }
    
    // ---- Line numbers ----
    function addLineNumbers(pre, text) {
      // Matches Prism's own line-count convention: a trailing newline
      // doesn't count as a new (empty) line.
      const lineCount = (text.match(/\n(?!$)/g) || []).length + 1;
      const digits = String(lineCount).length;
      pre.style.setProperty("--gutter-width", `${digits * 0.62 + 2.4}em`);
      pre.classList.add("line-numbers");
      
      const rows = document.createElement("span");
      rows.className = "line-numbers-rows";
      rows.setAttribute("aria-hidden", "true");
      const frag = document.createDocumentFragment();
      for (let i = 0; i < lineCount; i++) {
        frag.appendChild(document.createElement("span"));
      }
      rows.appendChild(frag);
      pre.appendChild(rows);
    }
    
    // ---- Link detection inside code ----
    const CODE_LINK_RE = /\bhttps?:\/\/[^\s<>"'`]+/g;
    
    function linkifyTextNode(node) {
      const text = node.nodeValue;
      CODE_LINK_RE.lastIndex = 0;
      if (!CODE_LINK_RE.test(text)) return;
      CODE_LINK_RE.lastIndex = 0;
      
      const frag = document.createDocumentFragment();
      let lastIndex = 0;
      let match;
      while ((match = CODE_LINK_RE.exec(text))) {
        let url = match[0];
        // Trailing punctuation is usually prose/syntax, not part of the URL
        let trail = "";
        while (url.length && /[.,;:!?'")\]}>]/.test(url[url.length - 1])) {
          trail = url[url.length - 1] + trail;
          url = url.slice(0, -1);
        }
        if (!url) continue;
        
        if (match.index > lastIndex) {
          frag.appendChild(
            document.createTextNode(text.slice(lastIndex, match.index)),
          );
        }
        const a = document.createElement("a");
        a.className = "code-link";
        a.href = url;
        a.target = "_blank";
        a.rel = "noopener noreferrer";
        a.title = url;
        a.textContent = url;
        a.addEventListener("click", (e) => e.stopPropagation());
        frag.appendChild(a);
        if (trail) frag.appendChild(document.createTextNode(trail));
        
        lastIndex = match.index + match[0].length;
      }
      frag.appendChild(document.createTextNode(text.slice(lastIndex)));
      node.parentNode.replaceChild(frag, node);
    }
    
    function linkifyCode(root) {
      const walker = document.createTreeWalker(
        root,
        NodeFilter.SHOW_TEXT,
        {
          acceptNode(n) {
            if (n.parentElement && n.parentElement.closest("a")) {
              return NodeFilter.FILTER_REJECT;
            }
            return /https?:\/\//.test(n.nodeValue) ?
              NodeFilter.FILTER_ACCEPT :
              NodeFilter.FILTER_SKIP;
          },
        },
      );
      const nodes = [];
      let n;
      while ((n = walker.nextNode())) nodes.push(n);
      nodes.forEach(linkifyTextNode);
    }
    // ------------------------------------
    
    const API_BASE = "https://api.github.com";
    const API = `${API_BASE}/repos/${OWNER}/${REPO}`;
    const repoLink = document.getElementById("repo-link");
    repoLink.href = `https://github.com/${OWNER}/${REPO}`;
    repoLink.innerHTML = icon("external", 16);
    
    const listView = document.getElementById("list-view");
    const listActionsBar = document.getElementById("list-actions");
    const codeView = document.getElementById("code-view");
    const imageView = document.getElementById("image-view");
    const backBtn = document.getElementById("back-btn");
    const crumbEl = document.getElementById("crumb");
    const titleEl = document.getElementById("title");
    const currentPathEl = document.getElementById("current-path");
    const currentDatesEl = document.getElementById("current-dates");
    const rawLinkEl = document.getElementById("raw-link");
    const codewrap = document.getElementById("codewrap");
    const copyBtn = document.getElementById("copy-btn");
    const downloadBtn = document.getElementById("download-btn");
    const offlineBanner = document.getElementById("offline-banner");
    const imagePathEl = document.getElementById("image-path");
    const imageDatesEl = document.getElementById("image-dates");
    const imageRawLinkEl = document.getElementById("image-raw-link");
    const imageDownloadBtn = document.getElementById("image-download-btn");
    const imagewrap = document.getElementById("imagewrap");
    const imageDeleteBtn = document.getElementById("image-delete-btn");
    const editBtn = document.getElementById("edit-btn");
    const deleteBtn = document.getElementById("delete-btn");
    
    const editView = document.getElementById("edit-view");
    const fileNameInput = document.getElementById("file-name-input");
    const commitMessageInput = document.getElementById("commit-message-input");
    const commitDescInput = document.getElementById("commit-desc-input");
    const editorEl = document.getElementById("editor");
    const saveFileBtn = document.getElementById("save-file-btn");
    const cancelEditBtn = document.getElementById("cancel-edit-btn");
    const deleteFileBtn = document.getElementById("delete-file-btn");
    const composeStatusEl = document.getElementById("compose-status");
    const modalRoot = document.getElementById("modal-root");
    
    const newFileBtn = document.getElementById("new-file-btn");
    
    const searchToggleBtn = document.getElementById("search-toggle-btn");
    const searchPanel = document.getElementById("search-panel");
    const searchPanelIcon = document.getElementById("search-panel-icon");
    const searchInput = document.getElementById("search-input");
    const searchGoBtn = document.getElementById("search-go-btn");
    const searchCloseBtn = document.getElementById("search-close-btn");
    const tokenIcon = document.getElementById("token-icon");
    const tokenInput = document.getElementById("token-input");
    const tokenSaveBtn = document.getElementById("token-save-btn");
    
    backBtn.innerHTML = icon("back", 18);
    copyBtn.innerHTML = icon("copy", 14) + " Copy";
    downloadBtn.innerHTML = icon("download", 14) + " Save";
    rawLinkEl.innerHTML = icon("external", 12) + " Raw";
    imageDownloadBtn.innerHTML = icon("download", 14) + " Save";
    imageRawLinkEl.innerHTML = icon("external", 12) + " Raw";
    searchToggleBtn.innerHTML = icon("search", 16);
    searchPanelIcon.innerHTML = icon("search", 15);
    searchCloseBtn.innerHTML = icon("x", 13);
    tokenIcon.innerHTML = icon("check", 15);
    newFileBtn.innerHTML = icon("plus", 16);
    editBtn.innerHTML = icon("edit", 13) + " Edit";
    deleteBtn.innerHTML = icon("trash", 13) + " Delete";
    imageDeleteBtn.innerHTML = icon("trash", 13) + " Delete";
    saveFileBtn.innerHTML = icon("git", 14) + " Commit";
    deleteFileBtn.innerHTML = icon("trash", 14) + " Delete";
    cancelEditBtn.innerHTML = icon("x", 13) + " Cancel";
    
    // ---- Token-derived state ----
    // Declared BEFORE the token block below, because saving a token refreshes
    // these synchronously. `let` is in the temporal dead zone until its
    // declaration is evaluated, so any earlier read throws a ReferenceError.
    const WRITE_SCOPES = ["repo", "public_repo", "contents", "write:contents"];
    const SCOPES_STORAGE_KEY = "gh_token_scopes";
    const PROFILE_STORAGE_KEY = "gh_user";
    
    let tokenScopes = readStoredJson(SCOPES_STORAGE_KEY, null); // string[] | null
    let githubUser = readStoredJson(PROFILE_STORAGE_KEY, null); // {login,name,email}
    
    function readStoredJson(key, fallback) {
      try {
        const raw = localStorage.getItem(key);
        if (!raw) return fallback;
        const parsed = JSON.parse(raw);
        return parsed == null ? fallback : parsed;
      } catch (e) {
        return fallback;
      }
    }
    
    function writeStoredJson(key, value) {
      try {
        if (value == null) localStorage.removeItem(key);
        else localStorage.setItem(key, JSON.stringify(value));
      } catch (e) {
        // quota / private mode — writes still work, we just can't cache
      }
    }
    
    function hasWriteAccess() {
      if (!githubToken) return false;
      if (!tokenScopes) return true; // unverified — let the API decide
      return tokenScopes.some((scope) => WRITE_SCOPES.includes(scope));
    }
    
    function normalizeScopes(raw) {
      if (!raw) return [];
      // Classic PATs look like "repo, workflow".
      return raw
        .split(",")
        .map((s) => s.trim())
        .filter(Boolean);
    }
    // ===============================================================
    
    // ---- GitHub token (stored locally, used to authenticate API calls) ----
    const TOKEN_STORAGE_KEY = "gh_token";
    let githubToken = localStorage.getItem(TOKEN_STORAGE_KEY) || "";
    if (githubToken) tokenInput.value = githubToken;
    
    function saveToken() {
      const val = tokenInput.value.trim();
      const previous = githubToken;
      githubToken = val;
      if (val) {
        localStorage.setItem(TOKEN_STORAGE_KEY, val);
        flashButton(tokenSaveBtn, "check", "Saved");
      } else {
        localStorage.removeItem(TOKEN_STORAGE_KEY);
        flashButton(tokenSaveBtn, "check", "Cleared");
      }
      // A different token means a different (or no) identity + permission set.
      if (val !== previous) {
        tokenScopes = null;
        githubUser = null;
        writeStoredJson(SCOPES_STORAGE_KEY, null);
        writeStoredJson(PROFILE_STORAGE_KEY, null);
        if (val) verifyTokenScopes();
      }
      refreshWriteAffordances();
    }
    
    // GitHub rejected the saved token: drop it (and the cached scopes/identity)
    // so the app falls back to unauthenticated browsing instead of failing.
    function clearRejectedToken() {
      githubToken = "";
      tokenScopes = null;
      githubUser = null;
      tokenInput.value = "";
      try {
        localStorage.removeItem(TOKEN_STORAGE_KEY);
        localStorage.removeItem(SCOPES_STORAGE_KEY);
        localStorage.removeItem(PROFILE_STORAGE_KEY);
      } catch (e) {
        // storage unavailable — in-memory state is already cleared
      }
      refreshWriteAffordances();
    }
    
    // Classic PAT scopes come back on every authenticated response header;
    // fine-grained tokens never expose them, so we optimistically allow writes
    // and let the API report a real error if the token lacks permission.
    async function verifyTokenScopes() {
      if (!githubToken) return;
      if (githubToken.startsWith("github_pat_")) {
        tokenScopes = ["fine-grained"];
        writeStoredJson(SCOPES_STORAGE_KEY, tokenScopes);
        refreshWriteAffordances();
        return;
      }
      try {
        const res = await fetchWithTimeout(`${API_BASE}/user`, {
          headers: authHeaders({ Accept: "application/vnd.github+json" }),
        });
        const raw = res.headers.get("x-oauth-scopes");
        if (raw != null) {
          tokenScopes = normalizeScopes(raw);
          writeStoredJson(SCOPES_STORAGE_KEY, tokenScopes);
        }
      } catch (e) {
        // Keep the optimistic default — the API is the source of truth.
      }
      refreshWriteAffordances();
    }
    
    if (githubToken) verifyTokenScopes();
    tokenSaveBtn.addEventListener("click", saveToken);
    tokenInput.addEventListener("keydown", (e) => {
      if (e.key === "Enter") {
        e.preventDefault();
        saveToken();
      }
    });
    
    function authHeaders(extra = {}) {
      const headers = { ...extra };
      if (githubToken) headers.Authorization = `token ${githubToken}`;
      return headers;
    }
    // ---------------------------------------------------------------
    
    // ================= Create / edit / delete + commit =============
    // All writes go through the GitHub Contents API:
    //   PUT    /contents/{path}  -> create or update (needs blob `sha` to update)
    //   DELETE /contents/{path}  -> delete (needs blob `sha`)
    // Each write is a single commit, so a custom commit message is required.
    // (WRITE_SCOPES / tokenScopes / githubUser and their storage helpers are
    //  declared above the token block — see "Token-derived state".)
    // ===============================================================
    
    function composeStatus(message, kind) {
      composeStatusEl.className = "compose-status" + (kind ? ` ${kind}` : "");
      if (!message) {
        composeStatusEl.innerHTML = "";
        return;
      }
      const iconName =
        kind === "error" ? "alert" : kind === "ok" ? "check" : "loader";
      composeStatusEl.innerHTML = `${icon(iconName, 13)}<span>${escapeHtml(message)}</span>`;
    }
    
    function setComposeBusy(busy, label) {
      saveFileBtn.disabled = busy;
      deleteFileBtn.disabled = busy;
      cancelEditBtn.disabled = busy;
      fileNameInput.disabled = busy;
      if (busy) {
        saveFileBtn.innerHTML = `${icon("loader", 14)} ${escapeHtml(label || "Working…")}`;
      } else {
        saveFileBtn.innerHTML = icon("git", 14) + " Commit";
        updateDeleteButtonLabel();
      }
    }
    
    // ---- UTF-8 safe base64 (btoa/atob only handle Latin-1) ----
    function encodeUtf8Base64(str) {
      const bytes = new TextEncoder().encode(str);
      let binary = "";
      const CHUNK = 0x8000; // avoids "too many arguments" on large files
      for (let i = 0; i < bytes.length; i += CHUNK) {
        binary += String.fromCharCode.apply(null, bytes.subarray(i, i + CHUNK));
      }
      return btoa(binary);
    }
    
    function decodeUtf8Base64(b64) {
      const binary = atob(String(b64 || "").replace(/\n/g, ""));
      const bytes = new Uint8Array(binary.length);
      for (let i = 0; i < binary.length; i++) bytes[i] = binary.charCodeAt(i);
      return new TextDecoder().decode(bytes);
    }
    
    // ---- Path helpers ----
    function normalizeRepoPath(input) {
      const cleaned = String(input || "")
        .replace(/\\/g, "/")
        .replace(/^\/+/, "")
        .split("/")
        .map((segment) => segment.trim())
        .filter((segment) => segment !== "" && segment !== ".");
      return cleaned.join("/");
    }
    
    function pathError(path) {
      if (!path) return "Enter a file name.";
      if (path.length > 400) return "That path is too long.";
      if (/(^|\/)\.\.(\/|$)/.test(path)) return "Paths can't contain \"..\".";
      if (/(^|\/)\.git(\/|$)/.test(path)) return "Files inside \".git\" can't be edited.";
      const name = path.split("/").pop();
      if (!name || name === "." || name === "..") return "Enter a valid file name.";
      if (/[\\:*?"<>|\u0000-\u001f]/.test(path)) {
        return "That name has characters GitHub doesn't allow.";
      }
      if (path.split("/").some((s) => s.length > 255)) return "That name is too long.";
      return "";
    }
    
    function parentPath(path) {
      const idx = path.lastIndexOf("/");
      return idx === -1 ? "" : path.slice(0, idx);
    }
    
    function suggestCommitMessage(action, path) {
      const name = path.split("/").pop();
      if (action === "delete") return `Delete ${name}`;
      if (action === "create") return `Add ${name}`;
      return `Update ${name}`;
    }
    
    // ---- Identity used for the commit's `committer` field ----
    async function ensureCommitIdentity() {
      if (githubUser && githubUser.login) return githubUser;
      try {
        const res = await fetchWithTimeout(`${API_BASE}/user`, {
          headers: authHeaders({ Accept: "application/vnd.github+json" }),
        });
        if (res.ok) {
          const me = await res.json();
          // GitHub hides private emails; the noreply form works as committer.
          githubUser = {
            login: me.login,
            name: me.name || me.login,
            email: me.email || `${me.id}+${me.login}@users.noreply.github.com`,
          };
          writeStoredJson(PROFILE_STORAGE_KEY, githubUser);
        }
      } catch (e) {
        // Offline — fall back to the default identity below.
      }
      return githubUser;
    }
    
    function committerFromIdentity(identity) {
      if (identity && identity.email) {
        return { name: identity.name, email: identity.email };
      }
      return {
        name: COMMITTER_NAME_FALLBACK,
        email: COMMITTER_EMAIL_FALLBACK,
      };
    }
    
    function encodeRepoPath(path) {
      return path.split("/").map(encodeURIComponent).join("/");
    }
    
    // ---- Read the live file so edits/deletes never clobber a newer commit ----
    // Returns null (rather than throwing) when the path doesn't exist yet,
    // which is exactly the "this is a new file" signal the composer needs.
    async function fetchRemoteFile(path) {
      const res = await githubRequest(
        `/contents/${encodeRepoPath(path)}?ref=${encodeURIComponent(BRANCH_WRITE)}`,
        { allow404: true },
      );
      if (!res) return null; // 404 -> the file doesn't exist (yet)
      return {
        sha: res.sha,
        content: res.content ? decodeUtf8Base64(res.content) : "",
        size: res.size,
      };
    }
    
    async function fetchBranchHead() {
      const res = await githubRequest(
        `/git/ref/heads/${encodeURIComponent(BRANCH_WRITE)}`,
      );
      return res ? res.object.sha : null;
    }
    
    // ---- Low-level authenticated request with friendly errors ----
    // Pass `allow404: true` to get `null` instead of a thrown error when the
    // resource is absent (used to detect "this file doesn't exist yet").
    async function githubRequest(endpoint, { method = "GET", body, allow404 } = {}) {
      const opts = {
        method,
        headers: authHeaders({
          Accept: "application/vnd.github+json",
          "X-GitHub-Api-Version": "2022-11-28",
        }),
      };
      if (body) {
        opts.headers["Content-Type"] = "application/json";
        opts.body = JSON.stringify(body);
      }
      
      let res;
      try {
        res = await fetchWithTimeout(`${API_BASE}${endpoint}`, opts);
      } catch (err) {
        if (err.name === "AbortError") {
          throw new Error("Request timed out — check your connection.");
        }
        throw new Error("Couldn't reach GitHub. Check your connection.");
      }
      
      if (allow404 && res.status === 404) return null;
      if (!res.ok) throw await writeError(res);
      if (res.status === 204) return null;
      return res.json();
    }
    
    async function writeError(res) {
      let payload = null;
      try {
        payload = await res.json();
      } catch (e) {
        // non-JSON error body
      }
      const apiMessage = payload && payload.message ? payload.message : "";
      
      if (res.status === 401) {
        return new Error(
          "GitHub rejected the token (401). Re-enter a valid token in the search panel.",
        );
      }
      if (res.status === 403 || res.status === 429) {
        const remaining = res.headers.get("x-ratelimit-remaining");
        if (remaining === "0") {
          const reset = Number(res.headers.get("x-ratelimit-reset") || 0);
          const mins = Math.max(
            1,
            Math.ceil((reset * 1000 - Date.now()) / 60000),
          );
          return new Error(
            `Rate limited by GitHub — try again in about ${mins} minute${mins === 1 ? "" : "s"}.`,
          );
        }
        if (/scope|permission|not accessible|forbidden for/i.test(apiMessage)) {
          return new Error(
            "This token can't write to this repo — it needs the \"repo\" (or \"public_repo\") scope.",
          );
        }
        return new Error(
          apiMessage ||
          "GitHub refused the change (403). Check the token's permissions.",
        );
      }
      if (res.status === 404) {
        return new Error(
          "Not found — the file, branch or repo may have moved, or the token can't see it.",
        );
      }
      if (res.status === 409) {
        return new Error(
          "This file changed on GitHub since you opened it. Reload and try again.",
        );
      }
      if (res.status === 422) {
        return new Error(
          apiMessage || "GitHub rejected that file path or content (422).",
        );
      }
      return new Error(apiMessage || `Something went wrong (${res.status}).`);
    }
    // ===============================================================
    
    let currentCode = "";
    let currentFileName = "";
    let activeController = null; // aborts stale in-flight requests
    // The contents-API entry behind the currently open code / image view, so
    // edit + delete always target the right path (and start from its blob sha).
    let currentFileItem = null;
    let currentImageItem = null;
    
    // ---- Compose (create / edit / delete) state ----
    // mode: "create" (new file) | "update" (existing file)
    let composeState = null;
    // Set when a write succeeds so the caller can show a confirmation.
    let lastCommitMessage = "";
    // Token input + search panel wiring happens above; this only needs to know
    // whether write actions should be offered at all.
    // Write buttons are always rendered so the feature stays discoverable.
    // Without a write-scoped token they show a "locked" look and, when
    // clicked, open the token prompt instead of silently doing nothing.
    function refreshWriteAffordances() {
      const allowed = hasWriteAccess();
      const hint = allowed ?
        "" :
        " — needs a GitHub token with the repo scope";
      newFileBtn.classList.toggle("locked", !allowed);
      newFileBtn.title = `Create a new file${hint}`;
      newFileBtn.setAttribute("aria-label", `Create a new file${hint}`);
      editBtn.classList.toggle("locked", !allowed);
      editBtn.title = `Edit this file${hint}`;
      deleteBtn.classList.toggle("locked", !allowed);
      deleteBtn.title = `Delete this file${hint}`;
      imageDeleteBtn.classList.toggle("locked", !allowed);
      imageDeleteBtn.title = `Delete this file${hint}`;
      if (composeState) updateDeleteButtonLabel();
    }
    
    function setOnlineStatus() {
      offlineBanner.classList.toggle("show", !navigator.onLine);
    }
    window.addEventListener("online", () => {
      setOnlineStatus();
      const top = stack[stack.length - 1];
      if (typeof top === "string") renderFolder(top);
    });
    window.addEventListener("offline", setOnlineStatus);
    setOnlineStatus();
    
    copyBtn.addEventListener("click", async () => {
      if (!currentCode) return;
      try {
        await navigator.clipboard.writeText(currentCode);
        flashButton(copyBtn, "check", "Copied");
      } catch (err) {
        flashButton(copyBtn, "x", "Failed");
      }
    });
    
    downloadBtn.addEventListener("click", () => {
      if (!currentCode) return;
      try {
        const blob = new Blob([currentCode], {
          type: "text/plain;charset=utf-8",
        });
        const url = URL.createObjectURL(blob);
        const a = document.createElement("a");
        a.href = url;
        a.download = currentFileName || "file.txt";
        document.body.appendChild(a);
        a.click();
        a.remove();
        setTimeout(() => URL.revokeObjectURL(url), 1000);
        flashButton(downloadBtn, "check", "Saved");
      } catch (err) {
        flashButton(downloadBtn, "x", "Failed");
      }
    });
    
    let currentImageUrl = "";
    let currentImageName = "";
    
    imageDownloadBtn.addEventListener("click", () => {
      if (!currentImageUrl) return;
      try {
        const a = document.createElement("a");
        a.href = currentImageUrl;
        a.download = currentImageName || "image.png";
        a.target = "_blank";
        a.rel = "noopener";
        document.body.appendChild(a);
        a.click();
        a.remove();
        flashButton(imageDownloadBtn, "check", "Saved");
      } catch (err) {
        flashButton(imageDownloadBtn, "x", "Failed");
      }
    });
    
    function flashButton(btn, iconName, label) {
      const original = btn.innerHTML;
      btn.classList.add("copied");
      btn.innerHTML = icon(iconName, 14) + " " + label;
      setTimeout(() => {
        btn.classList.remove("copied");
        btn.innerHTML = original;
      }, 1800);
    }
    
    const LANG_MAP = {
      js: "javascript",
      jsx: "jsx",
      ts: "typescript",
      tsx: "tsx",
      py: "python",
      java: "java",
      cpp: "cpp",
      cc: "cpp",
      c: "c",
      h: "c",
      hpp: "cpp",
      cs: "csharp",
      go: "go",
      rs: "rust",
      rb: "ruby",
      php: "php",
      html: "markup",
      htm: "markup",
      xml: "markup",
      css: "css",
      json: "json",
      md: "markdown",
      sh: "bash",
      bash: "bash",
      yml: "yaml",
      yaml: "yaml",
      sql: "sql",
      kt: "kotlin",
      swift: "swift",
      txt: "none",
      gitignore: "none",
    };
    
    // navigation stack: array of path strings ('' = root), {__file:true} markers,
    // or {__search:true} markers for the LeetCode-search results view
    let stack = [""];
    
    async function fetchWithTimeout(url, opts = {}) {
      const controller = new AbortController();
      activeController = controller;
      const timeout = setTimeout(() => controller.abort(), FETCH_TIMEOUT_MS);
      try {
        const res = await fetch(url, { ...opts, signal: controller.signal });
        return res;
      } finally {
        clearTimeout(timeout);
      }
    }
    
    async function ghFetch(path) {
      let res;
      try {
        res = await fetchWithTimeout(`${API}/contents/${encodeURI(path)}`, {
          headers: authHeaders({ Accept: "application/vnd.github+json" }),
        });
      } catch (err) {
        if (err.name === "AbortError") {
          throw new Error("Request timed out — check your connection.");
        }
        throw new Error("Couldn't reach GitHub. Check your connection.");
      }
      if (!res.ok) {
        // A rejected token would otherwise break every folder in the app.
        // Drop it and retry once unauthenticated — public repos still read
        // fine, and the token row in the search panel shows it was cleared.
        if (res.status === 401 && githubToken) {
          clearRejectedToken();
          try {
            const retry = await fetchWithTimeout(
              `${API}/contents/${encodeURI(path)}`,
              { headers: { Accept: "application/vnd.github+json" } },
            );
            if (retry.ok) return retry.json();
            res = retry;
          } catch (err) {
            if (err.name === "AbortError") {
              throw new Error("Request timed out — check your connection.");
            }
            throw new Error("Couldn't reach GitHub. Check your connection.");
          }
        }
        if (res.status === 401) {
          throw new Error(
            "GitHub rejected the token (401). Enter a valid one in the search panel.",
          );
        }
        if (res.status === 403 || res.status === 429) {
          const remaining = res.headers.get("x-ratelimit-remaining");
          const reset = res.headers.get("x-ratelimit-reset");
          if (remaining === "0" && reset) {
            const waitSec = Math.max(
              0,
              Math.ceil(Number(reset) - Date.now() / 1000),
            );
            const mins = Math.ceil(waitSec / 60);
            throw new Error(
              `Rate limited by GitHub — try again in about ${mins} minute${mins === 1 ? "" : "s"}.`,
            );
          }
          throw new Error("Too many requests right now — try again shortly.");
        }
        if (res.status === 404) throw new Error("Couldn't find that.");
        throw new Error(`Something went wrong (${res.status}).`);
      }
      return res.json();
    }
    
    function showList() {
      codeView.style.display = "none";
      imageView.style.display = "none";
      editView.style.display = "none";
      listView.style.display = "block";
    }
    
    function showCode() {
      listView.style.display = "none";
      imageView.style.display = "none";
      editView.style.display = "none";
      codeView.style.display = "flex";
    }
    
    function showImage() {
      listView.style.display = "none";
      codeView.style.display = "none";
      editView.style.display = "none";
      imageView.style.display = "flex";
    }
    
    function showCompose() {
      listView.style.display = "none";
      codeView.style.display = "none";
      imageView.style.display = "none";
      editView.style.display = "flex";
    }
    
    function updateHeader(path) {
      backBtn.classList.toggle("show", stack.length > 1);
      crumbEl.textContent = path === "" ? OWNER : path.split("/").join(" / ");
      titleEl.textContent = path === "" ? REPO : path.split("/").pop();
    }
    
    function renderSkeleton() {
      listView.innerHTML = "";
      const wrap = document.createElement("div");
      for (let i = 0; i < 6; i++) {
        const s = document.createElement("div");
        s.className = "skeleton-row";
        wrap.appendChild(s);
      }
      listView.appendChild(wrap);
    }
    
    function errorStatus(message, onRetry) {
      const el = document.createElement("div");
      el.className = "status error";
      el.innerHTML = `<span class="status-icon">${icon(
          navigator.onLine ? "alert" : "wifiOff",
          26,
        )}</span><span>${message}</span>`;
      const btn = document.createElement("button");
      btn.className = "retry-btn";
      btn.textContent = "Try again";
      btn.addEventListener("click", onRetry);
      el.appendChild(btn);
      return el;
    }
    
    // ============ Compose: open, commit, delete ============
    // Creates or edits a file, then commits the change with a custom message.
    // mode: "create" | "update"
    function openComposer({ mode, path, content, sha }) {
      if (!hasWriteAccess()) {
        promptForToken();
        return;
      }
      const fullPath = normalizeRepoPath(path || "");
      const initialContent = content || "";
      composeState = {
        mode,
        path: fullPath,
        originalPath: fullPath,
        // Snapshot of the text as opened, so "unsaved changes" is detectable.
        content: initialContent,
        sha: sha || null,
      };
      
      showCompose();
      backBtn.classList.add("show");
      crumbEl.textContent = `Commit to ${BRANCH_WRITE}`;
      titleEl.textContent = mode === "create" ?
        "New file" :
        fullPath.split("/").pop();
      
      fileNameInput.value = fullPath;
      editorEl.value = initialContent;
      commitMessageInput.value = suggestCommitMessage(mode, fullPath || "file");
      commitDescInput.value = "";
      composeStatus("");
      setComposeBusy(false);
      updateDeleteButtonLabel();
      updateComposePreview();
      
      stack.push({ __compose: true });
      (mode === "create" ? fileNameInput : editorEl).focus();
    }
    
    function updateDeleteButtonLabel() {
      // Delete only makes sense when editing an existing file.
      const deletable = Boolean(composeState) && composeState.mode === "update";
      deleteFileBtn.classList.toggle("hidden", !deletable);
      if (deletable) {
        deleteFileBtn.classList.toggle("locked", !hasWriteAccess());
      }
    }
    
    // Keeps the header preview in step with whatever path is typed.
    function updateComposePreview() {
      const path = normalizeRepoPath(fileNameInput.value);
      if (!path) {
        titleEl.textContent = composeState && composeState.mode === "create" ?
          "New file" :
          "Edit file";
        return;
      }
      titleEl.textContent = path.split("/").pop();
      composeState.path = path;
    }
    
    function composeGoBack() {
      if (stack.length > 1) stack.pop();
      const top = stack[stack.length - 1];
      if (typeof top === "string") {
        renderFolder(top);
      } else if (top && top.__search) {
        renderSearchResults(lastSearchQuery, lastSearchResults);
      } else {
        renderFolder("");
      }
    }
    
    function promptForToken() {
      openSearchPanel();
      tokenInput.focus();
    }
    
    // PUT /contents/{path} — creates the file, or updates it when `sha` is set.
    async function commitFile({ path, content, sha, message, description }) {
      const identity = await ensureCommitIdentity();
      const body = {
        message,
        content: encodeUtf8Base64(content),
        branch: BRANCH_WRITE,
        committer: committerFromIdentity(identity),
      };
      if (description) body.extended_description = description;
      if (sha) body.sha = sha;
      return githubRequest(`/contents/${encodeRepoPath(path)}`, {
        method: "PUT",
        body,
      });
    }
    
    // DELETE /contents/{path}
    async function deleteRemoteFile({ path, sha, message, description }) {
      const identity = await ensureCommitIdentity();
      const body = {
        message,
        sha,
        branch: BRANCH_WRITE,
        committer: committerFromIdentity(identity),
      };
      if (description) body.extended_description = description;
      return githubRequest(`/contents/${encodeRepoPath(path)}`, {
        method: "DELETE",
        body,
      });
    }
    
    function shortSha(sha) {
      return sha ? sha.slice(0, 7) : "committed";
    }
    
    // Drop caches a write invalidates so lists/searches show fresh data.
    function invalidateRepoCaches() {
      problemIndex = null;
      try {
        localStorage.removeItem(INDEX_STORAGE_KEY);
      } catch (e) {
        // ignore
      }
    }
    
    // A small, self-dismissing confirmation banner for completed commits.
    let bannerTimer = null;
    function flashBanner(text, url) {
      let el = document.getElementById("commit-banner");
      if (!el) {
        el = document.createElement("div");
        el.id = "commit-banner";
        el.className = "commit-banner";
        document.body.appendChild(el);
      }
      el.innerHTML =
        `${icon("check", 14)}<span>${escapeHtml(text)}</span>` +
        (url ?
          `<a href="${escapeHtml(url)}" target="_blank" rel="noopener">View commit</a>` :
          "");
      el.classList.add("show");
      clearTimeout(bannerTimer);
      bannerTimer = setTimeout(() => el.classList.remove("show"), 4000);
    }
    // ========================================================
    
    async function handleCommitClick() {
      if (!composeState) return;
      
      const path = normalizeRepoPath(fileNameInput.value);
      const message = commitMessageInput.value.trim();
      const description = commitDescInput.value.trim();
      
      const badPath = pathError(path);
      if (badPath) {
        composeStatus(badPath, "error");
        fileNameInput.focus();
        return;
      }
      if (!message) {
        composeStatus("Add a commit message so the change is easy to find.", "error");
        commitMessageInput.focus();
        return;
      }
      
      setComposeBusy(true, "Committing…");
      composeStatus("Reading the latest version from GitHub…");
      
      try {
        // Re-read the live blob so two edits in a row can never conflict.
        const live = await fetchRemoteFile(path);
        
        if (composeState.mode === "create" && live) {
          setComposeBusy(false);
          composeStatus(
            `${path} already exists — edit it instead.`,
            "error",
          );
          return;
        }
        if (composeState.mode === "update" && !live) {
          setComposeBusy(false);
          composeStatus(`${path} no longer exists on GitHub — nothing to update.`, "error");
          return;
        }
        
        const content = editorEl.value;
        if (live && live.content === content) {
          setComposeBusy(false);
          composeStatus("No changes to commit.", "error");
          return;
        }
        
        composeStatus(`Committing to ${BRANCH_WRITE}…`);
        const res = await commitFile({
          path,
          content,
          sha: live ? live.sha : null,
          message,
          description,
        });
        
        const verb = live ? "Updated" : "Created";
        invalidateRepoCaches();
        setComposeBusy(false);
        composeStatus(`${verb} ${path} — ${shortSha(res.commit.sha)}`, "ok");
        stack.pop();
        await renderFolder(parentPath(path));
        flashBanner(`${verb} ${path}`, res.commit.html_url);
      } catch (err) {
        setComposeBusy(false);
        composeStatus(err.message || "Couldn't commit that change.", "error");
      }
    }
    
    // Shared delete flow: confirm in a modal (with a commit message field),
    // then DELETE the contents entry so GitHub records a commit.
    async function confirmAndDeleteFile({ path, sha, message, onDone, onError }) {
      if (!hasWriteAccess()) {
        promptForToken();
        return;
      }
      let live = null;
      try {
        live = await fetchRemoteFile(path);
        if (!live) {
          if (onError) onError(`${path} doesn't exist on GitHub any more.`);
          return;
        }
      } catch (err) {
        if (onError) onError(err.message || "Couldn't reach GitHub.");
        return;
      }
      
      const messageInput = modalInput(
        "delete-commit-message",
        message || suggestCommitMessage("delete", path),
        "Commit message (required)",
      );
      
      openModal({
        title: "Delete file?",
        danger: true,
        body: [
          modalText(
            `This removes <code>${escapeHtml(path)}</code> from <strong>${escapeHtml(BRANCH_WRITE)}</strong> and records a commit.`,
          ),
          modalField("Commit message", messageInput),
        ],
        confirmLabel: "Delete & commit",
        onConfirm: async () => {
          const msg = messageInput.value.trim();
          if (!msg) {
            messageInput.focus();
            return;
          }
          try {
            const res = await deleteRemoteFile({
              path,
              sha: live.sha,
              message: msg,
            });
            invalidateRepoCaches();
            closeModal();
            flashBanner(`Deleted ${path}`, res.commit.html_url);
            if (onDone) onDone(res);
          } catch (err) {
            closeModal();
            if (onError) onError(err.message || "Couldn't delete that file.");
            else flashBanner(err.message || "Couldn't delete that file");
          }
        },
      });
    }
    // ========================================================
    
    // ---- Modal helpers (confirm / prompt) ----
    let activeModalCleanup = null;
    
    function closeModal() {
      if (activeModalCleanup) {
        activeModalCleanup();
        activeModalCleanup = null;
      }
      modalRoot.classList.remove("show");
      modalRoot.innerHTML = "";
    }
    
    function openModal({ title, danger, body, confirmLabel, onConfirm }) {
      closeModal();
      const modal = document.createElement("div");
      modal.className = "modal" + (danger ? " danger" : "");
      
      const heading = document.createElement("div");
      heading.className = "modal-title" + (danger ? " danger" : "");
      heading.innerHTML = `${icon(danger ? "alert" : "git", 17)}<span>${escapeHtml(title)}</span>`;
      modal.appendChild(heading);
      
      (body || []).forEach((el) => modal.appendChild(el));
      
      const actions = document.createElement("div");
      actions.className = "modal-actions";
      const cancelBtn = document.createElement("button");
      cancelBtn.className = "mini-btn ghost";
      cancelBtn.textContent = "Cancel";
      cancelBtn.addEventListener("click", closeModal);
      const confirmBtn = document.createElement("button");
      confirmBtn.className = danger ? "btn-danger" : "btn-primary";
      confirmBtn.innerHTML = `${icon(danger ? "trash" : "check", 14)} <span>${escapeHtml(confirmLabel || "Confirm")}</span>`;
      actions.appendChild(cancelBtn);
      actions.appendChild(confirmBtn);
      modal.appendChild(actions);
      
      modalRoot.innerHTML = "";
      modalRoot.appendChild(modal);
      modalRoot.classList.add("show");
      
      // Enter confirms, Escape cancels, and the backdrop closes.
      const onKey = (e) => {
        if (e.key === "Escape") {
          e.preventDefault();
          closeModal();
        } else if (e.key === "Enter" && !e.shiftKey) {
          const tag = document.activeElement && document.activeElement.tagName;
          if (tag === "TEXTAREA") return; // Enter belongs to the textarea
          e.preventDefault();
          confirmBtn.click();
        }
      };
      document.addEventListener("keydown", onKey);
      const onBackdrop = (e) => {
        if (e.target === modalRoot) closeModal();
      };
      modalRoot.addEventListener("click", onBackdrop);
      activeModalCleanup = () => {
        document.removeEventListener("keydown", onKey);
        modalRoot.removeEventListener("click", onBackdrop);
      };
      
      confirmBtn.addEventListener("click", async () => {
        confirmBtn.disabled = true;
        cancelBtn.disabled = true;
        const original = confirmBtn.innerHTML;
        confirmBtn.innerHTML = `${icon("loader", 14)} <span>Working…</span>`;
        try {
          await onConfirm();
        } finally {
          confirmBtn.innerHTML = original;
          confirmBtn.disabled = false;
          cancelBtn.disabled = false;
        }
      });
      
      const firstField = modal.querySelector("input, textarea");
      if (firstField) firstField.focus();
      return { modal, confirmBtn, cancelBtn, onKey };
    }
    
    function modalText(html) {
      const el = document.createElement("div");
      el.className = "modal-text";
      el.innerHTML = html;
      return el;
    }
    
    function modalField(labelText, inputEl) {
      const wrap = document.createElement("div");
      wrap.className = "modal-field";
      const label = document.createElement("label");
      label.textContent = labelText;
      label.setAttribute("for", inputEl.id || "");
      wrap.appendChild(label);
      wrap.appendChild(inputEl);
      return wrap;
    }
    
    function modalInput(id, value, placeholder, className) {
      const input = document.createElement("input");
      input.id = id;
      input.className = className || "field-input";
      input.type = "text";
      input.value = value || "";
      input.placeholder = placeholder || "";
      input.spellcheck = false;
      input.autocomplete = "off";
      return input;
    }
    
    async function renderFolder(path) {
      showList();
      updateHeader(path);
      renderSkeleton();
      renderListActions(path);
      try {
        const items = await ghFetch(path);
        if (!Array.isArray(items)) {
          listView.innerHTML = "";
          listView.appendChild(
            errorStatus("That doesn't look like a folder.", () =>
              renderFolder(path),
            ),
          );
          return;
        }
        const visible = items.filter(
          (item) => !HIDDEN_PATTERNS.some((re) => re.test(item.name)),
        );
        if (visible.length === 0) {
          listView.innerHTML = "";
          const empty = document.createElement("div");
          empty.className = "empty";
          empty.innerHTML = `<span class="empty-icon">${icon("emptyFolder", 30)}</span>Nothing to see here.`;
          listView.appendChild(empty);
          const addBtn = document.createElement("button");
          addBtn.className = "mini-btn ok" + (hasWriteAccess() ? "" : " locked");
          addBtn.innerHTML = `${icon("plus", 13)} New file here`;
          if (!hasWriteAccess()) {
            addBtn.title = "Needs a GitHub token with the repo scope";
          }
          addBtn.addEventListener("click", () => startNewFile(path));
          const wrap = document.createElement("div");
          wrap.style.display = "flex";
          wrap.style.justifyContent = "center";
          wrap.appendChild(addBtn);
          listView.appendChild(wrap);
          return;
        }
        const sorted = [...visible].sort((a, b) => {
          if (a.type !== b.type) return a.type === "dir" ? -1 : 1;
          return a.name.localeCompare(b.name);
        });
        const list = document.createElement("div");
        list.className = "card-list";
        sorted.forEach((item, i) => {
          const row = document.createElement("div");
          row.className = "row";
          row.style.animationDelay = `${Math.min(i, 10) * 18}ms`;
          const createdLabel = formatDate(item.created_at);
          const updatedLabel = formatDate(item.updated_at);
          const dateBits = [];
          if (createdLabel) dateBits.push(`Created ${createdLabel}`);
          if (updatedLabel) dateBits.push(`Modified ${updatedLabel}`);
          
          if (item.type === "dir") {
            row.innerHTML = `
          <div class="badge folder">${icon("folder", 18)}</div>
          <div class="row-info">
            <div class="row-name">${escapeHtml(item.name)}</div>
            <div class="row-sub">Folder${dateBits.length ? `<span class="dot">·</span>${dateBits.join(" · ")}` : ""}</div>
          </div>
          <div class="row-chev">${icon("chevron", 15)}</div>`;
            row.addEventListener("click", () => {
              stack.push(item.path);
              renderFolder(item.path);
            });
          } else {
            const sizeLabel = formatBytes(item.size);
            row.innerHTML = `
          <div class="badge">${fileIconHtml(item.name)}</div>
          <div class="row-info">
            <div class="row-name">${escapeHtml(item.name)}</div>
            <div class="row-sub">${sizeLabel}${dateBits.length ? `<span class="dot">·</span>${dateBits.join(" · ")}` : ""}</div>
          </div>
          <div class="row-chev">${icon("chevron", 15)}</div>`;
            row.addEventListener("click", () => openFile(item));
            addRowTools(row, item);
          }
          list.appendChild(row);
        });
        listView.innerHTML = "";
        listView.appendChild(list);
      } catch (err) {
        listView.innerHTML = "";
        listView.appendChild(
          errorStatus(err.message, () => renderFolder(path)),
        );
      }
    }
    
    function escapeHtml(str) {
      const div = document.createElement("div");
      div.textContent = str;
      return div.innerHTML;
    }
    
    // Extra per-row buttons (edit / delete), always shown so the feature is
    // discoverable. They dim and prompt for a token when write access is missing.
    function addRowTools(row, item) {
      const locked = hasWriteAccess() ? "" : " locked";
      const tools = document.createElement("div");
      tools.className = "row-actions";
      
      const editTool = document.createElement("button");
      editTool.className = "row-tool" + locked;
      editTool.title = hasWriteAccess() ?
        `Edit ${item.name}` :
        `Edit ${item.name} — needs a GitHub token with the repo scope`;
      editTool.setAttribute("aria-label", `Edit ${item.name}`);
      editTool.innerHTML = icon("edit", 14);
      editTool.addEventListener("click", (e) => {
        e.stopPropagation();
        startEditExistingFile(item);
      });
      
      const delTool = document.createElement("button");
      delTool.className = "row-tool del" + locked;
      delTool.title = hasWriteAccess() ?
        `Delete ${item.name}` :
        `Delete ${item.name} — needs a GitHub token with the repo scope`;
      delTool.setAttribute("aria-label", `Delete ${item.name}`);
      delTool.innerHTML = icon("trash", 14);
      delTool.addEventListener("click", (e) => {
        e.stopPropagation();
        confirmAndDeleteFile({
          path: item.path,
          sha: item.sha,
          onDone: () => renderFolder(parentPath(item.path)),
        });
      });
      
      tools.appendChild(editTool);
      tools.appendChild(delTool);
      row.insertBefore(tools, row.querySelector(".row-chev"));
    }
    
    // A slim floating toolbar above the list with folder-scoped write actions.
    // Always rendered; the "New file" button prompts for a token when needed.
    function renderListActions(path) {
      listActionsBar.innerHTML = "";
      const allowed = hasWriteAccess();
      listView.classList.add("has-actions");
      
      const newBtn = document.createElement("button");
      newBtn.className = "mini-btn ok" + (allowed ? "" : " locked");
      newBtn.innerHTML = `${icon("plus", 13)} New file`;
      newBtn.title = allowed ?
        `Create a file in ${path || REPO}` :
        `Create a file in ${path || REPO} — needs a GitHub token with the repo scope`;
      newBtn.addEventListener("click", () => startNewFile(path));
      listActionsBar.appendChild(newBtn);
      
      const refreshBtn = document.createElement("button");
      refreshBtn.className = "mini-btn ghost";
      refreshBtn.innerHTML = icon("refresh", 13);
      refreshBtn.title = "Refresh this folder";
      refreshBtn.setAttribute("aria-label", "Refresh this folder");
      refreshBtn.addEventListener("click", () => renderFolder(path));
      listActionsBar.appendChild(refreshBtn);
    }
    
    // ---- Entry points for creating / editing files ----
    function startNewFile(dirPath) {
      openComposer({
        mode: "create",
        path: dirPath ? `${dirPath}/` : "",
        content: "",
        sha: null,
      });
    }
    
    function startEditExistingFile(item) {
      // Open immediately with whatever text is already in memory, then swap in
      // the live blob (sha + content) so the commit is based on GitHub's copy.
      const cached =
        currentFileName === item.name && currentCode ? currentCode : "";
      const target = item.path;
      openComposer({
        mode: "update",
        path: target,
        content: cached,
        sha: item.sha || null,
      });
      // openComposer bails out (and prompts for a token) without write access.
      if (!composeState) return;
      composeStatus("Loading the latest version from GitHub…");
      fetchRemoteFile(target)
        .then((live) => {
          // The user may have navigated away or switched files by now.
          if (!composeState || composeState.path !== target) return;
          if (!live) {
            composeStatus(`${target} no longer exists on GitHub.`, "error");
            return;
          }
          composeState.sha = live.sha;
          if (!editorEl.value) {
            editorEl.value = live.content;
            composeState.content = live.content;
          }
          composeStatus("");
        })
        .catch((err) => {
          if (!composeState || composeState.path !== target) return;
          // Committing re-reads the sha, so a failed prefetch isn't fatal.
          composeStatus(err.message || "Couldn't preload the file.", "error");
        });
    }
    
    async function fetchFileContent(item) {
      // Prefer the direct download_url; fall back to the git blob API
      // for large files where GitHub omits download_url.
      if (item.download_url) {
        const res = await fetchWithTimeout(item.download_url);
        if (!res.ok)
          throw new Error(`Couldn't load this file (${res.status}).`);
        return res.text();
      }
      if (item.path) {
        const res = await fetchWithTimeout(rawFileUrl(item.path));
        if (res.ok) return res.text();
      }
      if (item.git_url) {
        const res = await fetchWithTimeout(item.git_url, {
          headers: { Accept: "application/vnd.github+json" },
        });
        if (!res.ok)
          throw new Error(`Couldn't load this file (${res.status}).`);
        const data = await res.json();
        if (data.encoding === "base64") {
          return decodeURIComponent(
            atob(data.content.replace(/\n/g, ""))
            .split("")
            .map((c) => "%" + c.charCodeAt(0).toString(16).padStart(2, "0"))
            .join(""),
          );
        }
        return data.content || "";
      }
      throw new Error("This file can't be previewed.");
    }
    
    function isImageFile(name) {
      const ext = name.includes(".") ?
        name.split(".").pop().toLowerCase() :
        "";
      return IMAGE_EXTENSIONS.has(ext);
    }
    
    async function openImage(item) {
      showImage();
      currentImageItem = item;
      backBtn.classList.add("show");
      crumbEl.textContent =
        item.path.split("/").slice(0, -1).join(" / ") || OWNER;
      titleEl.textContent = item.name;
      imagePathEl.textContent = item.name;
      currentImageName = item.name;
      const createdLabel = formatDate(item.created_at);
      const updatedLabel = formatDate(item.updated_at);
      imageDatesEl.textContent = [
          createdLabel ? `Created ${createdLabel}` : null,
          updatedLabel ? `Modified ${updatedLabel}` : null,
        ]
        .filter(Boolean)
        .join(" · ");
      imageRawLinkEl.href =
        item.html_url ||
        `https://github.com/${OWNER}/${REPO}/blob/${BRANCH_FALLBACK}/${item.path}`;
      imagewrap.innerHTML = `<div class="status">Loading ${escapeHtml(item.name)}…</div>`;
      currentImageUrl = "";
      
      try {
        const url = item.download_url;
        if (!url) throw new Error("This image can't be previewed.");
        currentImageUrl = url;
        
        const img = document.createElement("img");
        img.alt = item.name;
        img.onload = () => {
          imagewrap.innerHTML = "";
          imagewrap.appendChild(img);
        };
        img.onerror = () => {
          imagewrap.innerHTML = "";
          const wrap = document.createElement("div");
          wrap.style.padding = "8px";
          wrap.appendChild(
            errorStatus("Couldn't load this image.", () => openImage(item)),
          );
          imagewrap.appendChild(wrap);
        };
        img.src = url;
        
        stack.push({ __file: true });
      } catch (err) {
        imagewrap.innerHTML = "";
        const wrap = document.createElement("div");
        wrap.style.padding = "8px";
        wrap.appendChild(
          errorStatus(err.message || "Couldn't load this image.", () =>
            openImage(item),
          ),
        );
        imagewrap.appendChild(wrap);
      }
    }
    
    async function openFile(item) {
      if (isImageFile(item.name)) {
        await openImage(item);
        return;
      }
      showCode();
      currentFileItem = item;
      backBtn.classList.add("show");
      crumbEl.textContent =
        item.path.split("/").slice(0, -1).join(" / ") || OWNER;
      titleEl.textContent = item.name;
      currentPathEl.textContent = item.name;
      currentFileName = item.name;
      const createdLabel = formatDate(item.created_at);
      const updatedLabel = formatDate(item.updated_at);
      currentDatesEl.textContent = [
          createdLabel ? `Created ${createdLabel}` : null,
          updatedLabel ? `Modified ${updatedLabel}` : null,
        ]
        .filter(Boolean)
        .join(" · ");
      rawLinkEl.href =
        item.html_url ||
        `https://github.com/${OWNER}/${REPO}/blob/${BRANCH_FALLBACK}/${item.path}`;
      codewrap.innerHTML = `<div class="status">Loading ${escapeHtml(item.name)}…</div>`;
      currentCode = "";
      
      try {
        const text = await fetchFileContent(item);
        currentCode = text;
        
        const ext = item.name.includes(".") ?
          item.name.split(".").pop().toLowerCase() :
          "";
        const lang = LANG_MAP[ext] || "none";
        
        const pre = document.createElement("pre");
        pre.className = `language-${lang}`;
        const code = document.createElement("code");
        code.className = `language-${lang}`;
        code.textContent = text;
        pre.appendChild(code);
        
        codewrap.innerHTML = "";
        codewrap.appendChild(pre);
        if (lang !== "none") {
          try {
            Prism.highlightElement(code);
          } catch (e) {
            // Highlighting is best-effort; raw text is already visible.
          }
        }
        linkifyCode(code);
        addLineNumbers(pre, text);
        
        stack.push({ __file: true });
      } catch (err) {
        codewrap.innerHTML = "";
        const wrap = document.createElement("div");
        wrap.style.padding = "8px";
        wrap.appendChild(
          errorStatus(err.message || "Couldn't load this file.", () =>
            openFile(item),
          ),
        );
        codewrap.appendChild(wrap);
      }
    }
    
    // ---- LeetCode problem-number search ----
    // Code Search (/search/code) requires auth and is blocked by CORS in
    // the browser. Instead: one recursive git-tree request, then scan
    // file heads from raw.githubusercontent.com (CORS-friendly, no token).
    const INDEX_STORAGE_KEY = "gh_problem_index_v2";
    const PROBLEM_NO_RES = [
      /leet\s*code\s*(?:problem\s*)?(?:no\.?|nos\.?|number|#)?\s*:?\s*(\d+)/gi,
      /problem\s*(?:no\.?|nos\.?|number|#)\s*:?\s*(\d+)/gi,
      /\bLC\s*#?\s*:?\s*(\d+)/gi,
    ];
    
    function extractProblemNumbers(text) {
      const nums = new Set();
      const head = text.slice(0, 4000);
      for (const re of PROBLEM_NO_RES) {
        re.lastIndex = 0;
        let m;
        while ((m = re.exec(head)) !== null) nums.add(m[1]);
      }
      return [...nums];
    }
    const INDEX_CONCURRENCY = 8;
    let problemIndex = null; // { sha, files: [{ name, path, problemNos }] }
    let lastSearchQuery = "";
    let lastSearchResults = [];
    
    function openSearchPanel() {
      searchPanel.classList.add("show");
      searchToggleBtn.classList.add("active");
      searchInput.focus();
    }
    
    function closeSearchPanel() {
      searchPanel.classList.remove("show");
      searchToggleBtn.classList.remove("active");
    }
    
    searchToggleBtn.addEventListener("click", () => {
      if (searchPanel.classList.contains("show")) {
        closeSearchPanel();
      } else {
        openSearchPanel();
      }
    });
    searchCloseBtn.addEventListener("click", closeSearchPanel);
    searchInput.addEventListener("keydown", (e) => {
      if (e.key === "Enter") {
        e.preventDefault();
        triggerSearch();
      } else if (e.key === "Escape") {
        closeSearchPanel();
      }
    });
    searchGoBtn.addEventListener("click", triggerSearch);
    
    function triggerSearch() {
      const num = searchInput.value.replace(/[^0-9]/g, "").trim();
      if (!num) {
        searchInput.focus();
        return;
      }
      closeSearchPanel();
      runSearch(num);
    }
    
    async function fetchRepoTree() {
      let res;
      try {
        res = await fetchWithTimeout(
          `${API}/git/trees/${encodeURIComponent(BRANCH_FALLBACK)}?recursive=1`, { headers: authHeaders({ Accept: "application/vnd.github+json" }) },
        );
      } catch (err) {
        if (err.name === "AbortError") {
          throw new Error("Request timed out — check your connection.");
        }
        throw new Error("Couldn't reach GitHub. Check your connection.");
      }
      if (!res.ok) {
        if (res.status === 403 || res.status === 429) {
          throw new Error("Too many requests right now — try again shortly.");
        }
        if (res.status === 404) throw new Error("Couldn't find that.");
        throw new Error(`Something went wrong (${res.status}).`);
      }
      return res.json();
    }
    
    async function mapPool(items, limit, fn) {
      const results = new Array(items.length);
      let next = 0;
      async function worker() {
        while (next < items.length) {
          const i = next++;
          results[i] = await fn(items[i]);
        }
      }
      const n = Math.min(limit, items.length);
      await Promise.all(Array.from({ length: n }, () => worker()));
      return results;
    }
    
    function readCachedIndex() {
      try {
        const cached = JSON.parse(
          localStorage.getItem(INDEX_STORAGE_KEY) || "null",
        );
        if (cached && cached.sha && Array.isArray(cached.files)) return cached;
      } catch (e) {
        // ignore bad cache
      }
      return null;
    }
    
    async function ensureProblemIndex(onProgress) {
      if (problemIndex) return problemIndex;
      
      const tree = await fetchRepoTree();
      const cached = readCachedIndex();
      if (cached && cached.sha === tree.sha) {
        problemIndex = cached;
        return problemIndex;
      }
      
      const blobs = (tree.tree || []).filter((node) => {
        if (node.type !== "blob") return false;
        const name = node.path.split("/").pop();
        if (HIDDEN_PATTERNS.some((re) => re.test(name))) return false;
        const ext = name.includes(".") ?
          name.split(".").pop().toLowerCase() :
          "";
        return SEARCHABLE_EXT.has(ext);
      });
      
      if (onProgress) onProgress(0, blobs.length);
      
      let done = 0;
      const files = [];
      await mapPool(blobs, INDEX_CONCURRENCY, async (node) => {
        try {
          const res = await fetchWithTimeout(rawFileUrl(node.path));
          if (!res.ok) return;
          const text = await res.text();
          const problemNos = extractProblemNumbers(text);
          if (problemNos.length) {
            files.push({
              name: node.path.split("/").pop(),
              path: node.path,
              problemNos,
            });
          }
        } catch (e) {
          // skip files that fail to load
        } finally {
          done += 1;
          if (onProgress) onProgress(done, blobs.length);
        }
      });
      
      problemIndex = { sha: tree.sha, files };
      try {
        localStorage.setItem(INDEX_STORAGE_KEY, JSON.stringify(problemIndex));
      } catch (e) {
        // quota / private mode
      }
      return problemIndex;
    }
    
    async function runSearch(num) {
      showList();
      stack.push({ __search: true });
      backBtn.classList.add("show");
      crumbEl.textContent = "Search results";
      titleEl.textContent = `LeetCode #${num}`;
      renderSkeleton();
      lastSearchQuery = num;
      try {
        const index = await ensureProblemIndex((done, total) => {
          if (!total) return;
          titleEl.textContent = `Indexing files… ${done}/${total}`;
        });
        lastSearchResults = index.files.filter((item) =>
          (item.problemNos || []).includes(String(num)),
        );
        renderSearchResults(num, lastSearchResults);
      } catch (err) {
        titleEl.textContent = `LeetCode #${num}`;
        listView.innerHTML = "";
        listView.appendChild(
          errorStatus(err.message || "Couldn't search right now.", () =>
            runSearch(num),
          ),
        );
      }
    }
    
    function renderSearchResults(num, items) {
      showList();
      // The floating folder toolbar doesn't apply to search results.
      listActionsBar.innerHTML = "";
      listActionsBar.classList.add("hidden");
      listView.classList.remove("has-actions");
      crumbEl.textContent = "Search results";
      titleEl.textContent = `LeetCode #${num}`;
      backBtn.classList.add("show");
      if (!items.length) {
        listView.innerHTML = `<div class="empty"><span class="empty-icon">${icon("emptyFolder", 30)}</span>No files tagged with LeetCode problem #${escapeHtml(num)}.</div>`;
        return;
      }
      const list = document.createElement("div");
      list.className = "card-list";
      items.forEach((item, i) => {
        const row = document.createElement("div");
        row.className = "row";
        row.style.animationDelay = `${Math.min(i, 10) * 18}ms`;
        const dirPath = item.path.split("/").slice(0, -1).join(" / ");
        row.innerHTML = `
          <div class="badge">${fileIconHtml(item.name)}</div>
          <div class="row-info">
            <div class="row-name">${escapeHtml(item.name)}</div>
            <div class="row-sub">${dirPath ? escapeHtml(dirPath) : OWNER}<span class="dot">·</span><span class="result-tag">${icon("search", 11)} #${escapeHtml(num)}</span></div>
          </div>
          <div class="row-chev">${icon("chevron", 15)}</div>`;
        row.addEventListener("click", () => openSearchResult(item));
        list.appendChild(row);
      });
      listView.innerHTML = "";
      listView.appendChild(list);
    }
    
    async function openSearchResult(item) {
      await openFile({
        name: item.name,
        path: item.path,
        download_url: rawFileUrl(item.path),
        html_url: `https://github.com/${OWNER}/${REPO}/blob/${BRANCH_FALLBACK}/${item.path}`,
      });
    }
    // ---- end search ----
    
    backBtn.addEventListener("click", () => {
      if (stack.length <= 1) return;
      const leavingCompose =
        composeState && !isComposeClean() ? confirmDiscardCompose() : false;
      if (leavingCompose) return; // dialog takes over
      stack.pop();
      const top = stack[stack.length - 1];
      composeState = null;
      closeModal();
      if (typeof top === "string") {
        renderFolder(top);
      } else if (top && top.__search) {
        renderSearchResults(lastSearchQuery, lastSearchResults);
      } else if (top && top.__file) {
        renderFolder("");
      }
    });
    
    // ---- Compose wiring ----
    // "Clean" means nothing worth losing: the text, path and message all still
    // hold their opening values, so leaving can't discard real work.
    function isComposeClean() {
      if (!composeState) return true;
      const originalMessage = suggestCommitMessage(
        composeState.mode,
        composeState.originalPath || "file",
      );
      return (
        editorEl.value === composeState.content &&
        normalizeRepoPath(fileNameInput.value) === composeState.originalPath &&
        commitMessageInput.value.trim() === originalMessage &&
        !commitDescInput.value.trim()
      );
    }
    
    function confirmDiscardCompose() {
      if (!composeState || isComposeClean()) return false;
      openModal({
        title: "Discard changes?",
        danger: true,
        body: [
          modalText(
            "You have unsaved edits. Leaving now loses them — nothing has been committed.",
          ),
        ],
        confirmLabel: "Discard",
        onConfirm: () => {
          composeState = null;
          closeModal();
          if (stack.length > 1) stack.pop();
          const top = stack[stack.length - 1];
          if (typeof top === "string") renderFolder(top);
          else if (top && top.__search) {
            renderSearchResults(lastSearchQuery, lastSearchResults);
          } else renderFolder("");
        },
      });
      return true;
    }
    
    saveFileBtn.addEventListener("click", handleCommitClick);
    cancelEditBtn.addEventListener("click", () => {
      const blocked = confirmDiscardCompose();
      if (blocked) return;
      composeState = null;
      composeGoBack();
    });
    deleteFileBtn.addEventListener("click", () => {
      if (!composeState || composeState.mode !== "update") return;
      confirmAndDeleteFile({
        path: composeState.path,
        sha: composeState.sha,
        message: commitMessageInput.value.trim() ||
          suggestCommitMessage("delete", composeState.path),
        onDone: () => {
          composeState = null;
          composeGoBack();
        },
        onError: (msg) => composeStatus(msg, "error"),
      });
    });
    
    // Ctrl/Cmd+S commits; Escape backs out of the composer.
    document.addEventListener("keydown", (e) => {
      if (!composeState) return;
      if ((e.ctrlKey || e.metaKey) && e.key.toLowerCase() === "s") {
        e.preventDefault();
        handleCommitClick();
      }
    });
    
    commitMessageInput.addEventListener("keydown", (e) => {
      if (e.key === "Enter") {
        e.preventDefault();
        handleCommitClick();
      }
    });
    
    // Keep the header in sync while the path is typed.
    fileNameInput.addEventListener("input", () => {
      if (composeState) updateComposePreview();
    });
    
    // Ctrl/Cmd+Enter always commits, even from inside the editor.
    editorEl.addEventListener("keydown", (e) => {
      if ((e.ctrlKey || e.metaKey) && e.key === "Enter") {
        e.preventDefault();
        handleCommitClick();
        return;
      }
      // Keep tab-indentation inside the editor instead of moving focus.
      if (e.key === "Tab") {
        e.preventDefault();
        const start = editorEl.selectionStart;
        const end = editorEl.selectionEnd;
        editorEl.setRangeText("  ", start, end, "end");
      }
    });
    
    // ---- Code / image view write actions ----
    editBtn.addEventListener("click", () => {
      if (!currentFileItem) return;
      startEditExistingFile(currentFileItem);
    });
    
    deleteBtn.addEventListener("click", () => {
      if (!currentFileItem) return;
      const item = currentFileItem;
      confirmAndDeleteFile({
        path: item.path,
        sha: item.sha,
        onDone: () => {
          stack.pop();
          const top = stack[stack.length - 1];
          renderFolder(typeof top === "string" ? top : parentPath(item.path));
        },
      });
    });
    
    imageDeleteBtn.addEventListener("click", () => {
      if (!currentImageItem) return;
      const item = currentImageItem;
      confirmAndDeleteFile({
        path: item.path,
        sha: item.sha,
        onDone: () => {
          stack.pop();
          const top = stack[stack.length - 1];
          renderFolder(typeof top === "string" ? top : parentPath(item.path));
        },
      });
    });
    
    newFileBtn.addEventListener("click", () => {
      const top = stack[stack.length - 1];
      startNewFile(typeof top === "string" ? top : "");
    });
    
    window.addEventListener("error", (e) => {
      // Swallow stray script errors (e.g. from CDN hiccups) so the UI
      // doesn't get stuck on a blank screen.
      console.error("Unhandled error:", e.error || e.message);
    });
    
    // Show/hide the write affordances for whatever token is already stored.
    refreshWriteAffordances();
    
    renderFolder("");
  