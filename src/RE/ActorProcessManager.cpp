#include "RE/ActorProcessManager.h"

#include "RE/HighProcess.h"
#include "RE/Offsets.h"
#include "REL/Relocation.h"
#include "SKSE/API.h"


namespace RE
{
	TESForm* ActorProcessManager::GetEquippedLeftHand()
	{
		return equippedObjects[Hands::kLeft];
	}


	TESForm* ActorProcessManager::GetEquippedRightHand()
	{
		return equippedObjects[Hands::kRight];
	}


	bool ActorProcessManager::IsArrested() const
	{
		return highProcess && highProcess->arrested;
	}


	bool ActorProcessManager::IsGhost() const
	{
		return unk050 && (unk050->flags2 & Data050::Flag2::kGhost) != Data050::Flag2::kNone;
	}


	void ActorProcessManager::SetArrested(bool a_arrested)
	{
		if (highProcess) {
			highProcess->arrested = a_arrested;
		}
	}


	void ActorProcessManager::SetBaseScale(float a_scale)
	{
		using func_t = function_type_t<decltype(&ActorProcessManager::SetBaseScale)>;
		REL::Offset<func_t*> func(Offset::ActorProcessManager::SetBaseScale);
		return func(this, a_scale);
	}


	void ActorProcessManager::SetEquipFlag(Flag a_flag)
	{
		using func_t = function_type_t<decltype(&ActorProcessManager::SetEquipFlag)>;
		REL::Offset<func_t*> func(Offset::ActorProcessManager::SetEquipFlag);
		return func(this, a_flag);
	}


	void ActorProcessManager::UpdateEquipment(Actor* a_actor)
	{
		UpdateEquipment_Internal(a_actor);
		SKSE::NiNodeUpdateEvent event(a_actor);
		auto source = SKSE::GetNiNodeUpdateEventSource();
		source->SendEvent(&event);
	}


	void ActorProcessManager::UpdateEquipment_Internal(Actor* a_actor)
	{
		using func_t = function_type_t<decltype(&ActorProcessManager::UpdateEquipment_Internal)>;
		REL::Offset<func_t*> func(Offset::ActorProcessManager::UpdateEquipment);
		return func(this, a_actor);
	}
}
