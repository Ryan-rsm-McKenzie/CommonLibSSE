#include "RE/E/ExtraCharge.h"

namespace RE
{
	ExtraCharge::ExtraCharge() :
		BSExtraData(),
		charge(0.0F),
		pad14(0)
	{
		REL::Relocation<std::uintptr_t> vtbl{ Offset::ExtraCharge::Vtbl };
		((std::uintptr_t*)this)[0] = vtbl.address();
	}

	ExtraDataType ExtraCharge::GetType() const
	{
		return ExtraDataType::kCannotWear;
	}

	bool ExtraCharge::IsNotEqual(const BSExtraData* a_rhs) const
	{
		auto rhs = static_cast<const ExtraCharge*>(a_rhs);
		return charge != rhs->charge;
	}
}
