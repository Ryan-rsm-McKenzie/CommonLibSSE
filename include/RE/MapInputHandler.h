#pragma once

#include "RE/MenuEventHandler.h"  // MenuEventHandler


namespace RE
{
	class MapMenu;


	class MapInputHandler : public MenuEventHandler
	{
	public:
		virtual ~MapInputHandler();	// 00

		
		// members
		MapMenu* mapMenu;	// 10
	};
	STATIC_ASSERT(sizeof(MapInputHandler) == 0x18);
}
