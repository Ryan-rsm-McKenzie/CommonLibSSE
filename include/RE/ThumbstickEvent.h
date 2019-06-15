#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ThumbstickEvent

#include "RE/IDEvent.h"  // IDEvent


namespace RE
{
	class ThumbstickEvent : public IDEvent
	{
	public:
		inline static const void* RTTI = RTTI_ThumbstickEvent;


		struct InputTypes
		{
			enum InputType : UInt32
			{
				kLeftThumbstick = 0x0B,
				kRightThumbstick = 0x0C
			};
		};
		using InputType = InputTypes::InputType;


		bool	IsLeft() const;
		bool	IsRight() const;


		// members
		float	x;	// 28
		float	y;	// 2C
	};
	STATIC_ASSERT(sizeof(ThumbstickEvent) == 0x30);
}
