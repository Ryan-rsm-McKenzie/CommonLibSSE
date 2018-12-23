#pragma once

#include "skse64/GameExtraData.h"  // InventoryEntryData::EquipData

#include "RE/BSTList.h"  // BSSimpleList
#include "RE/Memory.h"


namespace RE
{
	class BaseExtraList;
	class TESForm;


	class InventoryEntryData
	{
	public:
		InventoryEntryData(TESForm* a_item, UInt32 a_count);
		~InventoryEntryData();

		void		GetExtraWornBaseLists(BaseExtraList*& a_pWornBaseListOut, BaseExtraList*& a_pWornLeftBaseListOut);
		void		GetEquipItemData(::InventoryEntryData::EquipData& a_stateOut, SInt32 a_itemId, SInt32 a_baseCount);
		const char*	GenerateName();
		SInt32		GetValue();
		bool		IsOwnedBy(TESForm* a_actor, bool a_unk1);
		UInt32		GetSoulLevel();

		void		AddEntryList(BaseExtraList* a_extra);
		bool		IsOwnedBy(TESForm* a_actor, TESForm* a_itemOwner, bool a_unk1);
		TESForm*	GetOwner();
		float		GetWeight();  // { return TESWeightForm::weight; } - Only for certain formtypes

		TES_HEAP_REDEFINE_NEW();


		// members
		TESForm*						type;		// 00
		BSSimpleList<BaseExtraList*>*	extraList;	// 08
		SInt32							countDelta;	// 10
	};
}
