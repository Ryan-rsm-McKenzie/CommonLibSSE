#pragma once

namespace RE
{
	enum class QuestEvent
	{
		kNone = static_cast<std::underlying_type_t<QuestEvent>>(-1),  // NONE
		kKillActor = 0,                                               // KILL
		kAssaultActor = 1,                                            // ASSU
		kChangeLocation = 2,                                          // CLOC
		kScript = 3,                                                  // SCPT
		kActorDialogue = 4,                                           // ADIA
		kActorHello = 5,                                              // AHEL
		kPlayerAddItem = 7,                                           // AIPL
		kPlayerRemoveItem = 8,                                        // REMP
		kCraftItem = 9,                                               // CRFT
		kNewVoicePower = 13,                                          // NVPE
		kDeadBody = 14,                                               // DEAD
		kSkillIncrease = 15,                                          // SKIL
		kIncreaseLevel = 16,                                          // LEVL
		kChangeRelationshipRank = 17,                                 // CHBR
		kJail = 23,                                                   // JAIL
		kEscapeJail = 25,                                             // ESIA
		Arrest = 28,                                                  // ARRT
		kCastMagic = 29                                               // CAST
	};
}
