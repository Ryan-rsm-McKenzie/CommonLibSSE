#pragma once

#include "RE/H/hkpBroadPhaseCastCollector.h"
#include "RE/H/hkpLinearCastCollisionInput.h"
#include "RE/H/hkpShapeType.h"

namespace RE
{
	class hkpCdPointCollector;
	class hkpCollidable;
	class hkpCollidableCollidableFilter;
	struct hkpLinearCastInput;

	class hkpWorldLinearCaster : public hkpBroadPhaseCastCollector
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkpWorldLinearCaster;

		~hkpWorldLinearCaster() override = default;  // 00

		// override (hkpBroadPhaseCastCollector)
		float AddBroadPhaseHandle(const hkpBroadPhaseHandle* a_broadphaseHandle, std::int32_t a_castIndex) override;  // 01

		// members
		const hkpLinearCastInput*            input;                // 10
		const hkpCollidableCollidableFilter* filter;               // 18
		hkpCdPointCollector*                 castCollector;        // 20
		hkpCdPointCollector*                 startPointCollector;  // 28
		const hkpCollidable*                 collidableA;          // 30
		hkpShapeType                         typeA;                // 38
		std::uint32_t                        pad3C;                // 3C
		hkpLinearCastCollisionInput          shapeInput;           // 40
	};
	static_assert(sizeof(hkpWorldLinearCaster) == 0xC0);
}
