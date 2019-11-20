#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TitleSequenceMenu

#include "RE/IMenu.h"  // IMenu


namespace RE
{
	class TitleSequenceMenu : public IMenu
	{
	public:
		inline static const void* RTTI = RTTI_TitleSequenceMenu;


		virtual ~TitleSequenceMenu();									// 00

		// override (IMenu)
		virtual Result ProcessMessage(UIMessage* a_message) override;	// 04
	};
	STATIC_ASSERT(sizeof(TitleSequenceMenu) == 0x30);
}
