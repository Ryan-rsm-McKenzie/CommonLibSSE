#pragma once

#include "RE/BSCore/BSTList.h"
#include "RE/FormComponents/Enums/FormTypes.h"
#include "RE/FormComponents/Enums/SoulLevels.h"
#include "RE/Memory/MemoryManager.h"


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
		InventoryEntryData(TESBoundObject* a_object, std::int32_t a_countDelta);
		~InventoryEntryData();

		InventoryEntryData& operator=(const InventoryEntryData& a_rhs);
		InventoryEntryData& operator=(InventoryEntryData&& a_rhs);

		void										  AddExtraList(ExtraDataList* a_extra);
		const char*									  GetDisplayName();
		std::optional<double>						  GetEnchantmentCharge() const;
		[[nodiscard]] constexpr TESBoundObject*		  GetObject() noexcept { return object; }
		[[nodiscard]] constexpr const TESBoundObject* GetObject() const noexcept { return object; }
		TESForm*									  GetOwner();
		SOUL_LEVEL									  GetSoulLevel() const;
		std::int32_t								  GetValue();
		float										  GetWeight() const;
		bool										  IsEnchanted() const;
		bool										  IsLeveled() const;
		bool										  IsOwnedBy(Actor* a_testOwner, bool a_defaultTo = true);
		bool										  IsOwnedBy(Actor* a_testOwner, TESForm* a_itemOwner, bool a_defaultTo = true);
		bool										  IsQuestObject() const;

		TES_HEAP_REDEFINE_NEW();


		// members
		TESBoundObject*				  object;	   // 00
		BSSimpleList<ExtraDataList*>* extraLists;  // 08
		std::int32_t				  countDelta;  // 10
		std::uint32_t				  pad14;	   // 14

	private:
		bool IsOwnedBy_Impl(Actor* a_testOwner, TESForm* a_itemOwner, bool a_defaultTo);
	};
	static_assert(sizeof(InventoryEntryData) == 0x18);
}
