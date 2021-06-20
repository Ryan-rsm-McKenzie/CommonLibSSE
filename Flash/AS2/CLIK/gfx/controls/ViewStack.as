/**
 * The CLIK ViewStack displays a single view from a set that is loaded and optionally cached internally. This component can be used for multi-view components such as a TabBox, or Accordion. A ViewStack can also be pointed at another component such as a RadioButton group to automatically change views when the component changes.

	<b>Inspectable Properties</b>
	A MovieClip that derives from the UILoader component will have the following inspectable properties:<ul>
	<li><i>visible</i>: Hides the component if set to false.</li>
	<li><i>cache</i>: If set to true, loaded views will be cached internally. This saves on processing time to create the views, but requires an immutable ViewStack targetGroup (see below).</li>
	<li><i>targetGroup</i>: A name of a valid group object, such as  ButtonGroup, that generates ‘change’ events. The current element in the group object must have a data property containing a linkage ID for the view to be loaded and displayed. RadioButtons, for example, have a data property that can be assigned a linkage ID via the Flash Studio Component Inspector.</li>
	<li><i>enableInitCallback</i>: If set to true, _global.CLIK_loadCallback() will be fired when a component is loaded and _global.CLIK_unloadCallback will be called when the component is unloaded. These methods receive the instance name, target path, and a reference the component as parameters.  _global.CLIK_loadCallback and _global.CLIK_unloadCallback should be overridden from the game engine using GFx FunctionObjects.</li></ul>

	<b>States</b>
	There are no states for the ViewStack component. Views loaded and displayed by the ViewStack may have its own states.

	<b>Events</b>
	The ViewStack does not produce any events.
 */


import flash.geom.Rectangle;
import gfx.core.UIComponent;


[InspectableList("visible", "cache", "inspectableTargetGroup", "enableInitCallback")]
class gfx.controls.ViewStack extends UIComponent
{
	/* PUBLIC VARIABLES */

	/** The default cache mode for views loaded without explicitly defining the cache argument. */
	[Inspectable(defaultValue="false")]
	public var cache: Boolean = false;


	/* PRIVATE VARIABLES */

	private var cachedViews: Object;
	private var depth: Number = 0;
	private var _targetGroup: Object;
	[Inspectable(name="targetGroup")]
	private var inspectableTargetGroup: String;


	/* STAGE ELEMENTS */

	/** The currently active, visible view. */
	public var currentView: MovieClip;
	private var container: MovieClip;


	/* INITIALIZATION */

	/**
	 * The constructor is called when a ViewStack or a sub-class of ViewStack is instantiated on stage or by using {@code attachMovie()} in ActionScript. This component can <b>not</b> be instantiated using {@code new} syntax. When creating new components that extend ViewStack, ensure that a {@code super()} call is made first in the constructor.
	 */
	private function ViewStack()
	{
		super();
		cachedViews = {};
		container = createEmptyMovieClip("container", 1);
	}


	/* PUBLIC FUNCTIONS */

	/**
	 * Instantiate a new view based on a linkage.  If the view has been already cached, it will become visible. The currently visible view will be hidden, and destroyed if it is not cached.
	 * @param linkage The linkage ID of the symbol in the library to create.
	 * @param cache The cache mode of the view.  If the view is already cached, but the cache parameter is false, the view will remain cached.
	 * @returns The view that is created or displayed.
	 */
	public function show(linkage: String, cache: Boolean): MovieClip
	{
		cache = Boolean(cache);
		if (currentView != null) {
			if (currentView["__cached__"] == true) {
				currentView._visible = false;
			} else {
				currentView.removeMovieClip();
			}
		}

		var view: MovieClip = createView(linkage, cache);
		currentView = view;

		if (view != null) {
			view._visible = true;
			/* We apply a scale9 grid to the each view in order to stop the ViewStack's scale9 grid from being
			   applied to it.  If it has a scale9 grid already, we do not apply one. */
			if (view.scale9Grid == null) {
				view.scale9Grid = new Rectangle(0, 0, 1, 1);
			}
		}
		invalidate();
		return view;
	}


	/**
	 * Pre-caches a set of views. All the views are set to {@code visible=false}. Currently, views with the same linkage can only be created once.
	 * @param linkages An array of linkages to instantiate.
	 */
	public function precache(linkages: Array): Void
	{
		var l: Number = linkages.length;
		for (var i: Number = 0; i < l; i++) {
			createView(linkages[i], true);
		}
		invalidate();
	}


	/**
	 * The component or ButtonGroup name to listen to for a "change" event. When the {@code targetGroup} dispatches a "change" event, the view will be changed using the {@code data} property of the {@code targetGroup} as the linkage.
	 */
	public function get targetGroup(): Object
	{
		return _targetGroup;
	}


	public function set targetGroup(value: Object): Void
	{
		if (_targetGroup == value) {
			return;
		}

		if (_targetGroup != null) {
			_targetGroup.removeEventListener("change", this, "changeView");
		}

		// Look for a component by name, a ButtonGroup by name, and finally use the group as a component, such as ButtonGroup, ButtonBar, etc.
		if (typeof(value) == "string") {
			_targetGroup = _parent[value] || _parent["_buttonGroup_" + value];
		} else {
			_targetGroup = value;
		}

		if (_targetGroup == null) {
			return;
		}

		_targetGroup.addEventListener("change", this, "changeView");
		changeView();
	}


	/** @exclude */
	public function toString(): String
	{
		return "[Scaleform ViewStack " + _name + "]";
	}


	/* PRIVATE FUNCTIONS */

	private function configUI(): Void
	{
		super.configUI();
		tabEnabled = false;

		if (inspectableTargetGroup != "") {
			targetGroup = inspectableTargetGroup;
		}
	}


	private function draw(): Void
	{
		if (sizeIsInvalid) {
			container._width = container._height = 5; // the container should not affect the component size.
			_width = __width;
			_height = __height;
		}
		container._xscale = 10000 / _xscale;
		container._yscale = 10000 / _yscale;
	}


	private function createView(linkage: String, cache: Boolean): MovieClip
	{
		if (cachedViews[linkage] != null) {
			return MovieClip(cachedViews[linkage]);
		}

		var view: MovieClip = container.attachMovie(linkage, "view" + depth, depth++, {_visible: false});

		if (view == null) {
			return null;
		}

		if (cache || this.cache) {
			view["__cached__"] = true; // This is so we can check if the view is cached when we remove it.  The "cachedViews" object only references the linkages already cached.
			cachedViews[linkage] = view;
		}

		return view;
	}


	/**
	 * The view change is triggered by a "change" event on the target. The new view to show is determined by the {@code data} property of the event target. In a {@link gfx.controls.ButtonGroup ButtonGroup}, that will be the {@code selectedButton.data}.  In a ButtonBar or component, a {@code data} property should return the new view linkage.
	 * @see gfx.controls.ButtonGroup ButtonGroup
	 */
	private function changeView(event: Object): Void
	{
		var linkage: Object = _targetGroup.data;
		if (linkage != null) {
			show(linkage.toString());
		}
	}
}
