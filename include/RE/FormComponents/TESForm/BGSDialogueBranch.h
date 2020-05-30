#pragma once

#include "RE/DialogueTypes.h"
#include "RE/FormTypes.h"
#include "RE/TESForm.h"


namespace RE
{
	class BGSDialogueBranch : public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSDialogueBranch;
		inline static constexpr auto FORMTYPE = FormType::DialogueBranch;


		enum class Flag : UInt32
		{
			kNone = 0,
			kTopLevel = 1 << 0,
			kBlocking = 1 << 1,
			kExclusive = 1 << 2
		};


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~BGSDialogueBranch();  // 00

		// override (TESForm)
		virtual void InitializeData() override;		 // 04
		virtual void ClearData() override;			 // 05
		virtual bool Load(TESFile* a_mod) override;	 // 06
		virtual void InitItemImpl() override;		 // 13


		// members
		Flag		  flags;		  // 20 - DNAM
		UInt32		  pad24;		  // 24
		TESQuest*	  quest;		  // 28 - QNAM
		TESTopic*	  startingTopic;  // 30 - SNAM
		DIALOGUE_TYPE type;			  // 38 - TNAM
		UInt32		  pad3C;		  // 3C
	};
	STATIC_ASSERT(sizeof(BGSDialogueBranch) == 0x40);
}
