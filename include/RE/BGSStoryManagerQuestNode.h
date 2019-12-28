#pragma once

#include "RE/BGSStoryManagerNodeBase.h"
#include "RE/BSTHashMap.h"
#include "RE/BSTArray.h"
#include "RE/FormTypes.h"


namespace RE
{
	class BGSStoryManagerQuestNode : public BGSStoryManagerNodeBase
	{
	public:
		inline static const void* RTTI = RTTI_BGSStoryManagerQuestNode;


		enum { kTypeID = FormType::StoryManagerQuestNode };


		struct ChangeFlags
		{
			enum ChangeFlag : UInt32
			{
				kTimeLastRun = (UInt32)1 << 31
			};
		};


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
		virtual void						ClearData() override;							// 05
		virtual bool						Load(TESFile* a_mod) override;					// 06
		virtual void						SaveGame(BGSSaveFormBuffer* a_buf) override;	// 0E
		virtual void						LoadGame(BGSLoadFormBuffer* a_buf) override;	// 0F
		virtual void						Revert(void* a_arg1) override;					// 12
		virtual void						InitItemImpl() override;						// 13
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
