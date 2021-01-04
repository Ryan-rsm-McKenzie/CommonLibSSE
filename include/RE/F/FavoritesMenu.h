#pragma once

#include "RE/B/BSTArray.h"
#include "RE/G/GFxValue.h"
#include "RE/I/IMenu.h"
#include "RE/M/MenuEventHandler.h"

namespace RE
{
	class InventoryEntryData;
	class TESForm;

	// menuDepth = 3
	// flags = kPausesGame | kUpdateUsesCursor | kInventoryItemMenu | kCustomRendering
	// context = kFavorites
	class FavoritesMenu :
		public IMenu,			 // 00
		public MenuEventHandler	 // 30
	{
	public:
		inline static constexpr auto	  RTTI = RTTI_FavoritesMenu;
		constexpr static std::string_view MENU_NAME = "FavoritesMenu";

		struct Entry
		{
			TESForm*			item;		// 00
			InventoryEntryData* entryData;	// 08
		};
		static_assert(sizeof(Entry) == 0x10);

		virtual ~FavoritesMenu();  // 00

		// override (IMenu)
		virtual void			   Accept(CallbackProcessor* a_processor) override;	 // 01
		virtual UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;	 // 04

		// override (MenuEventHandler)
		virtual bool CanProcess(InputEvent* a_event) override;		// 01
		virtual bool ProcessKinect(KinectEvent* a_event) override;	// 02
		virtual bool ProcessButton(ButtonEvent* a_event) override;	// 05

		// members
		GFxValue		root;			  // 40 - "Menu_mc"
		BSTArray<Entry> favorites;		  // 58
		std::uint16_t	unk70;			  // 70
		bool			pcControlsReady;  // 72
		bool			isVampire;		  // 73
		std::uint32_t	pad74;			  // 74
	};
	static_assert(sizeof(FavoritesMenu) == 0x78);
}
