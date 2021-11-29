#include "RE/T/TESHavokUtilities.h"

namespace RE
{
	namespace TESHavokUtilities
	{
		TESObjectREFR* FindCollidableRef(const hkpCollidable& a_collidable)
		{
			using func_t = decltype(&FindCollidableRef);
			REL::Relocation<func_t> func{ Offset::TESHavokUtilities::FindCollidableRef };
			return func(a_collidable);
		}
	}
}
