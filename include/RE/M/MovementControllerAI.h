#pragma once

#include "RE/B/BSIntrusiveRefCounted.h"
#include "RE/I/IMovementControllerRegisterInterface.h"

namespace RE
{
	class MovementControllerAI :
		public BSIntrusiveRefCounted,                // 008
		public IMovementControllerRegisterInterface  // 000
	{
	public:
		inline static constexpr auto RTTI = RTTI_MovementControllerAI;

		~MovementControllerAI() override;  // 00

		// add
		virtual void Unk_05(void);  // 05
		virtual void Unk_06(void);  // 06 - { return; }
		virtual void Unk_07(void);  // 07
		virtual void Unk_08(void);  // 08
		virtual void Unk_09(void);  // 09 - { return 1; }

		// members
		std::uint32_t unk00C;  // 00C
		std::uint64_t unk010;  // 010
		std::uint64_t unk018;  // 018
		std::uint64_t unk020;  // 020
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
		std::uint64_t unk080;  // 080
		std::uint64_t unk088;  // 088
		std::uint64_t unk090;  // 090
		std::uint64_t unk098;  // 098
		std::uint64_t unk0A0;  // 0A0
		std::uint64_t unk0A8;  // 0A8
		std::uint64_t unk0B0;  // 0B0
		std::uint64_t unk0B8;  // 0B8
		std::uint64_t unk0C0;  // 0C0
		std::uint64_t unk0C8;  // 0C8
		std::uint64_t unk0D0;  // 0D0
		std::uint64_t unk0D8;  // 0D8
		std::uint64_t unk0E0;  // 0E0
		std::uint64_t unk0E8;  // 0E8
		std::uint64_t unk0F0;  // 0F0
		std::uint64_t unk0F8;  // 0F8
		std::uint64_t unk100;  // 100
		std::uint64_t unk108;  // 108
		std::uint64_t unk110;  // 110
		std::uint64_t unk118;  // 118
	};
	static_assert(sizeof(MovementControllerAI) == 0x120);
}
