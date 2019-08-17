/**
 *	Displays an inventory "item" with quantity, and uses DragManager to allow dragging and dropping items between InventorySlots with compatible dragAcceptTypes.

 	This class does not provide for other user interaction with the inventory, such as clicking. @see ItemSlot For button like interaction, see the ItemSlot.

 	This component uses an icons movieclip to display items, but it could be extended to support external images or texture substitution.
 */


import gfx.controls.DragTarget;
import gfx.managers.DragManager;


class gfx.controls.InventorySlot extends DragTarget
{
	/* PRIVATE VARIABLES */

	private var _data: Object;
	private var dragOrigin: Boolean=false;


	/* STAGE ELEMENTS */

	private var icons: MovieClip;
	private var qtyFld: TextField;


	/* INITIALIZATION */

	/**
	 * The constructor is called when a InventorySlot or a sub-class of InventorySlot is instantiated on stage or by using {@code attachMovie()} in ActionScript. This component can <b>not</b> be instantiated using {@code new} syntax. When creating new components that extend InventorySlot, ensure that a {@code super()} call is made first in the constructor.
	 */
	public function InventorySlot()
	{
		super();
		_visible = true;
	}


	/* PUBLIC FUNCTIONS */

	/**
	* The data object representing the item to be displayed. Inventory slot expects the object to have {@code type}, {@code quantity}. and {@code asset} properties. The {@code asset} property specifies the frame or label to display in the {@code icons} MovieClip.
	**/
	public function get data(): Object
	{
		return _data;
	}


	public function set data(value: Object): Void
	{
		_data = value;
		update();
	}


	/**
	 * Determines if the DragTarget instance will accept the specified data object. Similar to DragTarget.allowDrop it matches the data object's "type" property against the types specified in dragAcceptTypes, but also adds a check to ensure that it will be able to swap data with the origin
	 * @param data The data object to check.
	 * @return Whether the drop was accepted ({@code true}) or not ({@code false}).
	 */
	public function allowDrop(data: Object): Boolean
	{
		// this includes a check to ensure we can swap data with the origin:
		return super.allowDrop(data) && (_data == data || !DragManager.instance.inDrag || DragManager.instance.relatedObject.allowDrop(_data));
	}


	/* PRIVATE FUNCTIONS */

	private function update(): Void
	{
		icons.gotoAndStop(_data == null ? 1 : _data.asset);
		qtyFld.text = (_data == null || _data.quantity == null ? "" : _data.quantity);
	}


	private function onPress(controllerIdx: Number): Void
	{
		if (_data == null) {
			return;
		}

		Selection.setFocus(this, controllerIdx);
		icons._alpha = 20;
		dragOrigin = true;
		DragManager.instance.startDrag(this, "icons", data, this, icons).gotoAndStop(_data.asset);
		_data = null;
	}


	private function acceptDrop(data: Object): Void
	{
		if (_data != null) {
			DragManager.instance.relatedObject.data = _data;
		}
		this.data = data;
		super.acceptDrop(data);
	}


	private function dragEnd(event: Object): Void
	{
		if (dragOrigin) {
			if (event.dropTarget != null && !event.cancelled) {
				data = _data;
			} else {
				data = event.data;
			}
			icons._alpha = 100;
			dragOrigin = false;
		}
		super.dragEnd(event);
		_visible = true;
	}
}
