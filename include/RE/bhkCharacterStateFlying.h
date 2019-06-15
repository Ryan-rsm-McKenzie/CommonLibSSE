#pragma once

#include "skse64/GameRTTI.h"  // RTTI_bhkCharacterStateFlying

#include "RE/bhkCharacterState.h"  // bhkCharacterState


namespace RE
{
	class bhkCharacterStateFlying : public bhkCharacterState
	{
	public:
		inline static const void* RTTI = RTTI_bhkCharacterStateFlying;


		virtual ~bhkCharacterStateFlying();							// 00

		// override (bhkCharacterState)
		virtual hkpCharacterStateType	GetType() const override;	// 03 - { return kFlying; }
		virtual void					Unk_08(void) override;		// 08
	};
	STATIC_ASSERT(sizeof(bhkCharacterStateFlying) == 0x10);
}
