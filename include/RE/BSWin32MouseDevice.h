#pragma once

#include "RE/BSMouseDevice.h"  // BSMouseDevice


namespace RE
{
	class BSWin32MouseDevice : public BSMouseDevice
	{
	public:
		enum Mouse : UInt32
		{
			kMouse_LeftButton = 0,
			kMouse_RightButton,
			kMouse_MiddleButton,
			kMouse_Button3,
			kMouse_Button4,
			kMouse_Button5,
			kMouse_Button6,
			kMouse_Button7,
			kMouse_WheelUp,
			kMouse_WheelDown,
		};


		// members
		UInt64	unk30;			// 30
		void*	inputDevice;	// 38 - IDirectInputDevice8*
	};
}
