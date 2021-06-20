/**
 * Singleton class providing methods to initiate and manage drag and drop operations. Used by DragTarget, InventorySlot, and ItemSlot components.

  <b>Events</b><ul>
  	<li><i>dragEnd</i>: Dispatched when a drag operation ends, either because the mouse was released, or because cancelDrag was called. The event object includes the following properties:<ul>
  		<li><i>cancelled</i>: indicates whether the drag was ended by calling cancelDrag</li>
  		<li><i>data</i>: the data associated with the drag operation</li>
  		<li><i>dropTarget</i>: the current drop target (ie. what is currently dragged over)</li></ul></li>
 	<li><i>dragBegin</i>: Dispatched when a drag operation begins. Includes the following properties:<ul>
  		<li><i>data</i>: the data associated with the drag operation</li></ul></li></ul>
 */


import gfx.events.EventDispatcher;
import gfx.managers.InputDelegate;
import gfx.managers.PopUpManager;
import gfx.utils.Delegate;


class gfx.managers.DragManager extends EventDispatcher
{
	/* PUBLIC VARIABLES */

	/**
	 * Indicates whether the target will be removed when the drag finishes. This is automatically set to true when using a linkageID for the target parameter of a startDrag operation, and false otherwise. You can override this default value after calling startDrag. For example, you may want to do this so that you can animate the avatar back into position.
	 */
	public var removeTarget: Boolean = false;

	/**
	 * Specifies the x offset of the drag target from the cursor position. This is automatically set to true when calling startDrag. You can override this default value after calling startDrag. You may wish to call update() after setting this value to immediately update the target's position.
	 */
	public var dragOffsetX: Number=0;

	/**
	 * Specifies the y offset of the drag target from the cursor position. This is automatically set to true when calling startDrag. You can override this default value after calling startDrag. You may wish to call update() after setting this value to immediately update the target's position.
	 */
	public var dragOffsetY: Number = 0;

	/**
	 * Indicates the key code that will cancel a drag. Set to 0 to disable.
	 */
	public var cancelKeyCode: Number = Key.ESCAPE;

	/**
	 * Indicates the current drop target for the drag.
	 */
	public var dropTarget: Object = null;

	/**
	 * Arbitrary data to associate with this drag operation. This is usually used to reference the object the drag originated from.
	 */
	public var relatedObject: Object;


	/* PRIVATE VARIABLES */

	private static var _instance: DragManager;

	private var _inDrag: Boolean = false;
	private var _data: Object;
	private var _target: MovieClip;
	private var eventProvider: MovieClip;
	private var dragProps: Object;
	private var pressOrigin: MovieClip;
	private var pressOriginTrackAsMenu: Boolean;

	private var leftBound: Number;
	private var rightBound: Number;
	private var topBound: Number;
	private var bottomBound: Number;


	/* INITIALIZATION */

	/**
	 * Create a new DragManager instance. This method should only be called internally by the DragManager class, as the implementation is a Singleton.
	 */
	private function DragManager()
	{
		InputDelegate.instance.addEventListener("input", this, "handleInput");
		eventProvider = _root;
	}


	/* PUBLIC FUNCTIONS */

	/**
	 * Returns a reference to the DragManager instance.
	 */
	public static function get instance(): DragManager
	{
		if (_instance == null) {
			_instance = new DragManager();
		}

		return _instance;
	}


	/** Indicates whether there is an active drag operation. */
	public function get inDrag(): Boolean
	{
		return _inDrag;
	}


	/** Returns the data associated with the currently active drag operation, or null if there is not an active drag. */
	public function get data(): Object
	{
		return _data;
	}


	/** Returns the target (avatar) of the currently active drag operation, or null if there is not an active drag. */
	public function get target(): MovieClip
	{
		return _target;
	}


