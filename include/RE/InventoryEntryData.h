#pragma once

#include "skse64/GameExtraData.h"  // InventoryEntryData::EquipData

#include "RE/BSTList.h"  // BSSimpleList
#include "RE/Memory.h"

class TESForm;


namespace RE
{
	class BaseExtraList;


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
		float		GetWeight();

		TES_HEAP_REDEFINE_NEW();


		// members
		TESForm*						type;		// 00
		BSSimpleList<BaseExtraList*>*	extraList;	// 08
		SInt32							countDelta;	// 10

	private:
		typedef bool _IsOwnedBy_t(InventoryEntryData* a_this, TESForm* actor, TESForm* itemOwner, bool unk1);
		static RelocAddr<_IsOwnedBy_t*> _IsOwnedBy;

		typedef TESForm* _GetOwner_t(InventoryEntryData* a_this);
		static RelocAddr<_GetOwner_t*> _GetOwner;

		typedef float _GetWeight_t(InventoryEntryData* a_this);  // { return TESWeightForm::weight; } - Only for certain formtypes
		static RelocAddr<_GetWeight_t*> _GetWeight;
	};
}
