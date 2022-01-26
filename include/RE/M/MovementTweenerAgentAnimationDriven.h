#pragma once

#include "RE/M/MovementTweenerAgent.h"

namespace RE
{
	class MovementTweenerAgentAnimationDriven : MovementTweenerAgent
	{
	public:
		inline static constexpr auto RTTI = RTTI_MovementTweenerAgentAnimationDriven;

		~MovementTweenerAgentAnimationDriven() override; // 00

		// add

		// members
		std::uint64_t unk20;  // 20
		std::uint64_t unk28;  // 28
		std::uint64_t unk30;  // 30
	};
	static_assert(sizeof(MovementTweenerAgentAnimationDriven) == 0x38);
}
