#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSStoryManagerNodeBase

#include "RE/BGSStoryManagerTreeForm.h"  // BGSStoryManagerTreeForm
#include "RE/Condition.h"  // Condition


namespace RE
{
	class BGSStoryManagerNodeBase : public BGSStoryManagerTreeForm
	{
	public:
		inline static const void* RTTI = RTTI_BGSStoryManagerNodeBase;


		struct Flags	// DNAM
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


			NodeFlag	nodeFlags;	// 0
			QuestFlag	questFags;	// 2
		};
		STATIC_ASSERT(sizeof(Flags) == 0x4);


		virtual ~BGSStoryManagerNodeBase();						// 00

		// override (BGSStoryManagerTreeForm)
		virtual void		InitDefaults() override;			// 04
		virtual void		ReleaseManagedData() override;		// 05
		virtual bool		LoadForm(TESFile* a_mod) override;	// 06
		virtual void		InitItem() override;				// 13
		virtual Condition*	GetConditions() override;			// 3D - { return &conditions; }


		// members
		BGSStoryManagerBranchNode*	parent;					// 28 - PNAM
		BGSStoryManagerNodeBase*	previousSibling;		// 30 - SNAM
		UInt32						maxConcurrentQuests;	// 38 - XNAM
		Flags						flags;					// 3C - DNAM
		Condition					conditions;				// 40 - CITC
	};
	STATIC_ASSERT(sizeof(BGSStoryManagerNodeBase) == 0x48);
}
