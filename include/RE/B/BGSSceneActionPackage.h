#pragma once

#include "RE/B/BGSSceneAction.h"
#include "RE/B/BSTArray.h"

namespace RE
{
	class TESPackage;

	class BGSSceneActionPackage : public BGSSceneAction
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSSceneActionPackage;
		inline static constexpr auto TYPE = Type::kPackage;

		~BGSSceneActionPackage() override;  // 00

		// override (BGSSceneAction)
		bool LoadSceneAction(TESFile* a_mod) override;                     // 01
		void Unk_02() override;                                        // 02
		Type GetType() const override;                                     // 07 - { return kPackage; }
		void Unk_08() override;                                        // 08
		void LoadBuffer(void* a_arg1, BGSLoadGameBuffer* a_buf) override;  // 09
		void Unk_0A() override;                                        // 0A
		void Unk_0B() override;                                        // 0B
		void Unk_10() override;                                        // 10
		void Unk_11() override;                                        // 11
		void Unk_12() override;                                        // 12
		void Unk_13() override;                                        // 13

		// members
		std::uint64_t         unk20;     // 20
		BSTArray<TESPackage*> packages;  // 28 - PNAM
	};
	static_assert(sizeof(BGSSceneActionPackage) == 0x40);
}
