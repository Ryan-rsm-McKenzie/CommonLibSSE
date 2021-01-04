#pragma once

#include "RE/B/BSTArray.h"
#include "RE/G/GFxValue.h"
#include "RE/I/IMenu.h"

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

		[[nodiscard]] RefHandle GetTargetRefHandle();

		// members
		GFxValue		root;			  // 30 - "Menu_mc"
		ItemList*		itemList;		  // 48
		ItemCard*		itemCard;		  // 50
		BSTArray<void*> unk58;			  // 58
		std::uint64_t	unk70;			  // 70
		bool			pcControlsReady;  // 78
		std::uint8_t	pad79;			  // 79
		std::uint16_t	pad7A;			  // 7A
		std::uint32_t	pad7C;			  // 7C
	};
	static_assert(sizeof(GiftMenu) == 0x80);
}
