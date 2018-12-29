#pragma once

#include "RE/FormTypes.h"  // FormType
#include "RE/TESForm.h"  // TESForm


namespace RE
{
	class BGSDialogueBranch : public TESForm
	{
	public:
		enum { kTypeID = FormType::DialogueBranch };


		enum class Flag : UInt32
		{
			kNone = 0,
			kTopLevel = 1 << 0,
			kBlocking = 1 << 1,
			kExclusive = 1 << 2
		};


		virtual ~BGSDialogueBranch();	// 00


		// members
		Flag		flags;			// 20 - DNAM
		UInt32		pad24;			// 24
		TESQuest*	quest;			// 28 - QNAM
		TESTopic*	startingTopic;	// 30 - SNAM
		UInt32		unk38;			// 38 - TNAM?
		UInt32		pad3C;			// 3C
	};
	STATIC_ASSERT(sizeof(BGSDialogueBranch) == 0x40);
}
