#include "RE/A/ArmorRatingVisitorBase.h"

namespace RE
{
	bool ArmorRatingVisitorBase::Visit(InventoryEntryData* a_entryData)
	{
		using func_t = decltype(&ArmorRatingVisitorBase::Visit);
		REL::Relocation<func_t> func(REL::Offset(0x6BC190));
		return func(this, a_entryData);
	}
}
