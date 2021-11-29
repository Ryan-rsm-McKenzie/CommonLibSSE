#pragma once

#include "RE/B/bhkCharacterState.h"

namespace RE
{
	class bhkCharacterStateSwimming : public bhkCharacterState
	{
	public:
		inline static constexpr auto RTTI = RTTI_bhkCharacterStateSwimming;

		~bhkCharacterStateSwimming() override;  // 00

		// override (bhkCharacterState)
		hkpCharacterStateType GetType() const override;  // 03 - { return kSwimming; }
		void                  Unk_08(void) override;     // 08
	};
	static_assert(sizeof(bhkCharacterStateSwimming) == 0x10);
}
