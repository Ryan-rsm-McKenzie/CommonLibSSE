#pragma once

#include "RE/BGSLocalizedStringDL.h"
#include "RE/TESCondition.h"


namespace RE
{
	class TESQuest;
	class TESQuestStage;


	struct TESQuestStageItem
	{
	public:
		// members
		TESCondition		 objConditions;	 // 00
		TESQuest*			 nextQuest;		 // 08
		BGSLocalizedStringDL logEntry;		 // 10
		UInt8				 data;			 // 14
		SInt8				 index;			 // 15
		bool				 hasLogEntry;	 // 16
		UInt8				 pad17;			 // 17
		TESQuest*			 owner;			 // 18
		TESQuestStage*		 owningStage;	 // 20
	};
	STATIC_ASSERT(sizeof(TESQuestStageItem) == 0x28);
}
