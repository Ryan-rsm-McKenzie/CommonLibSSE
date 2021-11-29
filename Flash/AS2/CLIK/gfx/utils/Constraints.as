/**
 * The Constraints utility helps symbols scale and align the assets contained within them. Elements can be added to a Constraints instance, and they will be reflowed when the {@code update(width,height)} method is called.
 *
 * This utility supports both re-scaling and counter-scaling methods.  Rescaling occurs when the component is scaled back to 100%, and the assets are reflowed and scaled to look correct. Counter-scaling occurs when the component is left at its transformed size, and the assets are scaled inversely to the parent clip.
 */


class gfx.utils.Constraints
{
	/* CONSTANTS */
	/** A constant ENUM value representing the left edge of the component **/
	public static var LEFT: Number = 1;
	/** A constant ENUM value representing the right edge of the component **/
	public static var RIGHT: Number = 2;
	/** A constant ENUM value representing the top edge of the component **/
	public static var TOP: Number = 4;
	/** A constant ENUM value representing the the bottom edge of the component **/
	public static var BOTTOM: Number = 8;
	/** A constant ENUM value representing the the left, right, top, and bottom edges of the component **/
	public static var ALL: Number = LEFT | RIGHT | TOP | BOTTOM;


	/* PUBLIC VARIABLES */

	/** Use a counter-scaling mode instead of a reflowing mode if this property is set to true. **/
	public var scaled: Boolean = false;

	/** The container component that the constraints are applied to. **/
	public var scope: Object;


	/* PRIVATE VARIABLES */

	private var elements: Array;


	/* INITIALIZATION */

	/**
	 * Create a new Constraints instance to assist in the positioning and scaling of an asset inside a component.
	 * @param scope The component scope which contains the constrained asset.
	 * @param scaled Determines if the component is counter-scaled ({@code true}) or not ({@code false}).
	 */
	public function Constraints(scope: MovieClip, scaled: Boolean)
	{
		this.scope = scope;
		this.scaled = scaled;
		elements = [];
	}


	/* PUBLIC FUNCTIONS */

	/**
	 * Add an element to this constraints instance.
	 * @param clip The MovieClip to add as a constrained element.
	 * @param constraints The constraining edges.  A bitwise number which can contain any combination of edge parameters.
	 */
	public function addElement(clip: Object, edges: Number): Void
	{
		if (clip == null) {
			return;
		}

		var xAdjust: Number = 100 / scope._xscale;
		var yAdjust: Number = 100 / scope._yscale;

		// Determine the scope width.  If it is the stage, use the full swf size, otherwise we get 0,0.
		var w: Number = scope._width;
		var h: Number = scope._height;
		if (scope == _root) {
			w = Stage.width;
			h = Stage.height;
		}

		var element: Object = {
			clip: clip,
			edges: edges,
			metrics: {
				left: clip._x,
				top: clip._y,
				right: w * xAdjust - (clip._x + clip._width),
				bottom: h * yAdjust - (clip._y + clip._height),
				xscale: clip._xscale,
				yscale: clip._yscale
			}
		}
		var m = element.metrics;
		elements.push(element);
	}


	/**
	 * Remove an element from this Constraints instance
	 * @param clip A reference to the MovieClip to remove.
	 */
	public function removeElement(clip: MovieClip): Void
	{
		for (var i: Number = 0; i < elements.length; i++) {
			if (elements[i].clip == clip) {
				elements.splice(i, 1);
				break;
			}
		}
	}


	/**
	 * Get the constraints rules for a given object.
	 * @param clip A reference to the MovieClip the constraints apply to.
	 * @returns the constraints rules object for the specified clip
	 */
	public function getElement(clip: Object): Object
	{
		for (var i: Number = 0; i < elements.length; i++) {
			if (elements[i].clip == clip) {
				return elements[i];
			}
		}
		return null;
	}


	/**
	 * Change the width/height and x/y of each registered component based on the scope's updated size and the constraint rules.
	 * @param width The new width of the scope component.
	 * @param height The new height of the scope component.
	 */
	public function update(width: Number, height: Number): Void
	{
		// Deterine the scale factor
		var xAdjust: Number = 100 / scope._xscale;
		var yAdjust: Number = 100 / scope._yscale;

		// Reset the scale based on the original size for reflowing.
		if (!scaled) {
			scope._xscale = 100;
			scope._yscale = 100;
		}

		// Loop through elements, and adjust each one
		for (var i: Number = 0; i < elements.length; i++) {
			var element: Object = elements[i];
			var edges: Number = element.edges;
			var clip: MovieClip = element.clip;
			var metrics: Object = element.metrics;

			var w: String = clip.width != null ? "width" : "_width";
			var h: String = clip.height != null ? "height" : "_height";

			// Use counter-scaling method
			if (scaled) {
				clip._xscale = metrics.xscale * xAdjust;
				clip._yscale = metrics.yscale * yAdjust;

				if ((edges & Constraints.LEFT) > 0) {
					clip._x = metrics.left * xAdjust;
					if ((edges & Constraints.RIGHT) > 0) {
						var nw: Number = width - metrics.left - metrics.right;
						if (!(clip instanceof TextField)) {
							nw = nw * xAdjust;
						}
						clip[w] = nw;
					}
				} else if ((edges & Constraints.RIGHT) > 0) {
					clip._x = (width - metrics.right) * xAdjust - clip._width;
				}

				if ((edges & Constraints.TOP) > 0) {
					clip._y = metrics.top * yAdjust;
					if ((edges & Constraints.BOTTOM) > 0) {
						var nh: Number = height - metrics.top - metrics.bottom;
						if (!(clip instanceof TextField)) {
							nh = nh * yAdjust;
						}
						clip[h] = nh;
					}
				} else if ((edges & Constraints.BOTTOM) > 0) {
					clip._y = (height - metrics.bottom) * yAdjust - clip._height;
				}

			}

			// Use reflowing
			else {
				if ((edges & Constraints.RIGHT) > 0) {
					if ((edges & Constraints.LEFT) > 0) {
						clip[w] = width - metrics.left - metrics.right; // Stretch
					} else {
						clip._x = width - clip._width - metrics.right; // Just move
					}
				}

				if ((edges & Constraints.BOTTOM) > 0) {
					if ((edges & Constraints.TOP) > 0) {
						clip[h] = height - metrics.top - metrics.bottom;
					} else {
						clip._y = height - clip._height - metrics.bottom;
					}
				}
			}
		}
	}


	/** @exclude */
	public function toString(): String
	{
		return "[Scaleform Constraints]";
	}
}
