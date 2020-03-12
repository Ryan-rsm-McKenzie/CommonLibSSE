#pragma once

#include <string_view>

#include "RE/BSTArray.h"
#include "RE/GFxValue.h"
#include "RE/IMenu.h"


namespace RE
{
	class GFxMovieView;
	class TESObjectREFR;
	struct BottomBar;
	struct ItemCard;
	struct ItemList;


	// menuDepth = 0
	// flags = kPausesGame | kDisablePauseMenu | kUpdateUsesCursor | kInventoryItemMenu | kCustomRendering
	// context = kNone
	class InventoryMenu : public IMenu
	{
	public:
		inline static constexpr auto	  RTTI = RTTI_InventoryMenu;
		constexpr static std::string_view MENU_NAME = "InventoryMenu";


		virtual ~InventoryMenu();  // 00

		// override (IMenu)
		virtual void			   Accept(CallbackProcessor* a_processor) override;	 // 01
		virtual UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;	 // 04
		virtual void			   PostDisplay() override;							 // 06


		// members
		GFxValue		root;			  // 30 - kDisplayObject - "_level0.Menu_mc"
		ItemList*		itemList;		  // 48
		ItemCard*		itemCard;		  // 50
		BottomBar*		bottomBar;		  // 58
		BSTArray<void*> unk60;			  // 60
		UInt8			unk78;			  // 78
		UInt8			pad79;			  // 79
		UInt16			pad7A;			  // 7A
		UInt32			unk7C;			  // 7C
		bool			pcControlsReady;  // 80
		UInt8			unk81;			  // 81
		UInt16			pad82;			  // 82
		UInt32			pad84;			  // 84
	};
	STATIC_ASSERT(sizeof(InventoryMenu) == 0x88);
}
