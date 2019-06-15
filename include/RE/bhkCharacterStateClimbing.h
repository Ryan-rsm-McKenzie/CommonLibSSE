#pragma once

#include "skse64/GameRTTI.h"  // RTTI_bhkCharacterStateClimbing

#include "RE/bhkCharacterState.h"  // bhkCharacterState


namespace RE
{
	class bhkCharacterStateClimbing : public bhkCharacterState
	{
	public:
		inline static const void* RTTI = RTTI_bhkCharacterStateClimbing;


		virtual ~bhkCharacterStateClimbing();						// 00

		// override (bhkCharacterState)
		virtual hkpCharacterStateType	GetType() const override;	// 03 - { return kClimbing; }
		virtual void					Unk_08(void) override;		// 08
	};
	STATIC_ASSERT(sizeof(bhkCharacterStateClimbing) == 0x10);
}
