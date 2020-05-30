#pragma once

#include "RE/hkpBroadPhaseCastCollector.h"
#include "RE/hkpLinearCastCollisionInput.h"
#include "RE/hkpShapeType.h"


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


		virtual ~hkpWorldLinearCaster() = default;	// 00

		// override (hkpBroadPhaseCastCollector)
		virtual float AddBroadPhaseHandle(const hkpBroadPhaseHandle* a_broadphaseHandle, SInt32 a_castIndex) override;	// 01


		// members
		const hkpLinearCastInput*			 input;				   // 10
		const hkpCollidableCollidableFilter* filter;			   // 18
		hkpCdPointCollector*				 castCollector;		   // 20
		hkpCdPointCollector*				 startPointCollector;  // 28
		const hkpCollidable*				 collidableA;		   // 30
		hkpShapeType						 typeA;				   // 38
		UInt32								 pad3C;				   // 3C
		hkpLinearCastCollisionInput			 shapeInput;		   // 40
	};
	STATIC_ASSERT(sizeof(hkpWorldLinearCaster) == 0xC0);
}
