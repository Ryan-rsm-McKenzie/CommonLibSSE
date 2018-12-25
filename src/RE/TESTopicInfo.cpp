#include "RE/TESTopicInfo.h"


namespace RE
{
	float TESTopicInfo::ResponseFlags::GetResetHours() const
	{
		return static_cast<float>(resetHours);
	}
}
