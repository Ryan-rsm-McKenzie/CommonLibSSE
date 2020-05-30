#pragma once

#include "RE/BGSStoryManagerTreeForm.h"
#include "RE/TESCondition.h"


namespace RE
{
	class BGSStoryManagerNodeBase : public BGSStoryManagerTreeForm
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSStoryManagerNodeBase;


		struct Flags  // DNAM
		{
			enum class NodeFlag : UInt16
			{
				kNone = 0,
				kRandom = 1 << 0,
				kWarnIfNoChildQuestStarted = 1 << 1
			};


			enum class QuestFlag : UInt16
			{
				kNone = 0,
				kDoAllBeforeRepeating = 1 << 0,
				kSharesEvent = 1 << 1,
				kNumQuestsToRun = 1 << 2
			};


			NodeFlag  nodeFlags;  // 0
			QuestFlag questFags;  // 2
		};
		STATIC_ASSERT(sizeof(Flags) == 0x4);


		virtual ~BGSStoryManagerNodeBase();	 // 00

		// override (BGSStoryManagerTreeForm)
		virtual void		  InitializeData() override;	  // 04
		virtual void		  ClearData() override;			  // 05
		virtual bool		  Load(TESFile* a_mod) override;  // 06
		virtual void		  InitItemImpl() override;		  // 13
		virtual TESCondition* QConditions() override;		  // 3D - { return &conditions; }


		// members
		BGSStoryManagerBranchNode* parent;			 // 28 - PNAM
		BGSStoryManagerNodeBase*   previousSibling;	 // 30 - SNAM
		UInt32					   maxQuests;		 // 38 - XNAM
		Flags					   flags;			 // 3C - DNAM
		TESCondition			   conditions;		 // 40 - CITC
	};
	STATIC_ASSERT(sizeof(BGSStoryManagerNodeBase) == 0x48);
}
