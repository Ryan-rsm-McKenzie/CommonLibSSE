#pragma once

#include "RE/M/MovementArbiter.h"
#include "RE/I/IMovementSetTweener.h"
#include "RE/I/IMovementQueryTweener.h"

namespace RE
{
	class IMovementControllerDataTracker;

	class MovementTweenerArbiter :
		public MovementArbiter,       // 000
		public IMovementSetTweener,   // 018
		public IMovementQueryTweener  // 020
	{
	public:
		inline static constexpr auto RTTI = RTTI_MovementTweenerArbiter;

		~MovementTweenerArbiter() override;  // 00

		// override (MovementArbiter)
		void Unk_01(void) override;  // 01
		void Unk_02(void) override;  // 02
		void Unk_03(void) override;  // 03
		void Unk_04(void) override;  // 04
		void Unk_06(void) override;  // 06
		void Unk_07(void) override;  // 07
		void Unk_08(void) override;  // 08
		void Unk_09(void) override;  // 09 - { return; }
		void Unk_0C(void) override;  // 0C
		void Unk_0D(void) override;  // 0D
		void Unk_0E(void) override;  // 0E
		void Unk_0F(void) override;  // 0F
		void Unk_10(void) override;  // 10
		void Unk_11(void) override;  // 11

		// override (IMovementSetTweener)
		//void Unk_01(void) override;  // 01
		//void Unk_02(void) override;  // 02
		//void Unk_03(void) override;  // 03

		// override (IMovementQueryTweener)
		//void Unk_01(void) override;  // 01
		//void Unk_02(void) override;  // 02
		//void Unk_03(void) override;  // 03

		// members
		NiTransform                     niTransform028;                 // 028
		NiTransform                     niTransform05C;                 // 05C
		NiTransform                     niTransform090;                 // 090
		std::uint32_t                   pad0C4;                         // 0C4
		std::uint64_t                   unk0C8;                         // 0C8
		std::uint64_t                   unk0D0;                         // 0D0
		std::uint64_t                   unk0D8;                         // 0D8
		std::uint64_t                   unk0E0;                         // 0E0
		std::uint64_t                   unk0E8;                         // 0E8
		std::uint64_t                   unk0F0;                         // 0F0
		std::uint64_t                   unk0F8;                         // 0F8
		std::uint64_t                   unk100;                         // 100
		std::uint64_t                   unk108;                         // 108
		std::uint64_t                   unk110;                         // 110
		std::uint64_t                   unk118;                         // 118
		std::uint64_t                   unk120;                         // 120
		std::uint64_t                   unk128;                         // 128
		std::uint64_t                   unk130;                         // 130
		std::uint64_t                   unk138;                         // 138
		std::uint64_t                   unk140;                         // 140
		std::uint64_t                   unk148;                         // 148
		std::uint64_t                   unk150;                         // 150
		std::uint64_t                   unk158;                         // 158
		std::uint64_t                   unk160;                         // 160
		std::uint64_t                   unk168;                         // 168
		std::uint64_t                   unk170;                         // 170
		MovementControllerNPC*          movementControllerNPC;          // 178
		IMovementControllerDataTracker* movementControllerDataTracker;  // 180
	};
	static_assert(sizeof(MovementTweenerArbiter) == 0x188);
}
