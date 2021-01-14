#include "RE/A/ActorEquipManager.h"

namespace RE
{
	ActorEquipManager* ActorEquipManager::GetSingleton()
	{
		REL::Relocation<ActorEquipManager**> singleton{ Offset::ActorEquipManager::Singleton };
		return *singleton;
	}

	void ActorEquipManager::EquipObject(Actor* a_actor, TESBoundObject* a_object, ExtraDataList* a_extraData, std::uint32_t a_count, const BGSEquipSlot* a_slot, bool a_queueEquip, bool a_forceEquip, bool a_playSounds, bool a_applyNow)
	{
		using func_t = decltype(&ActorEquipManager::EquipObject);
		REL::Relocation<func_t> func{ Offset::ActorEquipManager::EquipObject };
		return func(this, a_actor, a_object, a_extraData, a_count, a_slot, a_queueEquip, a_forceEquip, a_playSounds, a_applyNow);
	}

	void ActorEquipManager::EquipShout(Actor* a_actor, TESShout* a_shout)
	{
		using func_t = decltype(&ActorEquipManager::EquipShout);
		REL::Relocation<func_t> func{ REL::ID(37941) };
		return func(this, a_actor, a_shout);
	}

	void ActorEquipManager::EquipSpell(Actor* a_actor, SpellItem* a_spell, const BGSEquipSlot* a_slot)
	{
		using func_t = decltype(&ActorEquipManager::EquipSpell);
		REL::Relocation<func_t> func{ REL::ID(37939) };
		return func(this, a_actor, a_spell, a_slot);
	}

	bool ActorEquipManager::UnequipObject(Actor* a_actor, TESBoundObject* a_object, ExtraDataList* a_extraData, std::uint32_t a_count, const BGSEquipSlot* a_slot, bool a_queueEquip, bool a_forceEquip, bool a_playSounds, bool a_applyNow, const BGSEquipSlot* a_slotToReplace)
	{
		using func_t = decltype(&ActorEquipManager::UnequipObject);
		REL::Relocation<func_t> func{ Offset::ActorEquipManager::UnequipObject };
		return func(this, a_actor, a_object, a_extraData, a_count, a_slot, a_queueEquip, a_forceEquip, a_playSounds, a_applyNow, a_slotToReplace);
	}
}
