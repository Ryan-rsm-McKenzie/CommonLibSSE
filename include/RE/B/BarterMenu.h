#pragma once

#include "RE/B/BSTArray.h"
#include "RE/G/GFxValue.h"
#include "RE/I/IMenu.h"

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

		[[nodiscard]] RefHandle GetTargetRefHandle();

		// members
		ItemList*		itemList;		  // 30
		ItemCard*		itemCard;		  // 38
		BottomBar*		bottomBar;		  // 40
		GFxValue		root;			  // 48 - "Menu_mc"
		std::uint64_t	unk60;			  // 60
		std::uint64_t	unk68;			  // 68
		std::uint64_t	unk70;			  // 70
		std::uint8_t	unk78;			  // 78
		std::uint8_t	pad79;			  // 79
		std::uint16_t	pad7A;			  // 7A
		std::uint32_t	pad7C;			  // 7C
		BSTArray<void*> unk80;			  // 80
		std::uint64_t	unk98;			  // 98
		std::uint32_t	unkA0;			  // A0
		bool			pcControlsReady;  // A4
		std::uint8_t	padA5;			  // A5
		std::uint16_t	padA6;			  // A6
	};
	static_assert(sizeof(BarterMenu) == 0xA8);
}
