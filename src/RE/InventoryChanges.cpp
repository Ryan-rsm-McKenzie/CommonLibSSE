#include "RE/InventoryChanges.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	InventoryChanges::InventoryChanges(TESObjectREFR* a_ref)
	{
		Ctor_Internal(a_ref);
	}


	InventoryEntryData* InventoryChanges::FindItemEntry(TESForm* a_item)
	{
		using func_t = function_type_t<decltype(&InventoryChanges::FindItemEntry)>;
		func_t* func = function_cast<func_t*>(&::ExtraContainerChanges::Data::FindItemEntry);
		return func(this, a_item);
	}


	InventoryEntryData* InventoryChanges::CreateEquipEntryData(TESForm* a_item)
	{
		using func_t = function_type_t<decltype(&InventoryChanges::CreateEquipEntryData)>;
		func_t* func = function_cast<func_t*>(&::ExtraContainerChanges::Data::CreateEquipEntryData);
		return func(this, a_item);
	}


	void InventoryChanges::GetEquipItemData(::InventoryEntryData::EquipData& a_stateOut, TESForm* a_item, SInt32 a_itemID)
	{
		using func_t = function_type_t<decltype(&InventoryChanges::GetEquipItemData)>;
		func_t* func = function_cast<func_t*>(&::ExtraContainerChanges::Data::GetEquipItemData);
		return func(this, a_stateOut, a_item, a_itemID);
	}


	void InventoryChanges::SetUniqueID(BaseExtraList* a_itemList, TESForm* a_oldForm, TESForm* a_newForm)
	{
		using func_t = function_type_t<decltype(&InventoryChanges::SetUniqueID)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::ExtraContainerChanges::Data, SetUniqueID, func_t*);
		return func(this, a_itemList, a_oldForm, a_newForm);
	}


	void InventoryChanges::TransferItemUID(BaseExtraList* a_extraList, TESForm* a_oldForm, TESForm* a_newForm, UInt32 a_arg4)
	{
		using func_t = function_type_t<decltype(&InventoryChanges::TransferItemUID)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::ExtraContainerChanges::Data, TransferItemUID, func_t*);
		return func(this, a_extraList, a_oldForm, a_newForm, a_arg4);
	}


	void InventoryChanges::InitContainer()
	{
		using func_t = function_type_t<decltype(&InventoryChanges::InitContainer)>;
		REL::Offset<func_t*> func(Offset::InventoryChanges::InitContainer);
		return func(this);
	}


	void InventoryChanges::GenerateLeveledListChanges()
	{
		using func_t = function_type_t<decltype(&InventoryChanges::GenerateLeveledListChanges)>;
		REL::Offset<func_t*> func(Offset::InventoryChanges::GenerateLeveledListChanges);
		return func(this);
	}


	void InventoryChanges::SendContainerChangedEvent(BaseExtraList* a_itemExtraList, TESObjectREFR* a_fromRefr, TESForm* a_item, SInt32 a_count)
	{
		using func_t = function_type_t<decltype(&InventoryChanges::SendContainerChangedEvent)>;
		REL::Offset<func_t*> func(Offset::InventoryChanges::SendContainerChangedEvent);
		return func(this, a_itemExtraList, a_fromRefr, a_item, a_count);
	}


	InventoryChanges* InventoryChanges::Ctor_Internal(TESObjectREFR* a_ref)
	{
		using func_t = function_type_t<decltype(&InventoryChanges::Ctor_Internal)>;
		REL::Offset<func_t*> func(Offset::InventoryChanges::Ctor);
		return func(this, a_ref);
	}
}
