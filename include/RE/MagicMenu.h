#pragma once

#include "skse64/GameRTTI.h"  // RTTI_MagicMenu

#include "RE/GFxValue.h"  // GFxValue
#include "RE/IMenu.h"  // IMenu


namespace RE
{
	struct BottomBar;
	struct ItemCard;


	class MagicMenu : public IMenu
	{
	public:
		inline static const void* RTTI = RTTI_MagicMenu;


		virtual ~MagicMenu();												// 00

		// override (IMenu)
		virtual void	Accept(CallbackProcessor* a_processor) override;	// 01
		virtual Result	ProcessMessage(UIMessage* a_message) override;		// 04
		virtual void	Render() override;									// 06


		// members
		void*		unk30;				// 30 - some variation of the item list
		ItemCard*	itemCard;			// 38
		BottomBar*	bottomBar;			// 40
		GFxValue	root;				// 48 - "Menu_mc"
		bool		pcControlsReady;	// 60
		UInt8		pad61;				// 61
		UInt16		pad62;				// 62
		UInt32		pad64;				// 64
	};
	STATIC_ASSERT(sizeof(MagicMenu) == 0x68);
}
