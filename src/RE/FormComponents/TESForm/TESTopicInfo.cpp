#include "RE/TESTopicInfo.h"

#include "RE/TESTopic.h"


namespace RE
{
	TESTopicInfo::ResponseData::~ResponseData()
	{
		delete next;
	}


	float TOPIC_INFO_DATA::GetResetHours() const
	{
		return static_cast<float>(timeUntilReset);
	}


	DialogueItem TESTopicInfo::GetDialogueData(Actor* a_speaker)
	{
		return { parentTopic->ownerQuest, parentTopic, this, a_speaker };
	}
}
