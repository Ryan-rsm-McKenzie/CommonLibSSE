#pragma once

#include "RE/H/hkBaseTypes.h"
#include "RE/H/hkMotionState.h"
#include "RE/H/hkReferencedObject.h"
#include "RE/H/hkVector4.h"

namespace RE
{
	class hkMatrix3;
	class hkQuaternion;
	class hkTransform;
	class hkpMaxSizeMotion;

	class hkpMotion : public hkReferencedObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkpMotion;

		enum
		{
			kNumInactiveFramesToDeactivate = 5
		};

		enum class MotionType
		{
			kInvalid,
			kDynamic,
			kSphereInertia,
			kBoxInertia,
			kKeyframed,
			kFixed,
			kThinBoxInertia,
			kCharacter,

			kTotal
		};

		virtual ~hkpMotion();  // 00

		// add
		virtual void SetMass(float a_mass);																												  // 03 - { SetMassInv(a_mass); }
		virtual void SetMassInv(float a_massInv);																										  // 04 - { inertiaAndMassInv.quad.m128_f32[3] = a_massInv; }
		virtual void GetInertiaLocal(hkMatrix3& a_inertiaOut) const = 0;																				  // 05
		virtual void GetInertiaWorld(hkMatrix3& a_inertiaOut) const = 0;																				  // 06
		virtual void SetInertiaLocal(const hkMatrix3& a_inertia) = 0;																					  // 07
		virtual void SetInertiaInvLocal(const hkMatrix3& a_inertiaInv) = 0;																				  // 08
		virtual void GetInertiaInvLocal(hkMatrix3& a_inertiaInvOut) const = 0;																			  // 09
		virtual void GetInertiaInvWorld(hkMatrix3& a_inertiaInvOut) const = 0;																			  // 0A
		virtual void SetCenterOfMassInLocal(const hkVector4& a_centerOfMass);																			  // 0B
		virtual void SetPosition(const hkVector4& a_position);																							  // 0C
		virtual void SetRotation(const hkQuaternion& a_rotation);																						  // 0D
		virtual void SetPositionAndRotation(const hkVector4& a_position, const hkQuaternion& a_rotation);												  // 0E
		virtual void SetTransform(const hkTransform& a_transform);																						  // 0F
		virtual void SetLinearVelocity(const hkVector4& a_newVel);																						  // 10 - { linearVelocity = a_newVel; }
		virtual void SetAngularVelocity(const hkVector4& a_newVel);																						  // 11 - { angularVelocity = a_newVel; }
		virtual void GetProjectedPointVelocity(const hkVector4& a_point, const hkVector4& a_normal, float& a_velOut, float& a_invVirtMassOut) const = 0;  // 12
		virtual void ApplyLinearImpulse(const hkVector4& a_impulse);																					  // 13
		virtual void ApplyPointImpulse(const hkVector4& a_impulse, const hkVector4& a_point) = 0;														  // 14
		virtual void ApplyAngularImpulse(const hkVector4& a_impulse) = 0;																				  // 15
		virtual void ApplyForce(const float a_deltaTime, const hkVector4& a_force) = 0;																	  // 16
		virtual void ApplyForce(const float a_deltaTime, const hkVector4& a_force, const hkVector4& a_point) = 0;										  // 17
		virtual void ApplyTorque(const float a_deltaTime, const hkVector4& a_torque) = 0;																  // 18
		virtual void GetMotionStateAndVelocitiesAndDeactivationType(hkpMotion* a_motionOut);															  // 19

		// members
		stl::enumeration<MotionType, std::uint8_t> type;							  // 010
		std::uint8_t							   deactivationIntegrateCounter;	  // 011
		std::uint16_t							   deactivationNumInactiveFrames[2];  // 012
		std::uint16_t							   pad016;							  // 016
		std::uint64_t							   pad018;							  // 018
		hkMotionState							   motionState;						  // 020
		hkVector4								   inertiaAndMassInv;				  // 0D0
		hkVector4								   linearVelocity;					  // 0E0
		hkVector4								   angularVelocity;					  // 0F0
		hkVector4								   deactivationRefPosition[2];		  // 100
		std::uint32_t							   deactivationRefOrientation[2];	  // 120
		hkpMaxSizeMotion*						   mavedMotion;						  // 128
		std::uint16_t							   savedQualityTypeIndex;			  // 130
		std::uint16_t							   pad132;							  // 132
		hkHalf									   gravityFactor;					  // 134
		std::uint64_t							   pad138;							  // 138
	};
	static_assert(sizeof(hkpMotion) == 0x140);
}
