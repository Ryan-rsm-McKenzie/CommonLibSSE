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
	class ContainerMenu : public IMenu
	{
	public:
		inline static constexpr auto	  RTTI = RTTI_ContainerMenu;
		constexpr static std::string_view MENU_NAME = "ContainerMenu";

		enum class ContainerMode : std::uint32_t
		{
			kLoot = 0,
			kSteal = 1,
			kPickpocket = 2,
			kNPCMode = 3
		};

		virtual ~ContainerMenu();  // 00

		// override (IMenu)
		virtual void			   Accept(CallbackProcessor* a_processor) override;	 // 01
		virtual UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;	 // 04
		virtual void			   PostDisplay() override;							 // 06

		[[nodiscard]] ContainerMode GetContainerMode();
		[[nodiscard]] RefHandle		GetTargetRefHandle();

		// members
		GFxValue		root;			  // 30 - "Menu_mc"
		ItemList*		itemList;		  // 48
		ItemCard*		itemCard;		  // 50
		BottomBar*		bottomBar;		  // 58
		BSTArray<void*> unk60;			  // 60
		BSTArray<void*> unk78;			  // 78
		std::uint64_t	unk90;			  // 90
		std::uint64_t	unk98;			  // 98
		std::uint64_t	unkA0;			  // A0
		std::uint8_t	unkA8;			  // A8
		std::uint8_t	padA9;			  // A9
		std::uint16_t	padAA;			  // AA
		std::uint32_t	padAC;			  // AC
		std::int32_t	value;			  // B0
		std::uint32_t	unkB4;			  // B4
		std::uint8_t	unkB8;			  // B8
		bool			pcControlsReady;  // B9
		std::uint16_t	padBA;			  // BA
		std::uint32_t	padBC;			  // BC
	};
	static_assert(sizeof(ContainerMenu) == 0xC0);
}
