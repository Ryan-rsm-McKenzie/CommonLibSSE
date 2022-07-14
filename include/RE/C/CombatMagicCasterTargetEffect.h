#pragma once

#include "RE/C/CombatMagicCaster.h"

namespace RE
{
	class CombatMagicCasterTargetEffect : public CombatMagicCaster
	{
	public:
		inline static constexpr auto RTTI = RTTI_CombatMagicCasterTargetEffect;

		~CombatMagicCasterTargetEffect() override;  // 00

		// override (CombatMagicCaster)
		void SaveGame(BGSSaveGameBuffer* a_buf) override;  // 03
		void LoadGame(BGSLoadGameBuffer* a_buf) override;  // 04
		void Unk_05() override;                            // 05
		void Unk_06() override;                            // 06
		void Unk_07() override;                            // 07
		void Unk_08() override;                            // 08
		void Unk_09() override;                            // 09
		void Unk_0A() override;                            // 0A
	};
	static_assert(sizeof(CombatMagicCasterTargetEffect) == 0x20);
}
