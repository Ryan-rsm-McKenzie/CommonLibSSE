#pragma once

#include "skse64/GameRTTI.h"  // RTTI_SafeZoneMenu

#include "RE/IMenu.h"  // IMenu


namespace RE
{
	class SafeZoneMenu : public IMenu
	{
	public:
		inline static const void* RTTI = RTTI_SafeZoneMenu;


		virtual ~SafeZoneMenu();	// 00
	};
	STATIC_ASSERT(sizeof(SafeZoneMenu) == 0x30);
}
