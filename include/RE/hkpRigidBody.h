#pragma once

#include "skse64/GameRTTI.h"  // RTTI_hkpRigidBody

#include "RE/hkpEntity.h"  // hkpEntity


namespace RE
{
	class hkpRigidBody : public hkpEntity
	{
	public:
		inline static const void* RTTI = RTTI_hkpRigidBody;


		virtual ~hkpRigidBody();																		// 00

		// override (hkpEntity)
		virtual hkWorldOperation::Result	SetShape(const hkpShape* a_shape) override;					// 03
		virtual hkWorldOperation::Result	UpdateShape(hkpShapeModifier* a_shapeModifier) override;	// 04
		virtual hkMotionState*				GetMotionState() override;									// 05 - { return &motion.motionState; }

		// add
		virtual hkpRigidBody*				Clone() const;												// 07
	};
	STATIC_ASSERT(sizeof(hkpRigidBody) == 0x2D0);
}
