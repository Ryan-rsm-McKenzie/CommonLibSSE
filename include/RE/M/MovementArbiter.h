#pragma once

#include "RE/B/BSIntrusiveRefCounted.h"

namespace RE
{
	class MovementArbiter : public BSIntrusiveRefCounted
	{
	public:
		inline static constexpr auto RTTI = RTTI_MovementArbiter;

		virtual ~MovementArbiter();  // 00

		// add
		virtual void Unk_01(void) = 0;  // 01
		virtual void Unk_02(void) = 0;  // 02
		virtual void Unk_03(void) = 0;  // 03
		virtual void Unk_04(void);      // 04 - { return; }
		virtual void Unk_05(void);      // 05
		virtual void Unk_06(void);      // 06 - { return; }
		virtual void Unk_07(void);      // 07 - { return; }
		virtual void Unk_08(void) = 0;  // 08
		virtual void Unk_09(void) = 0;  // 09
		virtual void Unk_0A(void);      // 0A - { return; }
		virtual void Unk_0B(void);      // 0B - { return; }
		virtual void Unk_0C(void);      // 0C - { return; }
		virtual void Unk_0D(void);      // 0D - { return; }
		virtual void Unk_0E(void);      // 0E - { return; }
		virtual void Unk_0F(void);      // 0F
		virtual void Unk_10(void);      // 10
		virtual void Unk_11(void);      // 11 - { return; }

		// members
		std::uint32_t pad0C;       // 0C
		ActorState*   actorState;  // 10
	};
	static_assert(sizeof(MovementArbiter) == 0x18);
}
