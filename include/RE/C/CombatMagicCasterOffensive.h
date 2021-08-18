#pragma once

#include "RE/A/AITimer.h"
#include "RE/C/CombatMagicCaster.h"

namespace RE
{
	class CombatMagicCasterOffensive : public CombatMagicCaster
	{
	public:
		inline static constexpr auto RTTI = RTTI_CombatMagicCasterOffensive;

		virtual ~CombatMagicCasterOffensive();  // 00

		// override
		virtual std::uint32_t Unk_02() override;                            // 02
		virtual void          SaveGame(BGSSaveGameBuffer* a_buf) override;  // 03
		virtual void          LoadGame(BGSLoadGameBuffer* a_buf) override;  // 04
		virtual void          Unk_05() = 0;                                 // 05
		virtual void          Unk_06();                                     // 06
		virtual void          Unk_07();                                     // 07
		virtual void          Unk_08();                                     // 08
		virtual void          Unk_09();                                     // 09
		virtual void          Unk_0A();                                     // 0A
		virtual void          Unk_0B();                                     // 0B
		virtual void          Unk_0C();                                     // 0C
		virtual void          Unk_0D();                                     // 0D

		// members
		AITimer unk20;  // 20
		AITimer unk28;  // 28
	};
	static_assert(sizeof(CombatMagicCasterOffensive) == 0x30);
}
