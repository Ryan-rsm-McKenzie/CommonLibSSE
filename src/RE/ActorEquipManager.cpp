#include "RE/ActorEquipManager.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	ActorEquipManager* ActorEquipManager::GetSingleton()
	{
		REL::Offset<ActorEquipManager**> singleton(Offset::ActorEquipManager::Singleton);
		return *singleton;
	}


	void ActorEquipManager::EquipObject(Actor* a_actor, TESBoundObject* a_object, ExtraDataList* a_extraData, UInt32 a_count, const BGSEquipSlot* a_slot, bool a_queueEquip, bool a_forceEquip, bool a_playSounds, bool a_applyNow)
	{
		using func_t = decltype(&ActorEquipManager::EquipObject);
		REL::Offset<func_t> func(Offset::ActorEquipManager::EquipObject);
		return func(this, a_actor, a_object, a_extraData, a_count, a_slot, a_queueEquip, a_forceEquip, a_playSounds, a_applyNow);
	}


	bool ActorEquipManager::UnequipObject(Actor* a_actor, TESBoundObject* a_object, ExtraDataList* a_extraData, UInt32 a_count, const BGSEquipSlot* a_slot, bool a_queueEquip, bool a_forceEquip, bool a_playSounds, bool a_applyNow, const BGSEquipSlot* a_slotToReplace)
	{
		using func_t = decltype(&ActorEquipManager::UnequipObject);
		REL::Offset<func_t> func(Offset::ActorEquipManager::UnequipObject);
		return func(this, a_actor, a_object, a_extraData, a_count, a_slot, a_queueEquip, a_forceEquip, a_playSounds, a_applyNow, a_slotToReplace);
	}
}
