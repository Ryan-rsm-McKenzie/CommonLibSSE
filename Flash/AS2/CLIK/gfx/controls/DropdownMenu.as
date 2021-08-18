 /**
 * The DropdownMenu wraps the behavior of a button and a list. Clicking on this component opens a list that contains the elements to be selected. The DropdownMenu displays only the selected element in its idle state. It can be configured to use either the ScrollingList or the TileList, to which either a ScrollBar or ScrollIndicator can be paired with. The list is populated via an installed DataProvider. The DropdownMenu’s list element is populated via a DataProvider. The dataProvider is assigned via code, as shown in the example below:
<i>dropdownMenu.dataProvider = ["item1", "item2", "item3", "item4"];</i>

	<b>Inspectable Properties</b>
	The inspectable properties of the DropdownMenu component are:<ul>
	<li><i>visible</i>: Hides the component if set to false.</li>
	<li><i>disabled</i>: Disables the component if set to true.</li>
	<li><i>dropdown</i>: Symbol name of the list component (ScrollingList or TileList) to use with the DropdownMenu component.</li>
	<li><i>itemRenderer</i>: Symbol name of the list component's itemRenderer.</li>
	<li><i>dropdownWidth</i>: Width of the dropdown list. If this value is -1, then the DropdownMenu will size the list to the component’s width.</li>
      <li><i>itemRenderer</i>: Symbol name of the dropdown list’s item renderer. Created by the dropdown list instance.</li>
      <li><i>scrollBar</i>: Symbol name of the dropdown list’s scroll bar. Created by the dropdown list instance. If value is empty, then the dropdown list will have no scroll bar.</li>
	<li><i>margin</i>: The margin between the boundary of the list component and the list items created internally. This margin also affects the automatically generated scrollbar.</li>
	<li><i>paddingTop:</i>Extra padding at the top for the list items. Does not affect the automatically generated scrollbar.</li>
	<li><i>paddingBottom:</i>Extra padding at the bottom for the list items. Does not affect the automatically generated scrollbar.</li>
	<li><i>paddingLeft:</i>Extra padding on the left side for the list items. Does not affect the automatically generated scrollbar.</li>
	<li><i>paddingRight:</i>Extra padding on the right side for the list items. Does not affect the automatically generated scrollbar.</li>
	<li><i>thumbOffsetTop:</i>Scrollbar thumb top offset. This property has no effect if the list does not automatically create a scrollbar instance.</li>
	<li><i>thumbOffsetBottom:</i>Scrollbar thumb bottom offset. This property has no effect if the list does not automatically create a scrollbar instance.</li>
	<li><i>thumbSizeFactor:</i>Page size factor for the scrollbar thumb. A value greater than 1.0 will increase the thumb size by the given factor. This value has no effect if a scrollbar is not attached to the list.</li>
	<li><i>offsetX:</i>Horizontal offset of the dropdown list from the dropdown button position. A positive value moves the list to the right of the dropdown button horizontal position.</li>
	<li><i>offsetY:</i>Vertical offset of the dropdown list from the dropdown button. A positive value moves the list away from the button.</li>
	<li><i>extent:</i>An extra width offset that can be used in conjunction with offsetX. This value has no effect if the dropdownWidth property is set to a value other than -1.</li>
	<li><i>direction:</i>The list open direction. Valid values are "up" and "down".</li>
	<li><i>enableInitCallback</i>: If set to true, _global.CLIK_loadCallback() will be fired when a component is loaded and _global.CLIK_unloadCallback will be called when the component is unloaded. These methods receive the instance name, target path, and a reference the component as parameters.  _global.CLIK_loadCallback and _global.CLIK_unloadCallback should be overridden from the game engine using GFx FunctionObjects.</li>
	<li><i>soundMap</i>: Mapping between events and sound process. When an event is fired, the associated sound process will be fired via _global.gfxProcessSound, which should be overridden from the game engine using GFx FunctionObjects.</li></ul>


	<b>States</b>
	The DropdownMenu is toggled when opened, and therefore needs the same states as a ToggleButton or CheckBox that denote the selected state. These states include <ul>
	<li>an up or default state.</li>
	<li>an over state when the mouse cursor is over the component, or when it is focused.</li>
	<li>a down state when the button is pressed.</li>
	<li>a disabled state.</li>
	<li>a selected_up or default state.</li>
	<li>a selected_over state when the mouse cursor is over the component, or when it is focused.</li>
	<li>a selected_down state when the button is pressed.</li>
	<li>a selected_disabled state.</li></ul>

	These are the minimal set of keyframes that should be in a DropdownMenu. The extended set of states and keyframes supported by the Button component, and consequently the DropdownMenu component, are described in the Getting Started with CLIK Buttons document.

	<b>Events</b>
	All event callbacks receive a single Object parameter that contains relevant information about the event. The following properties are common to all events. <ul>
	<li><i>type</i>: The event type.</li>
	<li><i>target</i>: The target that generated the event.</li></ul>

	The events generated by the DropdownMenu component are listed below. They are the same as the Button component with the exception of the change event. The properties listed next to the event are provided in addition to the common properties.<ul>
	<li><i>show</i>: The component's visible property has been set to true at runtime.</li>
	<li><i>hide</i>: The component's visible property has been set to false at runtime.</li>
	<li><i>focusIn</i>: The component has received focus.</li>
	<li><i>focusOut</i>: The component has lost focus.</li>
	<li><i>select</i>: The component's selected property has changed.<ul>
		<li><i>selected</i>: The selected property of the Button. Boolean type.</li></ul></li>
	<li><i>stateChange</i>: The button's state has changed.<ul>
		<li><i>state</i>: The Button's new state. String type. Values "up", "over", "down", etc. </li></ul></li>
	<li><i>rollOver</i>: The mouse cursor has rolled over the button.<ul>
		<li><i>controllerIdx</i>: The index of the mouse cursor used to generate the event (applicable only for multi-mouse-cursor environments). Number type. Values 0 to 3.</li></ul></li>
	<li><i>rollOut</i>: The mouse cursor has rolled out of the button.<ul>
		<li><i>controllerIdx</i>: The index of the mouse cursor used to generate the event (applicable only for multi-mouse-cursor environments). Number type. Values 0 to 3.</li></ul></li>
	<li><i>press</i>: The button has been pressed.<ul>
		<li><i>controllerIdx</i>: The index of the mouse cursor used to generate the event (applicable only for multi-mouse-cursor environments). Number type. Values 0 to 3.</li></ul></li>
	<li><i>doubleClick</i>: The button has been double clicked. Only fired when the {@link Button.doubleClickEnabled} property is set.<ul>
		<li><i>controllerIdx</i>: The index of the mouse cursor used to generate the event (applicable only for multi-mouse-cursor environments). Number type. Values 0 to 3.</li></ul></li>
	<li><i>click</i>: The button has been clicked.<ul>
		<li><i>controllerIdx</i>: The index of the mouse cursor used to generate the event (applicable only for multi-mouse-cursor environments). Number type. Values 0 to 3.</li></ul></li>
	<li><i>dragOver</i>: The mouse cursor has been dragged over the button (while the left mouse button is pressed).<ul>
		<li><i>controllerIdx</i>: The index of the mouse cursor used to generate the event (applicable only for multi-mouse-cursor environments). Number type. Values 0 to 3.</li></ul></li>
	<li><i>dragOut</i>: The mouse cursor has been dragged out of the button (while the left mouse button is pressed).<ul>
		<li><i>controllerIdx</i>: The index of the mouse cursor used to generate the event (applicable only for multi-mouse-cursor environments). Number type. Values 0 to 3.</li></ul></li>
	<li><i>releaseOutside</i>: The mouse cursor has been dragged out of the button and the left mouse button has been released.<ul>
		<li><i>controllerIdx</i>: The index of the mouse cursor used to generate the event (applicable only for multi-mouse-cursor environments). Number type. Values 0 to 3.</li></ul></li></ul>
 */


