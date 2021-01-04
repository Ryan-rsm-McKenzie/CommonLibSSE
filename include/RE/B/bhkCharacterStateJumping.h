#pragma once

#include "RE/B/bhkCharacterState.h"

namespace RE
{
	class bhkCharacterStateJumping : public bhkCharacterState
	{
	public:
		inline static constexpr auto RTTI = RTTI_bhkCharacterStateJumping;

		virtual ~bhkCharacterStateJumping();  // 00

		// override (bhkCharacterState)
		virtual hkpCharacterStateType GetType() const override;	 // 03 - { return kJumping; }
		virtual void				  Unk_08(void) override;	 // 08
	};
	static_assert(sizeof(bhkCharacterStateJumping) == 0x10);
}
