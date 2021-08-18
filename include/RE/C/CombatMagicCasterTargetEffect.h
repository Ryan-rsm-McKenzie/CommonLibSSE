#pragma once

#include "RE/C/CombatMagicCaster.h"

namespace RE
{
	class CombatMagicCasterTargetEffect : public CombatMagicCaster
	{
	public:
		inline static constexpr auto RTTI = RTTI_CombatMagicCasterTargetEffect;

		virtual ~CombatMagicCasterTargetEffect();  // 00

		// override
		virtual void SaveGame(BGSSaveGameBuffer* a_buf) override;  // 03
		virtual void LoadGame(BGSLoadGameBuffer* a_buf) override;  // 04
		virtual void Unk_05() override;                            // 05
		virtual void Unk_06() override;                            // 06
		virtual void Unk_07() override;                            // 07
		virtual void Unk_08() override;                            // 08
		virtual void Unk_09() override;                            // 09
		virtual void Unk_0A() override;                            // 0A
	};
	static_assert(sizeof(CombatMagicCasterTargetEffect) == 0x20);
}
