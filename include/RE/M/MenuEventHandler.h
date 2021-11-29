#pragma once

#include "RE/B/BSIntrusiveRefCounted.h"

namespace RE
{
	class ButtonEvent;
	class InputEvent;
	class KinectEvent;
	class MouseMoveEvent;
	class ThumbstickEvent;

	class MenuEventHandler : public BSIntrusiveRefCounted
	{
	public:
		inline static constexpr auto RTTI = RTTI_MenuEventHandler;

		MenuEventHandler() = default;
		virtual ~MenuEventHandler() = default;  // 00

		virtual bool CanProcess(InputEvent* a_event) = 0;          // 01
		virtual bool ProcessKinect(KinectEvent* a_event);          // 02 - { return false; }
		virtual bool ProcessThumbstick(ThumbstickEvent* a_event);  // 03 - { return false; }
		virtual bool ProcessMouseMove(MouseMoveEvent* a_event);    // 04 - { return false; }
		virtual bool ProcessButton(ButtonEvent* a_event);          // 05 - { return false; }

		// members
		bool          registered;  // 0C
		std::uint8_t  unk0D;       // 0D
		std::uint16_t pad0E;       // 0E
	};
	static_assert(sizeof(MenuEventHandler) == 0x10);
}
