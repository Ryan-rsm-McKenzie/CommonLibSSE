#pragma once

#include <string_view>

#include "RE/BSTArray.h"
#include "RE/GFxValue.h"
#include "RE/IMenu.h"


namespace RE
{
	struct ItemCard;
	struct ItemList;


	// menuDepth = 3
	// flags = kPausesGame | kUsesMenuContext | kDisablePauseMenu | kUpdateUsesCursor | kInventoryItemMenu | kCustomRendering
	// context = kItemMenu
	class GiftMenu : public IMenu
	{
	public:
		inline static constexpr auto	  RTTI = RTTI_GiftMenu;
		constexpr static std::string_view MENU_NAME = "GiftMenu";


		virtual ~GiftMenu();  // 00

		// override (IMenu)
		virtual void			   Accept(CallbackProcessor* a_processor) override;	 // 01
		virtual UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;	 // 04
		virtual void			   PostDisplay() override;							 // 06


		// members
		GFxValue		root;			  // 30 - "Menu_mc"
		ItemList*		itemList;		  // 48
		ItemCard*		itemCard;		  // 50
		BSTArray<void*> unk58;			  // 58
		UInt64			unk70;			  // 70
		bool			pcControlsReady;  // 78
		UInt8			pad79;			  // 79
		UInt16			pad7A;			  // 7A
		UInt32			pad7C;			  // 7C
	};
	STATIC_ASSERT(sizeof(GiftMenu) == 0x80);
}
