#pragma once

#include "skse64/GameRTTI.h"  // RTTI_MapInputHandler

#include "RE/MenuEventHandler.h"  // MenuEventHandler


namespace RE
{
	class MapMenu;


	class MapInputHandler : public MenuEventHandler
	{
	public:
		inline static const void* RTTI = RTTI_MapInputHandler;


		virtual ~MapInputHandler();	// 00


		// members
		MapMenu* mapMenu;	// 10
	};
	STATIC_ASSERT(sizeof(MapInputHandler) == 0x18);
}
