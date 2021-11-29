#pragma once

#include "RE/B/BGSLocalizedStringDL.h"
#include "RE/T/TESCondition.h"

namespace RE
{
	class TESQuest;
	class TESQuestStage;

	struct TESQuestStageItem
	{
	public:
		// members
		TESCondition         objConditions;  // 00
		TESQuest*            nextQuest;      // 08
		BGSLocalizedStringDL logEntry;       // 10
		std::uint8_t         data;           // 14
		std::int8_t          index;          // 15
		bool                 hasLogEntry;    // 16
		std::uint8_t         pad17;          // 17
		TESQuest*            owner;          // 18
		TESQuestStage*       owningStage;    // 20
	};
	static_assert(sizeof(TESQuestStageItem) == 0x28);
}
