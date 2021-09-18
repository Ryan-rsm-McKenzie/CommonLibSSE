#pragma once

#include "RE/T/TESQuest.h"

namespace RE
{
	class BGSInstancedQuestObjective
	{
	public:
		using ObjectiveState = BGSQuestObjective::State;

		// members
		BGSQuestObjective* Objective;      // 00
		std::uint32_t      instanceID;     // 08
		ObjectiveState     instanceState;  // 0C
	};
	static_assert(sizeof(BGSInstancedQuestObjective) == 0x10);
}
