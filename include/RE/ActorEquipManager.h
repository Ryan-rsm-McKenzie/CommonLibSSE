#pragma once

#include "RE/BSTSingleton.h"


namespace RE
{
	class Actor;
	class BGSEquipSlot;
	class ExtraDataList;
	class TESForm;


	class ActorEquipManager : public BSTSingletonSDM<ActorEquipManager>
	{
	public:
		static ActorEquipManager* GetSingleton();
		/*
		 * @param a_arg9 = 0
		 */
		void EquipItem(Actor* a_actor, TESForm* a_item, ExtraDataList* a_extraData, SInt32 a_count, BGSEquipSlot* a_equipSlot, bool a_withEquipSound, bool a_preventUnequip, bool a_showMsg, bool a_arg9 = false);
		/*
		 * @param a_arg6 = true
		 * @param a_arg8 = true
		 * @param a_arg9 = false
		 * @param a_arg10 = 0
		 */
		bool UnequipItem(Actor* a_actor, TESForm* a_item, ExtraDataList* a_extraData, SInt32 a_count, BGSEquipSlot* a_equipSlot, bool a_arg6, bool a_preventEquip, bool a_arg8 = true, bool a_arg9 = false, void* a_arg10 = 0);


		// members
		bool unk01;	// 01
	};
	STATIC_ASSERT(sizeof(ActorEquipManager) == 0x2);
}
