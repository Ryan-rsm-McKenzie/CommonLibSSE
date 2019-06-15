#pragma once

#include "skse64/GameRTTI.h"  // RTTI_hkpKeyframedRigidMotion, RTTI_hkpMaxSizeMotion

#include "RE/hkpMotion.h"  // hkpMotion


namespace RE
{
	class hkpMaxSizeMotion;


	class hkpKeyframedRigidMotion : public hkpMotion
	{
	public:
		inline static const void* RTTI = RTTI_hkpKeyframedRigidMotion;


		virtual ~hkpKeyframedRigidMotion();																															// 00

		// override (hkpMotion)
		virtual void	SetMass(float a_mass) override;																												// 03 - { return; }
		virtual void	SetMassInv(float a_massInv) override;																										// 04 - { return; }
		virtual void	GetInertiaLocal(hkMatrix3& a_inertiaOut) const override;																					// 05
		virtual void	GetInertiaWorld(hkMatrix3& a_inertiaOut) const override;																					// 06
		virtual void	SetInertiaLocal(const hkMatrix3& a_inertia) override;																						// 07 - { return; }
		virtual void	SetInertiaInvLocal(const hkMatrix3& a_inertiaInv) override;																					// 08 - { return; }
		virtual void	GetInertiaInvLocal(hkMatrix3& a_inertiaInvOut) const override;																				// 09
		virtual void	GetInertiaInvWorld(hkMatrix3& a_inertiaInvOut) const override;																				// 0A
		virtual void	GetProjectedPointVelocity(const hkVector4& a_point, const hkVector4& a_normal, float& a_velOut, float& a_invVirtMassOut) const override;	// 12
		virtual void	ApplyLinearImpulse(const hkVector4& a_impulse) override;																					// 13 - { return; }
		virtual void	ApplyPointImpulse(const hkVector4& a_impulse, const hkVector4& a_point) override;															// 14 - { return; }
		virtual void	ApplyAngularImpulse(const hkVector4& a_impulse) override;																					// 15 - { return; }
		virtual void	ApplyForce(const float a_deltaTime, const hkVector4& a_force) override;																		// 16 - { return; }
		virtual void	ApplyForce(const float a_deltaTime, const hkVector4& a_force, const hkVector4& a_point) override;											// 17 - { return; }
		virtual void	ApplyTorque(const float a_deltaTime, const hkVector4& a_torque) override;																	// 18 - { return; }

		// add
		virtual void	SetStepPosition(float a_position, float a_timestep);																						// 1A - { return; }
		virtual void	SetStoredMotion(hkpMaxSizeMotion* a_savedMotion);																							// 1B
	};
	STATIC_ASSERT(sizeof(hkpKeyframedRigidMotion) == 0x140);


	class hkpMaxSizeMotion : public hkpKeyframedRigidMotion
	{
	public:
		inline static const void* RTTI = RTTI_hkpMaxSizeMotion;
	};
	STATIC_ASSERT(sizeof(hkpMaxSizeMotion) == 0x140);
}
