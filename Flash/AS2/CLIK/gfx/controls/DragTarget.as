/**
 *  Acts as a target for drag operations initiated with DragManager. The drag target will hide itself until a drag operation begins with a data object that it can accept, at which point it will show itself.

	While the usefulness of this class is limited, it provides a simple example for working with DragManager, and is the basis for the InventorySlot and ItemSlot components.
 */


import gfx.core.UIComponent;
import gfx.managers.DragManager;


[InspectableList("disabled", "visible", "_dragAcceptTypes", "enableInitCallback")]
class gfx.controls.DragTarget extends UIComponent
{
	/* PRIVATE VARIABLES */

    [Inspectable(type="Array", name="dragAcceptTypes")]
	private var _dragAcceptTypes: Array;
	private var dragAcceptTypeHash: Object;


	/* INITIALIZATION */

	/**
	 * The constructor is called when a DragTarget is instantiated on stage or by using {@code attachMovie()} in ActionScript. This component can <b>not</b> be instantiated using {@code new} syntax. When creating new components that extend DragTarget, ensure that a {@code super()} call is made first in the constructor.
	 */
	public function DragTarget()
	{
		super();
		_visible = false;
		if (_dragAcceptTypes != null) {
			dragAcceptTypes = _dragAcceptTypes;
			delete(_dragAcceptTypes);
		}
	}


	/* PUBLIC FUNCTIONS */

	/**
	 * Indicates the types of data this DragTarget will accept. These strings are matched against the "type" property of the data object passed to allowDrop. Setting dragAcceptTypes to ["*"] or null will cause it to accept all types.
	 *
	 * @param types An array of strings that will be matched against the data object "type" property.
	 */
	public function get dragAcceptTypes(): Array
	{
		var arr: Array = [];
		for (var n: String in dragAcceptTypeHash) {
			arr.push(n);
		}
		return arr;
	}


	public function set dragAcceptTypes(types: Array): Void
	{
		if (types == null || types.length < 1) {
			dragAcceptTypeHash = null;
			return;
		}

		dragAcceptTypeHash = {};

		for (var i: Number = 0; i < types.length; i++) {
			dragAcceptTypeHash[String(types[i])] = true;
		}
	}


	/**
	 * Returns true if the DragTarget instance will accept the specified data object. In this case it matches the data object's "type" property against the types specified in dragAcceptTypes, but this method can easily be overridden in subclasses to provide more advanced filtering.
	 *
	 * @param data The data object to check.
	 */
	public function allowDrop(data: Object): Boolean
	{
		if (data.bounds != undefined && dragAcceptTypeHash[data.type] && !boundsCheck(data)) {
			return false;
		}

		return (data == null || dragAcceptTypeHash == null || dragAcceptTypeHash[data.type] || dragAcceptTypeHash["*"]);
	}


	/**
	 * The DragManager has dropped data on to this component. It is public so that is can be externally overridden. See {@link ItemSlot}.
	 * @param data The data that is being dropped on the component.
	 */
	public function acceptDrop(data: Object): Void
	{
		dispatchEventAndSound({type:"drop", data:data});
	}


	/* PRIVATE FUNCTIONS */

	private function configUI(): Void
	{
		super.configUI();
		DragManager.instance.addEventListener("dragBegin", this, "dragBegin");
		DragManager.instance.addEventListener("dragEnd", this, "dragEnd");
		onRollOver = onDragOver = handleRollOver;
		onRollOut = onDragOut = handleRollOut;
	}


	private function dragBegin(event: Object): Void {
		if (!allowDrop(event.data)) {
			return;
		}

		trackAsMenu = _visible = true;
		gotoAndStop("up");
		gotoAndStop("dragUp");
	}


	private function dragEnd(event: Object): Void
	{
		trackAsMenu = _visible = false;
		gotoAndStop("dragUp");
		gotoAndStop("up");
		if (event.dropTarget == this && !event.cancelled) {
			acceptDrop(event.data);
		}
	}


	private function boundsCheck(data: Object): Boolean
	{
		var globalXY: Object = {x: 0, y: 0};
		this.localToGlobal(globalXY);
		var targetBounds: Object = data.bounds;
		if ((targetBounds.left > (globalXY.x + _width)) ||
		    (targetBounds.top > (globalXY.y + _height)) ||
		    (targetBounds.right < globalXY.x) ||
		    (targetBounds.bottom < globalXY.y)) {
				return false;
			}

		return true;
	}


	private function handleRollOver(controllerIdx: Number): Void
	{
		gotoAndPlay("over");
		if (trackAsMenu) {
			gotoAndPlay("dragOver");
		}
		DragManager.instance.dropTarget = this;
	}


	private function handleRollOut(controllerIdx: Number): Void
	{
		gotoAndPlay("up");
		gotoAndPlay("out");
		if (trackAsMenu) {
			gotoAndStop("dragUp");
			gotoAndPlay("dragOut");
			DragManager.instance.dropTarget = null;
		}
	}
}
