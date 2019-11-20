#pragma once

#include "skse64/GameRTTI.h"  // RTTI_SleepWaitMenu

#include "RE/GFxValue.h"  // GFxValue
#include "RE/IMenu.h"  // IMenu


namespace RE
{
	class SleepWaitMenu : public IMenu
	{
	public:
		inline static const void* RTTI = RTTI_SleepWaitMenu;


		virtual ~SleepWaitMenu();											// 00

		// override (IMenu)
		virtual void	Accept(CallbackProcessor* a_processor) override;	// 01
		virtual Result	ProcessMessage(UIMessage* a_message) override;		// 04


		// members
		UInt32		unk30;	// 30
		UInt32		pad34;	// 34
		GFxValue	root;	// 38 - "SleepWaitMenu_mc"
		UInt8		unk50;	// 50
		UInt8		unk51;	// 51
		UInt16		pad52;	// 52
		UInt32		pad54;	// 54
	};
	STATIC_ASSERT(sizeof(SleepWaitMenu) == 0x58);
}
