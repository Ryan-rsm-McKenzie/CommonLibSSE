#pragma once

#include "RE/H/hkpEntity.h"

namespace RE
{
	class hkpRigidBody : public hkpEntity
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkpRigidBody;

		~hkpRigidBody() override;  // 00

		// override (hkpEntity)
		hkWorldOperation::Result SetShape(const hkpShape* a_shape) override;               // 03
		hkWorldOperation::Result UpdateShape(hkpShapeModifier* a_shapeModifier) override;  // 04
		hkMotionState*           GetMotionState() override;                                // 05 - { return &motion.motionState; }

		// add
		virtual hkpRigidBody* Clone() const;  // 07
	};
	static_assert(sizeof(hkpRigidBody) == 0x2D0);
}
