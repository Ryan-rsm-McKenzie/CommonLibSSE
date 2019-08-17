/**
 * The Panel defines a minimal container with support for constraining sub-elements (other Panels and non-Panel elements), defining focus behavior and setting controller input support for sub-elements. This class is expected to be attached to container symbols that require the aforementioned functionality/behaviors.
 */


import gfx.core.UIComponent;
import gfx.utils.Constraints;


[InspectableList("vconstrain", "hconstrain", "focusModeVertical", "focusModeHorizontal", "controllerMask", "visible")]
class gfx.layout.Panel extends UIComponent
{
	/* PUBLIC VARIABLES */

	/** The vertical constraint rule for the Panel. This rule will be used by the Panel's parent panel (if any) for layout purposes. By default no rule is defined for the Panel. */
	[Inspectable(type="String", enumeration="none,top,center,bottom,all", defaultValue="none")]
	public var vconstrain: String = "none";
	/** The horizontal constraint rule for the Panel. This rule will be used by the Panel's parent panel (if any) for layout purposes. By default no rule is defined for the Panel. */
	[Inspectable(type="String", enumeration="none,left,center,right,all", defaultValue="none")]
	public var hconstrain: String = "none";
	/** The vertical focus behavior rule for the Panel. This rule will be used when focus is about to leave the top and bottom edges of the Panel. By default focus will move out of the Panel if there are other focusable elements in the operating direction. */
	[Inspectable(type="String", enumeration="default,loop,hold", defaultValue="default")]
	public var focusModeVertical: String = "default";
	/** The horizontal focus behavior rule for the Panel. This rule will be used when focus is about to leave the left and right edges of the Panel. By default focus will move out of the Panel if there are other focusable elements in the operating direction. */
	[Inspectable(type="String", enumeration="default,loop,hold", defaultValue="default")]
	public var focusModeHorizontal: String = "default";
	/** This bit-mask defines the controllers that are allowed to operate (manipulate focus) inside the Panel. By default all controllers are enabled. */
	[Inspectable(type="String", defaultValue="FFFF")]
	public var controllerMask: String = "FFFF";


	/* PRIVATE VARIABLES */

	private var _constraints: Constraints;
	private var _hcenter: Array;
	private var _vcenter: Array;


	/* INITIALIZATION */

	public function Panel()
	{
		super();
	}


	/** @exclude */
	public function toString(): String
	{
		return "[Scaleform Panel " + _name + "]";
	}


	/* PRIVATE FUNCTIONS */

	private function configUI(): Void
	{
		super.configUI();

		// Setup focus group system mask
		MovieClip(this).focusGroupMask = parseInt(controllerMask, 16);

		// Constrain mode for non-panel elements
		var hstretch: Boolean = (this.hconstrain == "all");
		var vstretch: Boolean = (this.vconstrain == "all");

		_constraints = new Constraints(this);
		_hcenter = [];
		_vcenter = [];

		// Find sub elements
		for (var i in this) {
			var obj: Object = this[i];

			// Child panel?
			if (obj instanceof Panel) {
				var vconstrain: Number = 0;
				var hconstrain: Number = 0;
				var panel:Panel = Panel(obj);

				switch (panel.vconstrain) {
					case "top":
						vconstrain = Constraints.TOP;
						break;

					case "center":
						addToVCenter(panel);
						break;

					case "bottom":
						vconstrain = Constraints.BOTTOM;
						break;

					case "all":
						vconstrain = Constraints.TOP | Constraints.BOTTOM;
						break;
				}

				switch (panel.hconstrain) {
					case "left":
						hconstrain = Constraints.LEFT;
						break;

					case "center":
						addToHCenter(panel);
						break;

					case "right":
						hconstrain = Constraints.RIGHT;
						break;

					case "all":
						hconstrain = Constraints.LEFT | Constraints.RIGHT;
						break;
				}

				_constraints.addElement(obj, vconstrain | hconstrain);
			}

			// Other element?
			else if (obj instanceof MovieClip) {
				if (hstretch || vstretch) {
					_constraints.addElement(obj, (hstretch ? (Constraints.LEFT | Constraints.RIGHT) : 0) |
											(vstretch ? (Constraints.TOP | Constraints.BOTTOM) : 0));
				}
			}
		}
	}


	private function addToHCenter(clip: MovieClip): Void
	{
		if (!_hcenter) {
			_hcenter = [];
		}

		_hcenter.push( { clip: clip, metrics: { left: clip._x, right: _width - clip._x - clip._width } } );
	}


	private function addToVCenter(clip: MovieClip): Void
	{
		if (!_vcenter) {
			_vcenter = [];
		}

		_vcenter.push({ clip: clip, metrics: { top: clip._y, right: _height - clip._y - clip._height } } );
	}


	private function draw(): Void
	{
		_constraints.update(__width, __height);

		if (_hcenter || _vcenter) {
			var o:flash.geom.Rectangle = Stage["originalRect"];
			var wdelta: Number = (__width - o.width) / 2;
			var hdelta: Number = (__height - o.height) / 2;

			if (_vcenter) {
				for (var i: Number = 0; i < _vcenter.length; i++) {
					var elem: Object = _vcenter[i];
					var clip: MovieClip = elem.clip;
					var metrics: Object = elem.metrics;
					clip._y = metrics.top + hdelta;
				}
			}

			if (_hcenter) {
				for (var i: Number = 0; i < _hcenter.length; i++) {
					var elem: Object = _hcenter[i];
					var clip: MovieClip = elem.clip;
					var metrics: Object = elem.metrics;
					clip._x = metrics.left + wdelta;
				}
			}
		}
	}
}