import gfx.controls.Button;
import gfx.data.DataProvider;
import gfx.managers.PopUpManager;
import gfx.ui.InputDetails;
import gfx.ui.NavigationCode;


[InspectableList("disabled", "visible", "inspectableDropdown", "inspectableItemRenderer", "inspectableScrollBar", "dropdownWidth", "margin", "paddingTop", "paddingBottom", "paddingLeft", "paddingRight", "thumbOffsetBottom", "thumbOffsetTop", "thumbSizeFactor", "offsetX", "offsetY", "extent", "direction", "enableInitCallback", "soundMap")]
class gfx.controls.DropdownMenu extends Button
{
	/* PUBLIC VARIABLES */

	/** The current visible state of the {@code dropdown} component. When the dropdown is open, it will receive input from the user. */
	public var isOpen: Boolean = false;
	/** A reference to the currently selected item in the {@code dataProvider}. */
	public var selectedItem: Object;

	/** Direction the list opens. Valid values are "up" and "down". **/
	[Inspectable(enumeration="up,down", defaultValue="down", verbose=1)]
	public var direction: String = "down";
	[Inspectable(type="Object", defaultValue="theme:default,focusIn:focusIn,focusOut:focusOut,select:select,rollOver:rollOver,rollOut:rollOut,press:press,doubleClick:doubleClick,click:click")]
	public var soundMap: Object = { theme:"default", focusIn:"focusIn", focusOut:"focusOut", select:"select", rollOver:"rollOver", rollOut:"rollOut", press:"press", doubleClick:"doubleClick", click:"click" };


