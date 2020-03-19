#pragma once

#include "RE/GFxValue.h"
#include "RE/GPtr.h"
#include "RE/StandardItemData.h"


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
			StandardItemData data;	 // 00
			GFxValue		 obj;	 // 18 - kObject
			UInt64			 unk30;	 // 30
			UInt64			 unk38;	 // 38
		};
		STATIC_ASSERT(sizeof(Item) == 0x40);


		Item* GetSelectedItem();
		void  Update();
		void  Update(TESObjectREFR* a_owner);


		// members
		GPtr<GFxMovieView> view;	   // 00
		GFxValue		   root;	   // 08 - kDisplayObject - "_level0.Menu_mc.inventoryLists.panelContainer.itemList"
		GFxValue		   entryList;  // 20 - kArray - root.GetMember("entryList", &entryList);
		BSTArray<Item*>	   items;	   // 38
		bool			   unk50;	   // 50
		UInt8			   pad51;	   // 51
		UInt16			   pad52;	   // 52
		UInt32			   pad54;	   // 54

	protected:
		void Update_Impl(TESObjectREFR* a_owner);
	};
	STATIC_ASSERT(sizeof(ItemList) == 0x58);
}
