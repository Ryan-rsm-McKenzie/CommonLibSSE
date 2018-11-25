#pragma once

#include "RE/IDEvent.h"  // IDEvent


namespace RE
{
	class ThumbstickEvent : public IDEvent
	{
	public:
		enum InputType : UInt32
		{
			kInputType_LeftThumbstick = 0x0B,
			kInputType_RightThumbstick = 0x0C
		};


		bool	IsLeft() const;
		bool	IsRight() const;


		// members
		InputType	keyMask;	// 20
		UInt32		pad24;		// 24
		float		x;			// 28
		float		y;			// 2C
	};
	STATIC_ASSERT(offsetof(ThumbstickEvent, keyMask) == 0x20);
	STATIC_ASSERT(offsetof(ThumbstickEvent, x) == 0x28);
	STATIC_ASSERT(offsetof(ThumbstickEvent, y) == 0x2C);
	STATIC_ASSERT(sizeof(ThumbstickEvent) == 0x30);
}
