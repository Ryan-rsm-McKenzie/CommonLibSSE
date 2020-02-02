#include "RE/TESHavokUtilities.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	namespace TESHavokUtilities
	{
		TESObjectREFR* FindCollidableRef(const hkpCollidable& a_collidable)
		{
			using func_t = decltype(&FindCollidableRef);
			REL::Offset<func_t> func(Offset::TESHavokUtilities::FindCollidableRef);
			return func(a_collidable);
		}
	}
}
