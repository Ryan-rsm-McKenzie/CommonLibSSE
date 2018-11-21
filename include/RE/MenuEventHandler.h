#pragma once

#include "skse64/GameTypes.h"  // BSIntrusiveRefCounted

class InputEvent;
class KinectEvent;
class MouseMoveEvent;
class ThumbstickEvent;

namespace RE
{
	class ButtonEvent;
}


namespace RE
{
	class MenuEventHandler : public BSIntrusiveRefCounted
	{
	public:
		MenuEventHandler();
		virtual ~MenuEventHandler() {}

		virtual bool	CanProcess(InputEvent* a_event) = 0;			// 1
		virtual bool	ProcessKinect(KinectEvent* a_event);			// 2
		virtual bool	ProcessThumbstick(ThumbstickEvent* a_event);	// 3
		virtual bool	ProcessMouseMove(MouseMoveEvent* a_event);		// 4
		virtual bool	ProcessButton(RE::ButtonEvent* a_event);		// 5


		UInt8	unk08;		// 08
		UInt8	unk09;		// 09
		UInt8	pad0A[2];	// 0A
	};
}
