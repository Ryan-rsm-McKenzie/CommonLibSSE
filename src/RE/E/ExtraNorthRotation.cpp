#include "RE/E/ExtraNorthRotation.h"

namespace RE
{
	ExtraNorthRotation::ExtraNorthRotation() :
		BSExtraData(),
		northRot(0.0F),
		pad14(0)
	{
		REL::Relocation<std::uintptr_t> vtbl{ ExtraNorthRotation::VTABLE[0] };
		((std::uintptr_t*)this)[0] = vtbl.address();
	}

	ExtraDataType ExtraNorthRotation::GetType() const
	{
		return ExtraDataType::kNorthRotation;
	}
}
