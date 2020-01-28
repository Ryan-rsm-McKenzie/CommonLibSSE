#include "RE/TESHavokUtilities.h"

#include "RE/hkpLinkedCollidable.h"
#include "RE/Offsets.h"
#include "RE/TESObjectREFR.h"
#include "REL/Relocation.h"


namespace RE
{
	namespace TESHavokUtilities
	{
		TESObjectREFR* FindCollidableRef(const hkpLinkedCollidable& a_collidable)
		{
			using func_t = function_type_t<decltype(&FindCollidableRef)>;
			REL::Offset<func_t*> func(Offset::TESHavokUtilities::FindCollidableRef);
			return func(a_collidable);
		}
	}
}
