#pragma once

#include "RE/I/IMenu.h"

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
	static_assert(sizeof(SafeZoneMenu) == 0x30);
}
