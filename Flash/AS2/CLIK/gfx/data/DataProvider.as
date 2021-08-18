/**
 * An Array-based DataProvider.  The DataProvider can be extended, or existing Arrays can be made into a DataProvider using the static {@link DataProvider.initialize}. {@code DataProvider.initialize()} adds the required interface for data components in the Scaleform component framework, including a model for handling asynchronous responses, although that is not necessary in this particular implementation.
 */


import gfx.events.EventDispatcher;


class gfx.data.DataProvider extends Array
{
	/* PUBLIC VARIABLES */

	/** Determine if an Object is a DataProvider, either by extension, or using {@link DataProvider.initialize()} */
	public var isDataProvider: Boolean = true;
	/** Mixed in from {@link EventDispatcher#addEventListener EventDispatcher} */
	public var addEventListener: Function;
	/** Mixed in from {@link EventDispatcher#removeEventListener EventDispatcher} */
	public var removeEventListener: Function;
	/** Mixed in from {@link EventDispatcher#hasEventListener EventDispatcher} */
	public var hasEventListener: Function;
	/** Mixed in from {@link EventDispatcher#removeAllEventListeners EventDispatcher} */
	public var removeAllEventListeners: Function;


	/* PRIVATE VARIABLES */

	private static var instance: DataProvider;

	/** Mixed in from {@link EventDispatcher#cleanUpEvents EventDispatcher} */
	private var cleanUpEvents: Function;
	/** Mixed in from {@link EventDispatcher#dispatchEvent EventDispatcher} */
	private var dispatchEvent: Function;


	/* INITIALIZATION */

	/**
	 * Create a new DataProvider. Typically, instead of instantiating a DataProvider, an Array can simply be passed into a component that uses a DataProvider, and it will be converted using the {@code DataProvider.initialize()} static method. The DataProvider can be used in place of an Array though. Note that you can not pass arguments to the DataProvider constructor.
	 */
	public function DataProvider(total: Number)
	{
		super();
		EventDispatcher.initialize(this);
	}


	/* PUBLIC FUNCTIONS */

	/**
	 * Mix-in the DataProvider functionality to an Array.
	 */
	public static function initialize(data: Object): Void
	{
		if (instance == undefined) {
			instance = new DataProvider();
		}

		var members: Array = ["indexOf", "requestItemAt", "requestItemRange", "invalidate", "toString", "cleanUp", "isDataProvider"];
		for (var i: Number = 0; i < members.length; i++) {
			data[members[i]] = instance[members[i]];
		}

		EventDispatcher.initialize(data);

		// Hide the DataProvider methods from introspection, but also hide the EventDispatcher methods, which doesn't happen by default.
		_global.ASSetPropFlags(data, members, 1);
		_global.ASSetPropFlags(data, "addEventListener,removeEventListener,hasEventListener,removeAllEventListeners,dispatchEvent,dispatchQueue,cleanUpEvents", 1);
	}


	/**
	 * Get the index of an item in the DataProvider.
	 * @param value The item in the DataProvider.
	 * @returns The index of the item in the DataProvider, or -1 if not found.
	 */
	public function indexOf(value: Object, scope: Object, callBack:String): Number
	{
		var i: Number = 0;
		for (i = 0; i < length; i++) {
			if (this[i] == value) {
				break;
			}
		}

		var index: Number = i == length ? -1 : i;
		if (callBack) {
			scope[callBack].call(scope, index);
		}

		return index;
	}


	/**
	 * Request an item at a specified index. Items will be passed back into the requesting object using a callBack.
	 * @param index The index of the requested item in the DataProvider.
	 * @param scope The scope of the requesting object.
	 * @param callBack The function name of the callBack.
	 * @returns The requested item, if it is immediately available. Note that components will not use the return value.
	 */
	public function requestItemAt(index: Number, scope: Object, callBack: String): Object
	{
		var item: Object = this[index];
		if (callBack) {
			scope[callBack].call(scope, item);
		}
		return item;
	}


	/**
	 * Get a range of items between two specified indexes inclusive of the items at {@code beginIndex} and {@code endIndex}.
	 * @param startIndex The start index of the range of requested items in the DataProvider.
	 * @param endIndex The end index of the range of requested items in the DataProvider.
	 * @param scope The scope of the requesting object.
	 * @param callBack The function name of the callBack.
	 * @returns The items in the range, if they are immediately available. Note that components will not use the return value.
	 */
	public function requestItemRange(startIndex: Number, endIndex: Number, scope: Object, callBack: String): Array
	{
		var items: Array = slice(startIndex, endIndex+1);
		if (callBack) {
			scope[callBack].call(scope, items);
		}
		return items;
	}


	/**
	 * The data or length of the DataProvider has changed.  This method dispatches a {@code change} event, which notifies the component(s) displaying the data that they may need to update. This method <i>expects</i> a {@code length} parameter to be passed in when using an asynchronous approach where only requested data is loaded into the DataProvider.
	 * @param length The current length of the data set, which needs to be kept up to date.
	 */
	public function invalidate(length: Number): Void
	{
		// The length parameter is in the Array DataProvider for compatibility purposes, and is not used.
		dispatchEvent( {type: "change"} );
	}


	/**
	 * Clean up callBacks and other data references in the DataProvider. No clean up is required in this simple implementation beyond cleaning up event queues.
	 */
	public function cleanUp(): Void
	{
		splice(0,length);
		cleanUpEvents();
	}


	/** @exclude */
	public function toString(): String
	{
		return "[DataProvider (" + length + ")]";
	}
}
