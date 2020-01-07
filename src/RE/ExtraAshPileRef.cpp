#include "RE/ExtraAshPileRef.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


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
		REL::Offset<std::uintptr_t> vtbl(Offset::ExtraAshPileRef::Vtbl);
		((std::uintptr_t*)this)[0] = vtbl.GetAddress();
	}


	ExtraDataType ExtraAshPileRef::GetType() const
	{
		return ExtraDataType::kAshPileRef;
	}
}
