#pragma once

#include "RE/BSTList.h"  // BSSimpleList
#include "RE/FormTypes.h"  // TESForm, Actor
#include "RE/Memory.h"  // TES_HEAP_REDEFINE_NEW
#include "RE/SoulLevels.h"  // SoulLevel


namespace RE
{
	class BaseExtraList;


	class InventoryEntryData
	{
	public:
		InventoryEntryData(TESForm* a_item, SInt32 a_count);
		~InventoryEntryData();

		void		GetExtraWornBaseLists(BaseExtraList*& a_pWornBaseListOut, BaseExtraList*& a_pWornLeftBaseListOut);
		const char*	GenerateName();
		SInt32		GetValue();
		bool		IsOwnedBy(Actor* a_actor, bool a_defaultTo = true);
		bool		IsOwnedBy(Actor* a_actor, TESForm* a_itemOwner, bool a_defaultTo = true);
		SoulLevel	GetSoulLevel();
		TESForm*	GetOwner();
		float		GetWeight();  // { return TESWeightForm::weight; } - Only for certain formtypes
		void		AddEntryList(BaseExtraList* a_extra);

		TES_HEAP_REDEFINE_NEW();


		// members
		TESForm*						type;		// 00
		BSSimpleList<BaseExtraList*>*	extraList;	// 08
		SInt32							countDelta;	// 10
		UInt32							pad14;		// 14
	};
	STATIC_ASSERT(sizeof(InventoryEntryData) == 0x18);
}
