#pragma once

#include "RE/H/hkMotionState.h"
#include "RE/H/hkpPhantom.h"

namespace RE
{
	class hkTransform;
	class hkpCdBodyPairCollector;
	class hkpCdPointCollector;
	struct hkpCollisionInput;
	struct hkpLinearCastInput;

	class hkpShapePhantom : public hkpPhantom
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkpShapePhantom;

		~hkpShapePhantom() override;  // 00

		// override (hkpPhantom)
		hkWorldOperation::Result SetShape(const hkpShape* a_shape) override;  // 03
		hkMotionState*           GetMotionState() override;                   // 05 - { return &motionState; }
		void                     CalcAabb(hkAabb& a_aabb) override;           // 07
		void                     DeallocateInternalArrays() override;         // 0E - { hkpPhantom::DeallocateInternalArrays(); }

		// add
		virtual void SetPositionAndLinearCast(const hkVector4& a_position, const hkpLinearCastInput& a_input, hkpCdPointCollector& a_castCollector, hkpCdPointCollector* a_startCollector) = 0;      // 0F
		virtual void SetTransformAndLinearCast(const hkTransform& a_transform, const hkpLinearCastInput& a_input, hkpCdPointCollector& a_castCollector, hkpCdPointCollector* a_startCollector) = 0;  // 10
		virtual void GetClosestPoints(hkpCdPointCollector& a_collector, const hkpCollisionInput* a_input = 0) = 0;                                                                                   // 11
		virtual void GetPenetrations(hkpCdBodyPairCollector& a_collector, const hkpCollisionInput* a_input = 0) = 0;                                                                                 // 12

		// members
		hkMotionState motionState;  // 0F0
	};
	static_assert(sizeof(hkpShapePhantom) == 0x1A0);
}
