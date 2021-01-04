#pragma once

#include "RE/B/BGSStoryManagerNodeBase.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTHashMap.h"
#include "RE/F/FormTypes.h"

namespace RE
{
	class BGSStoryManagerQuestNode : public BGSStoryManagerNodeBase
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSStoryManagerQuestNode;
		inline static constexpr auto FORMTYPE = FormType::StoryManagerQuestNode;

		struct ChangeFlags
		{
			enum ChangeFlag : std::uint32_t
			{
				kTimeLastRun = (std::uint32_t)1 << 31
			};
		};

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};

		virtual ~BGSStoryManagerQuestNode();  // 00

		// override (BGSStoryManagerNodeBase)
		virtual void									 ClearData() override;											 // 05
		virtual bool									 Load(TESFile* a_mod) override;									 // 06
		virtual void									 SaveGame(BGSSaveFormBuffer* a_buf) override;					 // 0E
		virtual void									 LoadGame(BGSLoadFormBuffer* a_buf) override;					 // 0F
		virtual void									 Revert(BGSLoadFormBuffer* a_buf) override;						 // 12
		virtual void									 InitItemImpl() override;										 // 13
		virtual std::uint32_t							 QChildCount() const override;									 // 3B - { return quests.size(); }
		virtual BGSStoryManagerTreeForm*				 GetChild(std::uint32_t a_idx) const override;					 // 3C - { return quests[a_idx]; }
		virtual BGSStoryManagerTreeVisitor::VisitControl AcceptVisitor(BGSStoryManagerTreeVisitor& a_visitor) override;	 // 3E - { return a_visitor->VisitQuestNode(this); }

		// members
		BSTArray<TESQuest*>					 quests;				   // 48 - NNAM
		BSTHashMap<TESQuest*, std::uint32_t> perQuestFlags;			   // 60 - maps NNAM to FNAM
		BSTHashMap<TESQuest*, float>		 perQuestHoursUntilReset;  // 90 - maps NNAM to RNAM
		std::uint32_t						 numQuestsToStart;		   // C0 - MNAM
		std::uint32_t						 padC4;					   // C4
		BSTArray<float>						 childrenLastRun;		   // C8
	};
	static_assert(sizeof(BGSStoryManagerQuestNode) == 0xE0);
}
