#pragma once

#include "RE/A/AITimeStamp.h"
#include "RE/A/ActorValues.h"
#include "RE/C/CombatMagicCaster.h"

namespace RE
{
	class CombatMagicCasterRestore : public CombatMagicCaster
	{
	public:
		inline static constexpr auto RTTI = RTTI_CombatMagicCasterRestore;

		~CombatMagicCasterRestore() override;  // 00

		// override (CombatMagicCaster)
		std::uint32_t Unk_02() override;                            // 02
		void          SaveGame(BGSSaveGameBuffer* a_buf) override;  // 03
		void          LoadGame(BGSLoadGameBuffer* a_buf) override;  // 04
		void          Unk_05() override;                            // 05
		void          Unk_06() override;                            // 06
		void          Unk_07() override;                            // 07
		void          Unk_0B() override;                            // 0B
		void          Unk_0C() override;                            // 0C

		// members
		AITimeStamp   concentrationCastTimeStamp;  // 20
		std::uint32_t unk24;                       // 24
		ActorValue    primaryAV;                   // 28
	};
	static_assert(sizeof(CombatMagicCasterRestore) == 0x30);
}
