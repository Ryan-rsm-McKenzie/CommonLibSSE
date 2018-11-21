#include "RE/InventoryChanges.h"

#include "RE/Offsets.h"

class TESForm;


namespace RE
{
	class TESObjectREFR;


	InventoryChanges::InventoryChanges(TESObjectREFR* a_ref)
	{
		_ctor(this, a_ref);
	}


	InventoryEntryData* InventoryChanges::FindItemEntry(TESForm* a_item)
	{
		typedef InventoryEntryData* _FindItemEntry_t(InventoryChanges* a_this, TESForm* a_item);
		static _FindItemEntry_t* _FindItemEntry = reinterpret_cast<_FindItemEntry_t*>(GetFnAddr(&::ExtraContainerChanges::Data::FindItemEntry));
		return _FindItemEntry(this, a_item);
	}


	InventoryEntryData* InventoryChanges::CreateEquipEntryData(TESForm* a_item)
	{
		typedef InventoryEntryData* _CreateEquipEntryData_t(InventoryChanges* a_this, TESForm* a_item);
		static _CreateEquipEntryData_t* _CreateEquipEntryData = reinterpret_cast<_CreateEquipEntryData_t*>(GetFnAddr(&::ExtraContainerChanges::Data::CreateEquipEntryData));
		return _CreateEquipEntryData(this, a_item);
	}


	void InventoryChanges::GetEquipItemData(::InventoryEntryData::EquipData& a_stateOut, TESForm* a_item, SInt32 a_itemId)
	{
		typedef void _GetEquipItemData_t(InventoryChanges* a_this, ::InventoryEntryData::EquipData& a_stateOut, TESForm* a_item, SInt32 a_itemId);
		static _GetEquipItemData_t* _GetEquipItemData = reinterpret_cast<_GetEquipItemData_t*>(GetFnAddr(&::ExtraContainerChanges::Data::GetEquipItemData));
		_GetEquipItemData(this, a_stateOut, a_item, a_itemId);
	}


	void InventoryChanges::SetUniqueID(::BaseExtraList* a_itemList, TESForm* a_oldForm, TESForm* a_newForm)
	{
		typedef void _SetUniqueID_t(InventoryChanges* a_this, ::BaseExtraList* a_itemList, TESForm* a_oldForm, TESForm* a_newForm);
		static uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::ExtraContainerChanges::Data*>(this)->_SetUniqueID_GetPtr());
		static _SetUniqueID_t* _SetUniqueID = reinterpret_cast<_SetUniqueID_t*>(*ptr);
		_SetUniqueID(this, a_itemList, a_oldForm, a_newForm);
	}


	void InventoryChanges::TransferItemUID(::BaseExtraList* a_extraList, TESForm* a_oldForm, TESForm* a_newForm, UInt32 a_unk1)
	{
		typedef void _TransferItemUID_t(InventoryChanges* a_this, ::BaseExtraList* a_extraList, TESForm* a_oldForm, TESForm* a_newForm, UInt32 a_unk1);
		static uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::ExtraContainerChanges::Data*>(this)->_TransferItemUID_GetPtr());
		static _TransferItemUID_t* _TransferItemUID = reinterpret_cast<_TransferItemUID_t*>(*ptr);
		_TransferItemUID(this, a_extraList, a_oldForm, a_newForm, a_unk1);
	}


	void InventoryChanges::InitContainer()
	{
		_InitContainer(this);
	}


	void InventoryChanges::GenerateLeveledListChanges()
	{
		_GenerateLeveledListChanges(this);
	}


	RelocAddr<InventoryChanges::_ctor_t*> InventoryChanges::_ctor(INVENTORY_CHANGES_CTOR);
	RelocAddr<InventoryChanges::_InitContainer_t*> InventoryChanges::_InitContainer(INVENTORY_CHANGES_INIT_CONTAINER);
	RelocAddr<InventoryChanges::_GenerateLeveledListChanges_t*> InventoryChanges::_GenerateLeveledListChanges(INVENTORY_CHANGES_GENERATE_LEVELED_LIST_CHANGES);
}
