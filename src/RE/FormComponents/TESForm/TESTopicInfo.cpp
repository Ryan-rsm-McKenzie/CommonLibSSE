#include "RE/FormComponents/TESForm/TESTopicInfo.h"

#include "RE/FormComponents/TESForm/TESTopic.h"


namespace RE
{
	TESTopicInfo::ResponseData::~ResponseData()
	{
		delete next;
	}

	void TESTopicInfo::ResponseData::PopulateResponseText(TESFile* a_file)
	{
			using func_t = decltype(&TESTopicInfo::ResponseData::PopulateResponseText);
			REL::Relocation<func_t> func{ REL::ID(24985) };
			func(this, a_file);
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
