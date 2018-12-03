#pragma once

#include "skse64/GameTypes.h"  // BSIntrusiveRefCounted

class KinectEvent;
class MouseMoveEvent;


namespace RE
{
	class ButtonEvent;
	class InputEvent;
	class ThumbstickEvent;


	class MenuEventHandler : public BSIntrusiveRefCounted
	{
	public:
		MenuEventHandler();
		virtual ~MenuEventHandler() {}									// 0

		virtual bool	CanProcess(InputEvent* a_event) = 0;			// 1
		virtual bool	ProcessKinect(KinectEvent* a_event);			// 2
		virtual bool	ProcessThumbstick(ThumbstickEvent* a_event);	// 3
		virtual bool	ProcessMouseMove(MouseMoveEvent* a_event);		// 4
		virtual bool	ProcessButton(ButtonEvent* a_event);			// 5
	};
	STATIC_ASSERT(sizeof(MenuEventHandler) == 0x10);
}
