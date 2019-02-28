#include "RE/InventoryChanges.h"

#include "RE/Offsets.h"


namespace RE
{
	InventoryChanges::InventoryChanges(TESObjectREFR* a_ref)
	{
		typedef InventoryChanges* _ctor_t(InventoryChanges * a_this, TESObjectREFR * a_ref);
		static RelocAddr<_ctor_t*> _ctor(INVENTORY_CHANGES_CTOR);
		_ctor(this, a_ref);
	}


	InventoryEntryData* InventoryChanges::FindItemEntry(TESForm* a_item)
	{
		typedef InventoryEntryData* _FindItemEntry_t(InventoryChanges* a_this, TESForm* a_item);
		_FindItemEntry_t* _FindItemEntry = reinterpret_cast<_FindItemEntry_t*>(GetFnAddr(&::ExtraContainerChanges::Data::FindItemEntry));
		return _FindItemEntry(this, a_item);
	}


	InventoryEntryData* InventoryChanges::CreateEquipEntryData(TESForm* a_item)
	{
		typedef InventoryEntryData* _CreateEquipEntryData_t(InventoryChanges* a_this, TESForm* a_item);
		_CreateEquipEntryData_t* _CreateEquipEntryData = reinterpret_cast<_CreateEquipEntryData_t*>(GetFnAddr(&::ExtraContainerChanges::Data::CreateEquipEntryData));
		return _CreateEquipEntryData(this, a_item);
	}


	void InventoryChanges::GetEquipItemData(::InventoryEntryData::EquipData& a_stateOut, TESForm* a_item, SInt32 a_itemId)
	{
		typedef void _GetEquipItemData_t(InventoryChanges* a_this, ::InventoryEntryData::EquipData& a_stateOut, TESForm* a_item, SInt32 a_itemId);
		_GetEquipItemData_t* _GetEquipItemData = reinterpret_cast<_GetEquipItemData_t*>(GetFnAddr(&::ExtraContainerChanges::Data::GetEquipItemData));
		_GetEquipItemData(this, a_stateOut, a_item, a_itemId);
	}


	void InventoryChanges::SetUniqueID(BaseExtraList* a_itemList, TESForm* a_oldForm, TESForm* a_newForm)
	{
		typedef void _SetUniqueID_t(InventoryChanges* a_this, BaseExtraList* a_itemList, TESForm* a_oldForm, TESForm* a_newForm);
		uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::ExtraContainerChanges::Data*>(this)->_SetUniqueID_GetPtr());
		_SetUniqueID_t* _SetUniqueID = reinterpret_cast<_SetUniqueID_t*>(*ptr);
		_SetUniqueID(this, a_itemList, a_oldForm, a_newForm);
	}


	void InventoryChanges::TransferItemUID(BaseExtraList* a_extraList, TESForm* a_oldForm, TESForm* a_newForm, UInt32 a_unk1)
	{
		typedef void _TransferItemUID_t(InventoryChanges* a_this, BaseExtraList* a_extraList, TESForm* a_oldForm, TESForm* a_newForm, UInt32 a_unk1);
		uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::ExtraContainerChanges::Data*>(this)->_TransferItemUID_GetPtr());
		_TransferItemUID_t* _TransferItemUID = reinterpret_cast<_TransferItemUID_t*>(*ptr);
		_TransferItemUID(this, a_extraList, a_oldForm, a_newForm, a_unk1);
	}


	void InventoryChanges::InitContainer()
	{
		typedef void _InitContainer_t(InventoryChanges* a_this);
		static RelocAddr<_InitContainer_t*> _InitContainer(INVENTORY_CHANGES_INIT_CONTAINER);
		_InitContainer(this);
	}


	void InventoryChanges::GenerateLeveledListChanges()
	{
		typedef void _GenerateLeveledListChanges_t(InventoryChanges* a_this);
		static RelocAddr<_GenerateLeveledListChanges_t*> _GenerateLeveledListChanges(INVENTORY_CHANGES_GENERATE_LEVELED_LIST_CHANGES);
		_GenerateLeveledListChanges(this);
	}


	void InventoryChanges::SendContainerChangedEvent(BaseExtraList* a_itemExtraList, TESObjectREFR* a_fromRefr, TESForm* a_item, SInt32 a_count)
	{
		typedef void _SendContainerChangedEvent_t(InventoryChanges* a_this, BaseExtraList* a_itemExtraList, TESObjectREFR* a_fromRefr, TESForm* a_item, SInt32 a_count);
		static RelocAddr<_SendContainerChangedEvent_t*> _SendContainerChangedEvent(INVENTORY_CHANGES_SEND_CONTAINER_CHANGED_EVENT);
		_SendContainerChangedEvent(this, a_itemExtraList, a_fromRefr, a_item, a_count);
	}
}
