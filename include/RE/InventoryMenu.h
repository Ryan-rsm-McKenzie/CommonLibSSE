#pragma once

#include "RE/BSTArray.h"  // BSTArray
#include "RE/GFxValue.h"  // GFxValue
#include "RE/IMenu.h"  // IMenu
#include "RE/StandardItemData.h"  // StandardItemData


namespace RE
{
	class GFxMovieView;


	class InventoryMenu : public IMenu
	{
		// menuDepth = 0
		// flags = kPauseGame | kPreventGameLoad | kUnk0400 | kItemMenu | kUnk8000
	public:
		// ItemMenu?
		struct InventoryData
		{
			struct Item
			{
				StandardItemData	data;	// 00
				GFxValue			unk18;	// 18 - kObject
				UInt64				unk30;	// 30
				UInt64				unk38;	// 38
			};
			STATIC_ASSERT(sizeof(Item) == 0x40);


			Item*	GetSelectedItem();
			void	Update(TESObjectREFR* a_owner);


			// members
			GFxMovieView*	view;			// 00
			GFxValue		itemMenuRoot;	// 08 - kDisplayObject
			GFxValue		unk20;			// 20 - kArray
			BSTArray<Item*>	items;			// 38
			bool			selected;		// 50
			UInt8			unk51;			// 51
			UInt16			unk52;			// 52
			UInt32			unk54;			// 54
		};


		virtual ~InventoryMenu();											// 00

		// override (IMenu)
		virtual void	Accept(CallbackProcessor* a_processor) override;	// 01
		virtual Result	ProcessMessage(UIMessage* a_message) override;		// 04
		virtual void	Render() override;									// 06


		// members
		GFxValue		root;				// 30 - kDisplayObject
		InventoryData*	inventoryData;		// 48 - doesn't own the object
		GFxValue*		unk50;				// 50 - kObject
		GFxValue*		unk58;				// 58 - kObject
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
