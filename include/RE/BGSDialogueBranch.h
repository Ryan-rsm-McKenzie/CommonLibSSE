#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSDialogueBranch

#include "RE/FormTypes.h"  // FormType
#include "RE/TESForm.h"  // TESForm


namespace RE
{
	class BGSDialogueBranch : public TESForm
	{
	public:
		inline static const void* RTTI = RTTI_BGSDialogueBranch;


		enum { kTypeID = FormType::DialogueBranch };


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


		virtual ~BGSDialogueBranch();						// 00

		// override (TESForm)
		virtual void	InitDefaults() override;			// 04
		virtual void	ReleaseManagedData() override;		// 05
		virtual bool	LoadForm(TESFile* a_mod) override;	// 06
		virtual void	InitItem() override;				// 13


		// members
		Flag		flags;			// 20 - DNAM
		UInt32		pad24;			// 24
		TESQuest*	quest;			// 28 - QNAM
		TESTopic*	startingTopic;	// 30 - SNAM
		UInt32		unk38;			// 38 - TNAM
		UInt32		pad3C;			// 3C
	};
	STATIC_ASSERT(sizeof(BGSDialogueBranch) == 0x40);
}
