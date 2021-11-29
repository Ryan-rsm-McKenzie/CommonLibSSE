#pragma once

#include "RE/H/hkpMotion.h"

namespace RE
{
	class hkpMaxSizeMotion;

	class hkpKeyframedRigidMotion : public hkpMotion
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkpKeyframedRigidMotion;

		~hkpKeyframedRigidMotion() override;  // 00

		// override (hkpMotion)
		void SetMass(float a_mass) override;                                                                                                           // 03 - { return; }
		void SetMassInv(float a_massInv) override;                                                                                                     // 04 - { return; }
		void GetInertiaLocal(hkMatrix3& a_inertiaOut) const override;                                                                                  // 05
		void GetInertiaWorld(hkMatrix3& a_inertiaOut) const override;                                                                                  // 06
		void SetInertiaLocal(const hkMatrix3& a_inertia) override;                                                                                     // 07 - { return; }
		void SetInertiaInvLocal(const hkMatrix3& a_inertiaInv) override;                                                                               // 08 - { return; }
		void GetInertiaInvLocal(hkMatrix3& a_inertiaInvOut) const override;                                                                            // 09
		void GetInertiaInvWorld(hkMatrix3& a_inertiaInvOut) const override;                                                                            // 0A
		void GetProjectedPointVelocity(const hkVector4& a_point, const hkVector4& a_normal, float& a_velOut, float& a_invVirtMassOut) const override;  // 12
		void ApplyLinearImpulse(const hkVector4& a_impulse) override;                                                                                  // 13 - { return; }
		void ApplyPointImpulse(const hkVector4& a_impulse, const hkVector4& a_point) override;                                                         // 14 - { return; }
		void ApplyAngularImpulse(const hkVector4& a_impulse) override;                                                                                 // 15 - { return; }
		void ApplyForce(const float a_deltaTime, const hkVector4& a_force) override;                                                                   // 16 - { return; }
		void ApplyForce(const float a_deltaTime, const hkVector4& a_force, const hkVector4& a_point) override;                                         // 17 - { return; }
		void ApplyTorque(const float a_deltaTime, const hkVector4& a_torque) override;                                                                 // 18 - { return; }

		// add
		virtual void SetStepPosition(float a_position, float a_timestep);  // 1A - { return; }
		virtual void SetStoredMotion(hkpMaxSizeMotion* a_savedMotion);     // 1B
	};
	static_assert(sizeof(hkpKeyframedRigidMotion) == 0x140);

	class hkpMaxSizeMotion : public hkpKeyframedRigidMotion
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkpMaxSizeMotion;
	};
	static_assert(sizeof(hkpMaxSizeMotion) == 0x140);
}
