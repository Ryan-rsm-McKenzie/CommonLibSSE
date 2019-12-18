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


	void ActorEquipManager::EquipItem(Actor* a_actor, TESForm* a_item, ExtraDataList* a_extraData, SInt32 a_count, BGSEquipSlot* a_equipSlot, bool a_withEquipSound, bool a_preventUnequip, bool a_showMsg, bool a_arg9)
	{
		using func_t = function_type_t<decltype(&ActorEquipManager::EquipItem)>;
		REL::Offset<func_t*> func(Offset::ActorEquipManager::EquipItem);
		return func(this, a_actor, a_item, a_extraData, a_count, a_equipSlot, a_withEquipSound, a_preventUnequip, a_showMsg, a_arg9);
	}


	bool ActorEquipManager::UnequipItem(Actor* a_actor, TESForm* a_item, ExtraDataList* a_extraData, SInt32 a_count, BGSEquipSlot* a_equipSlot, bool a_arg6, bool a_preventEquip, bool a_arg8, bool a_arg9, void* a_arg10)
	{
		using func_t = function_type_t<decltype(&ActorEquipManager::UnequipItem)>;
		REL::Offset<func_t*> func(Offset::ActorEquipManager::UnequipItem);
		return func(this, a_actor, a_item, a_extraData, a_count, a_equipSlot, a_arg6, a_preventEquip, a_arg8, a_arg9, a_arg10);
	}
}
