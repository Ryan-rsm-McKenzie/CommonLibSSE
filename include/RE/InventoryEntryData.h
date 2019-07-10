#pragma once

#include "RE/BSTList.h"  // BSSimpleList
#include "RE/FormTypes.h"  // TESForm, Actor
#include "RE/SoulLevels.h"  // SoulLevel
#include "RE/TESMemoryManager.h"  // TES_HEAP_REDEFINE_NEW


namespace RE
{
	class BaseExtraList;
	class TESBoundObject;


	class InventoryEntryData
	{
	public:
		InventoryEntryData(TESBoundObject* a_item, SInt32 a_count);
		~InventoryEntryData();

		void		GetExtraWornBaseLists(BaseExtraList*& a_wornBaseListOut, BaseExtraList*& a_wornLeftBaseListOut);
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
		TESBoundObject*					type;		// 00
		BSSimpleList<BaseExtraList*>*	extraList;	// 08
		SInt32							countDelta;	// 10
		UInt32							pad14;		// 14

	private:
		bool	IsOwnedBy_Internal1(Actor* a_actor, bool a_defaultTo);
		bool	IsOwnedBy_Internal2(Actor* a_actor, TESForm* a_itemOwner, bool a_defaultTo = true);
	};
	STATIC_ASSERT(sizeof(InventoryEntryData) == 0x18);
}
