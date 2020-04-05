#pragma once

#include "RE/IDEvent.h"


namespace RE
{
	class MouseMoveEvent : public IDEvent
	{
	public:
		inline static constexpr auto RTTI = RTTI_MouseMoveEvent;


		virtual ~MouseMoveEvent();	// 00


		// members
		SInt32 mouseInputX;	 // 28
		SInt32 mouseInputY;	 // 2C
	};
	STATIC_ASSERT(sizeof(MouseMoveEvent) == 0x30);
}
