/**
 * Create pop-up clips that reside in the application root, in order to be shown above all other content.  PopUpManager can be used by {@link DropdownMenu}, {@link Dialog}, Tooltips, {@link DragManager}, and other components. Different types of pop-up content can use pre-determined container depths to ensure a logical order of pop-ups when multiple pop-ups are displayed at the same time. For instance, tooltips and dropdowns will always be higher than dialogs. Constants are provided for pre-determined depth containers, however any number can be passed to layer content in a custom manner.
 */


class gfx.managers.PopUpManager
{
	/* PRIVATE VARIABLES */
	private static var index: Number = 0; // An auto-increment index used for pop-up clip names.


	/* PUBLIC FUNCTIONS */

	/**
	 * Create a pop-up clip.
	 * @param context The context used to create the popup instance. Typically this would be the source for the popup.
	 * @param linkage The linkage ID of the clip in the library.
	 * @param initProperties MovieClip properties to be passed into the pop-up.
	 * @param relativeTo Position the clip relative to a different MovieClip. Existing _x and _y properties in the {@code initProperties} object are converted to the global space using the relativeTo MovieClip as the scope.
	 * @returns A reference to the created pop-up.
	 */
	public static function createPopUp(context: MovieClip, linkage: String, initProperties: Object, relativeTo: MovieClip): MovieClip
	{
		var targetContainer: MovieClip = context._parent;
		if (!targetContainer) {
			targetContainer = context;
		}

		var depth: Number = targetContainer.getNextHighestDepth();
		var baseProps: Object = {_x: initProperties._x, _y: initProperties._y};

		if (relativeTo != undefined) {
			var p: Object = {x: initProperties._x, y: initProperties._y};
			relativeTo.localToGlobal(p);
			targetContainer.globalToLocal(p);
			if (initProperties._x != undefined) {
				initProperties._x = p.x;
			}

			if (initProperties._y != undefined) {
				initProperties._y = p.y;
			}
		}

		var clip: MovieClip = targetContainer.attachMovie(linkage, "popup" + index++, depth, initProperties);
		if (!clip) {
			trace("PopUpManager: attachMovie failed. Suggest moving popup source inside a symbol. Trying ("+ context +") as context..");
			initProperties._x = baseProps._x;
			initProperties._y = baseProps._y;
			clip = createPopUpRetry(context, linkage, initProperties, relativeTo);
			if (!clip) {
				trace("PopUpManager: failed all options.");
			}

			return clip;
		}

		clip.topmostLevel = true;
		return clip;
	}


	/**
	 * Remove a currently open pop-up.
	 * @param popUp The pop-up to remove.
	 */
	public static function destroyPopUp(popUp: MovieClip): Void
	{
		popUp.removeMovieClip();
	}


	/**
	 * Move a PopUp relative to another MovieClip.
	 * @param context The context used to create the popup instance. Typically this would be the source for the popup.
	 * @param popUp The pop-up to move.
	 * @param scope The scope to translate the coordinates from.
	 * @param x The new x position.
	 * @param y The new y position.
	 */
	public static function movePopUp(context: MovieClip, popUp: MovieClip, relativeTo: MovieClip, x: Number, y: Number): Void
	{
		if (popUp == null) {
			return;
		}

		var targetContainer: MovieClip = context._parent;
		if (!targetContainer) {
			targetContainer = context;
		}

		var p: Object = {x: x, y: y};
		relativeTo.localToGlobal(p);
		targetContainer.globalToLocal(p);
		popUp._x = p.x;
		popUp._y = p.y;
	}


	/**
	 * Center a pop-up in the stage.
	 * @param popUp The pop-up to center
	 */
	public static function centerPopUp(popUp: MovieClip): Void
	{
		if (popUp == null) {
			return;
		}

		popUp._x = Stage.width - popUp._width >> 1;
		popUp._y = Stage.height - popUp._height >> 1;
	}


	/* PRIVATE FUNCTIONS */

	// Fallback to solve an edge case on symbol lookup failure
	private static function createPopUpRetry(context: MovieClip, linkage: String, initProperties: Object, relativeTo: MovieClip): MovieClip
	{
		var depth: Number = context.getNextHighestDepth();
		if (relativeTo != null) {
			var p: Object = {x: initProperties._x, y: initProperties._y};
			relativeTo.localToGlobal(p);
			context.globalToLocal(p);

			if (initProperties._x != null) {
				initProperties._x = p.x;
			}

			if (initProperties._y != null) {
				initProperties._y = p.y;
			}
		}

		var clip: MovieClip = context.attachMovie(linkage, "popup" + index++, depth, initProperties);
		clip.topmostLevel = true;
		return clip;
	}
}
