#include "RE/ExtraCannotWear.h"

#include "skse64/GameExtraData.h"  // s_ExtraCannotWearVtbl


namespace RE
{
	ExtraCannotWear::ExtraCannotWear() :
		BSExtraData()
	{
		((std::uintptr_t*)this)[0] = s_ExtraCannotWearVtbl.GetUIntPtr();
	}


	ExtraDataType ExtraCannotWear::GetType() const
	{
		return ExtraDataType::kCannotWear;
	}
}
