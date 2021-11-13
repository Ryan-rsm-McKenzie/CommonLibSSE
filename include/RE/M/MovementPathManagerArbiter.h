#pragma once

#include "RE/M/MovementArbiter.h"
#include "RE/I/IMovementSetGoal.h"
#include "RE/I/IMovementQueryPathingState.h"

namespace RE
{
	class MovementPathManagerArbiter : 
		public MovementArbiter,            // 00
		public IMovementSetGoal,           // 18
		public IMovementQueryPathingState  // 20
	{
	public:
		inline static constexpr auto RTTI = RTTI_MovementPathManagerArbiter;

		~MovementPathManagerArbiter() override;  // 00

		// override (MovementArbiter)
		void Unk_01(void) override;  // 01
		void Unk_02(void) override;  // 02
		void Unk_03(void) override;  // 03
		void Unk_04(void) override;  // 04
		void Unk_06(void) override;  // 06
		void Unk_08(void) override;  // 08
		void Unk_09(void) override;  // 09
		void Unk_0C(void) override;  // 0C
		void Unk_0D(void) override;  // 0D
		void Unk_0E(void) override;  // 0E
		void Unk_0F(void) override;  // 0F
		void Unk_10(void) override;  // 10
		void Unk_11(void) override;  // 11

		// override (IMovementSetGoal)
		//void Unk_01(void) override;  // 01
		//void Unk_02(void) override;  // 02
		//void Unk_03(void) override;  // 03
		//void Unk_04(void) override;  // 04

		// override (IMovementQueryPathingState)
		//void Unk_01(void) override;  // 01
		//void Unk_02(void) override;  // 02
		//void Unk_03(void) override;  // 03
		//void Unk_04(void) override;  // 04
		//void Unk_05(void) override;  // 05
		//void Unk_06(void) override;  // 06
		//void Unk_07(void) override;  // 07
		//void Unk_08(void) override;  // 08
		//void Unk_09(void) override;  // 09
		//void Unk_0C(void) override;  // 0C
		//void Unk_0D(void) override;  // 0D

		// members
		std::uint64_t unk028;  // 028
		std::uint64_t unk030;  // 030
		std::uint64_t unk038;  // 038
		std::uint64_t unk040;  // 040
		std::uint64_t unk048;  // 048
		std::uint64_t unk050;  // 050
		std::uint64_t unk058;  // 058
		std::uint64_t unk060;  // 060
		std::uint64_t unk068;  // 068
		std::uint64_t unk070;  // 070
		std::uint64_t unk078;  // 078
	};
	static_assert(sizeof(MovementPathManagerArbiter) == 0x80);
}
