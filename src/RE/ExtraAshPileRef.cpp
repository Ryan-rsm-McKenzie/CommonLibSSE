#include "RE/ExtraAshPileRef.h"

#include "skse64/GameReferences.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	ExtraAshPileRef::ExtraAshPileRef() :
		ExtraAshPileRef(*g_invalidRefHandle)
	{}


	ExtraAshPileRef::ExtraAshPileRef(RefHandle a_refHandle) :
		BSExtraData(),
		refHandle(a_refHandle),
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
