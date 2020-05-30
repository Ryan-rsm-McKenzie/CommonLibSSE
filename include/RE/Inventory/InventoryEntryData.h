#pragma once

#include "RE/BSTList.h"
#include "RE/FormTypes.h"
#include "RE/MemoryManager.h"
#include "RE/SoulLevels.h"


namespace RE
{
	class ExtraDataList;
	class TESBoundObject;


	class InventoryEntryData
	{
	public:
		InventoryEntryData();
		InventoryEntryData(const InventoryEntryData& a_rhs);
		InventoryEntryData(InventoryEntryData&& a_rhs);
		InventoryEntryData(TESBoundObject* a_object, SInt32 a_countDelta);
		~InventoryEntryData();

		InventoryEntryData& operator=(const InventoryEntryData& a_rhs);
		InventoryEntryData& operator=(InventoryEntryData&& a_rhs);

		void			AddExtraList(ExtraDataList* a_extra);
		const char*		GetDisplayName();
		TESBoundObject* GetObject();
		TESForm*		GetOwner();
		SOUL_LEVEL		GetSoulLevel() const;
		SInt32			GetValue();
		float			GetWeight() const;
		bool			IsOwnedBy(Actor* a_actor, bool a_defaultTo = true);
		bool			IsOwnedBy(Actor* a_actor, TESForm* a_itemOwner, bool a_defaultTo = true);

		TES_HEAP_REDEFINE_NEW();


		// members
		TESBoundObject*				  object;	   // 00
		BSSimpleList<ExtraDataList*>* extraLists;  // 08
		SInt32						  countDelta;  // 10
		UInt32						  pad14;	   // 14

	private:
		bool IsOwnedBy_Impl(Actor* a_actor, TESForm* a_itemOwner, bool a_defaultTo);
	};
	STATIC_ASSERT(sizeof(InventoryEntryData) == 0x18);
}
