#pragma once

#include "RE/A/ActiveEffect.h"

namespace RE
{
	class SummonCreatureEffect : public ActiveEffect
	{
	public:
		inline static constexpr auto RTTI = RTTI_SummonCreatureEffect;

		// override (ActiveEffect)
		void Unk_04(void) override;                        // 04
		void Unk_07(void) override;                        // 07
		void LoadGame(BGSSaveFormBuffer* a_buf) override;  // 08
		void SaveGame(BGSLoadFormBuffer* a_buf) override;  // 09
		void Unk_0A(void) override;                        // 0A
		void Unk_0D(void) override;                        // 0D
		void Unk_12(void) override;                        // 12

		~SummonCreatureEffect() override;  // 13

		void Start() override;   // 14
		void Finish() override;  // 15

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
