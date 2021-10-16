#pragma once

#include "RE/H/hkbCharacter.h"

namespace RE
{
	class hkaDefaultAnimationControlMapperData;
	class hkbGeneratorOutputListener;
	class hkbEventQueue;
	class hkbAttachmentManager;

	class hkbContext
	{
	public:
		// members
		hkbCharacter*                         character;                 // 00
		hkbBehaviorGraph*                     behavior;                  // 08
		hkRefVariant                          nodeToIndexMap;            // 10 hkPointerMap<const hkbNode*, int>
		hkbEventQueue*                        eventQueue;                // 18
		hkaDefaultAnimationControlMapperData* sharedEventQueue;          // 20
		hkRefPtr<hkbGeneratorOutputListener>  generatorOutputListener;   // 28
		bool                                  eventTriggeredTransition;  // 30
		std::uint8_t                          pad31[7];                  // 31
		hkRefVariant                          world;                     // 38
		hkbAttachmentManager*                 attachmentManager;         // 40
		hkRefVariant                          animationCache;            // 48
	};
	static_assert(sizeof(hkbContext) == 0x50);
}
