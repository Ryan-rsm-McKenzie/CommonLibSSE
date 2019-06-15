#pragma once

#include "skse64/GameRTTI.h"  // RTTI_hkpCharacterContext

#include "RE/hkReferencedObject.h"  // hkReferencedObject
#include "RE/hkStepInfo.h"  // hkStepInfo
#include "RE/hkVector4.h"  // hkVector4
#include "RE/hkpCharacterControl.h"  // hkpSurfaceInfo
#include "RE/hkpCharacterState.h"  // hkpCharacterStateType


namespace RE
{
	class hkpCharacterStateManager;


	struct hkpCharacterInput
	{
		float			inputLR;			// 00
		float			inputUD;			// 04
		bool			wantJump;			// 08
		UInt8			pad09;				// 09
		UInt16			pad0A;				// 0A
		UInt32			pad0C;				// 0C
		hkVector4		up;					// 10
		hkVector4		forward;			// 20
		bool			atLadder;			// 30
		hkpSurfaceInfo	surfaceInfo;		// 40
		hkStepInfo		stepInfo;			// 80
		hkVector4		position;			// 90
		hkVector4		velocity;			// A0
		hkVector4		characterGravity;	// B0
		UInt64			userData;			// C0
		UInt64			padC8;				// C8
	};
	STATIC_ASSERT(sizeof(hkpCharacterInput) == 0xD0);


	struct hkpCharacterOutput
	{
		hkVector4 velocity;	// 00
	};
	STATIC_ASSERT(sizeof(hkpCharacterOutput) == 0x10);


	class hkpCharacterContext : public hkReferencedObject
	{
	public:
		inline static const void* RTTI = RTTI_hkpCharacterContext;


		enum class CharacterType : UInt32
		{
			kProxy = 0,
			kRigidBody = 1
		};


		virtual ~hkpCharacterContext();	// 00


		CharacterType					characterType;			// 10
		UInt32							pad14;					// 14
		const hkpCharacterStateManager*	stateManager;			// 18
		hkpCharacterStateType			currentState;			// 20
		hkpCharacterStateType			previousState;			// 24
		bool							filterEnable;			// 28
		UInt8							pad29;					// 29
		UInt16							pad2A;					// 2A
		float							maxLinearAcceleration;	// 2C
		float							maxLinearVelocity;		// 30
		float							gain;					// 34
	};
	STATIC_ASSERT(sizeof(hkpCharacterContext) == 0x38);
}
