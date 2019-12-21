#pragma once

#include <string_view>

#include "RE/IMenu.h"


namespace RE
{
	class TitleSequenceMenu : public IMenu
	{
	public:
		inline static const void* RTTI = RTTI_TitleSequenceMenu;
		constexpr static std::string_view MENU_NAME = "TitleSequence Menu";


		virtual ~TitleSequenceMenu();									// 00

		// override (IMenu)
		virtual Result ProcessMessage(UIMessage* a_message) override;	// 04
	};
	STATIC_ASSERT(sizeof(TitleSequenceMenu) == 0x30);
}
