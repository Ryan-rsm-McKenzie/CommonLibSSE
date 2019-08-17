/**
 * This class defines all the event types as constants to enable developers to add type-safe events to the components. The component framework does not use the constants, as the string equivalents are slightly faster to use, and it has been tested extensively. It is recommended that developers using the component framework use the EventType class to listen for events.
 *
 * {@code component.addEventListener(EventTypes.CLICK, this, "handleMouseClick");}
 */


class gfx.events.EventTypes
{
	// Mouse Events

	/** The mouse has been clicked on a button-type component. Click events are also dispatched when an "enter" navigation equivalent has been input. */
	public static var CLICK: String = "click";
	/** The mouse has been double-clicked on a button-type component. */
	public static var DOUBLE_CLICK: String = "doubleClick";
	/** The mouse has been rolled over a button-type component. */
	public static var ROLL_OVER: String = "rollOver";
	/** The mouse has been pressed on a button-type component. */
	public static var PRESS: String = "press";
	/** The mouse has been rolled out of a button-type component. */
	public static var ROLL_OUT: String = "rollOut";
	/** The mouse has been depressed outside of a button-type component. */
	public static var RELEASE_OUTSIDE: String = "releaseOutside";
	/** The mouse has been clicked on a button-type component inside of a composite component, such as {@link ScrollingList}. */
	public static var ITEM_CLICK: String = "itemClick";
	/** The mouse has been double-clicked on a button-type component inside of a composite component, such as {@link ScrollingList}. */
	public static var ITEM_DOUBLE_CLICK: String = "itemDoubleClick";
	/** The mouse has been rolled over a button-type component inside of a composite component, such as {@link ScrollingList}. */
	public static var ITEM_ROLL_OVER: String = "itemRollOver";
	/** The mouse has been pressed on button-type component inside of a composite component, such as {@link ScrollingList}. */
	public static var ITEM_PRESS: String = "itemPress";
	/** The mouse has been rolled out of a button-type component inside of a composite component, such as {@link ScrollingList}. */
	public static var ITEM_ROLL_OUT: String = "itemRollOut";


	// UI Component Events

	/** Stage focus has been given to a UIComponent. */
	public static var FOCUS_IN: String = "focusIn";
	/** Stage focus has taken from a UIComponent. */
	public static var FOCUS_OUT: String = "focusOut";
	/** The {@code visible} property of a UIComponent has been set from {@code false} to {@code true}. */
	public static var SHOW: String = "show";
	/** The {@code visible} property of a UIComponent has been set from {@code true} to {@code false}. */
	public static var HIDE: String = "hide";


	// Generic Events

	/** A component has become initialized. An initialization event is not dispatched from any components by default, but is available to be used when extending or creating components. */
	public static var INIT: String = "init";
	/** The value of a component has changed. Many components dispatch a "change" event when interacted with, such as changing the {@link ScrollingList#selectedIndex} or a {@link Slider#value}. */
	public static var CHANGE: String = "change";
	/** The frame state of a component has changed. Components that use keyframes for states, such as {@link Button} will dispatch a "stateChange" event when interacted with by the user. */
	public static var STATE_CHANGE: String = "stateChange";


	// Button Events

	/** A {@link Button#selected Button} component's {@code selected} property has changed. */
	public static var SELECT: String = "select";


	// Load Events

	/** A load operation has failed due to an incorrect path name or missing file. Used by {@link UILoader}. */
	public static var IO_ERROR: String = "ioError";
	/** A load operation has loaded a percentage of the overall total. Typically used by {@link ProgressBar} and {@code UILoader}. */
	public static var PROGRESS: String = "progress";
	/** A load operation has completed. Typically used by {@link ProgressBar} and {@code UILoader}. */
	public static var COMPLETE: String = "complete";


	// Other

	/** The scroll position of a component has changed. Used by {@link ScrollIndicator}, as well as list-based components such as {@link ScrollingList}. */
	public static var SCROLL: String = "scroll";
	/** The text of a component has changed, usually from user input. Typically used by {@link TextInput} and {@link TextArea}. */
	public static var TEXT_CHANGE: String = "textChange";
	/** The user or game has inputted data, usually through a controller or keyboard. {@link InputDelegate} intercepts input from the game and dispatches these events. */
	public static var INPUT: String = "input";


	// DragManager

	/** A component has begun a drag using the {@link DragManager}. */
	public static var DRAG_BEGIN: String = "dragBegin";
	/** A drag operation by the {@link DragManager} has completed. */
	public static var DRAG_END: String = "dragEnd";
	/** A drag operation has completed, and a component is the target of the drop. */
	public static var DROP: String = "drop";
}
