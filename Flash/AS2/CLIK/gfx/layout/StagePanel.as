/**
 * The StagePanel derives from the Panel class and provides a single inspectable interface to define the SWF's stage mode. It is expected to be attached to the root level container, and is not intended to be composed inside other Panels.
 */


import flash.geom.Rectangle;
import gfx.core.UIComponent;
import gfx.layout.Panel;


[InspectableList("scaleMode")]
class gfx.layout.StagePanel extends UIComponent
{
	/* CONSTANTS */
	private static var LEFT: Number = 1;
	private static var TOP: Number = 1;
	private static var CENTER: Number = 2;
	private static var RIGHT: Number = 4;
	private static var BOTTOM: Number = 4;
	private static var ALL: Number = LEFT | RIGHT;


	/* PUBLIC VARIABLES */

	/** The scale mode to set on the SWF */
	[Inspectable(type="String", enumeration="noScale,showAll,noBorder", defaultValue="noScale")]
	public var scaleMode:String = "noScale";


	/* PRIVATE VARIABLES */

	private var _offsets: Object;
	private var _orect: flash.geom.Rectangle;

	private var _elements: Array;


	/* INITIALIZATION */

	public function StagePanel()
	{
		super();
	}


	/** @exclude */
	public function toString(): String
	{
		return "[Scaleform StagePanel " + _name + "]";
	}


	/* PRIVATE FUNCTIONS */

	private function onResize(): Void
	{
		validateNow();
	}


	private function configUI(): Void
	{
		super.configUI();

		// *** Setup Stage
		_orect = Stage["originalRect"];
		Stage.addListener(this);
		Stage.align = "C";
		Stage.scaleMode = scaleMode;
		// Compute stage offsets
		var orect: flash.geom.Rectangle = Stage["originalRect"];
		_offsets = {
			left: this._x, right: orect.width - this._width - this._x,
			top: this._y, bottom: orect.height - this._height - this._y
		};

		// *** Introspect content
		_elements = [];
		var vconstrain: Number = 0;
		var hconstrain: Number = 0;

		// Find sub elements
		for (var i in this) {
			var obj:Object = this[i];

			// Child panel?
			if (obj instanceof Panel) {
				var panel: Panel = Panel(obj);

				switch (panel.hconstrain) {
					case "left":
						hconstrain = StagePanel.LEFT;
						break;

					case "center":
						hconstrain = StagePanel.CENTER;
						break;

					case "right":
						hconstrain = StagePanel.RIGHT;
						break;

					case "all":
						hconstrain = StagePanel.ALL;
						break;
				}

				switch (panel.vconstrain) {
					case "top":
						vconstrain = StagePanel.TOP;
						break;

					case "center":
						vconstrain = StagePanel.CENTER;
						break;

					case "bottom":
						vconstrain = StagePanel.BOTTOM;
						break;

					case "all":
						vconstrain = StagePanel.ALL;
						break;
				}

				addElement(obj, hconstrain, vconstrain);
			}

			// Other element?
			else if (obj instanceof MovieClip) {
				// Constrain mode for non-panel elements
				addElement(obj, StagePanel.ALL, StagePanel.ALL);
			}
		}
	}


	public function addElement(clip: Object, hconstrain: Number, vconstrain: Number): Void
	{
		if (clip == null) {
			return;
		}

		var w: Number = Stage.width;
		var h: Number = Stage.height;

		var element: Object = {
			clip:clip,
			hconstrain: hconstrain,
			vconstrain: vconstrain,
			metrics: {
				left: clip._x,
				top: clip._y,
				right: w - (clip._x + clip._width),
				bottom: h - (clip._y + clip._height),
				xscale: clip._xscale,
				yscale: clip._yscale
			}
		}
		_elements.push(element);
	}


	private function draw(): Void
	{
		var vr: flash.geom.Rectangle = Stage["visibleRect"];
		var cw: Number = vr.width - _offsets.right - _offsets.left;
		var ch: Number = vr.height - _offsets.bottom - _offsets.top;

		super.draw();

		processAlignment();
	}


	private function processAlignment(): Void
	{
		// Stage center alignment is in effect
		var origRect: Rectangle = Stage["originalRect"];
		var visRect: Rectangle = Stage["visibleRect"];
		var vwidth = visRect.width;
		var vheight = visRect.height;
		var hoffset: Number = (origRect.width - vwidth) / 2;
		var voffset: Number = (origRect.height - vheight) / 2;
		for (var i: Number = 0; i < _elements.length; i++) {
			var element: Object = _elements[i];
			var clip: MovieClip = MovieClip(element.clip);
			var metrics: Object = element.metrics;
			var w: String = clip.width ? "width" : "_width";
			var h: String = clip.height ? "height" : "_height";

			// Horizontal alignment
			switch (element.hconstrain) {
				case StagePanel.LEFT:
					clip._x = metrics.left + hoffset;
					break;

				case StagePanel.RIGHT:
					clip._x = metrics.left - hoffset;
					break;

				case StagePanel.ALL:
					clip._x = metrics.left + hoffset;
					clip[w] = vwidth - metrics.left - metrics.right;
					break;

				// Stage center alignment takes care of CENTER case automatically
			}

			// Vertical alignment
			switch (element.vconstrain) {
				case StagePanel.TOP:
					clip._y = metrics.top + voffset;
					break;

				case StagePanel.BOTTOM:
					clip._y = metrics.top - voffset;
					break;

				case StagePanel.ALL:
					clip._y = metrics.top + voffset;
					clip[h] = vheight - metrics.top - metrics.bottom;
					break;

				// Stage center alignment takes care of CENTER case automatically
			}
		}
	}
}
