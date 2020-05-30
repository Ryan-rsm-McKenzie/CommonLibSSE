#include "RE/FormComponents/Components/DialogueItem.h"


namespace RE
{
	DialogueItem::DialogueItem(TESQuest* a_quest, TESTopic* a_topic, TESTopicInfo* a_topicInfo, Actor* a_speaker) :
		responses(),
		currentResponse(),
		topicInfo(nullptr),
		topic(nullptr),
		quest(nullptr),
		speaker(nullptr),
		extraData(nullptr)
	{
		Ctor(a_quest, a_topic, a_topicInfo, a_speaker);
	}


	DialogueItem* DialogueItem::Ctor(TESQuest* a_quest, TESTopic* a_topic, TESTopicInfo* a_topicInfo, Actor* a_speaker)
	{
		using func_t = decltype(&DialogueItem::Ctor);
		REL::Offset<func_t> func(Offset::DialogueItem::Ctor);
		return func(this, a_quest, a_topic, a_topicInfo, a_speaker);
	}
}
