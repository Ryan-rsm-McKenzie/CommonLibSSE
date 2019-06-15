#pragma once

#include "skse64/GameRTTI.h"  // RTTI_bhkCharacterStateOnGround

#include "RE/bhkCharacterState.h"  // bhkCharacterState


namespace RE
{
	class bhkCharacterStateOnGround : public bhkCharacterState
	{
	public:
		inline static const void* RTTI = RTTI_bhkCharacterStateOnGround;


		virtual ~bhkCharacterStateOnGround();						// 00

		// override (bhkCharacterState)
		virtual hkpCharacterStateType	GetType() const override;	// 03 - { return kOnGround; }
		virtual void					Unk_08(void) override;		// 08


		// members
		UInt64 unk10;	// 10
	};
	STATIC_ASSERT(sizeof(bhkCharacterStateOnGround) == 0x18);
}
