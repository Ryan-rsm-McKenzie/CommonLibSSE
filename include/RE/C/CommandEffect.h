#pragma once

#include "RE/A/ActiveEffect.h"

namespace RE
{
	class CommandEffect : public ActiveEffect
	{
	public:
		inline static constexpr auto RTTI = RTTI_CommandEffect;
		inline static constexpr auto VTABLE = VTABLE_CommandEffect;

		// override (ActiveEffect)
		virtual void           Unk_01(void) override;                        // 01
		virtual TESObjectREFR* GetVisualsTarget() override;                  // 03
		virtual void           Unk_04(void) override;                        // 04
		virtual void           Unk_05(void) override;                        // 05
		virtual void           Unk_06(void) override;                        // 06
		virtual void           LoadGame(BGSSaveFormBuffer* a_buf) override;  // 08
		virtual void           SaveGame(BGSLoadFormBuffer* a_buf) override;  // 09
		virtual void           Unk_0A(void) override;                        // 0A
		virtual void           Unk_12(void) override;                        // 12

		virtual ~CommandEffect();  // 13

		virtual void Unk_14() override;  // 14
		virtual void Unk_15() override;  // 15

		// members
		ActorHandle   commandedActor;  // 90
		std::uint32_t pad94;           // 94
	};
	static_assert(sizeof(CommandEffect) == 0x98);
}
