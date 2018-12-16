#include "RE/EquipManager.h"

#include "skse64_common/Relocation.h"  // RelocAddr
#include "skse64/GameData.h"  // EquipManager


namespace RE
{
	EquipManager* EquipManager::GetSingleton()
	{
		typedef EquipManager* _GetSingleton_t();
		_GetSingleton_t* _GetSingleton = reinterpret_cast<_GetSingleton_t*>(GetFnAddr(&::EquipManager::GetSingleton));
		return _GetSingleton();
	}


	void EquipManager::EquipItem(Actor* a_actor, TESForm* a_item, BaseExtraList* a_extraData, SInt32 a_count, BGSEquipSlot* a_equipSlot, bool a_withEquipSound, bool a_preventUnequip, bool a_showMsg, void* a_arg9)
	{
		typedef void _EquipItem_t(EquipManager* a_this, Actor* a_actor, TESForm* a_item, BaseExtraList* a_extraData, SInt32 a_count, BGSEquipSlot* a_equipSlot, bool a_withEquipSound, bool a_preventUnequip, bool a_showMsg, void* a_arg9);
		uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::EquipManager*>(this)->_EquipItem_GetPtr());
		_EquipItem_t* _EquipItem = reinterpret_cast<_EquipItem_t*>(*ptr);
		_EquipItem(this, a_actor, a_item, a_extraData, a_count, a_equipSlot, a_withEquipSound, a_preventUnequip, a_showMsg, a_arg9);
	}


	bool EquipManager::UnEquipItem(Actor* a_actor, TESForm* a_item, BaseExtraList* a_extraData, SInt32 a_count, BGSEquipSlot* a_equipSlot, bool a_arg6, bool a_preventEquip, bool a_arg8, bool a_arg9, void* a_arg10)
	{
		typedef bool _UnEquipItem_t(EquipManager* a_this, Actor* a_actor, TESForm* a_item, BaseExtraList* a_extraData, SInt32 a_count, BGSEquipSlot* a_equipSlot, bool a_arg6, bool a_preventEquip, bool a_arg8, bool a_arg9, void* a_arg10);
		uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::EquipManager*>(this)->_UnequipItem_GetPtr());
		_UnEquipItem_t* _UnEquipItem = reinterpret_cast<_UnEquipItem_t*>(*ptr);
		return _UnEquipItem(this, a_actor, a_item, a_extraData, a_count, a_equipSlot, a_arg6, a_preventEquip, a_arg8, a_arg9, a_arg10);
	}
}
