#pragma once

#include "skse64/GameRTTI.h"  // RTTI_hkpCharacterState

#include "RE/hkReferencedObject.h"  // hkReferencedObject


namespace RE
{
	class hkpCharacterContext;
	struct hkpCharacterInput;
	struct hkpCharacterOutput;


	struct hkpCharacterStateTypes
	{
		enum hkpCharacterStateType : UInt32
		{
			kOnGround = 0,
			kJumping,
			kInAir,
			kClimbing,
			kFlying,

			kUserState0,
			kSwimming = kUserState0,

			kUserState1,
			kUserState2,
			kUserState3,
			kUserState4,
			kUserState5,

			kTotal
		};
	};
	using hkpCharacterStateType = hkpCharacterStateTypes::hkpCharacterStateType;


	class hkpCharacterState : public hkReferencedObject
	{
	public:
		inline static const void* RTTI = RTTI_hkpCharacterState;


		virtual ~hkpCharacterState();																																					// 00

		virtual hkpCharacterStateType	GetType() const = 0;																															// 03
		virtual void					EnterState(hkpCharacterContext& a_context, hkpCharacterStateType a_prevState, const hkpCharacterInput& a_input, hkpCharacterOutput& a_output);	// 04 - { return; }
		virtual void					LeaveState(hkpCharacterContext& a_context, hkpCharacterStateType a_nextState, const hkpCharacterInput& a_input, hkpCharacterOutput& a_output);	// 05 - { return; }
		virtual void					Update(hkpCharacterContext& a_context, const hkpCharacterInput& a_input, hkpCharacterOutput& a_output) = 0;										// 06
		virtual void					Change(hkpCharacterContext& a_context, const hkpCharacterInput& a_input, hkpCharacterOutput& a_output) = 0;										// 07
	};
	STATIC_ASSERT(sizeof(hkpCharacterState) == 0x10);
}
