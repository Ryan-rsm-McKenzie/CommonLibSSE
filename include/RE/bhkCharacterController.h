#pragma once

#include "RE/BSBound.h"
#include "RE/BSTEvent.h"
#include "RE/BSTHashMap.h"
#include "RE/NiPoint3.h"
#include "RE/NiRefObject.h"
#include "RE/NiSmartPointer.h"
#include "RE/hkRefPtr.h"
#include "RE/hkStepInfo.h"
#include "RE/hkVector4.h"
#include "RE/hkpCharacterContext.h"
#include "RE/hkpCharacterControl.h"
#include "RE/hkpCharacterState.h"


namespace RE
{
	class bhkCharacterMoveFinishEvent;
	class bhkICharOrientationController;
	class bhkShape;
	class hkpRigidBody;
	class hkTransform;
	class hkVector4;


	enum class CHARACTER_FLAGS : UInt32
	{
		kNone = 0,
		kQuadruped = 1 << 0,
		kNoGravityOnGround = 1 << 1,
		kTryStep = 1 << 2,
		kNoFriction = 1 << 3,
		kAllowJumpNoContact = 1 << 4,
		kStuckQuad = 1 << 5,
		kAnimAngleMod = 1 << 6,
		kHitDamage = 1 << 7,
		kHitFlags = 1 << 7,
		kSupport = 1 << 8,
		kHasPotentialSupportManifold = 1 << 9,
		kCanJump = 1 << 10,
		kChaseBip = 1 << 11,
		kFollowRagdoll = 1 << 12,
		kJumping = 1 << 13,
		kNotPushable = 1 << 14,
		kFloatLand = 1 << 15,
		kCheckSupport = 1 << 16,
		kNoSim = 1 << 17,
		kFarAway = 1 << 18,
		kOnStilts = 1 << 19,
		kQuickSimulate = 1 << 20,
		kRecordHits = 1 << 21,
		kComputeTiltPreIntegrate = 1 << 22,
		kShouldersUnderWater = 1 << 23,
		kOnStairs = 1 << 24,
		kCanPitch = 1 << 25,
		kCanRoll = 1 << 26,
		kNoCharacterCollisions = 1 << 27,
		kNotPushablePermanent = 1 << 28,
		kPossiblePathObstacle = 1 << 29,
		kShapeRequiresZRot = 1 << 30,
		kSwimAtWaterSurface = (UInt32)1 << 31,
	};


	class bhkCharacterController :
		public NiRefObject,									// 000
		public BSTEventSource<bhkCharacterMoveFinishEvent>	// 010
	{
	public:
		inline static constexpr auto RTTI = RTTI_bhkCharacterController;


		virtual ~bhkCharacterController();	// 00

		// add
		virtual void  GetPositionImpl(hkVector4&, bool a_arg2) const = 0;					  // 02
		virtual void  SetPositionImpl(const hkVector4& a_pos, bool a_arg2, bool a_arg3) = 0;  // 03
		virtual void  GetTransformImpl(hkTransform& a_tranform) const = 0;					  // 04
		virtual void  SetTransformImpl(const hkTransform& a_tranform) = 0;					  // 05
		virtual void  GetLinearVelocityImpl(hkVector4& a_velocity) const = 0;				  // 06
		virtual void  SetLinearVelocityImpl(const hkVector4& a_velocity) = 0;				  // 07
		virtual void  Unk_08(void) = 0;														  // 08
		virtual void  Unk_09(void) = 0;														  // 09
		virtual void  Unk_0A(void) = 0;														  // 0A
		virtual void  Unk_0B(void) = 0;														  // 0B
		virtual void  Unk_0C(void) = 0;														  // 0C
		virtual void  CheckSupportImpl() = 0;												  // 0D
		virtual void  Unk_0E(void) = 0;														  // 0E
		virtual void  Unk_0F(void) = 0;														  // 0F
		virtual void  Unk_10(void) = 0;														  // 10
		virtual float GetVDBAlpha() const = 0;												  // 11
		virtual void  Unk_12(void) = 0;														  // 12
		virtual void  Unk_13(void) = 0;														  // 13


		// members
		//UInt64						pad068;						// 068
		hkVector4					   forwardVec;				   // 070
		hkStepInfo					   stepInfo;				   // 080
		hkVector4					   outVelocity;				   // 090
		hkVector4					   initialVelocity;			   // 0A0
		hkVector4					   velocityMod;				   // 0B0
		hkVector4					   direction;				   // 0C0
		hkVector4					   rotCenter;				   // 0D0
		hkVector4					   pushDelta;				   // 0E0
		hkVector4					   fakeSupportStart;		   // 0F0
		hkVector4					   up;						   // 100
		hkVector4					   supportNorm;				   // 110
		BSBound						   collisionBound;			   // 120
		BSBound						   bumperCollisionBound;	   // 150
		UInt64						   unk180;					   // 180
		UInt64						   unk188;					   // 188
		bhkICharOrientationController* orientationCtrl;			   // 190
		UInt64						   pad198;					   // 198
		hkpSurfaceInfo				   surfaceInfo;				   // 1A0
		hkpCharacterContext			   context;					   // 1E0
		CHARACTER_FLAGS				   flags;					   // 218
		hkpCharacterStateType		   wantState;				   // 218
		float						   velocityTime;			   // 220
		float						   rotMod;					   // 224
		float						   rotModTime;				   // 228
		float						   calculatePitchTimer;		   // 22C
		float						   acrobatics;				   // 230
		float						   center;					   // 234
		float						   waterHeight;				   // 238
		float						   jumpHeight;				   // 23C
		float						   fallStartHeight;			   // 240
		float						   fallTime;				   // 244
		float						   gravity;					   // 248
		float						   pitchAngle;				   // 24C
		float						   rollAngle;				   // 250
		float						   pitchMult;				   // 254
		float						   scale;					   // 258
		float						   swimFloatHeight;			   // 25C
		float						   actorHeight;				   // 260
		float						   speedPct;				   // 264
		UInt32						   pushCount;				   // 268
		UInt32						   unk26C;					   // 26C
		UInt64						   unk270;					   // 270
		UInt64						   unk278;					   // 278
		NiPointer<bhkShape>			   shapes[2];				   // 280
		UInt64						   unk290;					   // 290
		UInt64						   unk298;					   // 298
		UInt64						   unk2A0;					   // 2A0
		UInt64						   unk2A8;					   // 2A8
		hkRefPtr<hkpRigidBody>		   supportBody;				   // 2B0
		float						   bumpedForce;				   // 2B8
		UInt32						   pad2BC;					   // 2BC
		hkRefPtr<hkpRigidBody>		   bumpedBody;				   // 2C0
		hkRefPtr<hkpRigidBody>		   bumpedCharCollisionObject;  // 2C8
		BSTHashMap<UnkKey, UnkValue>   unk2D0;					   // 2D0
		UInt64						   unk300;					   // 300
		UInt64						   unk308;					   // 308
		UInt64						   unk310;					   // 310
		UInt64						   unk318;					   // 318
		UInt64						   unk320;					   // 320
		UInt64						   unk328;					   // 328
	};
	STATIC_ASSERT(sizeof(bhkCharacterController) == 0x330);
}
