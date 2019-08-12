#include "RE/DialogueData.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	DialogueData::DialogueData(TESQuest* a_quest, TESTopic* a_topic, TESTopicInfo* a_topicInfo, Actor* a_speaker) :
		responses(),
		currentResponse(),
		topicInfo(0),
		topic(0),
		quest(0),
		speaker(0),
		extraData(0)
	{
		Ctor(a_quest, a_topic, a_topicInfo, a_speaker);
	}


	DialogueData* DialogueData::Ctor(TESQuest* a_quest, TESTopic* a_topic, TESTopicInfo* a_topicInfo, Actor* a_speaker)
	{
		using func_t = function_type_t<decltype(&DialogueData::Ctor)>;
		REL::Offset<func_t*> func(Offset::DialogueData::Ctor);
		return func(this, a_quest, a_topic, a_topicInfo, a_speaker);
	}
}