	/* PRIVATE VARIABLES */

	private var _dataProvider: Object;
	private var _dropdownWidth: Number = -1;
	private var _rowCount: Number = 5;
	private var _labelField: String = "label";
	private var _labelFunction: Function;
	private var _selectedIndex: Number = -1;
	[Inspectable(name="dropdown", type="String", defaultValue="ScrollingList")]
	private var inspectableDropdown: Object;
	[Inspectable(name="itemRenderer", type="String", defaultValue="ListItemRenderer")]
	private var inspectableItemRenderer: Object;
	[Inspectable(name="scrollBar", type="String")]
	private var inspectableScrollBar: Object;

	[Inspectable(defaultValue="1", verbose=1)]
	private var margin: Number = 1;
	[Inspectable(defaultValue="0", verbose=1)]
	private var paddingTop: Number = 0;
	[Inspectable(defaultValue="0", verbose=1)]
	private var paddingBottom: Number = 0;
	[Inspectable(defaultValue="0", verbose=1)]
	private var paddingLeft: Number = 0;
	[Inspectable(defaultValue="0", verbose=1)]
	private var paddingRight: Number = 0;
	[Inspectable(defaultValue="0", verbose=1)]
	private var thumbOffsetTop: Number = 0;
	[Inspectable(defaultValue="0", verbose=1)]
	private var thumbOffsetBottom: Number = 0;
	[Inspectable(defaultValue="1.0", verbose=1)]
	private var thumbSizeFactor: Number = 1.0;
	[Inspectable(defaultValue="0", verbose=1)]
	private var offsetX: Number = 0;
	[Inspectable(defaultValue="0", verbose=1)]
	private var offsetY: Number = 0;
	[Inspectable(defaultValue="0", verbose=1)]
	private var extent: Number = 0;


	/* STAGE ELEMENTS */

	private var _dropdown: MovieClip = null;


	/* INITIALIZATION */

	/**
	 * The constructor is called when a DropdownMenu or a sub-class of DropdownMenu is instantiated on stage or by using {@code attachMovie()} in ActionScript. This component can <b>not</b> be instantiated using {@code new} syntax. When creating new components that extend DropdownMenu, ensure that a {@code super()} call is made first in the constructor.
	 */
	public function DropdownMenu()
	{
		super();
		dataProvider = [];
	}


	/* PUBLIC FUNCTIONS */

	/**
	 * Sets the class or instance to use as a dropdown. If a linkage ID is specified, it will be created using the {@code PopUpManager}.  The dropdown property will return the persistent MovieClip instance created or referenced by the DropdownMenu so properties can be set on it directly.
	 * @see PopUpManager
	 */
	public function get dropdown(): Object
	{
		// Create the dropdown if not created yet
		if (!_dropdown) {
			createDropDown();
		}
		return _dropdown;
	}


