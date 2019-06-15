#pragma once

#include "skse64/GameRTTI.h"  // RTTI_hkpFixedRigidMotion

#include "RE/hkpKeyframedRigidMotion.h"  // hkpKeyframedRigidMotion


namespace RE
{
	class hkpFixedRigidMotion : public hkpKeyframedRigidMotion
	{
	public:
		inline static const void* RTTI = RTTI_hkpFixedRigidMotion;


		virtual ~hkpFixedRigidMotion();													// 00

		// override (hkpKeyframedRigidMotion)
		virtual void	SetLinearVelocity(const hkVector4& a_newVel) override;			// 10 - { return; }
		virtual void	SetAngularVelocity(const hkVector4& a_newVel) override;			// 11 - { return; }
		virtual void	SetStepPosition(float a_position, float a_timestep) override;	// 1A - { return; }

		// add
		virtual void	GetPositionAndVelocities(hkpMotion* a_motionOut);				// 1C
	};
	STATIC_ASSERT(sizeof(hkpFixedRigidMotion) == 0x140);
}
