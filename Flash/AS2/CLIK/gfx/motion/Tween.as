/**
 * The Tween class adds tween methods {@code tweenTo()} and {@code tweenFrom()} to all MovieClips when the {@code Tween.init()} method is called.
 */


class gfx.motion.Tween extends MovieClip
{
	/* PUBLIC VARIABLES */

	private static var _instance = new Tween();


	/* PRIVATE VARIABLES */

	private var tween__props: Object;
	private var tween__startProps: Object;
	private var tween__ease: Function;
	private var tween__startTime: Number;
	private var tween__duration: Number;


	/* INITIALIZATION */

	/**
	 * Create a new Tween instance. This method should only be called internally by the Tween class on creation, as it is only used to mix the Tween functionality into the MovieClip prototype once.
	 */
	private function Tween() {
		MovieClip.prototype.tweenTo = tweenTo;
		MovieClip.prototype.tweenFrom = tweenFrom;
		MovieClip.prototype.tweenEnd = tweenEnd;
		MovieClip.prototype.tween__run = tween__run;
		MovieClip.prototype.tween__to = tween__to;
		MovieClip.prototype.tween__start = tween__start;

		// Hide the private tween methods from introspection.
		_global.ASSetPropFlags(MovieClip.prototype, "tween__start,tween__to,tween__run", 1);
	}


	/* PUBLIC FUNCTIONS */

	/**
	 * Initialize the tween functions in the MovieClip class.  Once initialized, any MovieClip can make use of the Tween methods.
	 * @return Whether Tween was initialized in the current call. If Tween was already initialized, it will return {@code false}.
	 */
	public static function init(): Boolean
	{
		if (_instance != null) {
			return false;
		}
		_instance = new Tween();
	}


	/** The default ease equation. */
	public static function linearEase(t: Number, b: Number, c: Number, d: Number): Number
	{
		return c * t / d + b;
	}


	/**
	 * Tween the properties of a MovieClip specified in the {@code props} object.
	 * @param duration The duration of the tween in seconds
	 * @param props A list of properties in the MovieClip to tween
	 * @param ease An function to use to apply easing to the tween
	 */
	public function tweenTo(duration: Number, props: Object, ease: Function): Void
	{
		var startProps:Object = {};
		for (var n: String in props) {
			startProps[n] = this[n];
		}
		tween__start(duration, props, ease, startProps);
	}


	/**
	 * Tween the properties of a MovieClip from the properties specified in the {@code props} object to the current properties.
	 * @param duration The duration of the tween in seconds
	 * @param props A list of properties in the MovieClip to tween from
	 * @param ease An function to use to apply easing to the tween
	 */
	public function tweenFrom(duration: Number, props: Object, ease: Function): Void
	{
		// reverse the tween:
		var startProps: Object = {};
		for (var n: String in props) {
			startProps[n] = props[n];
			props[n] = this[n];
			this[n] = startProps[n];
		}
		tween__start(duration, props, ease, startProps);
	}


	/**
	 * End a tween immediately.
	 * @param jumpToEnd Determines if the tween sets all properties to their destination values, or leaves them at their current value.
	 */
	public function tweenEnd(jumpToEnd: Boolean): Void
	{
		if (jumpToEnd) {
			tween__to(1);
		}
		delete(tween__props);
		delete(tween__ease);
		delete(tween__startProps);
		delete(tween__startTime);
		delete(tween__duration);
		delete(onEnterFrame);
	}


	/* PRIVATE FUNCTIONS */

	private function tween__start(duration: Number, props: Object, ease: Function, startProps: Object): Void
	{
		tween__props = props;
		tween__startProps = startProps;
		tween__ease = ease != null ? ease : Tween.linearEase;
		tween__startTime = getTimer();
		tween__duration = duration;
		onEnterFrame = tween__run;
	}


	private function tween__to(position: Number): Void
	{
		var props: Object = tween__props;
		var startProps: Object = tween__startProps;
		for (var n: String in props) {
			this[n] = position * (props[n] - startProps[n]) + startProps[n];
		}
	}


	private function tween__run(): Void
	{
		var pos: Number = (getTimer() - tween__startTime) / (tween__duration * 1000);
		if (pos >= 1) {
			tweenEnd(true);
			if (this["onTweenComplete"]) {
				this["onTweenComplete"]();
			}
		} else {
			tween__to(tween__ease(pos, 0, 1, 1));
		}
	}
}
