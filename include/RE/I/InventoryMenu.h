#pragma once

#include "RE/B/BSTArray.h"
#include "RE/G/GFxValue.h"
#include "RE/I/IMenu.h"

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
		std::uint8_t	unk78;			  // 78
		std::uint8_t	pad79;			  // 79
		std::uint16_t	pad7A;			  // 7A
		std::uint32_t	unk7C;			  // 7C
		bool			pcControlsReady;  // 80
		std::uint8_t	unk81;			  // 81
		std::uint16_t	pad82;			  // 82
		std::uint32_t	pad84;			  // 84
	};
	static_assert(sizeof(InventoryMenu) == 0x88);
}
