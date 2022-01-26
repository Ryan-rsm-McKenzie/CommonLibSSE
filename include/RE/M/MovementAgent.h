#pragma once

#include "RE/B/BSIntrusiveRefCounted.h"

namespace RE
{
	class MovementAgent : public BSIntrusiveRefCounted
	{
	public:
		inline static constexpr auto RTTI = RTTI_MovementAgent;

		virtual ~MovementAgent();  // 00

		// add
		virtual void Unk01(void);  // 01
		virtual void Unk02(void);  // 02
		virtual void Unk03(void);  // 03
		virtual void Unk04(void);  // 04
		virtual void Unk05(void);  // 05

		// members
		MovementControllerNPC* movementControllerNPC;  // 10
	};
	static_assert(sizeof(MovementAgent) == 0x18);
}