	/**
	 * Starts a drag operation. This will automatically call initiateDrag to notify any drag listeners.
	 *
	 * @param pressOrigin The MovieClip that was pressed to begin this drag. In order for drags to work correctly, the press origin must have its trackAsMenu property set to true. This optional parameter allows DragManager to set this property, and revert it when the drag ends.
	 * @param avatar A movie clip reference or a linkage string to use as the avatar to drag. If a string is specified DragManager will attempt to instantiate the avatar in the reserved clip on the _root so that it appears over top of all UI elements. If null is specified, no avatar will be used.
	 * @param data Data representing the object being dragged. This will be included with all events associated with this drag, and is accessible during the drag via the .data property.
	 * @param relatedObject Arbitrary data to associate with this drag operation. This is usually used to reference the object the drag originated from.
	 * @param alignmentTarget A MovieClip to base initial position on. For example passing in the icon instance that was clicked to initiate the drag would position the avatar in the same position.
	 * @param lockCenter Locks the drag target's origin to the cursor position.
	 * @param bounds (optional) Object containing drag constraints for the target using in the target's parent's coordinates. Can contain "left", "right", "bottom", and "top" properties for drag bounds. If any bound property is undefined, it will default to have no boundary.
	 *
	 * @returns The target clip that will be dragged, this is either the reference passed in as the target parameter, the clip that was instantiated from the specified linkage id, or null.
	 */
	public function startDrag(pressOrigin: MovieClip, avatar: Object, data: Object, relatedObject: Object, alignmentTarget: MovieClip, lockCenter: Boolean, bounds: Object): MovieClip
	{
		if (pressOrigin == null) {
			return undefined;
		}

		removeTarget = false;
		var t: MovieClip;

		if (avatar instanceof MovieClip) {
			t = MovieClip(avatar);
		} else if (avatar == null) {
			t = null;
		} else {
			t = PopUpManager.createPopUp(pressOrigin, String(avatar), {_x:pressOrigin._xmouse, _y:pressOrigin._ymouse}, pressOrigin);
			if (t != null) {
				removeTarget = true;
			}

			t._xscale = pressOrigin._xscale;
			t._yscale = pressOrigin._yscale;
		}

		_target = t;

		if (alignmentTarget != null && alignmentTarget != t && t != null) {
			var pt: Object = {x: 0, y: 0};
			alignmentTarget.localToGlobal(pt);
			t._parent.globalToLocal(pt);
			t._x = pt.x;
			t._y = pt.y;
		}

		//Logic to limit the box's movement using coordinates defined in parameters.
		if (bounds != undefined) {
			leftBound = (bounds.left != undefined) ? bounds.left : -Number.MAX_VALUE;
			topBound =(bounds.top != undefined) ?  bounds.top : -Number.MAX_VALUE;
			rightBound = (bounds.right != undefined) ? bounds.right : Number.MAX_VALUE;
			bottomBound = (bounds.bottom != undefined) ? bounds.bottom : Number.MAX_VALUE;

			var globalXY: Object = {x: 0, y: 0};
			_target._parent.localToGlobal(globalXY);
			var db: Object = {};
			db.left = leftBound + globalXY.x;
			db.right = rightBound + globalXY.x;
			db.bottom = bottomBound + globalXY.y;
			db.top = topBound + globalXY.y;
			data.bounds = db;
		}

		initiateDrag(data, relatedObject);

		if (pressOrigin != null) {
			this.pressOrigin = pressOrigin;
			pressOriginTrackAsMenu = pressOrigin.trackAsMenu;
			pressOrigin.trackAsMenu = true;
		}

		if (t != null) {
			// Use the pressOrigin's _xpress/_ypress properties if they exist. These properties should be set during an onMouseDown event.
			// There is a chance that if we use t._xmouse/t._ymouse the offset will be incorrect as startDrag may fire after a MouseMove
			// that invalidated the origin's coordinates. Use t._xmouse/t._ymouse as defaults / to support existing implementations.
			var xcoord: Number = (pressOrigin["_xpress"] != undefined ? pressOrigin["_xpress"] : t._xmouse);
			var ycoord: Number = (pressOrigin["_ypress"] != undefined ? pressOrigin["_ypress"] : t._ymouse);
			dragOffsetX = (lockCenter) ? 0 : (-xcoord * t._xscale / 100 );
			dragOffsetY = (lockCenter) ? 0 : (-ycoord * t._yscale / 100 );
		}

		var _this: DragManager = this;
		eventProvider.onMouseMove = Delegate.create(this, doDrag);
		eventProvider.onMouseUp = Delegate.create(this, stopDrag);

		return _target;
	}


	/**
	 * Stops an active drag operation, and dispatches the "endDrag" event with the cancelled flag set to false. This method can be used with drag operations initiated by both startDrag and initiateDrag.
	 */
	public function stopDrag(): Void
	{
		finishDrag(false);
	}


	/**
	 * Sets the data and inDrag properties, and dispatches the "dragBegin" event. This method is useful for if you want to utilize custom drag logic, but still take advantage of DragManager's events.
	 *
	 * @param data Data representing the object being dragged. This will be included with all events associated with this drag, and is accessible during the drag via the .data property.
	 * @param relatedObject Arbitrary data to associate with this drag operation. This is usually used to reference the object the drag originated from.
	 */
	public function initiateDrag(data: Object, relatedObject: Object): Void
	{
		_inDrag = true;
		_data = data;
		this.relatedObject = relatedObject;
		dropTarget = null;
		dispatchEvent( { type: "dragBegin", data: data } );
	}


	/**
	 * Stops an active drag operation, and dispatches the "dragEnd" event with the cancelled flag set to true. The cancel flag indicates to listeners that they should not act on the drop.
	 */
	public function cancelDrag(): Void
	{
		finishDrag(true);
	}


	/**
	 * Repositions the drag target relative to the cursor position. Useful if you manually adjust the dragOffset properties and want to immediately update the target position.
	 */
	public function update(): Void
	{
		if (inDrag) {
			doDrag();
		}
	}


	/* PRIVATE FUNCTIONS */

	private function doDrag(): Void
	{
		if (_target != null) {
			var xTarget: Number = _target._parent._xmouse + dragOffsetX;
			var yTarget: Number = _target._parent._ymouse + dragOffsetY;

			if (leftBound != undefined) {
				if (xTarget < leftBound) {
					xTarget = leftBound;
				} else if (xTarget  > (rightBound - _target._width)) {
					xTarget = rightBound - _target._width;
				}

				if (yTarget < topBound) {
					yTarget = topBound;
				} else if (yTarget > (bottomBound - _target._height)) {
					yTarget = bottomBound - _target._height;
				}
			}

			_target._x = xTarget;
			_target._y = yTarget;
		}
	}


	private function finishDrag(cancelled: Boolean): Void
	{
		if (!_inDrag) {
			return;
		}

		if (pressOrigin != null) {
			pressOrigin.trackAsMenu = pressOriginTrackAsMenu;
		}

		dispatchEvent( {type: "dragEnd", cancelled: cancelled, data: _data, dropTarget: dropTarget} );
		cleanUp();
	}


	private function cleanUp(): Void
	{
		dropTarget = null;
		if (removeTarget && _target != null) {
			_target.removeMovieClip();
		}

		_target = null;
		_data = null;
		delete(eventProvider.onMouseMove);
		delete(eventProvider.onMouseUp);
		dragOffsetX = dragOffsetY = 0;
		_inDrag = false;
	}


	private function handleInput(event: Object): Void
	{
		if (event.details.code == cancelKeyCode) {
			cancelDrag();
		}
	}
}
