import flash.geom.Point;


intrinsic class Mouse
{
	static function addListener(listener: Object): Void;
	static function hide(): Number;
	static function removeListener(listener: Object): Boolean;
	static function show(): Number;

	// GFx Extensions
	static var HAND: Number;
	static var ARROW: Number;
	static var IBEAM: Number;
	static var LEFT: Number;
	static var RIGHT: Number;
	static var MIDDLE: Number;
	static var mouseIndex: Number;
	static function getButtonsState(mouseIndex: Number): Number;
	static function getTopMostEntity(arg1: Object,arg2: Number,arg3: Boolean): Object;
	static function getPosition(mouseIndex: Number): Point;
	static function setCursorType(cursorType: Number,mouseIndex: Number): Void;
}
