#include "RE/ExtraCharge.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	ExtraCharge::ExtraCharge() :
		BSExtraData(),
		charge(0.0F),
		pad14(0)
	{
		REL::Offset<std::uintptr_t> vtbl(Offset::ExtraCharge::Vtbl);
		((std::uintptr_t*)this)[0] = vtbl.GetAddress();
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
