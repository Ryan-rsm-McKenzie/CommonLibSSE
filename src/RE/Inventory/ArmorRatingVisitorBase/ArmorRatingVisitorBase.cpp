#include "RE/Inventory/ArmorRatingVisitorBase/ArmorRatingVisitorBase.h"

namespace RE
{
	bool ArmorRatingVisitorBase::Visit(InventoryEntryData* a_entryData)
	{
		using func_t = decltype(&ArmorRatingVisitorBase::Visit);
		REL::Offset<func_t> func(REL::ID(39223));
		return func(this, a_entryData);
	}
}