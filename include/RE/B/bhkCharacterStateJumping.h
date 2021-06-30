#pragma once

#include "RE/B/bhkCharacterState.h"

namespace RE
{
	class bhkCharacterStateJumping : public bhkCharacterState
	{
	public:
		inline static constexpr auto RTTI = RTTI_bhkCharacterStateJumping;

		~bhkCharacterStateJumping() override;  // 00

		// override (bhkCharacterState)
		hkpCharacterStateType GetType() const override;  // 03 - { return kJumping; }
		void                  Unk_08(void) override;     // 08
	};
	static_assert(sizeof(bhkCharacterStateJumping) == 0x10);
}
