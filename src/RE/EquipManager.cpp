#include "RE/EquipManager.h"

#include "skse64/GameData.h"  // EquipManager

#include "REL/Relocation.h"


namespace RE
{
	EquipManager* EquipManager::GetSingleton()
	{
		using func_t = function_type_t<decltype(&EquipManager::GetSingleton)>;
		func_t* func = unrestricted_cast<func_t*>(&::EquipManager::GetSingleton);
		return func();
	}


	void EquipManager::EquipItem(Actor* a_actor, TESForm* a_item, BaseExtraList* a_extraData, SInt32 a_count, BGSEquipSlot* a_equipSlot, bool a_withEquipSound, bool a_preventUnequip, bool a_showMsg, bool a_arg9)
	{
		using func_t = function_type_t<decltype(&EquipManager::EquipItem)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::EquipManager, EquipItem, func_t*);
		return func(this, a_actor, a_item, a_extraData, a_count, a_equipSlot, a_withEquipSound, a_preventUnequip, a_showMsg, a_arg9);
	}


	bool EquipManager::UnEquipItem(Actor* a_actor, TESForm* a_item, BaseExtraList* a_extraData, SInt32 a_count, BGSEquipSlot* a_equipSlot, bool a_arg6, bool a_preventEquip, bool a_arg8, bool a_arg9, void* a_arg10)
	{
		using func_t = function_type_t<decltype(&EquipManager::UnEquipItem)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::EquipManager, UnequipItem, func_t*);
		return func(this, a_actor, a_item, a_extraData, a_count, a_equipSlot, a_arg6, a_preventEquip, a_arg8, a_arg9, a_arg10);
	}
}
