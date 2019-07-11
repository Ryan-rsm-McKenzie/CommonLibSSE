#pragma once

#include "skse64/GameRTTI.h"  // RTTI_InventoryChanges__IItemChangeVisitor

#include "RE/BSTList.h"  // BSSimpleList
#include "RE/FormTypes.h"  // TESForm, TESObjectREFR
#include "RE/TESMemoryManager.h"  // TES_HEAP_REDEFINE_NEW


namespace RE
{
	class BaseExtraList;
	class InventoryEntryData;


	class InventoryChanges
	{
	public:
		class IItemChangeVisitor
		{
		public:
			inline static const void* RTTI = RTTI_InventoryChanges__IItemChangeVisitor;


			virtual ~IItemChangeVisitor();								// 00

			// add
			virtual bool	Visit(InventoryEntryData* a_entryData) = 0;	// 01
			virtual void	Unk_02(void);								// 02 - { return 1; }
			virtual void	Unk_03(void);								// 03
		};
		STATIC_ASSERT(sizeof(IItemChangeVisitor) == 0x8);


		explicit InventoryChanges(TESObjectREFR* a_ref);

		void	SetUniqueID(BaseExtraList* a_itemList, TESForm* a_oldForm, TESForm* a_newForm);
		void	TransferItemUID(BaseExtraList* a_extraList, TESForm* a_oldForm, TESForm* a_newForm, UInt32 a_arg4);
		void	InitContainer();
		void	GenerateLeveledListChanges();
		void	SendContainerChangedEvent(BaseExtraList* a_itemExtraList, TESObjectREFR* a_fromRefr, TESForm* a_item, SInt32 a_count);

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
		InventoryChanges* Ctor(TESObjectREFR* a_ref);
	};
	STATIC_ASSERT(sizeof(InventoryChanges) == 0x20);
}
