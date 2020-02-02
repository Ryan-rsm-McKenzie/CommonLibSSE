#include "RE/MagicFavorites.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	MagicFavorites* MagicFavorites::GetSingleton()
	{
		using func_t = decltype(&MagicFavorites::GetSingleton);
		REL::Offset<func_t> func(Offset::MagicFavorites::Singleton);
		return func();
	}
}
