#include "RE/ExtraForcedTarget.h"

#include "RE/Offsets.h"
#include "RE/TESObjectREFR.h"
#include "REL/Relocation.h"


namespace RE
{
	ExtraForcedTarget::ExtraForcedTarget() :
		ExtraForcedTarget(ObjectRefHandle())
	{}


	ExtraForcedTarget::ExtraForcedTarget(ObjectRefHandle a_target) :
		BSExtraData(),
		target(a_target),
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
		return target != rhs->target;
	}


	NiPointer<TESObjectREFR> ExtraForcedTarget::GetTarget()
	{
		return target.get();
	}
}
