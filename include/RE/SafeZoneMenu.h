#pragma once

#include <string_view>

#include "RE/IMenu.h"


namespace RE
{
	// menuDepth = 11
	// flags = kNone
	// context = kNone
	class SafeZoneMenu : public IMenu
	{
	public:
		inline static constexpr auto	  RTTI = RTTI_SafeZoneMenu;
		constexpr static std::string_view MENU_NAME = "SafeZoneMenu";


		virtual ~SafeZoneMenu();  // 00
	};
	STATIC_ASSERT(sizeof(SafeZoneMenu) == 0x30);
}
