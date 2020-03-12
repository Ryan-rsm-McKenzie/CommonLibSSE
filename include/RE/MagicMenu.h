#pragma once

#include <string_view>

#include "RE/GFxValue.h"
#include "RE/IMenu.h"


namespace RE
{
	struct BottomBar;
	struct ItemCard;


	// menuDepth = 0
	// flags = kPausesGame | kUsesMenuContext | kDisablePauseMenu | kUpdateUsesCursor | kInventoryItemMenu | kCustomRendering
	// context = kItemMenu
	class MagicMenu : public IMenu
	{
	public:
		inline static constexpr auto	  RTTI = RTTI_MagicMenu;
		constexpr static std::string_view MENU_NAME = "MagicMenu";


		virtual ~MagicMenu();  // 00

		// override (IMenu)
		virtual void			   Accept(CallbackProcessor* a_processor) override;	 // 01
		virtual UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;	 // 04
		virtual void			   PostDisplay() override;							 // 06


		// members
		void*	   unk30;			 // 30 - some variation of the item list
		ItemCard*  itemCard;		 // 38
		BottomBar* bottomBar;		 // 40
		GFxValue   root;			 // 48 - "Menu_mc"
		bool	   pcControlsReady;	 // 60
		UInt8	   pad61;			 // 61
		UInt16	   pad62;			 // 62
		UInt32	   pad64;			 // 64
	};
	STATIC_ASSERT(sizeof(MagicMenu) == 0x68);
}
