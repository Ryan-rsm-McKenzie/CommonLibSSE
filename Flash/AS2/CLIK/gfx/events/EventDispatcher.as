/**
 * The EventDispatcher manages the notification mechanism used throughout the components. EventDispatcher can be inherited from, or mixed in to add notification capabilities to a class.  The Scaleform EventDispatcher mirrors the API in the Macromedia AS2 EventDispatcher, and the common methods found in the AS3 EventDispatcher, but also includes some enhancements, such as the {@link #removeAllEventListeners()} method.
 */


class gfx.events.EventDispatcher
{
	/* PRIVATE VARIABLES */

	private static var _instance: EventDispatcher;
	private var _listeners: Object;


	/* INITIALIZATION */

	/**
	 * Create a new EventDispatcher, which is an Object capable of broadcasting events. It is more likely that the EventDispatcher will be extended, or the static {@code EventDispatcher.initialize()} method will be used to add event-broadcasting capabilities to a component.
	 */
	public function EventDispatcher()
	{}


	/* PUBLIC FUNCTIONS */

	/**
	 * Initialize a component or class, adding Event Dispatching capabilities to it.
	 */
	public static function initialize(target: Object): Void
	{
		if (_instance == undefined) {
			_instance = new EventDispatcher();
		}

		target.dispatchEvent = _instance.dispatchEvent;
		target.dispatchQueue = _instance.dispatchQueue;
		target.hasEventListener = _instance.hasEventListener;
		target.addEventListener = _instance.addEventListener;
		target.removeEventListener = _instance.removeEventListener;
		target.removeAllEventListeners = _instance.removeAllEventListeners;
		target.cleanUpEvents = _instance.cleanUpEvents;
		_global.ASSetPropFlags(target, "dispatchQueue", 1); // Hide the dispatchQueue property from introspection.
	}


	/**
	 * Subscribe a listener to an event.
	 * @param event The type of event.
	 * @param scope The scope of the listener.
	 * @param callBack The function name to call on the listener.
	 */
	public function addEventListener(event: String, scope: Object, callBack: String): Void
	{
		if (_listeners == undefined) {
			_listeners = {};
			_global.ASSetPropFlags(this, "_listeners", 1); // Hide the _listeners property from introspection.
		}

		var listeners: Array = _listeners[event];
		if (listeners == undefined) {
			_listeners[event] = listeners = [];
		}

		if (EventDispatcher.indexOfListener(listeners, scope, callBack) == -1) {
			listeners.push({listenerObject: scope, listenerFunction: callBack});
		}
	}


	/**
	 * Unsubscribe a listener from an event.
	 * @param event The type of event.
	 * @param scope The scope of the listener.
	 * @param callBack The function name to call on the listener.
	 */
	public function removeEventListener(event: String, scope: Object, callBack: String): Void
	{
		var listeners = _listeners[event];
		if (listeners == undefined) {
			return;
		}

		var index: Number = EventDispatcher.indexOfListener(listeners, scope, callBack);
		if (index != -1) {
			listeners.splice(index, 1);
		}
	}


	/**
	 * Dispatch an event to all listeners.
	 * @param event The event object to dispatch to the listeners.
	 */
	public function dispatchEvent(event: Object): Void
	{
		if (event.type == "all") {
			return;
		}

		if (event.target == undefined) {
			event.target = this;
		}

		dispatchQueue(this, event);
	}


	/**
	 * Check if a listener has been added for a specific event type.
	 * @param event The event type
	 * @param scope The scope of the listener.
	 * @param callBack The function name to call on the listener.
	 * @return If the component has a specific listener
	 */
	public function hasEventListener(event: String): Boolean
	{
		return _listeners[event] != null && _listeners[event].length > 0;
	}


	/**
	 * Unsubscribe all listeners from a specific event, or all events.
	 * @param event The type of event.
	 */
	public function removeAllEventListeners(event: String): Void
	{
		if (event == undefined) {
			delete(_listeners);
		} else {
			delete(_listeners[event]);
		}
	}


	/* PRIVATE FUNCTIONS */

	private static function indexOfListener(listeners: Array, scope: Object, callBack: String): Number
	{
		var l: Number = listeners.length;
		var i: Number = -1;
		while (++i < l) {
			var listener: Object = listeners[i];
			if (listener.listenerObject == scope && listener.listenerFunction == callBack) {
				return i;
			}
		}
		return -1;
	}


	private function dispatchQueue(dispatch: Object, event: Object): Void
	{
		var listeners: Array = dispatch._listeners[event.type];
		if (listeners != undefined) {
			EventDispatcher.$dispatchEvent(dispatch, listeners, event);
		}

		listeners = dispatch._listeners["all"];
		if (listeners != undefined) {
			EventDispatcher.$dispatchEvent(dispatch, listeners, event);
		}
	}


	private static function $dispatchEvent(dispatch: Object, listeners: Array, event: Object)
	{
		var l: Number = listeners.length;
		for (var i: Number = 0; i < l; i++) {
			var listenerObject: Object = listeners[i].listenerObject;
			var listenerType: String = typeof(listenerObject);
			var listenerFunction: String = listeners[i].listenerFunction;

			if (listenerFunction == undefined) {
				listenerFunction = event.type;
			}

			if (listenerType != "function") {
				if (listenerObject.handleEvent != undefined && listenerFunction == undefined) {
					listenerObject.handleEvent(event);
				} else {
					listenerObject[listenerFunction](event);
				}
			} else if (listenerObject[listenerFunction] != null) { // class
				listenerObject[listenerFunction](event);
			} else { // function
				listenerObject.apply(dispatch, [event]);
			}
		}
	}


	/**
	 * Clean up the EventDispatcher instance. The cleanUp method is not used to clean up EventDispatcher sub-classes, and is not mixed-in to components when the static initialize() method is used. Use {@link cleanUpEvents()} instead.
	 */
	public function cleanUp(): Void
	{
		cleanUpEvents();
	}


	/**
	 * Clean up the mixed-in EventDispatcher methods in a component.
	 */
	private function cleanUpEvents(): Void
	{
		removeAllEventListeners();
	}
}
