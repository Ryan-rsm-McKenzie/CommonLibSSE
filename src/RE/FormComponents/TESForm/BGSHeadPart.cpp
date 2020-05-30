#include "RE/FormComponents/TESForm/BGSHeadPart.h"


namespace RE
{
	bool BGSHeadPart::IsExtraPart()
	{
		return (flags & Flag::kIsExtraPart) != Flag::kNone;
	}
}
