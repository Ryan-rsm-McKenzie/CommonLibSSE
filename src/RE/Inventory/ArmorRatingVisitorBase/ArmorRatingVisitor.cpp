#include "RE/Inventory/ArmorRatingVisitorBase/ArmorRatingVisitor.h"

namespace RE
{
	bool ArmorRatingVisitor::HaveNotVisitedArmor(TESObjectARMO* a_armor)
	{
		using func_t = decltype(&ArmorRatingVisitor::HaveNotVisitedArmor);
		REL::Offset<func_t> func(REL::ID(39221));
		return func(this, a_armor);
	}

	void ArmorRatingVisitor::VisitArmor(TESObjectARMO* a_armor)
	{
		using func_t = decltype(&ArmorRatingVisitor::VisitArmor);
		REL::Offset<func_t> func(REL::ID(39217));
		return func(this, a_armor);
	}
}