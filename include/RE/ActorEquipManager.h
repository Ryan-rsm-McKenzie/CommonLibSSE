#pragma once

#include "RE/BSTSingleton.h"


namespace RE
{
	class Actor;
	class BGSEquipSlot;
	class ExtraDataList;
	class TESBoundObject;


	class ActorEquipManager : public BSTSingletonSDM<ActorEquipManager>
	{
	public:
		static ActorEquipManager* GetSingleton();

		void EquipObject(Actor* a_actor, TESBoundObject* a_object, ExtraDataList* a_extraData = 0, UInt32 a_count = 1, const BGSEquipSlot* a_slot = 0, bool a_queueEquip = true, bool a_forceEquip = false, bool a_playSounds = true, bool a_applyNow = false);
		bool UnequipObject(Actor* a_actor, TESBoundObject* a_object, ExtraDataList* a_extraData = 0, UInt32 a_count = 1, const BGSEquipSlot* a_slot = 0, bool a_queueEquip = true, bool a_forceEquip = false, bool a_playSounds = true, bool a_applyNow = false, const BGSEquipSlot* a_slotToReplace = 0);


		// members
		bool unk01;	 // 01
	};
	STATIC_ASSERT(sizeof(ActorEquipManager) == 0x2);
}
