#include "RE/TESTopicInfo.h"


namespace RE
{
	TESTopicInfo::ResponseData::~ResponseData()
	{
		delete next;
	}


	float TESTopicInfo::ResponseFlags::GetResetHours() const
	{
		return static_cast<float>(resetHours);
	}
}
