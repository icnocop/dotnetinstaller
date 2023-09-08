## 5.0.2.21

### Fixes:

* [Graphics] regression fixes.
* [JS] GC issue, forcing `Window.share = null` at main window closure.
* [gtk/cairo] fix of font metrics calculation;
* [virtual-list] fix;
* [select|dropdown] @set inheritance fix;
* [css] fix of AV in _appearance_ property inheritance;
* [i18n] `Intl.DateTimeFormat()` implementation;

### New:

* alternative event names, see [Known Events](https://docs.sciter.com/docs/DOM/Event#known-events).

## 5.0.2.20

### Fixes:

* [layout] fix of whitspace handling after `<br>`
* [linux/cairo] fix of Graphics.fillRect();
* `<select editable>` handling fix;
* [gtk] new Window() / OpenGL fix;

## 5.0.2.19

### Fixes:

* `<frameset>`, fix of mouse move handling.
* [reactor] fix of fragment stripping attributes. See: https://sciter.com/forums/topic/unexpected-behavior-with-blank-jsx-nodes/ .
* Fix of an issue with [CSS variables on root node](https://sciter.com/forums/topic/css-variables-in-html-selector/).
* fix of `<details>`
* `<widget|?scrollbar>` generation of "change" event + standalone-scrollbar demo 
* [API] Fix of "silent error issue".
* [CSS] fix of hit-test on `position:relative;z-index:...` inside scrollables.
* `element.state.box(...)` fix to report actual DOM positions.
* [layout] fix of layout adjustments after scroll bar appearance/disappearance.
* `env.arguments()`, implementation;
* [virtual-list] fix of `vlist.navigateTo()`;
* [reactor] r13n fix of elements that contain callbacks in attributes.
* [css] adjacent selector handling fixes;
* [osx] fix of random error in popup window creation;
* promise callbacks to come before `setTimer(,0)`;
* fix of mouse handling on vertical-align: middle | bottom; layouts
* [osx] NSOpenGLPFAAccelerated is optional while creating OpenGL context, to allow it to run VM.
* Fix of https://sciter.com/forums/topic/select-dropdown-emojis/
* `element.takeOff()`, `element.popup()` to not activate host window by default.
* [virtual-list] fix of non-animated scroll.
* [reactor] `componentDidMount` - not posted but immediate (sort of) event.
* `<br>` spacing, one more fix.
* videostart, videostop, videoready events

### New:

* [JSDOM] + `element.offsetParent` property.
* + `ZipItem.attributes` 
* `<select editable filter="...">` support.
* documentation refactoring for https://docs.sciter.com
* [lottie] support width:auto and height:auto;
* /samples.css/css-flex/ to match documentation.


## 5.0.2.18

### Fixes:

* [master-css] `<select|list multiple=checkmarks>` `option:current` style fix;
* [CSS] fix of animation when `animation-name` is removed (shall stop);
* [i18n-reactor] demo of context menu translation;
* sciter-mixin demo: enabling connection with inspector;
* `el.removeAttribute("style")` fix;
* `<select|list>` fix of `.value = ...;`;
* `Graphics.Rect(Point start,Point end)` fix when end < start;
* [sciter-webview] fix of initialization sequence on Windows;
* [touch scroll] rollback error fix;
* [layout] fix of extra 1ppx width in `<br/>`;
* [CSS] fix of  "a > b c" selector handling;
* [reactor] fix of reconciliation issue on similar elements, see: https://sciter.com/forums/topic/reactor-always-have-inexplicable-problems/;
* [reactor] fix of attribute `style` handling;
* `color.toString("RGBA")` fix;
* documentation of `<select|list multiple>` and `<select|tree>`;
* document node is always focusable if not explicitly disabled;
* [JSX] state-checked update fix;
* [CSS] `::marker` drawing fix;
* `flow:horizontal-flow;` fix of flex children handling;
* [JS] `fetch()` fix: https://sciter.com/forums/topic/fetch-does-not-support-binary-body ;
* `<input|text>` fix of caret position restoration;
* behavior:menu fix of focus restoration after menu closure;
* "unloadequest" -> "unloadrequest" fix;
* [DOM] `new Event("keydown", {code:"ArrowDown"})` fix;
* sdk.js/samples.sciter/lightbox-dialog/lightbox.js, fix of Alt+F4 handling;
* `plaintext.value = "text";` fix of extra line;
* JS error -> sciter::value, conversion fix;
* `<plaintext>` support of `editor.execCommand("edit:insert-html",...);`;
* [osx] OpenGL multiple Sciter windows fix;

### New:

* [gsciter] + demo of sys-menu-bar behavior; 
* [JS] + `Element.box(...) : Rect`, same as `Element.state.box(...)` but returns *Graphics.Rect*;
* `Window.this.state = Window.WINDOW_SHOWN_NA` - show window without activation;
* [API] event_handler, HANDLE_STYLE_CHANGE callback;
* [JSX] support of `<$...>` and `<_...>` as component markers;
* + `selectEl.select.optionByValue(val): Element`
* [JS] + `element.once("event"[,selector"], handler)` to subscribe and perform the event only once;
* [JS] + `Element.state.animationType:string` - reports current type of animation performed on element ("scroll", "transition", etc.);
* [JS] + event *scrollStepPlus* & Co. - click on scrollbar parts;
* [JS] + event *currentStateChange* - `:current` state change (select,menu);

## 5.0.2.17

### New

* `componentDidMount([byCSS:bool])` - _byCSS_ parameter to distinguish reason of componentDidMount call;
* `sciter::video_destination::render_external_frame()` new method for video rendering from user's supplied buffer.
* behavior `video_generated_stream_direct` demo implementation.
* `<terminal>`/`behavior:terminal` updates, `terminal.read(...)` method + documentation. 

### Fixes:

* `<input|number>` to generate event _changing_.
* [gtk] CURL HTTP client is disabled in favour of internal HTTP client;
* `<canvas>` fix AV on create_image_buffer_graphics returning nullptr;
* internal http client, fix of post json;
* Win11, fix of "maximize hover";
* `transaction.deleteRange()` fix;
* `sys.fs.sync.rename(src,dst)` fix;
* fix of https://sciter.com/forums/topic/access-violation-while-trying-to-insert-a-new-tag-in-a-plaintext-component/
* [a11y] fix of `<span>` (inline elements) handling in NVDA. 
* [Windows XP] compatibility fixes;

## 5.0.2.16

### New:

* `element.lang` property;
* [gtk] fallback OpenGL to OpenGLES;
* `Element.replaceChildren(...)` method;
* [css] support of `pointer-events:auto | none`;

### Fixes:

* echarts compatibility fixes, part I.
* Fix `<input|date>.value = "iso string"`.
* [dom] details/summary fix.
* [gtk] Fix of "100% CPU" issue;
* `<input|date />` fix - `input.value === undefined`, if it was not set by user.
* [virtual-list] virtual `<table>` scrolling fix.
* [scapp] run.js, fix of encoding. 
* context menu disabled items fix.
* `<input|number>` caret appearance fix.
* [Windows] flickering in window-frame=extended fix.
* `element.richtext.update(transaction)` fix - reports errors instead of AV.

## 5.0.2.15

### New:

* + `document.defaultView` property, alias of `globalThis`;
* `Window.this.animationsEnabled = true | false;` to enable / disable animations;
* + `Element.ownerElement` property and /sdk.js/samples.reactor/portal/ sample; 

### Fixes:

* [Win11] fix of "HTMAXBUTTON issue"
* [win] Fix of animation on two windows: https://sciter.com/forums/topic/multiple-windows-simultaneous-rendering/;
* LeafletJS compatibility fix;
* Fix of `console.log("...unicode chars ...");`



## 5.0.2.14

### New:

* `Asset` namespace helpers:
  * `Asset.instanceOf(object,assetClassName)`
  * `Asset.typeOf(object)`

### Fixes:

* [printing] Table rendering fix;
* [QuickJS], fix of error reporting when error happens in module initialization code;
* `<select editable>`, fix of `:empty` state calculation;
* fix of click on popup of button handling;
* border-radius rendering fix, see:   https://sciter.com/forums/topic/box-shadow-border-radius-problem/

## 5.0.2.13

### New:

* [win] `SciterSetOption(NULL,SCITER_EXTENDED_TOUCHPAD_SUPPORT,FALSE)` to disable extended touchpad and touch support by DirectManipulation

### Fixes:

* Skia backends: support of CSS::`image-rendering` property;
* [Storage] fix of possible AV in `index.set(...)`;
* [JSX] erroneous @styleset value is reported as an error rather than warning;
* regression fixes: ChartJS compatibility;
* [DOM] fix of possible memory leak;

## 5.0.2.12

### New:

* support of `Window.this.modal( new Window(...));` - allows to show arbitrary windows as modals.
* better implementation of `getComputedStyle(el)`;
* samples.sciter/printing sample;

### Fixes:

* [richtext] fix of column removal in tables;
* [richtext] fix of undo stack clearance on richtext.load();
* [win] fix of FreeLibrary(hSciterLib);
* frameset panel resizing fix;

## 5.0.2.11

### Fixes:

* [richtext] fix of insert column after last column;
* [linux/gtk] fix of modal dialogs in scapp; 
* [quark] use of internal svg2png convertor, imagemagic produces bad results at least on Mac.

## 5.0.2.10

### Fixes:

* Fix of `input|text:not(:focus) { text-overflow:ellipsis; }` handling;
* [plaintext] `el.state.focus = true` fix;
* [frameset] fix of layout issue after popup appearance;

## 5.0.2.9

### New:

* `Element.box("selection","window")` - to get selection area location.
* `window.addHotkeyHandler(combination,function)`, `window.removeHotkeyHandler(id)` - works on Windows only so far. On other platforms returns _false_.
*  `Element.selection.$("selector")` and `element.selection.$$("selector")` - reports element[s] covered by the selection.

### Fixes:

* [richtext] fix of caret navigation.
* [richtext] better caret position outside of tables;
* [richtext] UP/DOWN caret navigation fixes;
* [richtext] fix of table editing operations (insert row/column, merge cells, etc);
* [richtext] draw selected image when it is a block;
* [richtext] insert paragraph on block insertion point;
* [richtext] `<br>` handling fixes;
* regression fix of `graphics.fillStyle = "..."` parsing.
* [css] regression fix of `flow:vertical-wrap;` handling.
* [windows] PrintScreen key code fix.
* compress(lzf), fix of short sequences handling. 
* [DOM] fix of event click handling on popups.
* [DOM] fix of TAB handling by `<select|dropdown>`.
* [reactor] fix of `<select|dropdown>` reconciliation.
* `sciter.home()` fix of '/' appearance.
* `<frameset>` fix of cursor appearance.



## 5.0.2.8-bis

### Fixes:

* * [richtext] fix of caret navigation.
* [DOM] regression fix of `graphics.fillStyle = "..."` parsing.
* [CSS] regression fix of `flow:vertical-wrap;` handling.

## 5.0.2.8

### New:

* [demo] sdk.js/samples.sciter/@inputs/builtin-inputs.htm - list of inputs supported by Sciter out of the box;
* [css] `flow:horizontal-wrap` - wraps row if sum of flexes reaches 1* (grid system support);
* NodeJS compatibility, built-in modules `path` and `process` (partial);  
* [DOM] `Element.replaceWith(otherelement)` browser API support;
* [DOM] `Document.createRange()` API.
* [DOM+] `Node.commonParent(nodeA,nodeB) : element` - to find out common parent element of two nodes;
* [DOM+] `Tokenizer.elementType(tagName) : [defaultElementType,defaultContentModel,parsingModel]` default HTML element classification utility;
* [DOM+] `DateTimeFormat.monthView()` helper function to generate month view like in `<input|calendar>`, see: sdk.js/samples.sciter/i18n/year-view.htm
* [DOM+] `Range.nodes()` - list of nodes covered by the range.
* `<button|menu>` generates event `requestpopup` to create menus dynamically.
* [reactor|signals] + `signal.send(value)` - unconditional fire of the signal, [rationale](https://github.com/preactjs/signals/discussions/321);
* [VueJS] basic support, see sdk.js/samples/vue
  * [DOM] `SVGElement` class marker (compatibility with VueJS);

### Fixes:

* [css/master] Various fixes in default theme;
* [css] `%` calculation uses round to nearest int rather than roundf(). This fixes jumpy behavior when things like `width:25%` are used;
* [CSSOM] fix of `element.style.variable("...")` -> deep value resolution is used (vars based on vars, etc)
* `transactionCtx.insertHTML()` returns _bookmark_ rather than list of nodes. NOTE: this can be a breaking change;
* fix of `keydown` `+/=` event generation.
* [richtext/plaintext] spell check in readonly mode is disabled by default;


## 5.0.2.7

### Fixes:

* regression fixes in `<input type="text">` handling;
* external scroll bar "scroll" event generation fix;
* [storage] fix of Index handling by `commit()`;
* [storage] fix of `Date` objects persistence handling;

### New:

[reactor] + `element.componentDidUpdate()` lifecycle method, called after `render()` caused by `componentUpdate()`


## 5.0.2.6

### New:

* updates in Sciter module resolution algorithm. + `sciter.setModuleUrlResolver(resolver)`, see: https://sciter.com/forums/topic/on-module-url-resolution-npm-style/ discussion, and sample samples.sciter/js-module-resolver/ 
* `zip.mountTo(url)` support - downloadable packages, see: samples.sciter/zip/;  
* [JS] Support of `__FUNC__` (current function name) and `__LINE__` (current line) constants.
* [css] + `border-shape: path(...)` support, see: sdk.js/samples.css/css++inline-vector-images/border-shape-path.htm
* `Event.char` propery is writeable now, so in event ^keypress it is possible to filter/transform user input as `if(evt.char = "X") evt.char = "x";` 
* [behavior:edit] `element.edit.isStandalone` mode - consumes non-handled up/down/left/right keys.
* + `Request.fulfill(...)`, `Request.reject(...)` used in frame|htmlarea.onrequest(rq) handlers to e.g. fulfill requests from local DB for example. 


### Fixes:

* attempt to fix "garbage" background rendering in SVGs. Let me know if you still see the problem.
* fix of `flow:horizontal` calculation inside `display:inline-block`;
* fix of `Window.this.box(...,false)` (logic coordinates) calculations on high-dpi monitors on secondary windows.
* [css,layout] `flow:horizontal`, `height:auto` children are treated as `height:*`;
* [css,layout] `flow:horizontal[-wrap]` + `box-sizing: border-box` + `vertical-align` fix. 
* fix of https://sciter.com/forums/topic/flex-layout-issues/ and similar;
* fix of window position when initial x,y was defined in constructor; 
* [JS] Number formatting fix;
* [JS, persistence] fix of `db.commit()` operations related to indexes;
* [JS, persistence] fix of delete obj["prop"]
* [reactor] `<table>` content update fix;


## 5.0.2.5

### Fixes:

* [Windows] touchpad and touchscreen gesture suppot is again implemented by using DirectManipulation. Reason: DM supports various touchpad models better than I can afford by manual parsing of WM_INPUT.
* [scrollables] close owned popups before scrolling;
* fix of doubled _onclick_ event handler call;
* [CSS] Tweaks of `list-style-type: tree-line` (Sciter specific value);
* [plaintext] `element.plaintext[idx]` and `element.plaintext.someProp` inconsistency fix. 
* [core] Fixes in `Color` conversions;
* [JS] Fixes in event handlers defined inline, like `<el onchange={...}>`
* [widgets/color-selector] alpha channel and custom views support;
* [JS] fix of `let a = 1%10;` parsing.


## 5.0.2.4

### New:

* `storage.registerClass(cls)` - persistable objects with classes. This allows the following:
```JavaScript
  class Note {...}
  ...
  storage.registerClass(Note);
  ...
  const firstNote = storage.root.notes[0];  
  firstNote instanceof Note; // >> true 
  ```
* [quark] OSX, icons generation. Thanks to [mice2100](https://sciter.com/forums/users/mice2100/).
* [css] `{ attr(filename):attr(key) }` - attributes aliasing. Example: `filename` attribute is an alias of `this.attributes["key"]`
* [widgets] new widget: sdk.js/widgets/virtual-tree  - virtual tree.
* [widgets] new widget: widgets/color-selector - defines `<widget|color>` and `<input|color>`
* [js] + `Intl.Collator` implementation (partial) - lexical string comparison support.
* [dom] + `Element.flushPaint()` - force paint of element's window.
* [dom] + `Element.animate()` is split into `Element.replaceContent(vdom)` and `Element.morphContent(step)`, see documentation. **Warning**: the `Element.animate()` is obsolete now - it will be replaced in upcoming builds by [WebAPI compatible version](https://developer.mozilla.org/en-US/docs/Web/API/Element/animate), replace its use by the functions above.
* [richtext,plaintext] +  transactCtx.lastPosition -> [node,offset] reports last used caret position.
* [js] `Length.morph(from,to,ratio)` and `Color.morph(from,to,ratio)` functions, used in custom transition/animations.

### Fixes:

* [richtext,plaintext] transactional update fixes;
* [css] fix of mem resource consumption in gradients;
* [js, storage] binary db compatibility with Sciter.TIS (I am porting https://notes.sciter.com)
* [css,js] regression fix of `el.style.variables({...})`;
* [css] fix of .slider {min-height:...} in customized scroll-indicators, see: https://sciter.com/forums/topic/min-height-in-scroll-indicator/

## 5.0.2.3

### New:

* + `gesture-XXX` events support (touchpad and touchscreen), for the list of supported see [Gesture events](docs/md/Event.md#Gestures). 
  Implementation status:
  * Windows - all gestures supported on touchpad and touchscreen. Gesture recognition implemented from scratch by handling raw WM_INPUT and WM_TOUCH.
  * MacOS - uses OS gesture recognizers.
  * Linux - only gesture-pan so far. Others will added on demand.
* new `<icon|name />` element and built-in set of vector icons, see usciter.exe/icons button; 
* + [vipe] + subgroups;
* + sdk.js/samples.css/css-fontawesome;

### Fixes:

* [css,reactor] @styleset={...} applicability fix;
* [virtual-list] regression fix of scroll positioning;
* [css] fix of `@keyframes` parsing: `0%,90% {....}`
* [css] fix of `margin:xx%` handling;
* [css] fix of `calc(-XXpx)` handling;
* [css] fix of `border-radius` rendering with [semi-]transparent colors;
* [css] fix of `var()` handling inside `calc()`; 
* Fix of `flow:horizontal-wrap` and `%` units;

## 5.0.2.2

### Fixes:

* [osx] scapp fixes.
* [CSS] fix of `%` units handling in children of flex containers.
* popup componentWillUnmount() fix, see: https://sciter.com/forums/topic/componentwillumount-doesnt-get-called-for-popup-component/
* Missed methods: sys.fs.unlinkSync(), sys.fs.chmodSync(), sys.fs.copyfileSync().

## 5.0.2.1

### New:

* [Linux] Better support of touch screen and touch pad scrolling gestures on Linux/GTK; "overscroll" indication is back;

### Fixes:

* fix of `<popup>` dynamic update.  
* fix of touch[pad] scroll animation when x and y axis are both scrollable.
* scapp/run.js mode - fix of https://sciter.com/forums/topic/run-js-cant-find-htm-to-create-window-after-packing/ issue.
* [reactor] fix of "flattened kids" issue. 
* `<input|text>` scroll position fix : https://sciter.com/forums/topic/input-cursor/ 

## 5.0.2.0

### New:

* [scapp.exe/Quark] - new [bootstrap execution mode](docs/md/scapp/README.md);
* Better support of touch screen and touch pad scrolling gestures on Windows and MacOS; "overscroll" indication is back;
* [JS] support of `debugger;` statement.

### Fixes:

* `sys.fs.xxx` file functions accept either file URL or path. Previously - only path.
* Fix of sdk.js/samples.sciter/popup/editbox+popup.htm case.
* Fix of https://sciter.com/forums/topic/not-support-latest-win11-2022h2/ ;
* [css] rounded multicolor borders fix;

## 5.0.1.9

### New:

* + `Graphics.Rect`, `Graphics.Point`, `Graphics.Size` helper classes - 2D geometry support. 
* + `Graphics.Path.isPointOnStroke(distance:number, point)` - method to determine if the point is close to the path.  
* css4 color parsing flavour: `hsl(0deg 100% 50% / 0.5);` - hsl/hsv with alpha
* [API, C++] `sciter::value::get(int64_t)` implementation to pass 64-bit integers to JS. 
* [HTML] Support of x,y attributes in children of `flow:stack` containers;
* widgets/vipe - initial implementation of Visual Programming Environment, not complete.  

### Fixes:

* [css] fix of multy color borders with border-radius.  
* fix of AV on "naked" Windows 7 (without platform update).
* fix of `behavior:windowed;`.
* fix of first button click event generation.
* [css] `flow:horizontal-wrap`, fix of max-content calculation.
* `event mousedragrequest` generation fix.
* [QuickJS] fix of error reporting on erroneous module loading.
* Regression fix of window.modal { html: `<NewWindow />` }, see: https://sciter.com/forums/topic/window-this-modal-failed-to-show-jsx-window-content/
* GDI+ backend fix (Windows XP compatibility).
* `element.popup(..., {x,y})`  positioning fix.
* `<select|editable>` context menu handling while popup list is open.
* Fix of `animate` + `::after` combination: https://sciter.com/forums/topic/element-not-rendered-when-using-css-animation-combined-with-pseudo-element/
* Fix of samples.css/scrollbars-n-scrolling/scrollbar-bound.htm
* [usciter] dropzone file acceptance fix.


## 5.0.1.8

### Fixes:

* fix of `Zip.openData();`;
* fix of `element.options` to return `ElementList`;
* [MacOS] fix of `window-frame="transparent"` rendering;
* Fix of `:active` applied on MOUSE_ENTER/LEAVE from touchpad.
* `<plaintext>` loading speedup. 
* `storage.close();` fix, no need for explicit `storage.commit()`;
* [inspector] `eval`, fix of "r" being undefined;
* `env.homeURL()` fix;
* [Win11] fix of popup windows rendering;
* [macos] `Window.this.close()` fix for the case when window is not yet shown;
* [macos] http/gzip handling fix;
* [css] `hsl(90deg 100% 42%)` parsing fix;
* [css] `{ content: attr(name); }` dynamic attribute change fix;
* fix of AV in style-set/appearance:none combination: https://sciter.com/forums/topic/custom-style-causes-crash/ (second attempt);
* Documentation fixes.

### New:

* [css] + `baseline-shift: <length> | <percent>` property (reduced support to only those);



## 5.0.1.7

### Fixes:

* JQuery compatibility fixes. JQuery should work as it is.
* Audio memory leak fix.
* Hang up fix, see: https://sciter.com/forums/topic/simple-html-to-crash-usciter-or-scapp/
* `file.readSync()` return value fix.

### New:

* Win11: `window-corners = "default" | "not-round" | "round" | "round-small"` attribute on root HTML of the window.

## 5.0.1.6

### New:

* [Windows] Support of Acrylic/Mica backdrops on Windows 11 using official API. See: /samples.sciter/window/blurbehind-modes.htm

### Fixes:

* Fix of svg images rendering in "render element on image"  ( `new Graphics.Image(w,h,element)` )
* Fix of https://sciter.com/forums/topic/multiple-css-animation-issue/

## 5.0.1.5

### New:

* new attribute on root &lt;html&gt;: `window-corners="default|not-round|round|round-small"` - works on Windows 11 so far to suppress/enable window round corners. 

### Fixes:

* Fix of `event input` generation;
* [css] `layer:force` fix;
* Fix of opacity handling in `graphics.pushLayer(x,y,w,h,opacity)`

## 5.0.1.4

Fixes:

* [sciter::om, C++] property setters can throw custom exceptions now.
* [windows] tray icon generation fix.
* Fix of inheritable nature of `state.disabled`. If a container is disabled then all its subtree is also disabled. 
* [CSS] Fix of handling of URLs that contain non-ascii characters, like `background: url(привет.png);`
* [DOM] `componentDidMount()` gets posted by default.

## 5.0.1.3

Stabilization build.

* Various fixes of DOM updates rendering.
* Inspector fixes.

## 5.0.1.2

### Fixes:

* Fix of `Graphics.pushLayer("background-area")` , see: https://sciter.com/forums/topic/paintbackground-coordinates/
* [inspector] Node selection issue fix: https://sciter.com/forums/topic/inspector-dom-check-failure/

## 5.0.1.1

### New:

* "Cancellable Fetch" feature by [Request](docs/md/Fetch.md).abort() method. See: samples/fetch(AJAX)/test-fetch-progress.htm sample. 
* `Graphics.Image.load()` method is also cancellable.

### Fixes:

* Regression fixes of state change handling.

## 5.0.1.0

This build is mostly about parsing, DOM construction and rendering times optimizations. In some cases it reduces CPU load by 30%. 

### New:

* Windows: Windows XP support is back. But note that public binaries are not XP compatible. You'll need access to sources to make XP aware bimaries.
* console.log() & Co. refactoring to support printf alike formatting: `console.log("%x", num);`
* Added internal HTTP[S] client. To enable it use `SciterSetOption(NULL,SCITER_USE_INTERNAL_HTTP_CLIENT,TRUE);`
* `window.modal {html: <VNode/> }` - vnode window definition, similar to `new Window({html: <VNode/> });`
* "component signals", see: https://sciter.com/forums/topic/reactor-signal-failed-to-work-sometime-in-sciter-js-5-0-9/#post-79632
* Windows: `@media ui-accented-window-decoration {...}` to support Windows settings "accented colors in caption bar".
* `<terminal>` - ANSI virtual terminal component. Used for logging and with compination of `process.spawn()`
* `input|masked`, more API methods.
* [reactor] `CSS.set'...'` CSS-in-JS declarations. See: samples.reactor/styling/

### Fixes:

* [URLs] non-ascii handling fixes;
* `loadLibrary("abs path")` fix to support absolute paths.
* [CSS] Fix of high-CPU when `calc(...)` is used.
* [JS] Regression fix of `this` handling in event handlers.
* [high-dpi] Fix of `gfx.pushLayer("background-area");` scaling. 
* [Graphics] fixes of paths transformation handling  ctx.beginPath() -> ctx->rotate(...), etc;
* `<button|menu>` fix of tooltip handling;
* fix of https://sciter.com/forums/topic/takeoff-element-with-transparent-color-doesnt-get-parent-window-width-on-resize/
* fix of https://sciter.com/forums/topic/if-image-then-clipboard-has-not-work/

## 5.0.0.9

### Fixes:

* Fix of 'this' reference in event handlers.
* IM graphics: fix of initial transformation matrix settings. 
* Fix of nesting scrollbars handling: https://sciter.com/forums/topic/nesting-of-scrolls/
* Linux: fix of window initialization, https://sciter.com/forums/topic/dual-title-bar-on-linux-when-window-not-maximized/

## 5.0.0.8

### New:

* `console.log("n%d",42)` -> `n42` - C printf style of formatting in console.

### Fixes:

* Skia backends: `<canvas>` uses GPU texture rather than `SkPicture` as it used to be. This fixes https://sciter.com/forums/topic/memory-leak-at-skia-version/
* Fix of 'this' reference in 'mouseleave' events.
* Fix of element.state.expanded|collapsed = ...; handling.

Note: MacOS version uses OpenGL backend by default now (instead of Metal).

## 5.0.0.7

### New:

* Reactor: New feature, Window content can be generated solely by JSX. See: sdk.js/samples.reactor/window/trayicon-test.htm


### Fixes:

* Fix of regression introduced in 5.0.0.6 - unicode urls.
* Fix of AV in style-set/appearance:none combination: https://sciter.com/forums/topic/custom-style-causes-crash/
* DOM population optimization regarding CONTENT_CHANGED event generation - was too heavy on classic DOM population using element.appendChild() & co.
* Reactor/signals: `toString()` fix so signal can be used in JSX without explicit .value : `<div>UI observer of { sig }</div>;`
* Graphics: IM graphics setup fix, see: https://sciter.com/forums/topic/stroke-with-css-style-color/
* usciter.exe, fix of "no buttons rendered"
* Webview updates - sync with its public repository. 
* Win: `WM_NCHITTEST` -> `HTMAXBUTTON & Co` - Win11 aero snap compatibility.
* Fix of `<canvas>` graphics persistence: https://sciter.com/forums/topic/canvas-brush/

## 5.0.0.6

### New:

* [Reactor/Signals](docs/md/reactor/signals.md) - Sciter's native implementation of PReactJS/Signals.
* Support of animated WebP.
* URL aliases feature, root document may contain alias definitions like:
  ```HTML
  <meta alias="lib:" href="./scripts/lib/">
  <meta alias="root:" href="./root/" />
  ```
  and those locations can be addressed in the res of CSS and JS as 
  ```JavaScript
  import {Foo} from "lib:foo.js"; // will load {docurl}/scripts/lib/foo.js  
  ```
* HTML/CSS/JS: handling of urls that contain unicode like: `src: url(字体.TTF)`;  
* `window.postEvent(event)` method - same as window.dispatchEvent(event) but asynchronous;
* Sample: tray-icon update - this uses standalone popup window with menu to fix menu appearance on collapsed main window; 
* `sys.fs.sync.XXX` and `sys.fs.XXXSync` aliases of sys.fs.$XXX functions (that are obsolete now);

### Fixes:

* CSS: fix of horizontal-only scroll;
* CSS: _clearfix_ fix;
* UI: fix of scroll by scrollbar part click;
* XDOM: `event.isOnIcon` fix;
* lottie mem-leak fix;
* Windows: fix of `Event.code` handling on non-US keyboards. 
* Mac: Metal backend is enabled only on Big Sur and higher, seems like not reliable on below OSes.

## 5.0.0.5

### New:

* `<canvas>` combatibilty with browsers and H/W acceleration implementation;
* ChartJS demo at samples.charts/basic and samples.charts/component (Charts as Reactor Component);

### Fixes:

* fix of AV in focus handling;
* fix of https://sciter.com/forums/topic/sciterimage-access-violation/
* mouse wheel animation adaptive to scrollable size and other adjustments;
* fix of tab-focus handling on inputs;
* [JS DOM] mem-leak when document.createDocumentFragment() is used;
* [win] file:/// and file://localhost/ schema fix.
* stroke-dasharray in vector images : https://sciter.com/forums/topic/stroke-dasharray-not-working/
* [reactor] fix of @readonly handling, see: https://sciter.com/forums/topic/input-readonly-does-not-have-any-affect-when-state-disabled-specified-explicitly/
* fix of setting focus after menu|popup closure;
* [gtk] fix of flags in keydown/keyup;
* [css] position:absolute; left:0;right:0; fix, see: https://sciter.com/forums/topic/child-element-size-incorrect/
* [packfolder] project minification, removing non-used code;

## 5.0.0.4

### Fixes:

* Fix of AV in focus handling (introduced in 5.0.0.3).
* Fix of potential AV in `sciter::image::load()`. See [bug report](https://sciter.com/forums/topic/sciterimage-access-violation/).


## 5.0.0.3

### New:

* + sample sdk.js/samples.sciter/toast-notification
* `date.toLocaleDateString({format:...})` option for flexible date/time formatting.
* [scrolling] touch aware scroll, "overscroll" is back.
* + `Event.relatedTarget`, see: https://developer.mozilla.org/en-US/docs/Web/API/FocusEvent/relatedTarget
* [windows] trayicon reset implementation on Explorer restart.

### Fixes:

* virtual-list refactoring, rendering optimization.
* @window-minimizable and @window-maximizable fix.
* [persistence] fix, see: https://sciter.com/forums/topic/storage-does-not-store-value-properly/
* Fix of response.text() when server reports erroneous encoding.
* `<input|time>` rendering fix.
* Fix of `element.prepend()`.
* [mac] fix of secondary windows creation: https://sciter.com/forums/topic/samples-sciter-msgboxdialog-dialog-test-htm-crash-report/
* [macos] fix of popup rendering: https://sciter.com/forums/topic/popup-issue-2/
* Fix of https://sciter.com/forums/topic/missed-message-delegate-in-sciterwindow
* fix of dynamic update: https://sciter.com/forums/topic/sciter-buttons-and-hr-tags-broken-after-sciter-js-upgrade/
* [Mac] transparent popup fix.
* `event_handler::HANDLE_ATTRIBUTE_CHANGE` fix.
* [sciter runtime] `debug.setUnhandledExceptionHandler()` misspelling fix.
* `keyState("NumLock")` fix (Win).


## 5.0.0.2

### New:

+ support of events "mouseover" and "mouseout"
+ Zip reader. See: sdk.js/docs/md/Zip.md and sample in sdk.js/samples.sciter/zip/

### Fixes:

* [virtual list] incremental fetch and scroll optimization.
* [JS] `Request.method` to accept arbitrary HTTP verbs.
* [CSS] One more z-index fix.
* [CSS] `border-spacing: -1px;` fix.
* [Mac OS] fix of initial rendering.
* [inspector] minor tweaks;
* `Selection.containsNode(...,partial)`

## 5.0.0.1

### New:

Skia upgraded to most recent version (milestone 103), this leads to:

* MacOS: support of Metal GPU rendering (default), with fallback to OpenGL;
* Linux: support of Vulkan GPU rendering (default), with fallback to OpenGL;
* Windows: (xxxSkia binaries): support of DX12 and Vulkan GPU rendering (default), with fallback to OpenGL;
* `Graphics.createTile(image):Brush` and `Graphics.createSolid(color):Brush` implementation;
* Tooltip samples in samples.sciter/tooltips++/

### Fixes:

* `event "contentchange"` optimization. The event is not delivered as normal event. Only as callback element.oncontentchange ;
* samples/leaflet fix;
* element.addEventListener() fix;
* [svg] `<use>` handling fix;
* `<progress>` fix : https://sciter.com/forums/topic/progress-incorrect-percent-draw/ ;
* [CSS] fix of percentage dimensions calculation;
* [linux] fix of https://sciter.com/forums/topic/shift-key-number-key-doesnt-output-the-symbol-for-the-number-key/
* `element.popupAt()` fix - removed restriction to be on the same monitor. See: https://sciter.com/forums/topic/incorrect-tray-popup-menu-position-if-main-form-is-on-2nd-screen/
* [reactor] fix of `selectDropdown.componentUpdate()`;
* [win] `sys.fs.splitpath()` fix.

## 4.4.9.3

### Fixes:

* canvas, fix of "secondary draw op clears the canvas".
* [reactor] update optimization.
* [linux/gtk] fix of modal dialog positioning.

### New:

* `element.scrollBy()`
* [JSX] support of HTML entities: `body.append(<p>&lt;</p>);`
* [Sciter.Lite] `SC_SET_CURSOR` - callback to set cursor on host side.


## 4.4.9.2

### Fixes:

* fix of high CPU consumption at idle;

### New:

* widgets/prop-list - property sheet/list;
* samples.sciter/docking - docking system;

## 4.4.9.1

### Fixes:

*  <frame|pager> `loadHtml` method fix;
*  SDK headers - fix of some warnings;
*  `element.state.XXX = YYY;` fix of state updates;
*  `select.value = ...;` fixes;

## 4.4.9.0

### New:

* [win] SDK build scripts and projects are using VS2019 now.
* [sciter-webview](webview/README.md) - web view widget, uses installed system browser to render web pages. See sdk/webview/demo/webview.html
* [linux/gtk] arm64 build;
* [CSS,scrollbar] `@set my-scrollbar { .back {} }` - _back_ component defines whole area occupied by the scrollbar;
* `SciterVersion(0...4):uint` - access to Sciter version vector components: `SciterVersion(0) -> 4`, `SciterVersion(1) -> 4` ... Note: ABI of _SciterVersion_ function has not changed.
* [sample] samples.sciter/docking - implementation sketch of dockable widgets;

### Fixes:
* [reactor] fix of exception reporting.
* [gtk] mouse wheel direction fix.
* [css] custom scrollbars - margins accounting.
* script debugger, reducing memory consumption.
* [macos] keyup/down events for shift,capslock,etc. buttons.
* `<reactor>` fix, see: https://sciter.com/forums/topic/bug-problem-with-russian-characters-in-reactor/

## 4.4.8.38

### New:

* [CSS] `flow-columns` and `flow-rows` properties to define grid "lines" positioning. See [CSS layout](docs/md/css/css-layout.md).
* [http] "PATCH" HTTP verb support.

### Fixes:

* [Windows] `WM_GESTURE` handling on Windows. See: /samples.sciter/touch/ .
* [CSS] `flow:row()` fixes.
* [DOM] `form.value` fixes in Reactor environments. 
* [Windows] fix of shadow rendering when the window changes state.

## 4.4.8.37

### New:

* **sciter-webview** external component that wraps system browser. Use it when you need to present to the user web site as if it was loaded in browser. Windows, MacOS and Linux. By [Sora Yang](https://gitlab.com/ArcRain). 
  1. sciter-webview project and documentation is here: https://gitlab.com/sciter-engine/sciter-webview
  2. sciter-webview supports static linkage so you may compile it in inside your application without the need of separate sciter-webview.dll(.dylib|.so)
  3. sciter-webview project is a Git sub-module, use `git submodule update --init --recursive` command to update it.
  4. sciter-webview/build/ folder contains projects to build it.
 
### Fixes:

* `clearTimeout/Interval` fix;
* [CSS] fix of '+'/'~' selectors handling;
* [JS/Storage] fix of persistence handling;
* `form.value` fix: https://sciter.com/forums/topic/a-undfine-behaviornumber-in-the-form-in-the-component-will-be-object/

## 4.4.8.36

### New:

* `behavior: name library(dllname)`; - external (dll based) behaviors. Behaviors can live in separate DLLs now. This enables loadable native behaviors (e.g. for scapp);
* samples.sciter/docking - Phase I implementation of dockable panels in Sciter;
* `loadScript(url)` - script loader, equivalent of `<script src="url" />`;
* `loadScriptModule(url)` - script module loader, equivalent of `<script|module src="url" />`;
* `element.unwrapElement()` - removes element but keeps its content in the DOM;
* `element.wrapNodes(...)`  - injects new element in the middle of DOM tree; 
* `element.box(,,refElement,)` - coordinates relative to arbitrary _refElement_;

### Fixes:

* [Win] Fix of "exit fullscreen"  https://sciter.com/forums/topic/exit-fullscreen/ 
* `clearTimeout(undefined)` and `clearInterval(undefined)` fixes
* [css] `z-index:-1` fix - it is drawn on top of background but below content;
* [css] `:after` and `:before` are treated as `::after` and `::before`;

## 4.4.8.35

### Fixes:

* Fix of https://sciter.com/forums/topic/transition-animation-stuck/;
* `<button type="menu">` fix.
* [CSS] fix of cubic-bezier() function handling;
* fix of memleak in document context in JS;
* xgl/skia mem leak fixes;
* `behavior:virtual-list`, fix of memory leak;
* `input|calendar`, fix of days navigation;
* fix of `plaintext.value = "string longer than 32000"`;

## 4.4.8.34

### Fixes:

* [performance] 0x7FFF cap on length of paragraph text. This means that paragraphs cannot have more characters than 32767. HTML parser breaks text on multiple paragraphs if input exceeds that number. 
* [windows,osx] fix of compound emoji handling in editors.
* Fix of https://sciter.com/forums/topic/sys-fs-splitpath-doesnt-work-as-expected/ ;
* [virtual-list] mousewheel adjustments;
* fix of https://sciter.com/forums/topic/selectable-div-context-menu-bug/;
* optional delaying setting focus() to after measure (performance);
* fix of AV on broken Windows machines that cannot create layered popup Direct2D windows;
* removal of redundant debugging printout;
* [Windows] `Event.keyState()` fix;
* `NUMPAD ENTER` fix;

### New features:

* [API, pre 5.x.x.x], purpose of these two functions is to support non-C/C++ integrations.
  * `SciterExec()` - application methods/commands;
  * `SciterWindowExec()`- window methods/commands;
* [css,JS] "multi-entry aspects" - aspect functions that have `aspect.detached()` method are detachable. see: samples/css++/aspect.htm and sdk.js/samples.css/css++/aspect.htm


## 4.4.8.33

### Fixes:

* `import "module"` -> `import "module.js"` substitution fix;
* Fix of https://sciter.com/forums/topic/style-set-specificity-breaking-change/ ;
* [reactor] `<div state-html={...} />` update optimization;
* [CSS] `attr(window-frame): "...";` fix;

### New features:

* + `[globalThis.]evalModule("module text");` - like `eval("text")` but "module text" is parsed by module rules;
* + [virtual-list] `scrollBy(deltay)` method;

## 4.4.8.32

### Fixes:

* `<input|time no-seconds />` fix.
* fix of positioned double painting: https://sciter.com/forums/topic/problem-with-4-4-8-30/
* `parseValue()` support of BigInt's
* SDK sdk[.js]/include/value.h VALUE::T_CURRENCY is renamed to VALUE::T_BIG_INT - that allows to pass int64 from native code to JS as BigInt value.
* [windows] fix of 1px border around maximized window;
* [macos] navigation shortcuts (CMD+LEFT/RIGHT, OPTION+UP/DOWN etc.) 
* behavior:selection fix;
* Skia backend, fix of bitmap_graphics, text rendering.
* `flow:horizontal;` layout fix;
* `@media width > 600px {...}`; 

## 4.4.8.31

### New features:

* new sample samples.sciter/immediate-mode-painting/pie-chart.htm - circular progress indicator.
  Demonstrates use of units with Graphics;

### Fixes:

* [JS++]fix of angle literals parsing, like const s = 90deg;
* [MacOS] fix of `doubleclick` and `tripleclick` event generation;
* [MacOS] fix of AV in spellcheck functionality;
* [a11y] fix of aria-labeledby handling; 
* [CSS] fix of rules application ordering;
* `Sciter.parseValue()` fix of error generation on erroneous inputs;

## 4.4.8.30

### New features:

* JS extended by Length, Duration and Angle units. 

  ES2017 introduced numbers with units already, like BigInt:
  ```
  const maxSafeInteger = 9007199254740991n;
  ```
  This version adds more number units:
  - lengths: `100px`, `12pt`, `1em`, ...
  - durations: `20ms`, `2s`
  - angles: `90deg`, `0.5rad`, `1turn`, ...

* `sciter.parseValue(string): any`

  That's "JSON++" parser - parses the string using JSON extended by CSS syntax rules, this is valid JSON++ format:
  ```JS
    // Note: comments are supported in JSON++: 
    {
      date: 2020-10-11; // date literal
      width: 200px; // length literal;
      number: 42; // guess what?
      // Note: names may have '-' in them
      array-plain: [1,2,3,4]; // plain JS array
      array-list: 1 2 3 4, 5 6 7 8; // JS [[1,2,3,4],[5,6,7,8]]
      // name tokens are parsed to strings:
      foo: incredible; // JSON eq. "foo": "incredible"
    }
  ```

* `Event.platformKeyCode` - reports native key code like wParam in WM_KEYDOWN on Windows.
* `physicalDevicePixelRatio` - [MacOS] "retina" pixel ratio, on other platforms it is `1`. 

### Fixes:

* z-index handling fix.
* `<input|number>` layout fix.
* Regression fix of "preventing secondary style loading from the same url".
* `progresss.setAttribute()` fix;
* Fix of AV in frame deletion while loading.
* Fix of window alignment on multihome systems with different scale factors.


## 4.4.8.29

### New features:

* css selectors: `:last-of-type`, `:first-of-type`, `:only-of-type`
* [JS] implementation of 
* 
  * `console.assert(expr,fmt, ...)`
  * `console.assert(expr,{fields...})`
  
  Note that in Sciter `console.assert` throws error if _expr_ is falsy - in browsers console.assert() just prints stuff to console.

* + sdk.js/widgets/tabs/ sample - that `<tabs>` thing.
* Experimental support of system menus:
  ```HTML
     <menu role="window-menu">
       <li>File
           <menu>
              <li accesskey="^N">New</li>
              <li accesskey="^O">Open</li>
              <hr/>
              <li accesskey="Q">Quit</li>
           </menu>
       </li>
       ...
     </menu>
  ```
  On Windows this creates native menu bar in the window. On MacOS it populates application menu bar. On Linux - not ready yet.

  Note for window-frame != "standard" the menu is invisible but still makes sense as global hotkeys table.

  For the demo see [integration](https://github.com/c-smile/sciter-js-sdk/blob/main/demos/integration/res/default.htm) project in SDK.

* include/sciter-x-key-codes.h - list of key codes that are coming to KEY_DOWN/KEY_UP events. 

  NOTE: that can be a breaking change if you use platform dependent key codes (like `VK_ENTER` on Windows) in your code.


### Fixes:

* Fix of `KeyboardEvent.code` values to generaly match [W3C specification](https://www.w3.org/TR/uievents-code/);
* Fix of functions taking varargs, like `@env.exec(...)`, `printf(fmt,...)` and others;
* Fix of mouse reactivity in regard `:hover` styles. 
* Fix of stack overflow in style-set: "..." applying roots with appearance:none.
* Fix of position:relative inside position:absolute, see: https://sciter.com/forums/topic/css-position-issue/

## 4.4.8.28

### New features:

* + support of CSS selectors `:only-of-type`, `first-of-type` and `last-of-type`;

### Fixes:

* regression fixes of `@env.exec()` and `element.classList.add/remove()`;
* `:hover` style reactivity on mouse moves;

## 4.4.8.27-bis

Maintainance build: use of latest libjpeg, libwebp, libuv. This closes 32 CVEs found in those libraries.

## 4.4.8.27

### New features:

* Virtual desktops/spaces support:
  - Window _event spacechange_ is sent to the window when space / virtual desktop changes/ Use `window.on("spacechange",handler)` to subscribe to that event.  
  - `window.isOnActiveSpace` property. _true_ if the window is on active space and _false_ otherwise. 
  - sample: /samples.sciter/window/virtual-spaces.htm
  
* [CSS] `attr(name): value;` attribute-property declaration. This allows to define default values of DOM attributes in CSS. Example: 
  ```CSS
  input|number { attr(min):0; attr(max):100; attr(step):1 }
  ```
* sdk.js/samples.sciter/unit-test - unit test framework, modelled after [JEST](https://jestjs.io/).   
  Initial implementation, to be extended and documented.

* [reactor/JSX] Support of inline style definitions `<div style={obj}>`. [see](https://sciter.com/forums/topic/reactor-inline-style-does-not-work/).

* [SDK/API] `HANDLE_ATTRIBUTE_CHANGE` event_handler callback: 
  ```C++
  virtual void event_handler::handle_attribute_change(HELEMENT he, ATTRIBUTE_CHANGE_PARAMS& params)
      {
        return on_attribute_change(he, params.name, params.value);
      }
  ```
  Useful in cases when Reactor manages elements with custom behaviors.

### Fixes:

* `componentWillUnmount()` is coming while `element.parentElement` is still valid.
* [macosx] frequent click events generation fix. 
* Fix of `:popup` style application, [see issue](https://sciter.com/forums/topic/fade-in-out-animation-on-popup-dialog/#post-76241).
* Fix of initial window position if it is defined in `SciterCreateWindow()`.
* Fix of scrollbar dpi issue.
* Sciter's animated scroll-indicator is back. 
* Preventing multiple loading of the same CSS file.
* [windows] mouse-enter/leave on popup menus fix.
* [CSS] Fix of `position:absolute` positioning with `z-index`. [see](https://sciter.com/forums/topic/css-z-index-issue/).
* Fix of arrays handling in `xcall("...",)`

## 4.4.8.26

### New features:

* `SciterSetVariable()` and `SciterGetVariable()` API implementation. `SciterSetVariable()` function allows to initialize variables in global JS context of documents.
* `sciter.decode(..., "utf-16le/be")` support.
* *window-mixin* integration demo - demonstrates [mixin](https://sciter.com/developers/embedding-principles/#mixin) Sciter integration.
* "Script injects" :
  ``` C++
       static void set_init_script(const char* utf8z_js) {
        SBOOL r = SciterSetOption(NULL, SCITER_SET_INIT_SCRIPT, UINT_PTR(utf8z_js));
        assert(r); (void)r;
      }
  ```  

### Fixes:

* `usciter.exe -o filename.htm` fix.
* `scapp.exe` style fixes.
* [inspector] fix of frame content inspection.
* [inspector] reporting initialization errors.

## 4.4.8.25

### New features:

* [DOM] `Element.elementFromPoint(x,y)` - find element by coordinates and so 
* [DOM] `Document.elementFromPoint(x,y)` is also available.

### Fixes:

* Fix of window creation sequence.
* Fix `form.value` to collect only named (having name attribute defined) fields (used to be id's too).
* Fix `form.value` to collect custom elements with `value` property defined.
* [integration] Disabling `SetErrorMode(SEM_FAILCRITICALERRORS | SEM_NOGPFAULTERRORBOX | SEM_NOOPENFILEERRORBOX);` in libuv that prevents dump collection on app level.
* [graphics] Fix of `graphics.pushLayer("...area...")` geometry calculation.
* [Audio] fix of AV after `stop()` call.

## 4.4.8.24

### Fixes:

* [css] flow:horizontal, percent calculation in children;
* fix of potential av in htmlarea drag operation;
* [macos] fix of AV on window closing;
* [macos] fix of operation on versions of MacOS prior 10.14;
* `<input|number>` rendering optimization;
* [rtl] `<input>`,`<plaintext>` CTRL|SHIFT directionality switch;
* Support of `sciter::value::make_error("text")` to rise errors from native code;
* `behavior:form` / `<form>` , element.value fix;
* scapp.exe, cmdline parameters handling fix;
* generalization of initial window pos and size;
* [JS/DOM] `styleElement.innerText = "...."` to update CSS rules in `<style>` elements;
* [hyperlink] fix of NUMPAD-ENTER handling;
* [JS/DOM] fix of Event.eventPhase / AT_TARGET;
* [JS/DOM] fix of erroneous `Window.this` value after `Window.this.load(...)` call.

### New features:

* enable multiple handlers on sizechange and visualstatechange events:
  ```JS
  document.on("sizechange",function(){});
  document.on("visualstatechange",function(){});
  ```

## 4.4.8.23

### Fixes:

* [macosx] IME regression fix;
* [css] `@media ... {}` handling fix inside style sets;
* [reactor] attribute `checked` and `state-checked` are interchangeable;
* [macosx] light/dark theme switch event, regression fix;

### New features:

* event "close" on window objects;

## 4.4.8.22

### New features:

* `behavior:video-coordinator` - orchestrates multiple `<video>` to be rendering in sync to minimize CPU load.
* Code linting ports by David Monbaron: /samples.sciter/code-linting
* [macOS] generation of event `mediachange` on Window.this when light/dark theme is applied. 

### Fixes:

* [rtl] fix of `input|checkbox` and `input|radio`;
* [rtl] fix of `input|hslider`;
* [rtl] fix of `input|number`, `select|dropdown editable`   
* [css,js] aspect loading fix in context of scapp;
* [macOS] internal BGRA format enforced on MacOS too.
* usciter[exe/app] dark/light theme handling refactoring.


## 4.4.8.21

### New features:

* fetch API: `options.downloadProgress(loaded,total)` - download progress callback.

### Fixes:

* [JSX] fix of `disabled={true|false}` attribute handling.
* `componentDidMount`/`componentWillUnmount` fix for css::prototype definitions.
* Fix of loading document in frame.
* [macos] performance fixes in video rendering.
* [macos] window level fix for dialogs.
* Environment variable SCAPP-DEBUG=ON to enable sciter debugger in scapp and custom applications. Same as explicit `--debug` argument.
* `window.modal()` returns `undefined` if the dialog is closed by "X" window button.
* `Window.this.modal(<alert resizable=true>...</alert>)` to enable resizable dialog.
* Fix of memory leak in `sciter::value::operator["key"|index]` 
* Fix of threading issue in sciter::value, see: https://sciter.com/forums/topic/an-access-violation-occurred-while-reading-position-0x0000002c/


## 4.4.8.20

### New features:

* JSX: <NS-Comp /> - to call NS.Comp component (fully qualified names).
* [css] + `:window-root` selector - matches only root DOM element that is loaded into window directly.
* `elem.state.flow` property - reports CSS flow manager used on the element.
* `SciterSetOption(NULL,SCITER_SET_INIT_SCRIPT, (UINT_PTR) "/* JS module here */" )` - support of script injects.

### Fixes:

* Fix of `Clipboard.writeText("...")`, see: https://sciter.com/forums/topic/clipboard-write-bug/
* ACRYLIC_BLURBEHIND is disabled again - too many problems, for example: https://sciter.com/forums/topic/memory-leak/, Sciter still provides blurbehind but less blurry that acrylic.
* [osx] better handling of `window.isEnabled`.
* [virtual-list] `vlist.navigateTo(v)` and `vlist.advanceTo(n)` fixes.
* fix of custom scrollbar styling.

NOTE: that is probaly the last release of 4.4.x.x series. 
Next releases will switch to latest Skia version that enables Vulkan (Linux, Windows) and DirectX 12 (Windows) backends.  
Most of the changes will be on Linux: I am dropping use of GTK - Sciter will be purely X Window based.
Default backends on Linux will be: Vulkan -> OpenGL -> Raster with Skia graphics (no Cairo anymore).

## 4.4.8.19

### New features:

* [virtual-list] better scrollbar handling - less "jumpy".
* [i18n]: 
   - `let str = @"to translate"` - translatable string literals.
   - `/*@context for translation*/` - translation context, see documentation.
* + sdk.js/samples.app/classic - application template / prototype. 
* sciter.dll is not using uxtheme.dll on Windows anymore. Internal "theme:" URL scheme handling is disabled;

### Fixes:

* [osx] fix of loading files that contain non-trivial unicode characters;
* [osx] compatibility with 10.13;
* [osx] behavior:shell-icon fix;
* [osx] CoreGraphics backend regression fix;
* `Window.this.modal(<alert caption="Bar">Foo</alert>)`, @caption fix.
* `<input|slider min>` handling fix.
* `<include></include>` pair parsing fix.
* `<select>` click handling fix.
* [windows] `@media high-contrast {...}` handling fix.

## 4.4.8.18

### New features:

* [C++ api] + window::eval();
* [C++ api] + `sciter::window::close()` to force window closure. Also `sciter::window::request_close()`
* [integration] demos of call_function() and call_method();  
* `SciterLoadFile()`, support paths starting "./" and "../" - to open resources relative to CWD (whatever it means);

### Fixes:

* scrolling / animated scrolling: "overscroll" feature and touch specific functionality are disabled for now, more problems than solutions;
* [css] fix of `*` selector specificity handling;
* [reactor] `element.patch()` refactoring , speed up and better support of fragments;
* [MacOS] fullscreen fix;
* [MacOS] `window.move(...)` 1px offset fixed;
* [MacOS] fix of window closure delay;
* [MacOS] fix of role="window-caption" handling in custom frames;
* [win] scapp.exe + productDescription (David's patch);
* `Graphics.strokeRect()` fix;
* [inspector] fix of second instance detection handling;
* Fix of mem-leak alike timers pileup, see: https://sciter.com/forums/topic/serious-memory-leak-that-leads-to-frequent-crashes-reproducible/ ;
* Fix of popup closure: https://sciter.com/forums/topic/there-are-multiple-elements-on-the-page/ ;

## 4.4.8.17

### New:

* `Graphics.draw(element)`, see: sdk.js/samples.sciter/immediate-mode-painting/draw-element.htm
* [inspector] eval runs in context of 'this' that is set to current selected element.

### Fixes:

* win7 compatibility of usciter.exe, inspector.exe, etc. Note window-blurbehind works now on Win10 and above;
* graphics.clearRect() fix on MacOS;
* `sciter::value::call(...)` fix of error string generation.
* [MacOS] font ascent / descent calculation fix.
* [MacOS] fix of "missed idle events" bug that may manifset in non responsive UI.
* `<toggle disabled>` styling fix.
* [JS] `event.button` fix, see: https://sciter.com/forums/topic/bug-with-the-evt-button-processing-in-sciterjs/


## 4.4.8.16

### New features:

* [Windows] acrylic blur behind [is back](https://sciter.com/windows-acrylic-blur-behind-is-back/).
* `Window.send(event)` - send event synchronously to all windows.
* `Window.share : object` - data shared among all windows and documents - application wide data container. 
* `<select|dropdown>`: 
  1. `novalue` is back
  2. event `change` on `<select editable>`: `evt.source` is either `<caption>` or `<option>` that caused the change;
+ sdk.js/widgets/tag-list component.

### Fixes:

* `env.exec(...)` fix. See: https://sciter.com/forums/topic/call-executable-with-args/#post-74647
* fix of `overflow:scroll;` handling, see: https://sciter.com/forums/topic/scroll-function-will-freeze/
* event "change" from `<input|date>`;
* [reactor] reconciliation / focus fix;

## 4.4.8.15

### New features:

* Reactor namespace - [high-level Reactor API functions](docs/md/reactor/reactor-api.md).
* [css] role property, allows to define element role in CSS: 
  ```CSS
  tr { role:"option"; }
  header { role:"window-caption"; }
  ```
+ [JS] `sciter.import("module")` - sync version of `import("module")` JS built-in;
+ `element.animate(stepFn, {FPS:30})` to cap animation callback frequency;
+ `<input type=slider>` fix of "change" event generation;
* **CommonJS** modules support, `require()` function implementation: sdk.js/samples/commonJS;
* `<html disable-debug="true" >` to disable connection with inspector.
* [css] `var(--somename,#F00)` and `var(somename,#F00)` are equivalents now.

### Fixes:

* `<select|dropdown editable placeholder="...">` fix.
* [Win,a11y] fix of accName reporting if it was redefined by CSS content:"new text".
* [MacOS] fix of minimizable/maximizable button appearance.
* `Window.this.modal` styling;
* [MacOS] better painting;
* [MacOS] fix of layered windows (window-frame=transparent) update.
* [MacOS] date.toLocaleDateTimeString() fixes;
* [Win] Fix of `Clipboard.write(...)` - cleans clipboard first.
* JS, better error reporting on erroneous modules.
* Skia backend fix that prevents re-entrant engine creation, affects Sciter.Lite on all platforms and Sciter on MacOS.
* `document.on("beforeunload", function() { console.log("xxx") })` fix.


## 4.4.8.14

### New features:

* [JSX built-in internalization / translation](docs/md/reactor/JSX-i18n.md) support. Works with Reactor, ReactJS, PReact, Mithril - all libraries that provide JSX driver.
* `debug.callStackAt(level)` method, see: https://sciter.com/forums/topic/get-js-function-name-within-function/
* `Event.keyState("A"):boolean` - is key "A" pressed or not at the moment?

### Fixes:

* `slider.max` property handling fix.
* `SciterSetValue` / `SciterGetValue` to obey property `value` defined in script.
* `behavior:menu-bar`, keyboard operation fix.

## 4.4.8.13

### Fixes:

* `Audio.stop()` fix to stop async operation;
* [reactor] fix of fragment handling;
* `Storage.Index.delete(key)` implementation;
* `element.off(".ns")` fix (unsubscribe by namespace);
* [MacOS] fix of `Clipboard.write({...})`;
* 
## 4.4.8.12

### New features:

* `Audio.stop()` method. 

### Fixes:

* various regression fixes;

## 4.4.8.11

### Fixes:

* fix of `element.getElementById()`, see: https://sciter.com/forums/topic/getelementbyid-return-null-after-refresh-div-list/ ;
* fix of possible AV in textarea;
* [Skia backend], fix of possible deadlock on rendering;
* fix of `element.onsizechange()` callback generation in components;
* `sys.fs.splitpath()` fixes;
* `new Image(painter)` and `Image.update(painter)` fixes;
* `Graphics.ellipse()` fix;
* `Graphics.pushLayer(x,y,w,h,filter)` fix;
* CSS/painting, fix of text-decoration and selection painting;
* `element.append/perpend(<fragment>...</fragment>)` fix;
* `sys.fs.match(filename,pattern)` fix of string leak;
* VALUE API fix, correct coercion to T_BYTES in `nativeFunc(new ArrayBuffer(...))`;
* `Graphics.pushLayer("border-box")` generates error when Image based Graphics is used.
* [reactor] `.componentDidCatch(error,contextElement/*performing patch()*/)` - processing errors in render() methods (ReactJS notation);
  
### New features:

* `window.requestAttention("info" | "alert" | "stop")` - app icon blinking on OSes that support that (Windows, MacOS);
* JSX: <Foo {...props} /> support. See: https://sciter.com/forums/topic/react-spread-attributes/
* [SQLite] + recordset.field("name") method. See: https://sciter.com/forums/topic/name-can-not-be-used-as-column-name-of-sqlite/
* [reactor] <div attr={obj}> - warning if incompatible (non string convertible) value is passed.
* [JSX] fragment support using notation `<>...</>`, see: https://reactjs.org/docs/fragments.html#short-syntax

## 4.4.8.10

### Fixes:

* element.post() fix, see: https://sciter.com/forums/topic/virtual-list-vlist-navigate-issue/
* WM_INPUT handling fix (might causing non-handled exceptions);
* Windows: UIAutomation support is back, but requres SciterSetOption(NULL,SCITER_ENABLE_UIAUTOMATION,TRUE);
* env.home(path) - returns normalized path - without ".."; 
* flow:stack fix.
* VirtualSelect/VirtualList fix of the issue: https://sciter.com/forums/topic/virtual-list-vlist-navigate-issue/#post-73783
* reactor: fix of handling `(name)` as key in r13n;
* Tokenizer: fix of freeze on EOI marker;
* [JSX] better errors handling.
* fix of freeze in video rendering + behavior:file-icon/shell-icon;
* [CSS/JS] `prototype: Component`, fix of private fields handling;
* ["on click at :root"]() handling fix;
* Fix of hanging on `::after { position:absolute }` rules;
* Fix of script debugger in x64 versions;

### New features:

* `element.matches("selector")` / `element.$is("selector")`
*  API: `SciterEvalElementScript()` implementation for JS;
* `Element.animate(options,onEnd)` - non-promise version;
* `element.mapLocalToWindow(x,y)` and `element.mapWindowToLocal(x,y)`
* `element.swapWith(otherElement)`
* `image.colorAt(x,y): Color`
* `image.compose(other, op)` 

## 4.4.8.9

### Fixes:

* `overflow:scroll`, fix of non-overflow SB rendering. 
* [debugging] drain logs (a.k.a. flush) before document unload. See: https://sciter.com/forums/topic/wait-for-closerequest-function-calls-to-complete/
* leaflet.js compatibility fix, by adding document.createElementNS();  
* command event `"^exec:***"` handling fix;
* [VirtualList] fix of `render()`;
* [websocket] fix of AV in `new WebSocket("badaddr")`;
* `Clipboard.has("image"|"file"|"text")` - check if clipboard has needed data;
* `self` - yet another alias to current namespace ( `self == globalThis` ) 
* fix of splitter handling in Sciter.Lite.
* fix of element.click() event click generation.



### New features:

* samples/compatibility.js/.css - compatibility layer for browsers. Not complete, features will be added when required;
* samples/leaflet/test-geoJSON.htm sample - demo of layers in leaflet;


## 4.4.8.8-bis

### Fixes:

* `<select|list treelines>` rendering;
* leaflet.js compatibility fix;  


## 4.4.8.8

### Fixes:

* Fix of `<select|dropdown multiple>`
* Fix of `Audio.resume()`
* Fix of https://sciter.com/forums/topic/wrong-style-attribute-in-reactor-when-new-element-has-the-same-tag/ in Sciter.TIS and .JS
* Sciter.JS: events "change" (synchronous) and "input" (posted, asynchronous) are distinct now. 
* [virtual-list] + scroll-manner: scroll-manner(animation:false); //to disable animated scroll
* fix of divide by zero in esoteric situation of zero sized window.

### New features:

+ sdk.js/samples.sciter/virtual-list/virtual-multi-column.htm sample.

## 4.4.8.7

### Fixes:

* inspector exe fix to show real DOM structure;
* [osx] fix of ligatures handling in inputs;
* [osx] fix of transparent windows handling;
* [virtual-list] fix of scrollable table;
* [DOM] <div tabindex> === <div tabindex="0">

## 4.4.8.6

### New features:

* lottie playback API and samples in samples.sciter/lottie/
* `Window.this.monitor:int` - reports monitor index this window is on;
* `Window.monitors:int` - number of screens/monitors;

### Fixes:

* [JSX] fix of `<div tabindex state-selected={selected}>` parsing.
* [API/SOM] _integration.exe_, test of const methods.
* fix of Color values passing to built-in methods.

## 4.4.8.5

### New features:

* `new Graphics.Image(w,h,painter(gfx))` - generation of image by painting on it.
* `Window.this.screen:int` - reports monitor index this window is on;
* `Window.screens:int` - number of screens/monitors; 
* `Window.screenBox(N, "devicePixelRatio")` - reports dip/ppx ratio on Nth monitor; 
* New `EDIT_VALUE_CHANGE` event (JS: "change"). Sequence now: 
 
  * `EDIT_VALUE_CHANGING` (JS: "changing") - before changes, sync event;
  * `EDIT_VALUE_CHANGE` (JS: "change") - immediately after changes but before screen update, sync event;
  * `EDIT_VALUE_CHANGED` (JS: "input") - after changes, after screen update, async/posted event.
  * `behavior:video` -> `VIDEO_FRAME_REQUEST` event (a.k.a. animation frame)
  * `element.state.pixelsIn("1em")` - method to convert CSS length units to CSS pixels.
  * [DOM] attribute "selectable" - enables "HTML range selection" and copying on given element.
  * new sample sdk.js/samples.sciter/menu/custom-shape-menu.htm

### Fixes:

* SDK headers reorganization: sciter-x-primitives.h - non-GUI primitive types;
* fix of console.log() interaction with inspector;
* `placeholder` runtime change fix;
* [CSS] `html:owns-focus` flag on active window;
* [js] persistence fixes;
* virtual-list mouse hover fix;
* fix of mouse-over-scrollbar issue, see: https://sciter.com/forums/topic/sciter-scroll-popup-issue/
* `event.windowX/Y` are in CSS pixels (dips) now.
* color to string conversion fix.
* fix of behavior:virtual-list samples.
* [osx] window update fix on MacOS Mojave.
* websocket events notification fix.

## 4.4.8.4

### New features:

* [css] rgba(255,255,255,var(opacity)) - rgb() and rgba() may use variables now.
* `window-state="hidden" | "shown" | "minimized" | "maximized" | "full-screen"` attribute support on HTML element element. This attribute defines initial state of the window.

### Fixes:

* element.append/insert/children fixes;
* `element.takeOff(...)`  parameters are in dips (CSS pixels);
* fix of cascaded css vars;
* `element.componentDidMount()` invocation fix;
* behavior:pager fix of AV.
* [Storage] fixes.

## 4.4.8.3

### New features:

* [reactor] `this(props,kids)` method in reactive components, a.k.a Reactor's constructor.
* components, support of `>` in event handling selectors ["on click at >child"]() to match immediate child of `this`.

### Fixes:

* [css variables] fix of variable value resolving in cascaded rules.
* [vue|preact] compatibility, element.checked property.
* Fix of AV in timer in some cases.
* `fetch()`, allow use of relative URLs.
* [virtual-list] first|lastVisibleItem, fix of AV on empty list.
* [virtual-list] touchpad scrolling fix on MacOS.
* fix of sdk.js/samples.sciter/drag-n-drop/simplest.htm demo.

## 4.4.8.2

### Fixes:

* inspector fix.
* element.innerHTML fix.

## 4.4.8.1

### New features:

* [css] + support of + general sibling combinator (`~`):  `p ~ span { color: red; }`
* `behavior:hyperlink` support of `target="@system"` attribute to open link in system's default application (default browser for example) rather than Sciter.
* [module sciter], new functions
  * `sciter.compress()`
  * `sciter.decompress()`
  * `sciter.toBase64()`
  * `sciter.fromBase64()`
  * `sciter.md5()`
  * `sciter.crc32()`

### Fixes:

* `devicePixelRatio` fix.

## 4.4.8.0

### New features:

* CSS variables: 
  * now support all types of values (used to be just lengths and colors);
  * Sciter supports as its own `var(name)` as standard `--name` variable declarations. See /samples.css/css-variables;
* [html-window] window-min-width/height, window-max-width/height attributes.
* [css] svg image used as background/foreground image inherits stroke, fill colors and set of CSS variables of element where it is applied.
* zepto patch for mouseenter/mouseleave to work in Sciter. Sciter supports mouseenter/leave events but not mouseove/out.

### Fixes:

* [JS DOM API] fix of <select|dropdown> handling, os it is compatible now with Mithril/PReact, Vue, etc.;
* dispatchEvent preventing recursive call;
* virtual-list fixes;
* [QuickJS] `getTimezoneOffset()` implementation for Windows so Date reports values properly.

## 4.4.7.8

### New features:

* highlightion API, new methods:
  * `range.marks()`
  * `range.setToMark(name)` 
  * `element.rangeFromPoint(x,y)` 
  
  See /samples.sciter/editor-plaintext/highlighting-marks.htm

* `fetch()` API - POSTing JSON and other textual or binary data;

* sdk.js/samples.sciter/reactor-form/ - forms handling in reactor, inspired by Formik/ReactJS;

* SDK headers: SOM_PROP_EX + SOM_RO_PROP_EX

### Fixes:

* fix of window.close(val) for main window;
* virtual-list scroll fixes;
* fix of css::prototype and JS subclassing;
* optimiziation of `<img src="....svg">` handling;

## 4.4.7.7

### New features:

* new global functions:
  * `decode(arraybuffer,encoding): string`, character encoding/decoding 
  * `encode(string,encoding): arraybuffer` 
  * `btoa(arraybuffer): string` - Base64 encoding/decoding 
  * `atob(string): arraybuffer`
* `element.popup(element | vnode,options)` - popup generalization. This makes element.popupAt/For() functions obsolete;  
* `element.animate(stepfunc,options)` - another mode of animate function.  
* `element.state.occluded` - reports occlusion state of the element (partial or full invisibility);
* `Window.elementAt(screenX,screenY)` - find DOM element by screen coordinates;
* [reactor] + reactor-routing sample;
* sdk.js/samples.sciter/input-elements-styling - custom styling demos;
* sdk.js/samples.sciter/menu - menu samples;

### Fixes:

* fix of `element.onmouseXXXX()` handlers;
* [reactor] tunelling key attribute;
* scroll, 1ppx extra fix;
* [virtual-list] initialization fix;
* [css] fix of `currentcolor` handling;
* [dom] fix of `element.attributes["style"] = ...` updates (memory consumption);

## 4.4.7.6

### New features:

* [Clipboard](docs/md/Clipboard.md) support; 

### Fixes:

* `clearInterval()`` fix, see: https://sciter.com/forums/topic/calling-clearinterval-inside-setinterval-has-no-effect/
* [zepto.js] compatibility, element.style.cssText prop support;
* behavior: virtual-list fixes;

## 4.4.7.5

### New features:

* [`element.animate()`](Element.md#animate) - various animation effects;
* [`element.takeOff()`](Element.md#takeOff) - "airborn" DOM elements - replaced outside of host window;
* [`element.popupFor()`](Element.md#popupFor) - showing popup elements using this one as anchor;
* `node.parentWindow` - window that hosts this node;
* `Window.this.parent`  - parent window of this one;
* events "closerequest", "beforeunload", "close" on Window.this contain event.data of window.close(data) call;
* [svg] SVG images used as back/foreground images inherit CSS variables from host document. This allows change colors/lengths from CSS of host document, see: samples.sciter/svg-icons demo.

### Fixes:

* [virtual-list] fix on initialization sequence: samples.sciter/virtual-list/test-table.htm
* [reactor]  `render([props,kids])` - props and kids are not provided when rendering is don in response of `this.componentUpdate()`;
* [reactor]  fix of attribute "value" handling;
* graphics, path images, proper handling of repeat-x, repeat-y;
* http client, support of "content-type" override;
* Window's "size" event is generated after window size change *but* before DOM layout - can be used in cases when DOM needs to be changed in response of window size changing.

## 4.4.7.4

### New features:

* [windows] new demo sdk.js/demos/windows-directx demo project, demonstrates 
  * mixin style of Sciter integration;
  * use of Sciter on DirectX windows;

* `behavior:video`, "assetified", documented and sampled, see: sdk.js/samples.sciter/video/

* `printf(format, ...): string` - C-style [`printf()`](https://www.cplusplus.com/reference/cstdio/printf/) as a global function.
* `scanf(format, str): [...]` - C-style [`scanf()`](https://www.cplusplus.com/reference/cstdio/scanf/) as a global function.

* `fetch()` refactoring:
  * Request/Response split; 
  * samples/fetch(AJAX)/test-upload.htm - test of file upload

* transactional updates in &lt;plaintext&gt; , see samples.sciter/editor-plaintext/transactional-update.htm

### Fixes:

* fix of `element.innerText` for elements with behaviors.
* fix of AV in window event handlers - Window.this.on("...", function) - automatic un-subscription of subscribed documents.
* fix in `element.selection.setBaseAndExtent()` - offsets normalization.
* fix of asset methods calling in external behaviors.
* Implementation of missed `sciter::dom::element::call_method(...)`, `sciter::dom::element::call_function(...)`

## 4.4.7.3

### New features:

 * [behavior:richtext and behavior:plaintext] method `richtext|plaintex.update(function(tctx){})`` - transactional updates.

### Fixes:

* [sdk, C++ headers] sciter::vfunc() was replaced by sciter::value() constructors;
* fix of sys.fs.$readfile(), was not closing the file properly;
* [reactor.js] reconciliation fix.

## 4.4.7.2

### Fixes:

* fix of issues in behavior:virtual-list; 
* [css] fix of max-width handling;

## 4.4.7.1

### Fixes:

* fix of https://sciter.com/forums/topic/svg-does-not-render-until-hover/
* fix of https://sciter.com/forums/topic/widthmax-intrinsic-bug-on-hover/
* css: horizontal-align / flow:vertical combination fix.
* `&lt;select&gt;` uses `@as="string"` by default in Sciter.JS.
* fix of https://sciter.com/forums/topic/aspect/

## 4.4.7.0

Unified API: ISciterAPI uses the same structure (list of functions) on all platforms and variants (Sciter and Sciter.Lite). Functions that are not available on particular platform/variant are set to NULL. 

Note: that is breaking change for Rust/Go/Python/C# wrappers - they need to be updated.

### Fixes:

* fix of scrollable rendering;
* [select|dropdown] fix of first item set when @novalue is used.
* [drawing] fix of position:absolute / outline drawing.
* behavior:virtual-list; fix of https://sciter.com/forums/topic/bug-scroll-indicator-not-work/ 

## 4.4.6.8

### New features

* `Windows.this.performDrag()` - initiates Drag-n-Drop from your code side. This way you can support dragging of text,html,files,JSON from your application to outside. + D&D samples in samples.sciter/drag-n-drop-system/

### Fixes

* fix of scrollables rendering;
* [Sciter.JS/SDK] `value::date()`` conversion fix.
* `behavior:virtual-list` fix of first/lastVisibleElement properties.
* more docs on behaviors (still not complete but closer).

## 4.4.6.7

[Sciter.API] Sciter and Sciter.Lite use the same struct SciterAPI {} so non-C++ language wrappers can be used as for Sciter as for Sciter.Lite. Functions that are not available in Sciter.Lite are just NULLs in SciterAPI struct.

### Fixes

* <frameset>, more Reactor friendly.
* [inspector] breakpoint handling fixes.

### New features

* support of element.onsizechange = function(){} 
* element.style.setCursor(image) - set custom cursor.

## 4.4.6.6

### New builds/assemblies

* Linux/iot/arm32 - Sciter.JS.Lite for Raspberry Pi.

### Fixes

* [scrollable] 1px off at last position.
* [inspector.js] enabling F5...F11 shortcuts in debugger.
* [inspector.js/debug] more reliable debug output in frames.
* [Sciter.JS] `input.value = null` support.
* [behavior:calendar] $(input).calendar.mode = "months"; or <input|calendar mode="months" />
* [behavior:virtual-list] fix of element.vlist.navigate("start"|"end") method;

### New features

* [SDK/headers], custom to/from sciter::value serialization support:
  ```
  T getter(const sciter::value& v, T*);
  sciter::value setter(const T& t); 
  ```
* `scrollanimationstart` and `scrollanimationend` events.
* [SciterJS] usciter + help button is operational. 
* [SciterJS] mdview update with the help of [MustafHi](https://github.com/c-smile/sciter-js-sdk/pull/66)  

## 4.4.6.5

### Fixes

* fix of breakpoint handling in inspector

## 4.4.6.4

### New features

* + `Element.selection` support.
* + `Element.onGlobalEvent()` and `Element.offGlobalEvent()`, see : samples.sciter/global-events/README.md for the idea.

### Fixes

* [JSX] fix of line number reports when JSX is used in presence of tabs (`\t`);
* [Sciter.JS, Reactor] fix of "falsy" values handling.
* [OSX] better font ascent/descent calculation.

## 4.4.6.3

### New builds/assemblies

* MacOS - inspector.app and usciter.app

### New features

* [sciter.js/JSX] + support of numeric and boolean attributes <td cols=2 valid=true> 
* [sciter.js] + sample : sdk.js/samples.sciter/lightbox-dialog.
* [Sciter.JS] window.load(url) - loads document into this window.

### Fixes

* [Sciter][Sciter.JS] Reactor fix of <select|dropdown> reconciliation. See: https://sciter.com/forums/topic/select-behaves-erratically-in-reactor-component/
* [Sciter.JS] better console.log() output when inspector is not present.
* [Sciter.JS] behavior:virtual-list - scroll animation outside of virtual scroll functionality.
* [linux] fix of AV on msgbox close.
* [inspector/debugger] fix of breakpoint set.
* [frameset] fix of https://sciter.com/forums/topic/frameset-column-changes-height-when-container-is-resized/ issue.
* [reactor] fix of missed didMount/willUnmount() call when element changes prototype.

## 4.4.6.2

### New builds/assemblies

* MacOS/ARM - MacOS binaries are universal now - contain as x64 as ARM (M1) code.

### New features

* Sciter.JS.Quark is operational now. Use bat/sh files in bin/quark. Source code of the Quark is in /quark folder.
* JSX support of HTML style no-value attributes like: <input disabled />
* `sys.fs.$readfile()` - synchronous file read.
* `canvas.canvasUpdate(function(gfx){...});` - transactional painitng on `<canvas>`, see [discussion](https://sciter.com/forums/topic/how-to-free-graphics-image/).
* [API] window::broadcast_event(BEHAVIOR_EVENT_PARAMS event); post/send customs events to all windows of the application. See demos/integration project.

### New samples

* MDView at sdk.js/samples.sciter/applications.quark/mdview - viewer of MD files:
  * can be compiled as Quark monolitic application;
  * demonstrates Sciter.JS printing support;

## 4.4.6.1

### New builds/assemblies

* Sciter.JS.Lite - GLFW based demo in demos.lite/sciter-glfw-opengl/
* Sciter.JS.Lite builds on:
  * Windows
  * MacOS
  * Linux

### New features

1. *CSS* - support of `@keyframes` inside `@set`'s;
2. *video* - new event "videocoordinate" - allows to coordinate output of multiple `<video>'`s. Coordinated output allows to reduce FPS rate of several videos running at the same time. See: sdk/samples/video/video-25-videos.htm
3. *Audio*, basic audio playback, see: sdk.js/samples.sciter/audio/test-basic.htm;
4. [module @storage](docs/md/storage/README.md) - persistent storage, NoSQL DB built into JS runtime.
5. `sys.fs.$readdir()` - sync version of readdir.
6. `Color.RGB(0..255,0..255,0..255[,0..255])`

### New samples

1. The `$` - Zepto (micro jQuery) sample, see: sdk.js/samples/$
2. samples.sciter/sys/folder.htm - `sys.fs.readdir()` demo.
3. samples.sciter/process/spawn.htm - process spawning demo with stdout redirection. 

### Fixes

* *inspector* fix of style url reporting, see: https://sciter.com/forums/topic/inspector-cant-loads-css-files/
* `<frame>`, fix of `frame.attributes["src"] = ...;`
* [core] `flow:vertical-wrap;` fix of stack overflow when percent units used.


## 4.4.6.0

### New features

* `behavior:virtual-list` - native virtual list;
* `element.post(function | event)` - posts either function or event to the element;
* [JS runtime] `sys.fs.watch(path,callback)` - watch changes on FS (folders and files);
* [JS runtime] `sys.fs.splitpath(path) -> [dirpath,file]` ;
* [usctier] LiveReload functionality is operational;

### New samples

* samples.sciter/virtual-list - vurtual list samples;

### New builds/assemblies

* Sciter.JS.Lite - Linux 

## 4.4.5.12

### New samples

* demos/integration - demonstrates native code <-> JavaScript interaction, running native worker threads, exposing native classes and objects, etc.  
* docs/md - documentation as part of SDK, markdown formatted. 
* samples.sciter/input-elements/ - home of various samples of built-in input elements.
* samples.sciter/themes/ - demo of built-in theme (light/dark), MS Metro and Android Material.
* samples.sciter/tray-icon/ - tray icon demo.
* samples.sciter/window/ - demo of different types of window chromes (window frame types).
* samples/markdown/ - demo of RemarkableJS library.

### New features

* graphics.push/popLayer() - clipping(rect,path,bitmap), filters, opacity layers. 
* graphics.draw(path|text|image|element, {options}) - drawing those objects. 
* class [Graphics.Text](docs/md/Graphics.Text.md) - text drawing and measurement.
* class [Graphics.Path](docs/md/Graphics.Path.md) - paths 
* class [Graphics.Color](docs/md/Graphics.Color.md) - color object (RGBA/HSLA/HSLV) 
* element.style.colorOf(prop) - getting used color values
* element.style.pixelsOf(prop) - getting used length values
* window.isResizable, isMinimizable and other prperties. 

### New builds

* Sciter.JS.Lite - Windows
* Sciter.JS.Skia - Windows
* Sciter.JS.Lite - Android

## 4.4.5.10, revision 8422, 2021-01-15

### New

#### JS Runtime

* Immediate mode drawing support, element.paintBackground, element.paintForeground, element.paintContent and element.paintOutline properties/methods.

### Fixes

* debugger/inspector support by sciter.dll and scapp.exe

## 4.4.5.10, revision 8420, 2021-01-13

By this release Sciter.JS has reached BETA phase.

### New

#### HTML/CSS

* [CSS] + `appearance` property. Example `button { appearance:none; }` will suppress default styling of button elements.
* [CSS] + support of `transition: ... cubic-bezier(x1,y1,x2,y2);` ease function.

#### JS Runtime

* + support of JavaScript debugger in scapp, usciter and user applications. Window shall be created with SW_ENABLE_DEBUG flag in order to be debugable. 
* Element.onclick and other property-ehandlers.
* `window.xcall("name"[,arg0,... argN])` and `element.xcall("name"[,arg0,... argN])` - calling methods of native behaviors attached to window and elements.

#### Frameworks

* [PReact](https://preactjs.com/) framework is generally operational "as it is". JSX (built-in native implementation) can be used with PReact by defining `JSX = h;` - `h()` function of PReact is used as a driver of JSX expressions.
  See: sdk.js/samples/preact/ demos.

### Fixes

* various fixes in HTML/CSS core;
* QuickJS has upgraded to latest (2020-11-08) version. This fixes several issues in JS core. 


## 4.4.5.9, revision 8396, 2020-12-18

### New

1. `element.children` support
1. `element.removeEventListener` support
1. `CSS.supports()` support
1. `navigator` object support
1. inspector.exe is more or less operational but JS debugger functionality is still in progress.
1. Leaflet.JS demo. See: sdk.js/samples/leaflet . Note: Leaflet runs "as it is" with minor tweaks - Leaflet has outdated feature detection.

### Fixes

1. event.clientX/Y ppx/px fix.
1. Event, various fixes.

## 4.4.5.8, revision 8364, 2020-12-03

### New

1. `element.tag` - lowercase tag name, `element.tagName` uppercase tagname
2. `element.hasAttributes` 
3. `element.hasAttribute()` 
4. `element.attributes` - note in Sciter this returns an array of {name:..., value:...} objects - snapshot of current attributes collection (but not a live map).
5. `element.disabled` - in Sciter it is a synonym of `element.state.disabled`
6. `element.readonly` - in Sciter it is a synonym of `element.state.readonly`
7. `Window.this.data` as semi-persistent object - survives document reload.
8. `Range` class
9. `Tokenizer` class (Sciter specific), see samples.sciter/colorizer/
9. `element.state.value` value (of input and other elements)
9. `scapp.exe -debug` to support connection with inspector.exe, inspector.exe should be running.
9. `usciter.exe` supports connection with inspector.exe, inspector.exe should be running.

Note: I am using *inspector* project as a testing tool for sciter.js

### Fixes

1. fix of loading local resources (including `file://`) by `fetch()`.
2. Promise rejection is reported as an error on console.error() channel.
3. Various rendering fixes.

## 4.4.5.7, revision 8347, 2020-11-24

### New

1. `document.createNodeIterator()`
2. `document.url([relurl])` - Sciter specific
3. `element.click()`
4. `element.childNodes`
5. `event.altKey`, `event.ctrlKey`, `event.metaKey`, `event.shiftKey`, `event.button`, `event.buttons`, `event.clientX/Y`, `event.screenX/Y`, `event.x/y`,  
6. `class Text extends Node`;
7. `class Comment extends Node`;
8. `class Graphics.Image` - sciter specific; 
9. native module "@debug" - sciter specific;
10. `Element.state.box()` - sciter specific;
11. `sciter.uuid()` - uuid string generator
12. event `"reloaddocument"`;
13. samples/debug-peer.js (this will move inside sciter.dll) + inspector.exe, console log is operational there + F5 support (by debug-peer.js).


### Fixes

1. JSX, fix of <var>, etc parsing;


## 4.4.5.6, revision 8341, 2020-11-17

### New

1. WebSocket support, see sdk/samples/websockets/. Note: that is home grown implementation on top of libuv sockets - only basic functionality. 
2. Node.remove() added.

## 4.4.5.6, revision 8340, 2020-11-17

1. [css] hit test fix on inline-block/transform elements;

## 4.4.5.6, revision 8335, 2020-11-17

### New

1. `Window.modal()` - modal windowed message boxes and dialogs
   * `Window.modal(<info>...</info>)`
   * `Window.modal(<alert>...</alert>)`
   * `Window.modal(<error>...</error>)`
   * `Window.modal(<question>...</question>)`
   * `Window.modal{ params }` - showing arbitrary window as a modal dialog
2. `Element.classList`
   * `Element.classList.item()`
   * `Element.classList.add()`
   * `Element.classList.remove()`
   * `Element.classList.toggle()`
   * `Element.classList.contains()`
   * `Element.classList.length`
   * `Element.classList.entries()`
3. `class CustomEvent`
4. `Element.dispatchEvent(new CustomEvent(...))`
6. `window.dispatchEvent(new CustomEvent(...))`
7. `window.minSize = [w,h]`
8. `window.maxSize = [w,h]`
9. `window.on("eventname", cb)` and `window.addEventHandler("eventname", cb)`
9. `window.off("eventname" | cb)`
9. [Window events]: `"statechange"`, `"resolutionchange"`, `"replacementstart"`, `"replacementend"`
9. [API] `SciterCall()`, `SciterEval()` are operational
9. [@sciter module] `loadLibrary("name")` - load Sciter extension native library (dll,so,dylib). "name" is dll name without extension. The dll shall reside in the same folder as executable. SQLite demo operational in scapp.exe. 

### Fixes

1. [css] hit test fix on inline-block/transform elements;
2. [jsx] fix of white space runs handling.
3. [css] fix of box calculation in case of box-sizing:border-box / display:inline-block combination;


## 4.4.5.5 2020-11-12

### New

1. `Element.dispatchEvent()`
2. `Element.queryCommand()`
3. `Element.executeCommand()`
4. `Element.prepend(vnode)`
5. `Element.append(vnode)`
6. `Element.patch(vnode)` - core of the Sciter's Reactor, a.k.a. "Native React"
7. `Element.componentUpdate(props)` - Sciter's Reactor, request to render/patch the component.
