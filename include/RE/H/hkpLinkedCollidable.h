#pragma once

#include "RE/H/hkArray.h"
#include "RE/H/hkpCollidable.h"

namespace RE
{
	struct hkpAgentNnEntry;

	class hkpLinkedCollidable : public hkpCollidable
	{
	public:
		struct CollisionEntry
		{
		public:
			// members
			hkpAgentNnEntry*     agentEntry;  // 00
			hkpLinkedCollidable* partner;     // 08
		};
		static_assert(sizeof(CollisionEntry) == 0x10);

		// members
		hkArray<CollisionEntry> collisionEntries;  // 70
	};
	static_assert(sizeof(hkpLinkedCollidable) == 0x80);
}
