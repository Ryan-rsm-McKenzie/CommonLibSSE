#pragma once

#include "RE/IDEvent.h"


namespace RE
{
	class ThumbstickEvent : public IDEvent
	{
	public:
		inline static constexpr auto RTTI = RTTI_ThumbstickEvent;


		struct InputTypes
		{
			enum InputType : UInt32
			{
				kLeftThumbstick = 0x0B,
				kRightThumbstick = 0x0C
			};
		};
		using InputType = InputTypes::InputType;


		bool IsLeft() const;
		bool IsRight() const;


		// members
		float xValue;  // 28
		float yValue;  // 2C
	};
	STATIC_ASSERT(sizeof(ThumbstickEvent) == 0x30);
}
