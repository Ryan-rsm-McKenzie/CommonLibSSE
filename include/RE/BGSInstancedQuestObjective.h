#pragma once

#include "RE/QuestObjectiveStates.h"


namespace RE
{
	struct BGSQuestObjective;


	struct BGSInstancedQuestObjective
	{
		// members
		BGSQuestObjective*		Objective;		// 00
		UInt32					instanceID;		// 08
		QUEST_OBJECTIVE_STATE	InstanceState;	// 0C
	};
	STATIC_ASSERT(sizeof(BGSInstancedQuestObjective) == 0x10);
}
