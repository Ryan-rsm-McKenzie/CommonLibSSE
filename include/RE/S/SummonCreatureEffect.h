#pragma once

#include "RE/A/ActiveEffect.h"

namespace RE
{
	class SummonCreatureEffect : public ActiveEffect
	{
	public:
		inline static constexpr auto RTTI = RTTI_SummonCreatureEffect;

		// override (ActiveEffect)
		void Unk_04() override;  // 04
		void Unk_07() override;  // 07
		void Unk_08() override;  // 08
		void Unk_09() override;  // 09
		void Unk_0A() override;  // 0A
		void Unk_0D() override;  // 0D
		void Unk_12() override;  // 12

		~SummonCreatureEffect() override;  // 13

		void Unk_14() override;  // 14
		void Unk_15() override;  // 15

		// members
		std::uint64_t unk90;  // 90
		std::uint64_t unk98;  // 98
		std::uint64_t unkA0;  // A0
		std::uint64_t unkA8;  // A8
		std::uint64_t unkB0;  // B0
		std::uint64_t unkB8;  // B8
	};
	static_assert(sizeof(SummonCreatureEffect) == 0xC0);
}