	public function set dropdown(value: Object): Void
	{
		inspectableDropdown = value;
		if (initialized) {
			createDropDown();
		}
	}


	/**
	 * Sets the linkage ID to use as the dropdown's item renderer, which will be created by the dropdown list component.
	 */
	public function get itemRenderer(): Object
	{
		return _dropdown.itemRenderer;
	}


	public function set itemRenderer(value: Object): Void
	{
		inspectableItemRenderer = value;
		if (_dropdown) {
			_dropdown.itemRenderer = inspectableItemRenderer;
		}
	}


	/**
	 * Sets the class or instance to use as the dropdown's scrollbar. If a linkage ID is specified, it will be created by the dropdown list component.  The scrollbar property will return the persistent MovieClip instance created or referenced by the DropdownMenu's list so properties can be set on it directly.
	 */
	public function get scrollBar(): Object
	{
		return _dropdown.scrollBar;
	}


	public function set scrollBar(value: Object): Void
	{
		inspectableScrollBar = value;
		if (_dropdown) {
			_dropdown.scrollBar = inspectableScrollBar;
		}
	}


	/**
	 * The width of the dropdown.
	 	<ul><li>When set to -1, the component will scale to match the width of the dropdownMenu.</li>
		<li>When set to 0, the component will not scale at all, and will be left at its original size.</li>
		<li>When set to a number greater than 0, the dropdown will be set to that size exactly.</li><ol>
		Auto-sizing based on row contents is not supported.</li></ul>
	 */
	[Inspectable(defaultValue="-1")]
	public function get dropdownWidth(): Number
	{
		return _dropdownWidth;
	}


	public function set dropdownWidth(value: Number): Void
	{
		_dropdownWidth = value;
	}


	/**
	 * The number of rows to display in the dropdown. The {@code autoRowCount} property on the dropdown determines how that property is applied. If the length of the {@code dataProvider} is less than the rowCount, only the number of items in the dataProvider will be displayed.
	 */
	public function get rowCount(): Number
	{
		return _rowCount;
	}


	public function set rowCount(value: Number): Void
	{
		_rowCount = value;
		if (_dropdown != null && _dropdown.hasOwnProperty("rowCount")) {
			_dropdown.rowCount = value;
		}
	}


	/**
	 * The data model displayed in the component. The dataProvider can be an Array or any object exposing the appropriate API, defined in the {@code IDataProvider} interface. If an Array is set as the {@code dataProvider}, functionality will be mixed into it by the {@code DataProvider.initialize} method. When a new DataProvider is set, the {@code selectedIndex} property will be reset to 0.
	 * @see DataProvider
	 * @see IDataProvider
	 */
	public function get dataProvider(): Object
	{
		return _dataProvider;
	}


	public function set dataProvider(value: Object): Void
	{
		if (_dataProvider == value) {
			return;
		}

		if (_dataProvider != null) {
			_dataProvider.removeEventListener("change", this, "onDataChange");
		}
		_dataProvider = value;
		DataProvider.initialize(_dataProvider);
		_dataProvider.addEventListener("change", this, "onDataChange");
		if (_dropdown != null) {
			_dropdown.dataProvider = _dataProvider;
		}
		selectedIndex = 0;
		updateSelectedItem();
	}


	/**
	 * The index of the item that is selected in a single-selection list. The DropdownMenu will always have a {@code selectedIndex} of 0 or greater, unless there is no data.
	 */
	public function get selectedIndex(): Number
	{
		return _selectedIndex;
	}


	public function set selectedIndex(value: Number): Void
	{
		_selectedIndex = value;
		if (_dropdown != null) {
			_dropdown.selectedIndex = value;
		}

		updateSelectedItem();
	}


	/**
	 * The name of the field in the {@code dataProvider} to be displayed as the label for the TextInput field.  A {@code labelFunction}  will be used over a {@code labelField} if it is defined.
	 * @see #itemToLabel()
	 */
	public function get labelField(): String
	{
		return _labelField;
	}


	public function set labelField(value: String): Void
	{
		_labelField = value;
		if (_dropdown != null) {
			_dropdown.labelField = _labelField;
		}

		updateLabel();
	}


