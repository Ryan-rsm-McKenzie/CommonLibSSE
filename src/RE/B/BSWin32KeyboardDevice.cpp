#include "RE/B/BSWin32KeyboardDevice.h"

namespace RE
{
	bool BSWin32KeyboardDevice::IsPressed(std::uint32_t a_keyCode) const
	{
		return (a_keyCode < sizeof(curState)) && ((curState[a_keyCode] & 0x80) != 0);
	}
}
