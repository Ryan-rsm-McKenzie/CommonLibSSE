#include "RE/Menus/MagicFavorites.h"


namespace RE
{
	MagicFavorites* MagicFavorites::GetSingleton()
	{
		REL::Offset<MagicFavorites**> singleton(Offset::MagicFavorites::Singleton);
		return *singleton;
	}
}
