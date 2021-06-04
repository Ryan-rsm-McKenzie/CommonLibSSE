#pragma once

#include "RE/B/BSAtomic.h"
#include "RE/B/BSPointerHandle.h"

namespace RE
{
	class ActorPackageData;
	class TESPackage;

	class ActorPackage
	{
	public:
		enum class ACTOR_PACKAGE_FLAG
		{
			kNone = 0,
			kSaveLoadSharedPackage = 1 << 0
		};

		// members
		mutable BSSpinLock                                packageLock;            // 00
		TESPackage*                                       package;                // 08
		ActorPackageData*                                 data;                   // 10
		ObjectRefHandle                                   target;                 // 18
		std::int32_t                                      currentProcedureIndex;  // 1C
		float                                             packageStartTime;       // 20
		std::uint32_t                                     modifiedPackageFlag;    // 24
		std::uint16_t                                     modifiedInterruptFlag;  // 28
		stl::enumeration<ACTOR_PACKAGE_FLAG, std::int8_t> actorPackageFlags;      // 2A
		std::int8_t                                       preferredSpeed;         // 2B
		std::uint32_t                                     pad2C;                  // 2C
	};
	static_assert(sizeof(ActorPackage) == 0x30);
}
