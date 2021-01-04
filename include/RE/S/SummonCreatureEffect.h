#pragma once

#include "RE/A/ActiveEffect.h"

namespace RE
{
	class SummonCreatureEffect : public ActiveEffect
	{
	public:
		inline static constexpr auto RTTI = RTTI_SummonCreatureEffect;

		// override (ActiveEffect)
		virtual void Unk_04(void) override;	 // 04
		virtual void Unk_07(void) override;	 // 07
		virtual void Unk_08(void) override;	 // 08
		virtual void Unk_09(void) override;	 // 09
		virtual void Unk_0A(void) override;	 // 0A
		virtual void Unk_0D(void) override;	 // 0D
		virtual void Unk_12(void) override;	 // 12

		virtual ~SummonCreatureEffect();  // 13

		virtual void Unk_14(void) override;	 // 14
		virtual void Unk_15(void) override;	 // 15

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
