#include "RE/BSKeyboardDevice.h"


namespace RE
{
	bool BSKeyboardDevice::IsPressed(UInt32 keyCode) const
	{
		return (keyCode < sizeof(curState)) && ((curState[keyCode] & 0x80) != 0);
	}
}
