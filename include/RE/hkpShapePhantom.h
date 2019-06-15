#pragma once

#include "skse64/GameRTTI.h"  // RTTI_hkpShapePhantom

#include "RE/hkMotionState.h"  // hkMotionState
#include "RE/hkpPhantom.h"  // hkpPhantom


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
		inline static const void* RTTI = RTTI_hkpShapePhantom;


		virtual ~hkpShapePhantom();																																															// 00

		// override (hkpPhantom)
		virtual hkWorldOperation::Result	SetShape(const hkpShape* a_shape) override;																																		// 03
		virtual hkMotionState*				GetMotionState() override;																																						// 05 - { return &motionState; }
		virtual void						CalcAabb(hkAabb& a_aabb) override;																																				// 07
		virtual void						DeallocateInternalArrays() override;																																			// 0E - { hkpPhantom::DeallocateInternalArrays(); }

		// add
		virtual void						SetPositionAndLinearCast(const hkVector4& a_position, const hkpLinearCastInput& a_input, hkpCdPointCollector& a_castCollector, hkpCdPointCollector* a_startCollector) = 0;		// 0F
		virtual void						SetTransformAndLinearCast(const hkTransform& a_transform, const hkpLinearCastInput& a_input, hkpCdPointCollector& a_castCollector, hkpCdPointCollector* a_startCollector) = 0;	// 10
		virtual void						GetClosestPoints(hkpCdPointCollector& a_collector, const hkpCollisionInput* a_input = 0) = 0;																					// 11
		virtual void						GetPenetrations(hkpCdBodyPairCollector& a_collector, const hkpCollisionInput* a_input = 0) = 0;																					// 12


		// members
		hkMotionState motionState;	// 0F0
	};
	STATIC_ASSERT(sizeof(hkpShapePhantom) == 0x1A0);
}
