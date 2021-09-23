#pragma once

#include "RE/Q/QuestObjectiveStates.h"

namespace RE
{
	class BGSQuestObjective;

	class BGSInstancedQuestObjective
	{
	public:
		// members
		BGSQuestObjective*    Objective;      // 00
		std::uint32_t         instanceID;     // 08
		QUEST_OBJECTIVE_STATE InstanceState;  // 0C
	};
	static_assert(sizeof(BGSInstancedQuestObjective) == 0x10);
}
