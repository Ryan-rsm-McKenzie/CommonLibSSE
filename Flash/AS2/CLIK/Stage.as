import flash.geom.Point;
import flash.geom.Rectangle;


intrinsic class Stage
{
	static var align: String;
	static var height: Number;
	static var scaleMode: String;
	static var showMenu: Boolean;
	static var width: Number;

	static function addListener(listener: Object): Void;
	static function removeListener(listener: Object): Boolean;

	// GFx Extensions
	static var visibleRect: Rectangle;
	static var safeRect: Rectangle;
	static var originalRect: Rectangle;

	static function translateToScreen(pt: Object): Point;
}
