#include "RE/G/GStd.h"

namespace RE
{
	wchar_t G_towlower(wchar_t a_ch)
	{
		return static_cast<wchar_t>(std::towlower(a_ch));
	}
}
