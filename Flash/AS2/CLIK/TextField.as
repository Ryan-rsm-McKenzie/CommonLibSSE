 import flash.geom.Rectangle;


dynamic intrinsic class TextField
{
	var _alpha: Number;
	var _height: Number;
	var _highquality: Number;
	var _name: String;
	var _parent: MovieClip;
	var _quality: String;
	var _rotation: Number;
	var _soundbuftime: Number;
	var _target: String;
	var _url: String;
	var _visible: Boolean;
	var _width: Number;
	var _x: Number;
	var _xmouse: Number;
	var _xscale: Number;
	var _y: Number;
	var _ymouse: Number;
	var _yscale: Number;
	var antiAliasType: String;
	var autoSize: Object;
	var background: Boolean;
	var backgroundColor: Number;
	var border: Boolean;
	var borderColor: Number;
	var bottomScroll: Number;
	var condenseWhite: Boolean;
	var embedFonts: Boolean;
	var gridFitType: String;
	var filters: Array;
	var hscroll: Number;
	var html: Boolean;
	var htmlText: String;
	var length: Number;
	var maxChars: Number;
	var maxhscroll: Number;
	var maxscroll: Number;
	 var menu: ContextMenu;
	var mouseWheelEnabled: Boolean;
	var multiline: Boolean;
	var password: Boolean;
	var restrict: String;
	var scroll: Number;
	var selectable: Boolean;
	var sharpness: Number;
	var styleSheet: TextField.StyleSheet;
	var tabEnabled: Boolean;
	var tabIndex: Number;
	var text: String;
	var textColor: Number;
	var textHeight: Number;
	var textWidth: Number;
	var thickness: Number;
	var type: String;
	var variable: String;
	var wordWrap: Boolean;

	static function getFontList(): Array;

	function addListener(listener: Object): Boolean;
	function getDepth(): Number;
	function getNewTextFormat(): TextFormat;
	function getTextFormat(beginIndex: Number, endIndex: Number): TextFormat;
	function removeListener(listener: Object): Boolean;
	function removeTextField(): Void;
	function replaceSel(newText: String): Void;
	function replaceText(beginIndex: Number, endIndex: Number, newText: String): Void;
	function setNewTextFormat(tf: TextFormat): Void;
	function setTextFormat(): Void; // arguments can either be indices or a TextFormat instance
	function onChanged(changedField: TextField): Void;
	function onKillFocus(newFocus: Object): Void;
	function onScroller(scrolledField: TextField): Void;
	function onSetFocus(oldFocus: Object): Void;
	
	//GFx Extensions;
	var autoFit: Boolean;
	var caretIndex: Number;
	var focusGroup: Number;
	var hitTestDisable: Boolean;
	var noTranslate: Boolean;
	var numLines: Number;
	var topmostLevel: Boolean;
	var inactiveSelectionBkgColor: Number;
	var alwaysShowSelection: Boolean;
	var noAutoSelection: Boolean;
	var selectionBeginIndex: Number;
	var selectionEndIndex: Number;
	var selectionBkgColor: Number;
	var selectionTextColor: Number;
	var useRichTextClipboard: Boolean;
	var inactiveSelectionTextColor: Number;
	var fontScaleFactor: Number;
	var textAutoSize: String;
	var verticalAlign: String;
	var verticalAutoSize: String;
	function appendText(newText: String): Void;
	function appendHtml(newHtml: String): Void;
	function getCharBoundaries(charIndex: Number): Rectangle;
	function getExactCharBoundaries(charIndex: Number): Rectangle;
	function getCharIndexAtPoint(x: Number, y: Number): Number;
	function getFirstCharInParagraph(charIndex: Number): Number;
	function getLineIndexAtPoint(x: Number, y: Number): Number;
	function getLineLength(lineIndex: Number): Number;
	function getLineMetrics(lineIndex: Number):  Object
	function getLineOffset(lineIndex: Number): Number;
	function getLineText(lineIndex: Number): String;
	function copyToClipboard(richClipboard: Boolean, startIndex: Number, endIndex: Number): Void;
	function cutToClipboard(richClipboard: Boolean, startIndex: Number, endIndex: Number): Void;
	function pasteFromClipboard(richClipboard: Boolean, startIndex: Number, endIndex: Number): Void
}
