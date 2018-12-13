#pragma once

#include "RE/BSMouseDevice.h"  // BSMouseDevice


namespace RE
{
	class BSWin32MouseDevice : public BSMouseDevice
	{
	public:
		enum class Mouse : UInt32
		{
			kLeftButton,
			kRightButton,
			kMiddleButton,
			kButton3,
			kButton4,
			kButton5,
			kButton6,
			kButton7,
			kWheelUp,
			kWheelDown
		};


		// members
		UInt64	unk30;			// 30
		void*	inputDevice;	// 38 - IDirectInputDevice8*
	};
}
