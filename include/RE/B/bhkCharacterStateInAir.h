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
		hkpCharacterStateType GetType() const override;                                                    // 03 - { return kInAir; }
		void                  SimulateStatePhysics(bhkCharacterController* characterController) override;  // 08

		// members
		float         maxVelocityDelta;  // 10
		std::uint32_t pad14;             // 14
	};
	static_assert(sizeof(bhkCharacterStateInAir) == 0x18);
}
