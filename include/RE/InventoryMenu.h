#pragma once

#include "skse64/GameRTTI.h"  // RTTI_InventoryMenu

#include "RE/BSTArray.h"  // BSTArray
#include "RE/GFxValue.h"  // GFxValue
#include "RE/IMenu.h"  // IMenu


namespace RE
{
	class GFxMovieView;
	class TESObjectREFR;
	struct BottomBar;
	struct ItemCard;
	struct ItemList;


	class InventoryMenu : public IMenu
	{
		// menuDepth = 0
		// flags = kPauseGame | kPreventGameLoad | kUnk0400 | kItemMenu | kUnk8000
	public:
		inline static const void* RTTI = RTTI_InventoryMenu;


		virtual ~InventoryMenu();											// 00

		// override (IMenu)
		virtual void	Accept(CallbackProcessor* a_processor) override;	// 01
		virtual Result	ProcessMessage(UIMessage* a_message) override;		// 04
		virtual void	Render() override;									// 06


		// members
		GFxValue		root;				// 30 - kDisplayObject - "_level0.Menu_mc"
		ItemList*		list;				// 48
		ItemCard*		itemCard;			// 50
		BottomBar*		bottomBar;			// 58
		BSTArray<void*>	unk60;				// 60
		UInt8			unk78;				// 78
		UInt8			pad79;				// 79
		UInt16			pad7A;				// 7A
		UInt32			unk7C;				// 7C
		bool			pcControlsReady;	// 80
		UInt8			unk81;				// 81
		UInt16			pad82;				// 82
		UInt32			pad84;				// 84
	};
	STATIC_ASSERT(sizeof(InventoryMenu) == 0x88);
}
