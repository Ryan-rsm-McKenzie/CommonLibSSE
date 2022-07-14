#pragma once

#include "RE/C/CommandEffect.h"

namespace RE
{
	class ReanimateEffect : public CommandEffect
	{
	public:
		inline static constexpr auto RTTI = RTTI_ReanimateEffect;
		inline static constexpr auto VTABLE = VTABLE_ReanimateEffect;

		// override (CommandEffect)
		void Unk_04(void) override;                        // 04
		void LoadGame(BGSSaveFormBuffer* a_buf) override;  // 08
		void SaveGame(BGSLoadFormBuffer* a_buf) override;  // 09
		void Unk_10(void) override;                        // 0A
		void Unk_12(void) override;                        // 12

		~ReanimateEffect() override;  // 13

		void Start() override;   // 14
		void Finish() override;  // 15

		// members
		bool          unk98;  // 98
		std::uint8_t  pad99;  // 99
		std::uint16_t pad9A;  // 9A
		std::uint32_t pad9C;  // 9C
	};
	static_assert(sizeof(ReanimateEffect) == 0xA0);
}
