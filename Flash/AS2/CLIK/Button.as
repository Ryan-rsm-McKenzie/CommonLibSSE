import flash.geom.Rectangle;


intrinsic class Button
{
	var _alpha: Number;
	var _focusrect: Boolean;
	var _height: Number;
	var _highquality: Number;
	var menu: ContextMenu;
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
	var scale9Grid: Rectangle;
	var enabled: Boolean;
	var filters: Array;
	var cacheAsBitmap: Boolean;
	var blendMode: Object;
	var tabEnabled: Boolean;
	var tabIndex: Number;
	var trackAsMenu: Boolean;
	var useHandCursor: Boolean;

	function getDepth(): Number;
	function onDragOut(): Void;
	function onDragOver(): Void;
	function onKeyDown(): Void;
	function onKeyUp(): Void;
	function onKillFocus(newFocus: Object): Void; // newFocus can be a TextField, MC, or Button
	function onPress(): Void;
	function onRelease(): Void;
	function onReleaseOutside(): Void;
	function onRollOut(): Void;
	function onRollOver(): Void;
	function onSetFocus(oldFocus: Object): Void; // oldFocus can be a TextField, MC, or Button

	// GFx Extensions
	var hitTestDisable: Boolean;
	var topmostLevel: Boolean;
	var focusGroup: Number;
}
