#pragma once

#include <string_view>

#include "RE/IMenu.h"


namespace RE
{
	// menuDepth = 11
	// flags = kNone
	// context = kInvalid
	class SafeZoneMenu : public IMenu
	{
	public:
		inline static const void* RTTI = RTTI_SafeZoneMenu;
		constexpr static std::string_view MENU_NAME = "SafeZoneMenu";


		virtual ~SafeZoneMenu();	// 00
	};
	STATIC_ASSERT(sizeof(SafeZoneMenu) == 0x30);
}
