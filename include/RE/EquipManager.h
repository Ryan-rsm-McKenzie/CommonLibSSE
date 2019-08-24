#pragma once

#include "RE/BSTSingleton.h"  // BSTSingletonSDM


namespace RE
{
	class Actor;
	class BaseExtraList;
	class BGSEquipSlot;
	class TESForm;


	class EquipManager : public BSTSingletonSDM<EquipManager>
	{
	public:
		static EquipManager* GetSingleton();
		/*
		 * @param a_arg9 = 0
		 */
		void EquipItem(Actor* a_actor, TESForm* a_item, BaseExtraList* a_extraData, SInt32 a_count, BGSEquipSlot* a_equipSlot, bool a_withEquipSound, bool a_preventUnequip, bool a_showMsg, bool a_arg9 = false);
		/*
		 * @param a_arg6 = true
		 * @param a_arg8 = true
		 * @param a_arg9 = false
		 * @param a_arg10 = 0
		 */
		bool UnEquipItem(Actor* a_actor, TESForm* a_item, BaseExtraList* a_extraData, SInt32 a_count, BGSEquipSlot* a_equipSlot, bool a_arg6, bool a_preventEquip, bool a_arg8 = true, bool a_arg9 = false, void* a_arg10 = 0);


		// members
		bool unk01;	// 01
	};
	STATIC_ASSERT(offsetof(EquipManager, unk01) == 0x1);
	STATIC_ASSERT(sizeof(EquipManager) == 0x2);
}
