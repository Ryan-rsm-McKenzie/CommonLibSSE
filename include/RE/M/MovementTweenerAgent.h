#pragma once

#include "RE/M/MovementAgent.h"
#include "RE/I/IMovementTweenerAgent.h"

namespace RE
{
	class MovementTweenerAgent : MovementAgent, IMovementTweenerAgent
	{
	public:
		inline static constexpr auto RTTI = RTTI_MovementTweenerAgent;

		~MovementTweenerAgent() override;
	};
	static_assert(sizeof(MovementTweenerAgent) == 0x20);
}
