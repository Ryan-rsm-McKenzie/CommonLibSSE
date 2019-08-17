/**
 * DataProvider that can be bound to a game/application.  This data provider can register itself with the backend, and interface with data stores linked to CLIK components on the stage.
 */


import flash.external.ExternalInterface;
import gfx.events.EventDispatcher;


class gfx.data.GameDataProvider extends EventDispatcher
{
	/* PUBLIC VARIABLES */

	public var length = 0;


	/* PRIVATE VARIABLES */

	private var bindingName:String;


	/* INITIALIZATION */

	public function GameDataProvider(binding: String)
	{
		super();
		bindingName = binding;
		ExternalInterface.call("__registerModel", bindingName, this);
	}


	/* PUBLIC FUNCTIONS */

	// Request the data of a specific element. Not used by the list control; used by the LoginPanel to query individual profiles.
	public function requestItemAt(index: Number, scope: Object, callBack: String): Void
	{
		ExternalInterface.call("__requestItemAt", bindingName, index, scope, callBack);
	}


	// Request the data of a certain index range. Called by the list control that uses this data provider.
	public function requestItemRange(startIndex: Number, endIndex: Number, scope: Object, callBack: String): Void
	{
		ExternalInterface.call("__requestItemRange", bindingName, startIndex, endIndex, scope, callBack);
	}


	// Called when the number of profiles has changed. This forces a redraw of the list control as well.
	public function invalidate(length: Number): Void
	{
		this.length = length;
		dispatchEvent({type: "change"});
	}
}
