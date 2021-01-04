#include "RE/E/ExtraAshPileRef.h"

namespace RE
{
	ExtraAshPileRef::ExtraAshPileRef() :
		ExtraAshPileRef(ObjectRefHandle())
	{}

	ExtraAshPileRef::ExtraAshPileRef(ObjectRefHandle ashPileRef) :
		BSExtraData(),
		ashPileRef(ashPileRef),
		pad14(0)
	{
		REL::Relocation<std::uintptr_t> vtbl{ Offset::ExtraAshPileRef::Vtbl };
		((std::uintptr_t*)this)[0] = vtbl.address();
	}

	ExtraDataType ExtraAshPileRef::GetType() const
	{
		return ExtraDataType::kAshPileRef;
	}
}
