#pragma once

#include "RE/M/MapInputHandler.h"

namespace RE
{
	class MapZoomHandler : public MapInputHandler
	{
	public:
		inline static constexpr auto RTTI = RTTI_MapZoomHandler;

		virtual ~MapZoomHandler();	// 00

		// override (MapInputHandler)
		virtual bool CanProcess(InputEvent* a_event) override;		// 01
		virtual bool ProcessButton(ButtonEvent* a_event) override;	// 05
	};
	static_assert(sizeof(MapZoomHandler) == 0x18);
}
