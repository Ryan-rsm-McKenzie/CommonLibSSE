#pragma once

#include "RE/MapInputHandler.h"


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
	STATIC_ASSERT(sizeof(MapZoomHandler) == 0x18);
}
