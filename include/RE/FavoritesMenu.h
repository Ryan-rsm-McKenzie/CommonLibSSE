#pragma once

#include "skse64/GameRTTI.h"  // RTTI_FavoritesMenu

#include "RE/BSTArray.h"  // BSTArray
#include "RE/GFxValue.h"  // GFxValue
#include "RE/IMenu.h"  // IMenu
#include "RE/MenuEventHandler.h"  // MenuEventHandler


namespace RE
{
	class InventoryEntryData;
	class TESForm;


	class FavoritesMenu :
		public IMenu,			// 00
		public MenuEventHandler	// 30
	{
	public:
		inline static const void* RTTI = RTTI_FavoritesMenu;


		struct Entry
		{
			TESForm*			item;		// 00
			InventoryEntryData*	entryData;	// 08
		};
		STATIC_ASSERT(sizeof(Entry) == 0x10);


		virtual ~FavoritesMenu();											// 00

		// override (IMenu)
		virtual void	Accept(CallbackProcessor* a_processor) override;	// 01
		virtual Result	ProcessMessage(UIMessage* a_message) override;		// 04

		// override (MenuEventHandler)
		virtual bool	CanProcess(InputEvent* a_event) override;			// 01
		virtual bool	ProcessKinect(KinectEvent* a_event) override;		// 02
		virtual bool	ProcessButton(ButtonEvent* a_event) override;		// 05


		// members
		GFxValue			root;				// 40 - "Menu_mc"
		BSTArray<Entry>		favorites;			// 58
		UInt16				unk70;				// 70
		bool				pcControlsReady;	// 72
		bool				isVampire;			// 73
		UInt32				pad74;				// 74
	};
	STATIC_ASSERT(sizeof(FavoritesMenu) == 0x78);
}
