#pragma once

#include "RE/BSTList.h"  // BSSimpleList
#include "RE/Memory.h"  // TES_HEAP_REDEFINE_NEW
#include "RE/SoulLevels.h"  // SoulLevel


namespace RE
{
	class BaseExtraList;
	class TESForm;


	class InventoryEntryData
	{
	public:
		InventoryEntryData(TESForm* a_item, SInt32 a_count);
		~InventoryEntryData();

		void		GetExtraWornBaseLists(BaseExtraList*& a_pWornBaseListOut, BaseExtraList*& a_pWornLeftBaseListOut);
		const char*	GenerateName();
		SInt32		GetValue();
		bool		IsOwnedBy(TESForm* a_actor, bool a_unk1);
		SoulLevel	GetSoulLevel();

		void		AddEntryList(BaseExtraList* a_extra);
		bool		IsOwnedBy(TESForm* a_actor, TESForm* a_itemOwner, bool a_unk1);
		TESForm*	GetOwner();
		float		GetWeight();  // { return TESWeightForm::weight; } - Only for certain formtypes

		TES_HEAP_REDEFINE_NEW();


		// members
		TESForm*						type;		// 00
		BSSimpleList<BaseExtraList*>*	extraList;	// 08
		SInt32							countDelta;	// 10
		UInt32							pad14;		// 14
	};
	STATIC_ASSERT(sizeof(InventoryEntryData) == 0x18);
}
