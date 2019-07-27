#include "RE/ActorProcessManager.h"

#include "skse64/GameFormComponents.h"  // ActorProcessManager

#include "SKSE/API.h"  // NiNodeUpdateEvent


namespace RE
{
	void ActorProcessManager::SetEquipFlag(Flag a_flag)
	{
		using func_t = function_type_t<decltype(&ActorProcessManager::SetEquipFlag)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::ActorProcessManager, SetEquipFlag, func_t*);
		return func(this, a_flag);
	}


	void ActorProcessManager::UpdateEquipment(Actor* a_actor)
	{
		using func_t = function_type_t<decltype(&ActorProcessManager::UpdateEquipment)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::ActorProcessManager, UpdateEquipment, func_t*);
		return func(this, a_actor);
	}


	void ActorProcessManager::SetDataFlag(float a_flag)
	{
		using func_t = function_type_t<decltype(&ActorProcessManager::SetDataFlag)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::ActorProcessManager, SetDataFlag, func_t*);
		return func(this, a_flag);
	}


	void ActorProcessManager::UpdateEquipment_Hooked(Actor* a_actor)
	{
		UpdateEquipment(a_actor);
		SKSE::NiNodeUpdateEvent event(a_actor);
		auto source = SKSE::GetNiNodeUpdateEventSource();
		source->SendEvent(&event);
	}


	TESForm* ActorProcessManager::GetEquippedLeftHand()
	{
		return equippedObjects[Hands::kLeft];
	}


	TESForm* ActorProcessManager::GetEquippedRightHand()
	{
		return equippedObjects[Hands::kRight];
	}


	bool ActorProcessManager::IsGhost() const
	{
		return unk050 && (unk050->flags2 & Data050::Flag2::kGhost) != Data050::Flag2::kNone;
	}
}
