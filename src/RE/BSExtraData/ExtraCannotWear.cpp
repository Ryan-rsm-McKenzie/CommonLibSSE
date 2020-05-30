#include "RE/BSExtraData/ExtraCannotWear.h"


namespace RE
{
	ExtraCannotWear::ExtraCannotWear() :
		BSExtraData()
	{
		REL::Offset<std::uintptr_t> vtbl(Offset::ExtraCannotWear::Vtbl);
		((std::uintptr_t*)this)[0] = vtbl.GetAddress();
	}


	ExtraDataType ExtraCannotWear::GetType() const
	{
		return ExtraDataType::kCannotWear;
	}
}
