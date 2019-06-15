#pragma once

#include "skse64/GameRTTI.h"  // RTTI_bhkCharacterStateJumping

#include "RE/bhkCharacterState.h"  // bhkCharacterState


namespace RE
{
	class bhkCharacterStateJumping : public bhkCharacterState
	{
	public:
		inline static const void* RTTI = RTTI_bhkCharacterStateJumping;


		virtual ~bhkCharacterStateJumping();						// 00

		// override (bhkCharacterState)
		virtual hkpCharacterStateType	GetType() const override;	// 03 - { return kJumping; }
		virtual void					Unk_08(void) override;		// 08
	};
	STATIC_ASSERT(sizeof(bhkCharacterStateJumping) == 0x10);
}
