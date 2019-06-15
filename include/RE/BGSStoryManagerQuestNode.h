#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSStoryManagerQuestNode

#include "RE/BGSStoryManagerNodeBase.h"  // BGSStoryManagerNodeBase
#include "RE/BSTHashMap.h"  // BSTHashMap
#include "RE/BSTArray.h"  // BSTArray
#include "RE/FormTypes.h"  // FormType


namespace RE
{
	class BGSStoryManagerQuestNode : public BGSStoryManagerNodeBase
	{
	public:
		inline static const void* RTTI = RTTI_BGSStoryManagerQuestNode;


		enum { kTypeID = FormType::StoryManagerQuestNode };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~BGSStoryManagerQuestNode();												// 00

		// override (BGSStoryManagerNodeBase)
		virtual void						ReleaseManagedData() override;					// 05
		virtual bool						LoadForm(TESFile* a_mod) override;				// 06
		virtual void						SaveBuffer(BGSSaveFormBuffer* a_buf) override;	// 0E
		virtual void						LoadBuffer(BGSLoadFormBuffer* a_buf) override;	// 0F
		virtual void						InitItem() override;							// 13
		virtual TESFile*					GetFinalSourceFile() override;					// 14
		virtual UInt32						GetNumChildren() const override;				// 3B - { return quests.size(); }
		virtual BGSStoryManagerEventNode*	GetNthChild(UInt32 a_idx) override;				// 3C - { return quests[a_idx]; }
		virtual void						Unk_3E(void) override;							// 3E - { return a_arg1->Unk_02(this); }


		// members
		BSTArray<TESQuest*>				quests;			// 48 - NNAM
		BSTHashMap<TESQuest*, UInt32>	questFNAMMap;	// 60 - maps NNAM to FNAM
		BSTHashMap<TESQuest*, float>	questResetMap;	// 90 - maps NNAM to RNAM
		UInt32							numQuestsToRun;	// C0 - MNAM
		UInt32							padC4;			// C4
		BSTArray<UInt32>				unkC8;			// C8
	};
	STATIC_ASSERT(sizeof(BGSStoryManagerQuestNode) == 0xE0);
}
