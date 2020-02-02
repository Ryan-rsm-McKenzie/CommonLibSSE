#include "RE/MagicFavorites.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	MagicFavorites* MagicFavorites::GetSingleton()
	{
		REL::Offset<MagicFavorites**> singleton(Offset::MagicFavorites::Singleton);
		return *singleton;
	}
}
