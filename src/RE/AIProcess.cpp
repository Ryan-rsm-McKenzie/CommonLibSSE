#include "RE/AIProcess.h"

#include "RE/HighProcess.h"
#include "RE/Offsets.h"
#include "REL/Relocation.h"
#include "SKSE/API.h"


namespace RE
{
	TESForm* AIProcess::GetEquippedLeftHand()
	{
		return equippedObjects[Hands::kLeft];
	}


	TESForm* AIProcess::GetEquippedRightHand()
	{
		return equippedObjects[Hands::kRight];
	}


	bool AIProcess::IsArrested() const
	{
		return highProcess && highProcess->arrested;
	}


	bool AIProcess::IsGhost() const
	{
		return unk050 && (unk050->flags2 & Data050::Flag2::kGhost) != Data050::Flag2::kNone;
	}


	void AIProcess::SetArrested(bool a_arrested)
	{
		if (highProcess) {
			highProcess->arrested = a_arrested;
		}
	}


	void AIProcess::SetBaseScale(float a_scale)
	{
		using func_t = function_type_t<decltype(&AIProcess::SetBaseScale)>;
		REL::Offset<func_t*> func(Offset::AIProcess::SetBaseScale);
		return func(this, a_scale);
	}


	void AIProcess::SetEquipFlag(Flag a_flag)
	{
		using func_t = function_type_t<decltype(&AIProcess::SetEquipFlag)>;
		REL::Offset<func_t*> func(Offset::AIProcess::SetEquipFlag);
		return func(this, a_flag);
	}


	void AIProcess::UpdateEquipment(Actor* a_actor)
	{
		UpdateEquipment_Internal(a_actor);
		SKSE::NiNodeUpdateEvent event(a_actor);
		auto source = SKSE::GetNiNodeUpdateEventSource();
		source->SendEvent(&event);
	}


	void AIProcess::UpdateEquipment_Internal(Actor* a_actor)
	{
		using func_t = function_type_t<decltype(&AIProcess::UpdateEquipment_Internal)>;
		REL::Offset<func_t*> func(Offset::AIProcess::UpdateEquipment);
		return func(this, a_actor);
	}
}
