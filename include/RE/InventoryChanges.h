#pragma once

#include "skse64/GameExtraData.h"  // ::InventoryEntryData::EquipData

#include "RE/BSTList.h"  // BSSimpleList
#include "RE/FormTypes.h"  // TESForm, TESObjectREFR
#include "RE/Memory.h"  // TES_HEAP_REDEFINE_NEW


namespace RE
{
	class BaseExtraList;
	class InventoryEntryData;


	class InventoryChanges
	{
	public:
		explicit InventoryChanges(TESObjectREFR* a_ref);

		InventoryEntryData*	FindItemEntry(TESForm* a_item);
		InventoryEntryData*	CreateEquipEntryData(TESForm* a_item);
		void				GetEquipItemData(::InventoryEntryData::EquipData& a_stateOut, TESForm* a_item, SInt32 a_itemId);
		void				SetUniqueID(BaseExtraList* a_itemList, TESForm* a_oldForm, TESForm* a_newForm);
		void				TransferItemUID(BaseExtraList* a_extraList, TESForm* a_oldForm, TESForm* a_newForm, UInt32 a_unk1);

		void				InitContainer();
		void				GenerateLeveledListChanges();

		TES_HEAP_REDEFINE_NEW();


		BSSimpleList<InventoryEntryData*>*	entryList;		// 00
		TESObjectREFR*						owner;			// 08
		float								totalWeight;	// 10
		float								armorWeight;	// 14
		bool								changed;		// 18
		UInt8								unk19;			// 19
		UInt8								unk1A;			// 1A
		UInt8								unk1B;			// 1B
		UInt32								unk1C;			// 1C
	};
	STATIC_ASSERT(sizeof(InventoryChanges) == 0x20);
}
