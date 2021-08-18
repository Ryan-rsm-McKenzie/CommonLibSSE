#pragma once

#include "RE/A/AITimer.h"
#include "RE/C/CombatMagicCaster.h"

namespace RE
{
	class CombatMagicCasterOffensive : public CombatMagicCaster
	{
	public:
		inline static constexpr auto RTTI = RTTI_CombatMagicCasterOffensive;

		~CombatMagicCasterOffensive() override;  // 00

		// override (CombatMagicCaster)
		std::uint32_t Unk_02() override;                            // 02
		void          SaveGame(BGSSaveGameBuffer* a_buf) override;  // 03
		void          LoadGame(BGSLoadGameBuffer* a_buf) override;  // 04
		void          Unk_05() override;                            // 05
		void          Unk_06() override;                            // 06
		void          Unk_07() override;                            // 07
		void          Unk_08() override;                            // 08
		void          Unk_09() override;                            // 09
		void          Unk_0B() override;                            // 0B
		void          Unk_0C() override;                            // 0C

		// members
		AITimer unk20;  // 20
		AITimer unk28;  // 28
	};
	static_assert(sizeof(CombatMagicCasterOffensive) == 0x30);
}
