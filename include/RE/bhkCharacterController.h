#pragma once

#include "RE/BSBound.h"
#include "RE/BSTEvent.h"
#include "RE/BSTHashMap.h"
#include "RE/hkpCharacterContext.h"
#include "RE/hkpCharacterControl.h"
#include "RE/hkpCharacterState.h"
#include "RE/hkRefPtr.h"
#include "RE/hkStepInfo.h"
#include "RE/hkVector4.h"
#include "RE/NiPoint3.h"
#include "RE/NiRefObject.h"
#include "RE/NiSmartPointer.h"


namespace RE
{
	class bhkCharacterMoveFinishEvent;
	class bhkICharOrientationController;
	class bhkShape;
	class hkpEntity;
	class hkVector4;


	class bhkCharacterController :
		public NiRefObject,									// 000
		public BSTEventSource<bhkCharacterMoveFinishEvent>	// 010
	{
	public:
		inline static const void* RTTI = RTTI_bhkCharacterController;


		virtual ~bhkCharacterController();									// 00

		// add
		virtual void		Unk_02(void) = 0;								// 02
		virtual void		Unk_03(void) = 0;								// 03
		virtual void		Unk_04(void) = 0;								// 04
		virtual void		Unk_05(void) = 0;								// 05
		virtual hkVector4	GetLinearVelocity() const = 0;					// 06
		virtual void		SetLinearVelocity(const hkVector4& a_vel) = 0;	// 07
		virtual void		Unk_08(void) = 0;								// 08
		virtual void		Unk_09(void) = 0;								// 09
		virtual void		Unk_0A(void) = 0;								// 0A
		virtual void		Unk_0B(void) = 0;								// 0B
		virtual void		Unk_0C(void) = 0;								// 0C
		virtual void		Unk_0D(void) = 0;								// 0D
		virtual void		Unk_0E(void) = 0;								// 0E
		virtual void		Unk_0F(void) = 0;								// 0F
		virtual void		Unk_10(void) = 0;								// 10
		virtual void		Unk_11(void) = 0;								// 11
		virtual void		Unk_12(void) = 0;								// 12
		virtual void		Unk_13(void) = 0;								// 13


		// members
		//UInt64						pad068;					// 068
		hkVector4						forwardVec;				// 070
		hkStepInfo						stepInfo;				// 080
		hkVector4						outVelocity;			// 090
		hkVector4						initialVelocity;		// 0A0
		hkVector4						velocityMod;			// 0B0
		hkVector4						direction;				// 0C0
		hkVector4						rotCenter;				// 0D0
		hkVector4						pushDelta;				// 0E0
		hkVector4						fakeSupportStart;		// 0F0
		hkVector4						up;						// 100
		hkVector4						supportNorm;			// 110
		BSBound							collisionBound;			// 120
		BSBound							bumperCollisionBound;	// 150
		UInt64							unk180;					// 180
		UInt64							unk188;					// 188
		bhkICharOrientationController*	orientationCtrl;		// 190
		UInt64							pad198;					// 198
		hkpSurfaceInfo					surfaceInfo;			// 1A0
		hkpCharacterContext				context;				// 1E0
		UInt32							flags;					// 218
		hkpCharacterStateType			wantState;				// 218
		float							velocityTime;			// 220
		float							rotMod;					// 224
		float							rotModTime;				// 228
		float							calculatePitchTimer;	// 22C
		float							acrobatics;				// 230
		float							center;					// 234
		float							waterHeight;			// 238
		float							jumpHeight;				// 23C
		float							fallStartHeight;		// 240
		float							fallTime;				// 244
		float							gravity;				// 248
		float							pitchAngle;				// 24C
		float							rollAngle;				// 250
		float							pitchMult;				// 254
		float							scale;					// 258
		float							swimFloatHeight;		// 25C
		float							actorHeight;			// 260
		float							speedPct;				// 264
		UInt32							pushCount;				// 268
		UInt32							unk26C;					// 26C
		UInt64							unk270;					// 270
		UInt64							unk278;					// 278
		NiPointer<bhkShape>				shapes[2];				// 280
		UInt64							unk290;					// 290
		UInt64							unk298;					// 298
		UInt64							unk2A0;					// 2A0
		UInt64							unk2A8;					// 2A8
		hkRefPtr<hkpEntity>				supportBody;			// 2B0
		UInt64							unk2B8;					// 2B8
		hkRefPtr<hkReferencedObject>	unk2C0;					// 2C0
		hkRefPtr<hkReferencedObject>	unk2C8;					// 2C8
		BSTHashMap<UnkKey, UnkValue>	unk2D0;					// 2D0
		UInt64							unk300;					// 300
		UInt64							unk308;					// 308
		UInt64							unk310;					// 310
		UInt64							unk318;					// 318
		UInt64							unk320;					// 320
		UInt64							unk328;					// 328
	};
	STATIC_ASSERT(sizeof(bhkCharacterController) == 0x330);
}
