#pragma once

#include "skse64_common/Relocation.h"  // RelocAddr
#include "skse64/GameExtraData.h"  // ::InventoryEntryData::EquipData
#include "RE/FormTypes.h"  // TESForm

#include "RE/BSTList.h"  // BSSimpleList
#include "RE/Memory.h"  // TES_HEAP_REDEFINE_NEW

class BaseExtraList;
class InventoryEntryData;


namespace RE
{
	class InventoryEntryData;
	class TESObjectREFR;


	class InventoryChanges
	{
	public:
		explicit InventoryChanges(TESObjectREFR* a_ref);

		InventoryEntryData*	FindItemEntry(TESForm* a_item);
		InventoryEntryData*	CreateEquipEntryData(TESForm* a_item);
		void				GetEquipItemData(::InventoryEntryData::EquipData& a_stateOut, TESForm* a_item, SInt32 a_itemId);
		void				SetUniqueID(::BaseExtraList* a_itemList, TESForm* a_oldForm, TESForm* a_newForm);
		void				TransferItemUID(::BaseExtraList* a_extraList, TESForm* a_oldForm, TESForm* a_newForm, UInt32 a_unk1);

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

	private:
		typedef InventoryChanges* _ctor_t(InventoryChanges* a_this, TESObjectREFR* a_ref);
		static RelocAddr<_ctor_t*> _ctor;

		typedef void _InitContainer_t(InventoryChanges* a_this);
		static RelocAddr<_InitContainer_t*> _InitContainer;

	public:
		typedef void* _GenerateLeveledListChanges_t(InventoryChanges* a_this);
		static RelocAddr<_GenerateLeveledListChanges_t*> _GenerateLeveledListChanges;
	};
	STATIC_ASSERT(sizeof(InventoryChanges) == 0x20);
}
