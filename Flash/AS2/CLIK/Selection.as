intrinsic class Selection
{
	// Methods in the Flash Player
	static function addListener(listener: Object): Void;
	static function getBeginIndex(): Number;
	static function getCaretIndex(): Number;
	static function getEndIndex(): Number;
	static function getFocus(): String;
	static function removeListener(listener: Object): Void;
	static function setFocus(newFocus: Object): Boolean;
	static function setSelection(beginIndex: Number, endIndex: Number): Void;
	
	// GFx Extensions
	static var alwaysEnableArrowKeys: Boolean;
    static var alwaysEnableKeyboardPress: Boolean;
	static function captureFocus(doCapture: Boolean): Void;
	static var disableFocusAutoRelease: Boolean;
	static var disableFocusKeys: Boolean;
	static var disableFocusRolloverEvent: Boolean;
	static var modalClip: MovieClip;
	static var numFocusGroups: Number;
	static function moveFocus(keyToSimmulate: String, startFromMovie: Object): Object;
	static function findFocus(keyToSimulate: String, parentMovie: Object, loop: Boolean, startFromMovie: Object, includeFocusEnabledChars: Boolean, controllerIndex: Number): Object;
	static function setModalClip(modalClip: Object, controllerIndex: Number): Object;
	static function getModalClip(controllerIndex: Number): Void;
	static function setControllerFocusGroup(controllerIndex: Number, focusGroupIdx: Number): Boolean;
	static function getControllerFocusGroup(controllerIndex: Number): Number;
	static function getFocusArray(mc: Object): Array;
	static function getFocusBitmask(mc: Object): Number;
	static function getControllerMaskByFocusGroup(focusGroupIdx: Number): Number;
}
