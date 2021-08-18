#include "RE/M/MagicFavorites.h"

namespace RE
{
	MagicFavorites* MagicFavorites::GetSingleton()
	{
		REL::Relocation<MagicFavorites**> singleton{ Offset::MagicFavorites::Singleton };
		return *singleton;
	}
}
