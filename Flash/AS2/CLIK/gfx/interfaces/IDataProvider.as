/**
 * Defines the methods that all DataProviders should expose. Note that this interface is not implemented by the existing components, and does not need to be implemented, it is just a reference. There are additional properties and getter/setters defined in the interface, which are commented out for compiler compatibility.
 */


interface gfx.interfaces.IDataProvider
{
	/* PUBLIC FUNCTIONS */

	// public function get length(): Number;


	/**
	 * Request an item from the given index. Although this method returns an object, the components that use it all expect the item to be returned using the scope/callBack to support delayed data results when dealing with the Game Engine.
	 * @param index The index in the DataProvider
	 * @param scope The scope for the callBack
	 * @param callBack The callBack function name
	 * @returns The requested item, if it is immediately available. Note that components will not use the return value.
	 */
	public function requestItemAt(index: Number, scope: Object, callBack: String): Object;


	/**
	 * Request an item range from the given index. Although this method returns an object, the components that use it all expect the item to be returned using the scope/callBack to support delayed data results when dealing with the Game Engine.
	 * @param index The start index of the requested item range
	 * @param endIndex The end index of the requested item range
	 * @param scope The scope for the callBack
	 * @param callBack The callBack function name
	 * @returns The items in the range, if they are immediately available. Note that components will not use the return value.
	 */
	public function requestItemRange(startIndex: Number, endIndex: Number, scope: Object, callBack: String): Array;


	/**
	 * Get the index of an item in the DataProvider. Although this method returns an number, the components that use it all expect the item to be returned using the scope/callBack to support delayed data results when dealing with the Game Engine.
	 * @param value The item in the DataProvider
	 * @param scope The scope for the callBack
	 * @param callBack The callBack function name
	 * @returns The index of the item in the DataProvider, or -1 if not found.
	 */
	public function indexOf(item: Object, scope: Object, callBack: String): Number;


	/**
	 * The dataProvider has changed.
	 * @param length the current length of the data set, which needs to be kept up to date.
	 */
	public function invalidate(length: Number): Void;
}
