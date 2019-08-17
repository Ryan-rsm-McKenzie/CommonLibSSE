/**
 * The locale class manages translation calls from the component framework, interfacing directly with translation features of the player, or using the GameEngine to make calls to the game for translation.
 */


class gfx.utils.Locale
{
	/* PUBLIC FUNCTIONS */

	/**
	 * Requested a Locale string from the Player. Currently, this is not wired to the GameEngine or Player.
	 * @param value The untranslated string or ID.
	 * @returns A translated string
	 */
	public static function getTranslatedString(value: String): String
	{
		return value;	//Intrinsic.getTranslatedString(value);
	}
}
