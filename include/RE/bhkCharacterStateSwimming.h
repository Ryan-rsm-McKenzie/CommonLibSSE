#pragma once

#include "skse64/GameRTTI.h"  // RTTI_bhkCharacterStateSwimming

#include "RE/bhkCharacterState.h"  // bhkCharacterState


namespace RE
{
	class bhkCharacterStateSwimming : public bhkCharacterState
	{
	public:
		inline static const void* RTTI = RTTI_bhkCharacterStateSwimming;


		virtual ~bhkCharacterStateSwimming();						// 00

		// override (bhkCharacterState)
		virtual hkpCharacterStateType	GetType() const override;	// 03 - { return kSwimming; }
		virtual void					Unk_08(void) override;		// 08
	};
	STATIC_ASSERT(sizeof(bhkCharacterStateSwimming) == 0x10);
}
