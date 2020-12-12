#include "RE/FormComponents/TESForm/BGSHeadPart.h"


namespace RE
{
	bool BGSHeadPart::IsExtraPart()
	{
		return flags.all(Flag::kIsExtraPart);
	}
}
