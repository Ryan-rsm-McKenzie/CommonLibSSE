#pragma once

#include "RE/MapInputHandler.h"


namespace RE
{
	class MapMoveHandler : public MapInputHandler
	{
	public:
		inline static constexpr auto RTTI = RTTI_MapMoveHandler;


		virtual ~MapMoveHandler();	// 00

		// override (MapInputHandler)
		virtual bool CanProcess(InputEvent* a_event) override;				// 01
		virtual bool ProcessThumbstick(ThumbstickEvent* a_event) override;	// 03


		// members
		UInt64 unk18;  // 18
	};
	STATIC_ASSERT(sizeof(MapMoveHandler) == 0x20);
}
