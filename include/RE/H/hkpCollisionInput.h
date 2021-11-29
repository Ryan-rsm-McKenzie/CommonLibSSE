#pragma once

#include "RE/H/hkBaseTypes.h"
#include "RE/H/hkVector4.h"

namespace RE
{
	class hkpCollisionDispatcher;
	class hkpCollisionFilter;
	class hkpConvexListFilter;

	struct hkpCollisionInput
	{
	public:
		struct Aabb32Info
		{
		public:
			// members
			hkVector4 bitOffsetLow;   // 00
			hkVector4 bitOffsetHigh;  // 10
			hkVector4 bitScale;       // 20
		};
		static_assert(sizeof(Aabb32Info) == 0x30);

		// members
		hkpCollisionDispatcher*    dispatcher;                // 00
		std::int32_t               weldClosestPoints;         // 08
		std::int32_t               forceAcceptContactPoints;  // 0C
		float                      tolerance;                 // 10
		std::uint32_t              pad14;                     // 14
		const hkpCollisionFilter*  filter;                    // 18
		const hkpConvexListFilter* convexListFilter;          // 20
		mutable std::int32_t       createPredictiveAgents;    // 28
		std::uint32_t              pad2C;                     // 2C
		Aabb32Info                 aabb32Info;                // 30
	};
	static_assert(sizeof(hkpCollisionInput) == 0x60);
}
