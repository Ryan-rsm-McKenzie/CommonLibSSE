#include "RE/BSWin32KeyboardDevice.h"


namespace RE
{
	bool BSWin32KeyboardDevice::IsPressed(UInt32 keyCode) const
	{
		return (keyCode < sizeof(curState)) && ((curState[keyCode] & 0x80) != 0);
	}
}
