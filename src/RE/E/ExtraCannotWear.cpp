#include "RE/E/ExtraCannotWear.h"

namespace RE
{
	ExtraCannotWear::ExtraCannotWear() :
		BSExtraData()
	{
		REL::Relocation<std::uintptr_t> vtbl{ Offset::ExtraCannotWear::Vtbl };
		((std::uintptr_t*)this)[0] = vtbl.address();
	}

	ExtraDataType ExtraCannotWear::GetType() const
	{
		return ExtraDataType::kCannotWear;
	}
}
