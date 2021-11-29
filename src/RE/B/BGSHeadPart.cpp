#include "RE/B/BGSHeadPart.h"

namespace RE
{
	bool BGSHeadPart::IsExtraPart()
	{
		return flags.all(Flag::kIsExtraPart);
	}
}
