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
		void           Unk_01(void) override;                        // 01
		TESObjectREFR* GetVisualsTarget() override;                  // 03
		void           Unk_04(void) override;                        // 04
		void           Unk_05(void) override;                        // 05
		void           Unk_06(void) override;                        // 06
		void           LoadGame(BGSSaveFormBuffer* a_buf) override;  // 08
		void           SaveGame(BGSLoadFormBuffer* a_buf) override;  // 09
		void           Unk_0A(void) override;                        // 0A
		void           Unk_12(void) override;                        // 12

		~CommandEffect() override;  // 13

		void Start() override;   // 14
		void Finish() override;  // 15

		// members
		ActorHandle   commandedActor;  // 90
		std::uint32_t pad94;           // 94
	};
	static_assert(sizeof(CommandEffect) == 0x98);
}
