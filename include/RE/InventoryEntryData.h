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

		void		AddEntryList(BaseExtraList* a_extra);
		const char*	GenerateName();
		TESForm*	GetOwner();
		SoulLevel	GetSoulLevel() const;
		SInt32		GetValue();
		float		GetWeight();
		bool		IsOwnedBy(Actor* a_actor, bool a_defaultTo = true);
		bool		IsOwnedBy(Actor* a_actor, TESForm* a_itemOwner, bool a_defaultTo = true);

		TES_HEAP_REDEFINE_NEW();


		// members
		TESBoundObject*					type;		// 00
		BSSimpleList<BaseExtraList*>*	extraList;	// 08
		SInt32							countDelta;	// 10
		UInt32							pad14;		// 14

	private:
		bool IsOwnedBy_Impl(Actor* a_actor, TESForm* a_itemOwner, bool a_defaultTo);
	};
	STATIC_ASSERT(sizeof(InventoryEntryData) == 0x18);
}
