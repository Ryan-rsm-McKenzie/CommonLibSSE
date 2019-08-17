/**
 *	The ItemSlot composes a button and a Drag target to add button-state functionality to and item with a dragTarget. This is useful when both clicking and dragging functionality is required.

 	@see InventorySlot For a non-button ItemSlot, see the InventorySlot.
 */


import gfx.controls.Button;
import gfx.controls.DragTarget;
import gfx.core.UIComponent;
import gfx.managers.DragManager;
import gfx.utils.Delegate;


[InspectableList("disabled", "visible", "toggle", "selected", "iconLinkage", "dragAcceptTypes", "enableInitCallback", "soundMap")]
class gfx.controls.ItemSlot extends UIComponent
{
	/* PUBLIC FUNCTIONS */

	/** The linkage of the draggable "icons" symbol in the library. */
	[Inspectable(defaultValue="icons")]
	public var iconLinkage: String = "icons";

	/** Mapping between events and sound process **/
	[Inspectable(type="Object", defaultValue="theme:default,focusIn:focusIn,drop:drop")]
	public var soundMap: Object = { theme: "default",focusIn: "focusIn", focusOut: "focusOut", drop: "drop"};


	/* PRIVATE VARIABLES */

	private var dragOrigin: Boolean = false;
	private var _data: Object;
	private var _toggle: Boolean = false;
	private var _selected: Boolean = false;
	private var _dragAcceptTypes: Array;


	/* STAGE ELEMENTS */

	/** The button element of the ItemSlot. */
	public var button: Button;
	/** The drag target element of the ItemSlot. */
	public var dragTarget: DragTarget;
	private var icons: MovieClip;
	private var qtyFld: TextField;
	private var originalAllowDropFunction: Function;


	/* INITIALIZATION */

	private function ItemSlot()
	{
		super();
	}


	/* PUBLIC FUNCTIONS */

	/**
	* The data object representing the item to be displayed. Item slot expects the object to have {@code type}, {@code quantity}. and {@code asset} properties. The {@code asset} property specifies the frame or label to display in the {@code icons} MovieClip.
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
	 * Indicates the types of data this ItemSlot will accept. These strings are matched against the "type" property of the data object passed to allowDrop. Setting dragAcceptTypes to ["*"] or null will cause it to accept all types.
	 *
	 * @param types An array of strings that will be matched against the data object "type" property.
	 */
	[Inspectable()]
	public function get dragAcceptTypes(): Array
	{
		return _dragAcceptTypes;
	}


	public function set dragAcceptTypes(value: Array): Void
	{
		_dragAcceptTypes = value;
		if (initialized) { dragTarget.dragAcceptTypes = value; }
	}


	/**
	 * An ItemSlot with a toggle value of {@code true} will change its selected state when it is "clicked".
	 */
	[Inspectable(defaultValue="false")]
	public function get toggle(): Boolean
	{
		return _toggle;
	}


	public function set toggle(value: Boolean): Void
	{
		_toggle = value;
		if (initialized) {
			button.toggle = value;
		}
	}


	/**
	 * Set the selected state of the ItemSlot. ItemSlots can have two sets of mouse states, a selected and unselected.  When an ItemSlot's {@code toggle} property is {@code true} the selected state will be changed when the item slot is clicked, however the selected state can be set using ActionScript even if the toggle property is false.
	 */
	[Inspectable(defaultValue="false")]
	public function get selected(): Boolean
	{
		return _selected;
	}


	public function set selected(value: Boolean): Void
	{
		_selected = value;
		if (initialized) { button.selected = value; }
	}


	/**
	 * Disable this component. Focus (along with keyboard events) and mouse events will be suppressed if disabled.
	 */
	[Inspectable(defaultValue="false", verbose="true")]
	public function get disabled(): Boolean
	{
		return super.disabled;
	}


	public function set disabled(value: Boolean): Void
	{
		super.disabled = value;
		if (initialized) {
			button.disabled = _disabled;
		}
	}


	/* PRIVATE FUNCTIONS */

	private function configUI(): Void
	{
		super.configUI();
		DragManager.instance.addEventListener("dragEnd", this, "dragEnd");
		button.addEventListener("press", this, "handlePress");
		button.addEventListener("click", this, "handleRelease");
		button.addEventListener("rollOver", this, "propagateEvent");
		button.addEventListener("rollOut", this, "propagateEvent");
		button.addEventListener("dragOver", this, "propagateEvent");
		button.addEventListener("dragOut", this, "propagateEvent");
		button.addEventListener("select", this, "propagateEvent");
		dragTarget.addEventListener("drop", this, "propagateEvent");

		dragTarget.acceptDrop = Delegate.create(this, acceptDrop);
		originalAllowDropFunction = dragTarget.allowDrop;
		dragTarget.allowDrop = Delegate.create(this, allowDrop);

		// If we set these in the setter before the onLoad, they will fail.
		button.toggle = _toggle;
		button.selected = _selected;
		button.disabled = _disabled;
		dragTarget.dragAcceptTypes = _dragAcceptTypes;

	}


	// Button or DropTarget events that need to bubble out of ItemSlot:
	private function propagateEvent(event: Object): Void
	{
		// No button events if there is no data in the slot
		if (!_data && event.target == button) {
			return;
		}

		// Substitute the event target
		event.target = this;
		dispatchEventAndSound(event);
	}


	// Start dragging onMouseMove:
	private function handlePress(event: Object): Void
	{
		if (data == null) {
			return;
		}

        button["_xpress"] = button._xmouse;
        button["_ypress"] = button._ymouse;
		onMouseMove = beginDrag;
		propagateEvent(event);
	}


	private function handleRelease(event: Object): Void
	{
		delete onMouseMove;
		propagateEvent(event);
	}


	private function beginDrag(): Void
	{
		delete onMouseMove;
		dragOrigin = true;
		icons._alpha = 20;
		DragManager.instance.startDrag(button, iconLinkage, data, this, icons).gotoAndStop(data.asset);
		_data = null;
	}


	private function update(): Void
	{
		icons.gotoAndStop(_data == null ? 1 : _data.asset);
		qtyFld.text = _data.quantity == null ? "" : _data.quantity;
	}


	// Overrides the acceptDrop in the dragTarget, but runs in the ItemSlot scope
	private function acceptDrop(data: Object): Void {
		if (_data != null) {
			DragManager.instance.relatedObject.data = _data;
		}
		this.data = data;
		dispatchEventAndSound({type: "drop", data: data});
	}


	// Check if the drop is acceptable.
	private function allowDrop(data: Object): Boolean
	{
		return (originalAllowDropFunction.call(dragTarget, data) && (_data == data || !DragManager.instance.inDrag || DragManager.instance.relatedObject.allowDrop(_data)));
	}


	// Restores the data.
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
	}
}
