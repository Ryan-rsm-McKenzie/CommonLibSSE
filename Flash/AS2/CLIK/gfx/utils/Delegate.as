/**
 * The Delegate helps resolve function callbacks when no scope can be passed in. Currently, all component callbacks include a scope, so this class may be deprecated.
 */


class gfx.utils.Delegate extends Object
{
	/* PUBLIC FUNCTIONS */

	/**
	 * Creates a function wrapper for the original function so that it runs in the provided context.
	 * @parameter obj Context in which to run the function.
	 * @parameter func Function to run.
	 * @return A wrapper function that when called will make the appropriate scoped callback.
	*/
	public static function create(obj: Object, func: Function): Function
	{
		var f = function() {
			var target = arguments.callee.target;
			var _func = arguments.callee.func;
			return _func.apply(target, arguments);
		};
		f.target = obj;
		f.func = func;
		return f;
	}
}
