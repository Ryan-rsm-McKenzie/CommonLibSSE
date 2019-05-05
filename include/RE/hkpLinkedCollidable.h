#pragma once

#include "RE/hkArray.h"  // hkArray
#include "RE/hkpCollidable.h"  // hkpCollidable


namespace RE
{
	struct hkpAgentNnEntry;


	class hkpLinkedCollidable : public hkpCollidable
	{
	public:
		struct CollisionEntry
		{
			hkpAgentNnEntry*		agentEntry;	// 00
			hkpLinkedCollidable*	partner;	// 08
		};
		STATIC_ASSERT(sizeof(CollisionEntry) == 0x10);


		hkArray<CollisionEntry> collisionEntries;	// 70
	};
	STATIC_ASSERT(sizeof(hkpLinkedCollidable) == 0x80);
}
