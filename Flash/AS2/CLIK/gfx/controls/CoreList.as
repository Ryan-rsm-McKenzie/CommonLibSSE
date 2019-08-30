/**
 * An abstract class used to display a list of data, and set a selectedIndex (or indices). This class only manages data, and instantiating itemRenderers, but the sub-class must request the renderers and arrange them. It is sub-classed by the ScrollingList and TileList components.
 */


import flash.geom.Rectangle;
import gfx.core.UIComponent;
import gfx.data.DataProvider;


[InspectableList("disabled", "visible", "itemRenderer", "enableInitCallback", "inspectableRendererInstanceName", "soundMap")]
class gfx.controls.CoreList extends UIComponent
{
	/* PUBLIC VARIABLES */

    /** Mapping between events and sound process */
	[Inspectable(type="Object", defaultValue="theme:default,focusIn:focusIn,focusOut:focusOut,select:select,change:change,rollOver:rollOver,rollOut:rollOut,itemClick:itemClick,itemDoubleClick:itemDoubleClick,itemPress:itemPress,itemRollOver:itemRollOver,itemRollOut:itemRollOut")]
	public var soundMap: Object = { theme:"default", focusIn:"focusIn", focusOut:"focusOut", select:"select", change:"change", rollOver:"rollOver", rollOut:"rollOut", itemClick:"itemClick", itemDoubleClick:"itemDoubleClick", itemPress:"itemPress", itemRollOver:"itemRollOver", itemRollOut:"itemRollOut" };


	/* PRIVATE VARIABLES */

	private var _dataProvider: Object;
	private var _itemRenderer: String = "ListItemRenderer";
	private var _selectedIndex: Number = -1;
	private var _labelField: String = "label";
	private var _labelFunction: Function;
	private var externalRenderers: Boolean = false; // Determines if the List is using external renderers, or generated
	private var renderers: Array;
	private var deferredScrollIndex: Number = -1;
	[Inspectable(name="rendererInstanceName")]
	private var inspectableRendererInstanceName: String;


	/* STAGE ELEMENTS */

	private var container: MovieClip;


	/* INITIALIZATION */

	/**
	 * The constructor is called when a CoreList or a sub-class of CoreList is instantiated on stage or by using {@code attachMovie()} in ActionScript. This component can <b>not</b> be instantiated using {@code new} syntax. When creating new components that extend CoreList, ensure that a {@code super()} call is made first in the constructor.
	 */
	public function CoreList()
	{
		super();
		renderers = [];
		dataProvider = []; // Default Data.
		if (container == undefined) {
			container = createEmptyMovieClip("container", 1);
		}
		container.scale9Grid = new Rectangle(0, 0, 1, 1);
		tabEnabled = focusEnabled = true;
	}


	/* PUBLIC FUNCTIONS */

	/**
	 * The linkage ID for the renderer used to display each item in the list. The list components only support a single itemRenderer for all items.
	 */
	[Inspectable(defaultValue="ListItemRenderer")]
	public function get itemRenderer(): String
	{
		return _itemRenderer;
	}


	public function set itemRenderer(value: String): Void
	{
		if (value == _itemRenderer || value == "") {
			return;
		}

		_itemRenderer = value;
		resetRenderers();
		invalidate();
	}


	/**
	 * The data model displayed in the component. The dataProvider can be an Array or any object exposing the appropriate API, defined in the {@code IDataProvider} interface. If an Array is set as the dataProvider, functionality will be mixed into it by the {@code DataProvider.initialize} method. When a new DataProvider is set, the {@code selectedIndex} property will be reset to 0.
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
		if (_dataProvider == null) {
			return;
		}

		if ((value instanceof Array) && !value.isDataProvider) {
			DataProvider.initialize(_dataProvider);
		} else if (_dataProvider.initialize != null) {
			_dataProvider.initialize(this);
		}

		_dataProvider.addEventListener("change", this, "onDataChange");  // Do a full redraw
		invalidate();
	}


	/**
	 * The index of the item that is selected in a single-selection list.
	 */
	public function get selectedIndex(): Number
	{
		return _selectedIndex;
	}