	/**
	 * The function used to determine the label for an item. A {@code labelFunction} will override a {@code labelField} if it is defined.
	 * @see #itemToLabel()
	 */
	public function get labelFunction(): Function
	{
		return _labelFunction;
	}


	public function set labelFunction(value: Function): Void
	{
		_labelFunction = value;
		if (_dropdown != null) {
			_dropdown.labelFunction = _labelFunction;
		}

		updateLabel();
	}


	/**
	 * Convert an item to a label string using the {@code labelField} and {@code labelFunction}.
	 * @param item The item to convert to a label.
	 * @returns The converted label string.
	 * @see #labelField
	 * @see #labelFunction
	 */
	public function itemToLabel(item: Object): String
	{
		if (item == null) {
			return "";
		}

		if (_labelFunction != null) {
			return _labelFunction(item);
		} else if (_labelField != null && item[_labelField] != null) {
			return item[_labelField];
		}
		return item.toString();
	}


	/**
	 * Open the dropdown list. The {@code selected} and {@code isOpen} properties of the DropdownMenu are set to {@code true} when open. Input will be passed to the dropdown when it is open before it is handled by the DropdownMenu.
	 */
	public function open(): Void
	{
		if (!_dropdown) {
			createDropDown();
			if (!_dropdown) {
				isOpen = false;
				return;
			}
		}
		openImpl();
	}


	/**
	 * Close the dropdown list. The list is not destroyed, the {@code visible} property is set to {@code false}. The {@code selected} property of the DropdownMenu is set to {@code false} when closed.
	 */
	public function close(): Void
	{
		if (!isOpen) {
			return;
		}

		isOpen = false;
		if (_dropdown == null) {
			return;
		}

		_dropdown.visible = false;
		Mouse.removeListener(this);
		/*if (_dropdown.scrollBar != null && MovieClip(_dropdown.scrollBar)._parent != _dropdown) {
			MovieClip(_dropdown.scrollBar)._visible = false;
		}*/
		selected = false;
	}


	/**
	 * The current data has become invalid, usually via a data change. The component requests a data update from the {@code dataProvider}.
	 */
	public function invalidateData(): Void
	{
		_dataProvider.requestItemAt(_selectedIndex, this, "populateText");
	}


	public function setSize(width: Number, height: Number): Void
	{
		super.setSize(width, height);
		if (_dropdown != null && _dropdownWidth == -1) {
			_dropdown.width = __width;
		}
	}


	public function handleInput(details: InputDetails, pathToFocus: Array): Boolean
	{
		var handled: Boolean;
		if (_dropdown != null && isOpen) {
			handled = _dropdown.handleInput(details);
			if (handled) {
				return true;
			}
		}

		// Let the Button also try and handle it.
		handled = super.handleInput(details, pathToFocus);

		var keyPress:Boolean = (details.value == "keyDown" || details.value == "keyHold");
		switch (details.navEquivalent) {
			case NavigationCode.ESCAPE:
				if (isOpen) {
					if (keyPress) {
						close();
					}
					return true;
				}
		}

		// Return the value the button handleInput returned.
		return handled;
	}


	// Override in order to help out.
	/** @exclude */
	public function removeMovieClip(): Void
	{
		if (_dropdown) {
			_dropdown.removeMovieClip();
		}
		super.removeMovieClip();
	}


	/** @exclude */
	public function toString(): String
	{
		return "[Scaleform DropdownMenu " + _name + "]";
	}


	/* PRIVATE FUNCTIONS */

