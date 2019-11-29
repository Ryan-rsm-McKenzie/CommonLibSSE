#include "RE/InventoryChanges.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	InventoryChanges::InventoryChanges(TESObjectREFR* a_ref)
	{
		Ctor(a_ref);
	}


	void InventoryChanges::SetUniqueID(BaseExtraList* a_itemList, TESForm* a_oldForm, TESForm* a_newForm)
	{
		using func_t = function_type_t<decltype(&InventoryChanges::SetUniqueID)>;
		REL::Offset<func_t*> func(Offset::InventoryChanges::SetUniqueID);
		return func(this, a_itemList, a_oldForm, a_newForm);
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


	InventoryChanges* InventoryChanges::Ctor(TESObjectREFR* a_ref)
	{
		using func_t = function_type_t<decltype(&InventoryChanges::Ctor)>;
		REL::Offset<func_t*> func(Offset::InventoryChanges::Ctor);
		return func(this, a_ref);
	}
}
