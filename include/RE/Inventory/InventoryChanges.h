#pragma once

#include "RE/BSCore/BSTList.h"
#include "RE/FormComponents/Enums/FormTypes.h"
#include "RE/Memory/MemoryManager.h"


namespace RE
{
	class ExtraDataList;
	class InventoryEntryData;


	class InventoryChanges
	{
	public:
		class IItemChangeVisitor
		{
		public:
			inline static constexpr auto RTTI = RTTI_InventoryChanges__IItemChangeVisitor;


			virtual ~IItemChangeVisitor();	// 00

			// add
			virtual bool Visit(InventoryEntryData* a_entryData) = 0;  // 01
			virtual void Unk_02(void);								  // 02 - { return 1; }
			virtual void Unk_03(void);								  // 03
		};
		STATIC_ASSERT(sizeof(IItemChangeVisitor) == 0x8);


		InventoryChanges();
		explicit InventoryChanges(TESObjectREFR* a_ref);
		~InventoryChanges();

		void   AddEntryData(InventoryEntryData* a_entry);
		UInt16 GetNextUniqueID();
		void   InitFromContainerExtra();
		void   InitLeveledItems();
		void   InitScripts();
		void   SendContainerChangedEvent(ExtraDataList* a_itemExtraList, TESObjectREFR* a_fromRefr, TESForm* a_item, SInt32 a_count);
		void   SetUniqueID(ExtraDataList* a_itemList, TESForm* a_oldForm, TESForm* a_newForm);

		TES_HEAP_REDEFINE_NEW();


		// members
		BSSimpleList<InventoryEntryData*>* entryList;	 // 00
		TESObjectREFR*					   owner;		 // 08
		float							   totalWeight;	 // 10
		float							   armorWeight;	 // 14
		bool							   changed;		 // 18
		UInt8							   unk19;		 // 19
		UInt8							   unk1A;		 // 1A
		UInt8							   unk1B;		 // 1B
		UInt32							   unk1C;		 // 1C

	private:
		InventoryChanges* Ctor(TESObjectREFR* a_ref);
		void			  Dtor();
	};
	STATIC_ASSERT(sizeof(InventoryChanges) == 0x20);
}
