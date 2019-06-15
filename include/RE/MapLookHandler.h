#pragma once

#include "skse64/GameRTTI.h"  // RTTI_MapLookHandler

#include "RE/MapInputHandler.h"  // MapInputHandler


namespace RE
{
	class MapLookHandler : public MapInputHandler
	{
	public:
		inline static const void* RTTI = RTTI_MapLookHandler;


		virtual ~MapLookHandler();												// 00

		// override (MapInputHandler)
		virtual bool	ProcessThumbstick(ThumbstickEvent* a_event) override;	// 03
		virtual bool	ProcessMouseMove(MouseMoveEvent* a_event) override;		// 04
		virtual bool	ProcessButton(ButtonEvent* a_event) override;			// 05


		// members
		UInt64 unk18;	// 18
	};
	STATIC_ASSERT(sizeof(MapLookHandler) == 0x20);
}
