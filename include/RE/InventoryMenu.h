#pragma once

#include "skse64/GameRTTI.h"  // RTTI_InventoryMenu

#include "RE/BSString.h"  // BSString
#include "RE/BSTArray.h"  // BSTArray
#include "RE/GFxValue.h"  // GFxValue
#include "RE/GPtr.h"  // GPtr
#include "RE/IMenu.h"  // IMenu


namespace RE
{
	class GFxMovieView;
	class TESObjectREFR;
	struct ItemList;


	class InventoryMenu : public IMenu
	{
		// menuDepth = 0
		// flags = kPauseGame | kPreventGameLoad | kUnk0400 | kItemMenu | kUnk8000
	public:
		inline static const void* RTTI = RTTI_InventoryMenu;


		struct ItemCard
		{
			GFxValue			obj;		// 00 - kObject
			BSString			infoText;	// 18
			UInt64				unk28;		// 28
			UInt32				unk30;		// 30
			UInt32				pad34;		// 34
			GPtr<GFxMovieView>	unk38;		// 38
		};
		STATIC_ASSERT(sizeof(ItemCard) == 0x40);


		virtual ~InventoryMenu();											// 00

		// override (IMenu)
		virtual void	Accept(CallbackProcessor* a_processor) override;	// 01
		virtual Result	ProcessMessage(UIMessage* a_message) override;		// 04
		virtual void	Render() override;									// 06


		// members
		GFxValue		root;				// 30 - kDisplayObject - "_level0.Menu_mc"
		ItemList*		list;				// 48
		ItemCard*		itemCard;			// 50
		GFxValue*		bottomBarInfo;		// 58 - kObject
		BSTArray<void*>	unk60;				// 60
		UInt32			unk78;				// 78
		UInt32			unk7C;				// 7C
		bool			pcControlsReady;	// 80
		UInt8			pad81;				// 81
		UInt16			pad82;				// 82
		UInt32			pad84;				// 84
	};
	STATIC_ASSERT(sizeof(InventoryMenu) == 0x88);
}