	public function set selectedIndex(value: Number): Void
	{
		var lastIndex: Number = _selectedIndex;
		_selectedIndex = value;
		dispatchEventAndSound({type: "change", index: _selectedIndex, lastIndex: lastIndex});
	}


	/**
	 * Scrolls the list to the item at the specified index. If the index is not out of range, the scroll position does not change. This method is not implemented in CoreList, so it must be implemented in sub-classes.
	 * @param index The index in the {@code dataProvider} to scroll to.
	 */
	public function scrollToIndex(index: Number): Void
	{}


	/**
	 * The name of the field in the {@code dataProvider} model to be displayed as the label for itemRenderers.  A {@code labelFunction} will be used over a {@code labelField} if it is defined.
	 * @see #itemToLabel
	 */
	public function get labelField(): String
	{
		return _labelField;
	}


	public function set labelField(value: String): Void
	{
		_labelField = value;
		invalidateData();
	}


	/**
	 * The function used to determine the label for itemRenderers. A {@code labelFunction} will override a {@code labelField} if it is defined.
	 * @see #itemToLabel
	 */
	public function get labelFunction(): Function
	{
		return _labelFunction;
	}


	public function set labelFunction(value: Function): Void
	{
		_labelFunction = value;
		invalidateData();
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
	 * The current data has become invalid, either by a data change, or a display change such as scrolling. It is up to the sub-classes to determine the behaviour.
	 */
	public function invalidateData(): Void
	{}


	/**
	 * The amount of the component's width that can be used for renderers. This can be overridden to accommodate padding or ScrollBars.
	 */
	public function get availableWidth(): Number
	{
		return __width;
	}


	/**
	 * The amount of the component's height that can be used for renderers. This can be overridden to accommodate padding or ScrollBars
	 */
	public function get availableHeight(): Number
	{
		return __height;
	}


	/**
	 * Set a list of external MovieClips to use as renderers, instead of auto-generating the renderers at run-time. The rendererInstance property uses this method to set the renderer list.
	 */
	public function setRendererList(value: Array): Void
	{
		// Clean up old external renderers.
		if (externalRenderers) {
			for (var i: Number = 0; i < renderers.length; i++) {
				var clip: MovieClip = renderers[i];
				clip.owner = null;
				clip.removeEventListener("click", this, "handleItemClick");
				clip.removeEventListener("rollOver", this, "dispatchItemEvent");
				clip.removeEventListener("rollOut", this, "dispatchItemEvent");
				clip.removeEventListener("press", this, "dispatchItemEvent");
				clip.removeEventListener("doubleClick", this, "dispatchItemEvent");
				Mouse.removeListener(clip);
			}
		} else {
			resetRenderers();
		}

		externalRenderers = (value != null);

		if (externalRenderers) {
			renderers = value;
		}
		invalidate();
	}


	/**
	 * The name of data renderers to be used in this list instance. The names are a string followed by consecutive numbers incrementing from 0 or 1. For instance "renderer1, renderer2, renderer3, etc". The renderers must be in the parent timeline of the list instance in order to be used. If a specific numbered clip is missing, then only the renderers up to that point will be used.
	 */
	public function get rendererInstanceName(): String
	{
		return null;
	}


	public function set rendererInstanceName(value: String): Void
	{
		if (value == null || value == "") {
			return;
		}

		var i: Number = 0;
		var newRenderers: Array = [];
		while (true) {
			i++;
			var clip: MovieClip = _parent[value + i];
			if (clip == null && i > 0) {
				break;	// No more in the list
			}

			if (clip == null) {
				continue;	// 0 is not found, continue to 1 (we can start with either)
			}

			setUpRenderer(clip);
			// Need to defer mouse scroll events to owner because it will not process them for external renderers
			Mouse.addListener(clip);
			clip.scrollWheel = function(delta: Number) {
				this.owner.scrollWheel(delta);
			}
			newRenderers.push(clip);
		}

		if (newRenderers.length == 0) {
			newRenderers = null;
		}

		setRendererList(newRenderers);
	}


	/** @exclude */
	public function toString(): String
	{
		return "[Scaleform CoreList " + _name + "]";
	}


	/* PRIVATE FUNCTIONS */

	private function configUI(): Void
	{
		super.configUI();
		if (_selectedIndex > -1) {
			deferredScrollIndex = _selectedIndex;
		}
		if (inspectableRendererInstanceName != "") {
			rendererInstanceName = inspectableRendererInstanceName;
		}
		Mouse.addListener(this);
	}


	/**
	 * Called by sub-classes to create a single renderer based on an index.  The renderer is specified by the {@code itemLinkage} property.
	 * @param index The index in the dataProvider
	 * @returns The newly-created itemRenderer
	 */
	private function createItemRenderer(index: Number): MovieClip
	{
		var clip: MovieClip = container.attachMovie(_itemRenderer, "renderer" + index, index);
		if (clip == null) {
			return null;
		}
		setUpRenderer(clip);
		return clip;
	}


	private function setUpRenderer(clip: MovieClip): Void
	{
		clip.owner = this;
		clip.tabEnabled = false; // Children can still be tabEnabled, or the renderer could re-enable this.
		clip.doubleClickEnabled = true;
		clip.addEventListener("press", this, "dispatchItemEvent");
		clip.addEventListener("click", this, "handleItemClick");
		clip.addEventListener("doubleClick", this, "dispatchItemEvent");
		clip.addEventListener("rollOver", this, "dispatchItemEvent");
		clip.addEventListener("rollOut", this, "dispatchItemEvent");
	}


	/**
	 * Called by sub-classes to create multiple renderers between a range of indexes.
	 * @param startIndex The first index of items in the dataProvider to create
	 * @param endIndex The endIndex of items in the dataProvider to create
	 * @returns An Array of itemRenderers
	 */
	private function createItemRenderers(startIndex: Number, endIndex: Number): Array
	{
		var list: Array = [];
		for (var i: Number = startIndex; i <= endIndex; i++) {
			list.push(createItemRenderer[i]);
		}
		return list;
	}


	private function draw(): Void
	{
		if (deferredScrollIndex != -1) {
			scrollToIndex(deferredScrollIndex);
			deferredScrollIndex = -1;
		}
	}


	/**
	 * Create new renderers and destroy old renderers to ensure there are a specific number of renderers in the component.
	 * @param totalRenderers The number of renderers that the component needs.
	 */
	private function drawRenderers(totalRenderers: Number): Void
	{
		// Remove extra renderers
		while (renderers.length > totalRenderers) {
			renderers.pop().removeMovieClip();
		}

		// Add new renderers
		while (renderers.length < totalRenderers) {
			renderers.push(createItemRenderer(renderers.length));
		}
	}


	/**
	 * Get a renderer based on a data index.  The default method assumes the renderers are all visible, and indexed accordingly.  Sub-classes may have to use math to determine if an item is currently displayed.
	 * @param index The index in the DataProvider
	 * @returns A reference to the renderer that contains the specified data
	 */
	private function getRendererAt(index: Number): MovieClip
	{
		return renderers[index];
	}


	private function resetRenderers(): Void
	{
		while (renderers.length > 0) {
			renderers.pop().removeMovieClip();
		}
	}


	// This method is not called by CoreList, but is a guide to the method that should be used to do layout logic in the sub-classes.
	private function drawLayout(rendererWidth: Number, rendererHeight: Number): Void
	{}


	private function onDataChange(event: Object): Void
	{
		// Full data refresh
		invalidateData();
	}


	// Dispatch a mouse event that comes from an itemRenderer.
	private function dispatchItemEvent(event: Object): Void
	{
		var type: String;
		switch (event.type) {
			case "press":
				type = "itemPress";
				break;
			case "click":
				type = "itemClick";
				break;
			case "rollOver":
				type = "itemRollOver";
				break;
			case "rollOut":
				type = "itemRollOut";
				break;
			case "doubleClick":
				type = "itemDoubleClick";
				break;
			default:
				return;
		}

		var newEvent: Object = {
			target: this,
			type: type,
			item: event.target.data,
			renderer: event.target,
			index: event.target.index,
			controllerIdx: event.controllerIdx
		};

		dispatchEventAndSound(newEvent);
	}


	private function handleItemClick(event: Object): Void
	{
		var index: Number = event.target.index;
		if (isNaN(index)) {
			return;	// If the data has not been populated, but the listItemRenderer is clicked, it will have no index.
		}
		selectedIndex = index;
		dispatchItemEvent(event);
	}
}
