#include "RE/ExtraCharge.h"


#include "skse64/GameExtraData.h"  // s_ExtraChargeVtbl


namespace RE
{
	ExtraCharge::ExtraCharge() :
		BSExtraData()
	{
		((std::uintptr_t*)this)[0] = s_ExtraChargeVtbl.GetUIntPtr();
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
