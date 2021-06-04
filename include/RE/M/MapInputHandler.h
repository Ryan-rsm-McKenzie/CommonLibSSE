#pragma once

#include "RE/M/MenuEventHandler.h"

namespace RE
{
	class MapMenu;

	class MapInputHandler : public MenuEventHandler
	{
	public:
		inline static constexpr auto RTTI = RTTI_MapInputHandler;

		virtual ~MapInputHandler();  // 00

		// members
		MapMenu* mapMenu;  // 10
	};
	static_assert(sizeof(MapInputHandler) == 0x18);
}
