#pragma once

#include "skse64/GameRTTI.h"  // RTTI_GiftMenu

#include "RE/BSTArray.h"  // BSTArray
#include "RE/GFxValue.h"  // GFxValue
#include "RE/IMenu.h"  // IMenu


namespace RE
{
	struct ItemCard;
	struct ItemList;


	class GiftMenu : public IMenu
	{
	public:
		inline static const void* RTTI = RTTI_GiftMenu;


		virtual ~GiftMenu();												// 00

		// override (IMenu)
		virtual void	Accept(CallbackProcessor* a_processor) override;	// 01
		virtual Result	ProcessMessage(UIMessage* a_message) override;		// 04
		virtual void	Render() override;									// 06


		// members
		GFxValue		root;				// 30 - "Menu_mc"
		ItemList*		list;				// 48
		ItemCard*		itemCard;			// 50
		BSTArray<void*>	unk58;				// 58
		UInt64			unk70;				// 70
		bool			pcControlsReady;	// 78
		UInt8			pad79;				// 79
		UInt16			pad7A;				// 7A
		UInt32			pad7C;				// 7C
	};
	STATIC_ASSERT(sizeof(GiftMenu) == 0x80);
}
