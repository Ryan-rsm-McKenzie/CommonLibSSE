#pragma once

#include "RE/GFxValue.h"  // GFxValue
#include "RE/StandardItemData.h"  // StandardItemData


namespace RE
{
	class GFxMovieView;


	struct ItemList
	{
		struct Item
		{
			StandardItemData	data;	// 00
			GFxValue			unk18;	// 18 - kObject
			UInt64				unk30;	// 30
			UInt64				unk38;	// 38
		};
		STATIC_ASSERT(sizeof(Item) == 0x40);


		Item*	GetSelectedItem();
		void	Update(TESObjectREFR* a_owner);


		// members
		GFxMovieView*	view;		// 00
		GFxValue		root;		// 08 - kDisplayObject - "_level0.Menu_mc.inventoryLists.panelContainer.itemList"
		GFxValue		unk20;		// 20 - kArray
		BSTArray<Item*>	items;		// 38
		bool			selected;	// 50
		UInt8			unk51;		// 51
		UInt16			unk52;		// 52
		UInt32			unk54;		// 54
	};
}
