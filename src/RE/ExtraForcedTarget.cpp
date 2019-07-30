#include "RE/Skyrim.h"

#include "skse64/GameExtraData.h"  // s_ExtraForcedTargetVtbl

#include "RE/TESObjectREFR.h"  // TESObjectREFR


namespace RE
{
	ExtraForcedTarget::ExtraForcedTarget() :
		BSExtraData(),
		handle(*g_invalidRefHandle),
		pad14(0)
	{
		((std::uintptr_t*)this)[0] = s_ExtraForcedTargetVtbl.GetUIntPtr();
	}


	ExtraForcedTarget::ExtraForcedTarget(RefHandle a_handle) :
		BSExtraData(),
		handle(a_handle),
		pad14(0)
	{
		((std::uintptr_t*)this)[0] = s_ExtraForcedTargetVtbl.GetUIntPtr();
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
		NiPointer<TESObjectREFR> refr;
		RE::TESObjectREFR::LookupByHandle(handle, refr);
		return refr;
	}
}
