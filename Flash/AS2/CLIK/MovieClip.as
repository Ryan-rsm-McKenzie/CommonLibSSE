import flash.display.BitmapData;
import flash.geom.Matrix;
import flash.geom.Rectangle;
import flash.geom.Transform;


dynamic intrinsic class MovieClip
{
	var _alpha: Number;
	var _currentframe: Number;
	var _droptarget: String;
	var _focusrect: Boolean;
	var _framesloaded: Number;
	var _height: Number;
	var _highquality: Number;
	var _lockroot: Boolean;
	var _name: String;
	var _parent: MovieClip;
	var _quality: String;
	var _rotation: Number;
	var _soundbuftime: Number;
	var _target: String;
	var _totalframes: Number;
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
	var focusEnabled: Boolean;
	var hitArea: Object;
	var menu: ContextMenu;
	var tabChildren: Boolean;
	var tabEnabled: Boolean;
	var tabIndex: Number;
	var tooltipText: String; // Central API
	var trackAsMenu: Boolean;
	var useHandCursor: Boolean;
	var cacheAsBitmap: Boolean;
	var filters: Array;
	var opaqueBackground: Number;
	var scrollRect: Object;
 	var transform: Transform;
	var blendMode: Object;
    var _xrotation: Number; // 3Di
    var _yrotation: Number;
    var _z: Number;
    var _zScale: Number;
    var _matrix3d: Array;
	var _perspfov: Number;

	function attachAudio(id: Object): Void;
	function attachBitmap(bmp: BitmapData, depth: Number, pixelSnapping: String, smoothing: Boolean): Void;
	function attachMovie(id: String, name: String, depth: Number, initObject: Object): MovieClip;
	function clear(): Void;
	function createEmptyMovieClip(name: String, depth: Number): MovieClip;
	function beginBitmapFill(bmp: BitmapData, matrix: Matrix, repeat: Boolean, smoothing: Boolean): Void;
	function beginFill(rgb: Number, alpha: Number): Void;
	function beginGradientFill(fillType: String, colors: Array, alphas: Array, ratios: Array, matrix: Object, spreadMethod: String, interpolationMethod: String, focalPointRatio: Number): Void;
	function lineGradientStyle(fillType: String, colors: Array, alphas: Array, ratios: Array, matrix: Object, spreadMethod: String, interpolationMethod: String, focalPointRatio: Number): Void;
	function createTextField(instanceName: String, depth: Number, x: Number, y: Number, width: Number, height: Number): TextField;
	function curveTo(controlX: Number, controlY: Number, anchorX: Number, anchorY: Number): Void;
	function duplicateMovieClip(name: String, depth: Number, initObject: Object): MovieClip;
	function endFill(): Void;
	function getBounds(bounds: Object): Object;
	function getRect(bounds: Object): Object;
	function getBytesLoaded(): Number;
	function getBytesTotal(): Number;
	function getDepth(): Number;
	function getInstanceAtDepth(depth: Number): MovieClip;
	function getNextHighestDepth(): Number;
	function getSWFVersion(): Number;
	function getTextSnapshot(): TextSnapshot;
	function getURL(url: String, window: String, method: String): Void;
	function globalToLocal(pt: Object): Void;
	function gotoAndPlay(frame: Object): Void; // frame can be String or Number
	function gotoAndStop(frame: Object): Void; // frame can be String or Number
	function hitTest(): Boolean; // arguments can be either target or x/y/shapeFlag
	function lineStyle(thickness: Number, rgb: Number, alpha: Number, pixelHinting: Boolean, noScale: String, capsStyle: String, jointStyle: String, miterLimit: Number): Void;
	function lineTo(x: Number, y: Number): Void;
	function loadMovie(url: String, method: String): Void;
	function loadVariables(url: String, method: String): Void;
	function localToGlobal(pt: Object): Void;
	function moveTo(x: Number, y: Number): Void;
	function nextFrame(): Void;
	function play(): Void;
	function prevFrame(): Void;
	function removeMovieClip(): Void;
	function setMask(mc: Object): Void;
	function startDrag(lockCenter: Boolean, left: Number, top: Number, right: Number, bottom: Number): Void;
	function stop(): Void;
	function stopDrag(): Void;
	function swapDepths(target: Object): Void;
	function unloadMovie(): Void;
	function valueOf(): MovieClip;
	function onData(): Void;
	function onDragOut(): Void;
	function onDragOver(): Void;
	function onEnterFrame(): Void;
	function onKeyDown(): Void;
	function onKeyUp(): Void;
	function onKillFocus(newFocus: Object): Void;
	function onLoad(): Void;
	function onMouseDown(): Void;
	function onMouseMove(): Void;
	function onMouseUp(): Void;
	function onPress(): Void;
	function onRelease(): Void;
	function onReleaseOutside(): Void;
	function onRollOut(): Void;
	function onRollOver(): Void;
	function onSetFocus(oldFocus: Object): Void;
	function onUnload(): Void;

	// GFx Extensions
	var hitTestDisable: Boolean;
	var noAdvance: Boolean;
	var topmostLevel: Boolean;
	var rendererString: String;
	var rendererFloat: Number;
	var focusGroup: Number;
}
