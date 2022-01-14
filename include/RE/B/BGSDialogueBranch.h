#pragma once

#include "RE/D/DialogueTypes.h"
#include "RE/F/FormTypes.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class BGSDialogueBranch : public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSDialogueBranch;
		inline static constexpr auto VTABLE = VTABLE_BGSDialogueBranch;
		inline static constexpr auto FORMTYPE = FormType::DialogueBranch;

		enum class Flag
		{
			kNone = 0,
			kTopLevel = 1 << 0,
			kBlocking = 1 << 1,
			kExclusive = 1 << 2
		};

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};

		~BGSDialogueBranch() override;  // 00

		// override (TESForm)
		void InitializeData() override;      // 04
		void ClearData() override;           // 05
		bool Load(TESFile* a_mod) override;  // 06
		void InitItemImpl() override;        // 13

		// members
		stl::enumeration<Flag, std::uint32_t> flags;          // 20 - DNAM
		std::uint32_t                         pad24;          // 24
		TESQuest*                             quest;          // 28 - QNAM
		TESTopic*                             startingTopic;  // 30 - SNAM
		DIALOGUE_TYPE                         type;           // 38 - TNAM
		std::uint32_t                         pad3C;          // 3C
	};
	static_assert(sizeof(BGSDialogueBranch) == 0x40);
}
