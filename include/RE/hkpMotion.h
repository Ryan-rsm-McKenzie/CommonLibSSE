#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESForm

#include "RE/hkBaseTypes.h"  // hkHalf
#include "RE/hkMotionState.h"  // hkMotionState
#include "RE/hkReferencedObject.h"  // hkReferencedObject
#include "RE/hkVector4.h"  // hkVector4


namespace RE
{
	class hkMatrix3;
	class hkQuaternion;
	class hkTransform;
	class hkpMaxSizeMotion;


	class hkpMotion : public hkReferencedObject
	{
	public:
		inline static const void* RTTI = RTTI_hkpMotion;


		enum { kNumInactiveFramesToDeactivate = 5 };


		enum class MotionType : UInt8
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


		virtual ~hkpMotion();																																// 00

		// add
		virtual void	SetMass(float a_mass);																												// 03 - { SetMassInv(a_mass); }
		virtual void	SetMassInv(float a_massInv);																										// 04 - { inertiaAndMassInv.quad.m128_f32[3] = a_massInv; }
		virtual void	GetInertiaLocal(hkMatrix3& a_inertiaOut) const = 0;																					// 05
		virtual void	GetInertiaWorld(hkMatrix3& a_inertiaOut) const = 0;																					// 06
		virtual void	SetInertiaLocal(const hkMatrix3& a_inertia) = 0;																					// 07
		virtual void	SetInertiaInvLocal(const hkMatrix3& a_inertiaInv) = 0;																				// 08
		virtual void	GetInertiaInvLocal(hkMatrix3& a_inertiaInvOut) const = 0;																			// 09
		virtual void	GetInertiaInvWorld(hkMatrix3& a_inertiaInvOut) const = 0;																			// 0A
		virtual void	SetCenterOfMassInLocal(const hkVector4& a_centerOfMass);																			// 0B
		virtual void	SetPosition(const hkVector4& a_position);																							// 0C
		virtual void	SetRotation(const hkQuaternion& a_rotation);																						// 0D
		virtual void	SetPositionAndRotation(const hkVector4& a_position, const hkQuaternion& a_rotation);												// 0E
		virtual void	SetTransform(const hkTransform& a_transform);																						// 0F
		virtual void	SetLinearVelocity(const hkVector4& a_newVel);																						// 10 - { linearVelocity = a_newVel; }
		virtual void	SetAngularVelocity(const hkVector4& a_newVel);																						// 11 - { angularVelocity = a_newVel; }
		virtual void	GetProjectedPointVelocity(const hkVector4& a_point, const hkVector4& a_normal, float& a_velOut, float& a_invVirtMassOut) const = 0;	// 12
		virtual void	ApplyLinearImpulse(const hkVector4& a_impulse);																						// 13
		virtual void	ApplyPointImpulse(const hkVector4& a_impulse, const hkVector4& a_point) = 0;														// 14
		virtual void	ApplyAngularImpulse(const hkVector4& a_impulse) = 0;																				// 15
		virtual void	ApplyForce(const float a_deltaTime, const hkVector4& a_force) = 0;																	// 16
		virtual void	ApplyForce(const float a_deltaTime, const hkVector4& a_force, const hkVector4& a_point) = 0;										// 17
		virtual void	ApplyTorque(const float a_deltaTime, const hkVector4& a_torque) = 0;																// 18
		virtual void	GetMotionStateAndVelocitiesAndDeactivationType(hkpMotion* a_motionOut);																// 19


		// members
		MotionType			type;								// 010
		UInt8				deactivationIntegrateCounter;		// 011
		UInt16				deactivationNumInactiveFrames[2];	// 012
		UInt16				pad016;								// 016
		UInt64				pad018;								// 018
		hkMotionState		motionState;						// 020
		hkVector4			inertiaAndMassInv;					// 0D0
		hkVector4			linearVelocity;						// 0E0
		hkVector4			angularVelocity;					// 0F0
		hkVector4			deactivationRefPosition[2];			// 100
		UInt32				deactivationRefOrientation[2];		// 120
		hkpMaxSizeMotion*	mavedMotion;						// 128
		UInt16				savedQualityTypeIndex;				// 130
		UInt16				pad132;								// 132
		hkHalf				gravityFactor;						// 134
		UInt64				pad138;								// 138
	};
	STATIC_ASSERT(sizeof(hkpMotion) == 0x140);
}
