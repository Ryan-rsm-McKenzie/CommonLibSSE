#include "RE/ExtraForcedTarget.h"

#include "skse64/GameReferences.h"

#include "RE/Offsets.h"
#include "RE/TESObjectREFR.h"
#include "REL/Relocation.h"


namespace RE
{
	ExtraForcedTarget::ExtraForcedTarget() :
		ExtraForcedTarget(*g_invalidRefHandle)
	{}


	ExtraForcedTarget::ExtraForcedTarget(RefHandle a_handle) :
		BSExtraData(),
		handle(a_handle),
		pad14(0)
	{
		REL::Offset<std::uintptr_t> vtbl(Offset::ExtraForcedTarget::Vtbl);
		((std::uintptr_t*)this)[0] = vtbl.GetAddress();
	}


	ExtraDataType ExtraForcedTarget::GetType() const
	{
		return ExtraDataType::kForcedTarget;
	}


	bool ExtraForcedTarget::IsNotEqual(const BSExtraData* a_rhs) const
	{
		auto rhs = static_cast<const ExtraForcedTarget*>(a_rhs);
		return handle != rhs->handle;
	}


	NiPointer<TESObjectREFR> ExtraForcedTarget::GetTarget()
	{
		return TESObjectREFR::LookupByHandle(handle);
	}
}
