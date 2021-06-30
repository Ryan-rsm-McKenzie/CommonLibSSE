#pragma once

#include "RE/B/bhkCharacterState.h"

namespace RE
{
	class bhkCharacterStateOnGround : public bhkCharacterState
	{
	public:
		inline static constexpr auto RTTI = RTTI_bhkCharacterStateOnGround;

		~bhkCharacterStateOnGround() override;  // 00

		// override (bhkCharacterState)
		hkpCharacterStateType GetType() const override;  // 03 - { return kOnGround; }
		void                  Unk_08(void) override;     // 08

		// members
		std::uint64_t unk10;  // 10
	};
	static_assert(sizeof(bhkCharacterStateOnGround) == 0x18);
}
