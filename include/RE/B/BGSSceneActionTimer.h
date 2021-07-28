#pragma once

#include "RE/B/BGSSceneAction.h"

namespace RE
{
	class BGSSceneActionTimer : public BGSSceneAction
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSSceneActionTimer;
		inline static constexpr auto TYPE = Type::kTimer;

		~BGSSceneActionTimer() override;  // 00

		// override (BGSSceneAction)
		bool LoadSceneAction(TESFile* a_mod) override;                     // 01
		void ClearFlags() override;                                        // 04 - { BGSSceneAction::ClearFlags(); }
		Type GetType() const override;                                     // 07 - { return kTimer; }
		void LoadBuffer(void* a_arg1, BGSLoadGameBuffer* a_buf) override;  // 09
		void Unk_0A() override;                                        // 0A
		void Unk_0B() override;                                        // 0B
		void Unk_0D() override;                                        // 0D
		void Unk_11() override;                                        // 11
		void Unk_13() override;                                        // 13

		// members
		float         timerSeconds;  // 20 - SNAM
		std::uint32_t unk24;         // 24
		std::uint64_t unk28;         // 28
	};
	static_assert(sizeof(BGSSceneActionTimer) == 0x30);
}
