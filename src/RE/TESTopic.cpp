#include "RE/TESTopic.h"

#include "skse64_common/Relocation.h"  // RelocAddr

#include "RE/Offsets.h"


namespace RE
{
	float TESTopic::GetPriority() const
	{
		return static_cast<float>(priority);
	}


	DialogueData* TESTopic::CreateDialogueData(Actor* a_speaker, Actor* a_listener, TESTopicInfo* a_topicInfo, void* a_arg4, void* a_arg5)
	{
		typedef DialogueData* _CreateDialogueData_t(TESTopic* a_this, Actor* a_speaker, Actor* a_listener, TESTopicInfo* a_topicInfo, void* a_arg4, void* a_arg5);
		RelocAddr<_CreateDialogueData_t*> _CreateDialogueData(TES_TOPIC_CREATE_DIALOGUE_DATA);
		return _CreateDialogueData(this, a_speaker, a_listener, a_topicInfo, a_arg4, a_arg5);
	}
}
