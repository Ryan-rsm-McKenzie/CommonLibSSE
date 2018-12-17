#pragma once

#include "RE/BSTArray.h"  // BSTArray
#include "RE/IMenu.h"  // IMenu

class StandardItemData;


namespace RE
{
	class InventoryMenu : public IMenu
	{
		// menuDepth = 0
		// flags = kPauseGame | kPreventGameLoad | kUnk0400 | kItemMenu | kUnk8000
	public:
		struct InventoryData
		{
			StandardItemData*	GetSelectedItemData();
			void				Update(TESObjectREFR* a_owner);


			// members
			void*						unk00;				// 00
			GFxValue					categoryListRoot;	// 08
			GFxValue					unk20;				// 20
			BSTArray<StandardItemData*>	items;				// 38
			bool						selected;			// 68
		};


		virtual ~InventoryMenu();											// 00

		// override (IMenu)
		virtual void	Accept(CallbackProcessor* a_processor) override;	// 01
		virtual Result	ProcessMessage(UIMessage* a_message) override;		// 04
		virtual void	Render() override;									// 06


		// members
		GFxValue		root;				// 30 - view->GetVariable(&root, "Menu_mc")
		InventoryData*	inventoryData;		// 48 - init'd 0
		GFxValue*		unk50;				// 50 - init'd 0
		GFxValue*		unk58;				// 58 - init'd 0
		BSTArray<void*>	unk60;				// 60
		UInt32			unk78;				// 78 - init'd 0
		UInt32			unk7C;				// 7C - init'd 0
		bool			bPCControlsReady;	// 80 - init'd 0 root.GetMember("bPCControlsReady", tmpValue)
		UInt8			pad81;				// 81
		UInt16			pad82;				// 82
		UInt32			pad84;				// 84
	};
	STATIC_ASSERT(offsetof(InventoryMenu, root) == 0x30);
	STATIC_ASSERT(offsetof(InventoryMenu, inventoryData) == 0x48);
	STATIC_ASSERT(sizeof(InventoryMenu) == 0x88);
}
