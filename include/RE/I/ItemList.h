#pragma once

#include "RE/B/BSTArray.h"
#include "RE/G/GFxValue.h"
#include "RE/G/GPtr.h"
#include "RE/S/StandardItemData.h"

namespace RE
{
	class GFxMovieView;
	class TESObjectREFR;

	struct ItemList
	{
	public:
		struct Item
		{
		public:
			// members
			StandardItemData data;   // 00
			GFxValue         obj;    // 18 - kObject
			std::uint64_t    unk30;  // 30
			std::uint64_t    unk38;  // 38
		};
		static_assert(sizeof(Item) == 0x40);

		Item* GetSelectedItem();
		void  Update();
		void  Update(TESObjectREFR* a_owner);

		// members
		GPtr<GFxMovieView> view;       // 00
		GFxValue           root;       // 08 - kDisplayObject - "_level0.Menu_mc.inventoryLists.panelContainer.itemList"
		GFxValue           entryList;  // 20 - kArray - root.GetMember("entryList", &entryList);
		BSTArray<Item*>    items;      // 38
		bool               unk50;      // 50
		std::uint8_t       pad51;      // 51
		std::uint16_t      pad52;      // 52
		std::uint32_t      pad54;      // 54

	protected:
		void Update_Impl(TESObjectREFR* a_owner);
	};
	static_assert(sizeof(ItemList) == 0x58);
}
