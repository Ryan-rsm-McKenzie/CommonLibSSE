#pragma once

#include "RE/M/MovementArbiter.h"
#include "RE/I/IMovementQueryDeltas.h"

namespace RE
{
	class MovementPostUpdateArbiter : 
		public MovementArbiter,      // 00
		public IMovementQueryDeltas  // 18
	{
	public:
		inline static constexpr auto RTTI = RTTI_MovementPostUpdateArbiter;

		~MovementPostUpdateArbiter() override;  // 00

		// override (MovementArbiter)
		void Unk_01(void) override;  // 01
		void Unk_02(void) override;  // 02
		void Unk_03(void) override;  // 03
		void Unk_04(void) override;  // 04
		void Unk_07(void) override;  // 07
		void Unk_08(void) override;  // 08
		void Unk_09(void) override;  // 09
		void Unk_0C(void) override;  // 0C
		void Unk_0D(void) override;  // 0D
		void Unk_0E(void) override;  // 0E

		// override (IMovementQueryDeltas)
		//void Unk_01(void) override;  // 01
		//void Unk_02(void) override;  // 02
		//void Unk_03(void) override;  // 03
		//void Unk_04(void) override;  // 04

		// members
		std::uint64_t unk020;  // 020
		std::uint64_t unk028;  // 028
		std::uint64_t unk030;  // 030
		std::uint64_t unk038;  // 038
		std::uint64_t unk040;  // 040
		std::uint64_t unk048;  // 048
		std::uint64_t unk050;  // 050
		std::uint64_t unk058;  // 058
	};
	static_assert(sizeof(MovementPostUpdateArbiter) == 0x60);
}
