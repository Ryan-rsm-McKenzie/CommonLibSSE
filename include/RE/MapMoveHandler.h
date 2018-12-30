#pragma once

#include "RE/MapInputHandler.h"  // MapInputHandler


namespace RE
{
	class MapMoveHandler : public MapInputHandler
	{
	public:
		virtual ~MapMoveHandler();												// 00

		// override (MapInputHandler)
		virtual bool	CanProcess(InputEvent* a_event) override;				// 01
		virtual bool	ProcessThumbstick(ThumbstickEvent* a_event) override;	// 03


		// members
		UInt64 unk18;	// 18
	};
	STATIC_ASSERT(sizeof(MapMoveHandler) == 0x20);
}
