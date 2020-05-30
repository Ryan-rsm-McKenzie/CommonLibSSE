#include "RE/BSWin32KeyboardDevice.h"


namespace RE
{
	bool BSWin32KeyboardDevice::IsPressed(UInt32 a_keyCode) const
	{
		return (a_keyCode < sizeof(curState)) && ((curState[a_keyCode] & 0x80) != 0);
	}
}
