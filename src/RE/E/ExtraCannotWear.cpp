#include "RE/E/ExtraCannotWear.h"

namespace RE
{
	ExtraCannotWear::ExtraCannotWear() :
		BSExtraData()
	{
		REL::Relocation<std::uintptr_t> vtbl{ VTABLE[0] };
		((std::uintptr_t*)this)[0] = vtbl.address();
	}

	ExtraDataType ExtraCannotWear::GetType() const
	{
		return ExtraDataType::kCannotWear;
	}
}
