#pragma once

#include "RE/B/BSTSingleton.h"

namespace RE
{
	class Actor;
	class BGSEquipSlot;
	class ExtraDataList;
	class SpellItem;
	class TESBoundObject;
	class TESShout;

	class ActorEquipManager : public BSTSingletonSDM<ActorEquipManager>
	{
	public:
		static ActorEquipManager* GetSingleton();

		void EquipObject(Actor* a_actor, TESBoundObject* a_object, ExtraDataList* a_extraData = nullptr, std::uint32_t a_count = 1, const BGSEquipSlot* a_slot = nullptr, bool a_queueEquip = true, bool a_forceEquip = false, bool a_playSounds = true, bool a_applyNow = false);
		void EquipShout(Actor* a_actor, TESShout* a_shout);
		void EquipSpell(Actor* a_actor, SpellItem* a_spell, const BGSEquipSlot* a_slot = nullptr);
		bool UnequipObject(Actor* a_actor, TESBoundObject* a_object, ExtraDataList* a_extraData = nullptr, std::uint32_t a_count = 1, const BGSEquipSlot* a_slot = nullptr, bool a_queueEquip = true, bool a_forceEquip = false, bool a_playSounds = true, bool a_applyNow = false, const BGSEquipSlot* a_slotToReplace = nullptr);

		// members
		bool unk01;  // 01
	};
	static_assert(sizeof(ActorEquipManager) == 0x2);
}
