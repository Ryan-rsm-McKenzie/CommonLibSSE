#pragma once

#include "RE/B/bhkCharacterState.h"

namespace RE
{
	class bhkCharacterStateInAir : public bhkCharacterState
	{
	public:
		inline static constexpr auto RTTI = RTTI_bhkCharacterStateInAir;

		~bhkCharacterStateInAir() override;  // 00

		// override (bhkCharacterState)
		hkpCharacterStateType GetType() const override;  // 03 - { return kInAir; }
		void                  Unk_08(void) override;     // 08

		// members
		std::uint64_t unk10;  // 10
	};
	static_assert(sizeof(bhkCharacterStateInAir) == 0x18);
}
