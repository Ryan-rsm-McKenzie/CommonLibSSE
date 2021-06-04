#pragma once

namespace RE
{
	class InventoryEntryData;

	class StandardItemData
	{
	public:
		inline static constexpr auto RTTI = RTTI_StandardItemData;

		virtual ~StandardItemData();  // 00

		virtual const char*   GetName();        // 01 - { return objDesc->GenerateName(); }
		virtual std::uint32_t GetCount();       // 02 - { return objDesc->GetCount(); }
		virtual std::uint32_t GetEquipState();  // 03
		virtual std::uint32_t GetFilterFlag();  // 04
		virtual std::uint32_t GetFavorite();    // 05
		virtual bool          GetEnabled();     // 06 - { return true; }

		// members
		InventoryEntryData* objDesc;  // 08
		RefHandle           owner;    // 10
		std::uint32_t       pad14;    // 14
	};
	static_assert(sizeof(StandardItemData) == 0x18);
}
