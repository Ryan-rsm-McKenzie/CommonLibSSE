/**
 * The GameDelegate marshals calls from Flash into the Game Engine, and vice versa using an ID-system. An immediate result returned from the Game Engine will be passed back to the calling object via the provided scope and callBack. Asynchronous results require an appropriate callback already installed with the GameDelegate.
 */


import flash.external.ExternalInterface;


class gfx.io.GameDelegate
{
	/* PRIVATE VARIABLES */

	private static var responseHash: Object = {};
	private static var callBackHash: Object = {};
	private static var nextID: Number = 0;
	private static var initialized: Boolean = false;


	/* PUBLIC FUNCTIONS */

	/**
	 * Make a call on the Game Engine.
	 * @param methodName The name of the method in the Game Engine to call.
	 * @param params An array of parameters to call on the method.
	 * @param scope The scope of the callBack.
	 * @param callBack The function name of the callBack.
	 */
	public static function call(methodName: String, params: Array, scope: Object, callBack: String): Void
	{
		if (!initialized) {
			initialize();
		}

		var uid: Number = nextID++; // A unique ID is created to identify the callBack if it is asynchronous
		responseHash[uid] = [scope, callBack];// Add the ID to a hash so that it can be connected later.
		params.unshift(methodName, uid); // Prepend the method name and UID
		ExternalInterface.call.apply(null, params); // Make the call on the game Engine.
		delete responseHash[uid];
	}


	/**
	 * The Game Engine has sent data. The callBack associated with the uid will be made.
	 * @param uid The unique ID created when the call was first made.
	 * @param ...rest The parameters to return in the callBack.
	 */
	public static function receiveResponse(uid: Number): Void
	{
		var callBack: Array = responseHash[uid];
		if (callBack == null) {
			return;
		}

		var scope: Object = callBack[0];
		var functionName: String = callBack[1];
		scope[functionName].apply(scope, arguments.slice(1)); // Make the callBack
	}


	/**
	 * Add a callBack that the Game Engine can use to pass in data using a specific method name. The callBack will be made any time the method is called from the Game Engine. Only one component can register for a specific method call.
	 * @param methodName The name of the method to call on the game.
	 * @param scope The scope of the callBack.
	 * @param callBack The function name of the callBack.
	 */
	public static function addCallBack(methodName: String, scope: Object, callBack: String): Void
	{
		if (!initialized) {
			initialize();
		}

		callBackHash[methodName] = [scope, callBack]; // Add an item to a hash
	}


	/**
	 * A method has been called from the Game Engine. Route the function call to the callBack that has already been registered.
	 * @param methodName The name of the method that has been called from the GameEngine.
	 */
	public static function receiveCall(methodName: String): Void
	{
		var callBack: Object = callBackHash[methodName];
		if (callBack == null) {
			return;
		}

		var scope: Object = callBack[0];
		var functionName: String = callBack[1];
		scope[functionName].apply(scope, arguments.slice(1));
	}


	/* PRIVATE FUNCTIONS */

	/**
	 * Initialize the ExternalInterface callBacks. This happens once the application has requested notification for a callBack.
	 */
	private static function initialize(): Void
	{
		initialized = true;
		ExternalInterface.addCallback("call", GameDelegate, receiveCall);
		ExternalInterface.addCallback("respond", GameDelegate, receiveResponse);
	}
}