	private function createDropDown(): Void
	{
		if (_dropdown == inspectableDropdown) {
			return;
		}

		if (_dropdown != null) {
			_dropdown.removeMovieClip();
		}
		// Create or cast the dropdown
		if (typeof(inspectableDropdown) == "string") {
			_dropdown = MovieClip(_parent[inspectableDropdown]);
			if (_dropdown == null) {
				_dropdown = PopUpManager.createPopUp(this, inspectableDropdown.toString(),
							{itemRenderer:inspectableItemRenderer, paddingTop:paddingTop, paddingBottom:paddingBottom,
							 paddingLeft:paddingLeft, paddingRight:paddingRight, thumbOffsetTop:thumbOffsetTop,
							 thumbOffsetBottom:thumbOffsetBottom, thumbSizeFactor:thumbSizeFactor, margin:margin});
				_dropdown.scrollBar = inspectableScrollBar;
			}
		} else if (inspectableDropdown instanceof MovieClip) {
			_dropdown = MovieClip(_dropdown);
		}

		if (_dropdown == null) {
			return;
		}

		// Initialize the dropdown
		_dropdown.addEventListener("itemClick", this, "handleChange");
		_dropdown.labelField = _labelField;
		_dropdown.labelFunction = _labelFunction;
		_dropdown.dataProvider = _dataProvider;
		_dropdown.selectedIndex = _selectedIndex;
		_dropdown.visible = false;

        if (!_disableFocus) {
		    _dropdown.focusTarget = this;
        }

		if (_dropdown.wrapping != null) {
			_dropdown.wrapping = "stick";
		}

		if (_dropdown.autoRowCount != null) {
			_dropdown.autoRowCount = true;
		}

		if (_dropdown.rowCount != null) {
			_dropdown.rowCount = Math.min(_dataProvider.length, _rowCount);
		}

		if (_dropdownWidth != 0) {
			_dropdown.width = (_dropdownWidth == -1) ? (__width + extent) : _dropdownWidth;
		}
	}


	private function openImpl(): Void
	{
		if (isOpen) {
			return;
		}
		isOpen = true;

		// Set the width *before* the rowCount, in case the width changes the rowCount.
		if (_dropdownWidth != _dropdown.width) {
			_dropdown.width = (_dropdownWidth == -1) ? (__width + extent) : _dropdownWidth;
		}
		if (_rowCount != _dropdown.rowCount) {
			_dropdown.rowCount = Math.min(_dataProvider.length, _rowCount);
		}
		_dropdown.validateNow();

		onMouseDown = handleStageClick;
		Mouse.addListener(this);

		selected = true; // Select the Button state.

		_dropdown.selectedIndex = _selectedIndex;
		_dropdown.scrollToIndex(_selectedIndex);

		var oX:Number = offsetX * (100/_xscale);
		var oY:Number = offsetY * (100/_yscale);
		PopUpManager.movePopUp(this, MovieClip(_dropdown), this, oX,
							   (direction == "down") ? __height + oY : -_dropdown.height - oY);
		_dropdown.visible = true;
	}


	private function configUI(): Void
	{
		super.configUI();
		addEventListener("click", this, "toggleMenu");
		toggle = false; // In case the developer doesn't know better.
	}


	private function changeFocus(): Void
	{
		super.changeFocus();
		if (isOpen && _dropdown != null) {
			close();
		}
	}


	private function updateSelectedItem(): Void
	{
		invalidateData();
	}


	private function updateLabel(): Void
	{
		label = itemToLabel(selectedItem);
	}


	private function populateText(item: Object): Void
	{
		selectedItem = item;
		updateLabel();
		dispatchEvent({type:"change", index:_selectedIndex, data:item});
	}


	// The dropdown has been clicked/changed.
	private function handleChange(event: Object): Void
	{
		var index: Number = _dropdown.selectedIndex;
		_selectedIndex = index; // No need to trigger a selection change using selectedIndex instead
		close();
		updateSelectedItem();
	}


	private function onDataChange(event: Object): Void
	{
		updateSelectedItem();
	}


	private function toggleMenu(event: Object): Void
	{
		!_selected ? open() : close();
	}


	// Close the dropdown if the user clicks anywhere else in the application.
	private function handleStageClick(event: Object): Void
	{
		if (hitTest(_root._xmouse, _root._ymouse, true)) {
			return;
		}

		close();
	}


	// Overridden hitTest to account for dropdown list
	private function hitTest(x: Number, y: Number, shapeFlag: Boolean): Boolean
	{
		return (super.hitTest(x, y, shapeFlag) || ((_dropdown && isOpen) ? _dropdown.hitTest(x, y, shapeFlag) : false));
	}
}
