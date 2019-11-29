#include "RE/TESTopicInfo.h"

#include "RE/TESTopic.h"


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


	DialogueData TESTopicInfo::GetDialogueData(Actor* a_speaker)
	{
		return { topic->quest, topic, this, a_speaker };
	}
}
