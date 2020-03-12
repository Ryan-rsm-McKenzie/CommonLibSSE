#pragma once

#include <string_view>

#include "RE/BSTArray.h"
#include "RE/GFxValue.h"
#include "RE/IMenu.h"


namespace RE
{
	struct BottomBar;
	struct ItemCard;
	struct ItemList;


	// menuDepth = 0
	// flags = kPausesGame | kUsesMenuContext | kDisablePauseMenu | kUpdateUsesCursor | kInventoryItemMenu | kCustomRendering
	// context = kItemMenu
	class BarterMenu : public IMenu
	{
	public:
		inline static constexpr auto	  RTTI = RTTI_BarterMenu;
		constexpr static std::string_view MENU_NAME = "BarterMenu";


		virtual ~BarterMenu();	// 00

		// override (IMenu)
		virtual void			   Accept(CallbackProcessor* a_processor) override;	 // 01
		virtual UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;	 // 04
		virtual void			   PostDisplay() override;							 // 06


		// members
		ItemList*		itemList;		  // 30
		ItemCard*		itemCard;		  // 38
		BottomBar*		bottomBar;		  // 40
		GFxValue		root;			  // 48 - "Menu_mc"
		UInt64			unk60;			  // 60
		UInt64			unk68;			  // 68
		UInt64			unk70;			  // 70
		UInt8			unk78;			  // 78
		UInt8			pad79;			  // 79
		UInt16			pad7A;			  // 7A
		UInt32			pad7C;			  // 7C
		BSTArray<void*> unk80;			  // 80
		UInt64			unk98;			  // 98
		UInt32			unkA0;			  // A0
		bool			pcControlsReady;  // A4
		UInt8			padA5;			  // A5
		UInt16			padA6;			  // A6
	};
	STATIC_ASSERT(sizeof(BarterMenu) == 0xA8);
}
