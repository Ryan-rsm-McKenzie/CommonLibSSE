#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TutorialMenu

#include "RE/GFxValue.h"  // GFxValue
#include "RE/IMenu.h"  // IMenu


namespace RE
{
	class TutorialMenu : public IMenu
	{
	public:
		inline static const void* RTTI = RTTI_TutorialMenu;


		virtual ~TutorialMenu();											// 00

		// override (IMenu)
		virtual void	Accept(CallbackProcessor* a_processor) override;	// 01
		virtual Result	ProcessMessage(UIMessage* a_message) override;		// 04


		// members
		GFxValue root;	// 30 - "Menu_mc"
	};
	STATIC_ASSERT(sizeof(TutorialMenu) == 0x48);
}
