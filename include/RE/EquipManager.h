#pragma once

#include "RE/FormTypes.h"


namespace RE
{
	class BaseExtraList;


	class EquipManager
	{
	public:
		virtual ~EquipManager();

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
		UInt8	unk0;	// 0
		bool	unk1;	// 1
	};
}
