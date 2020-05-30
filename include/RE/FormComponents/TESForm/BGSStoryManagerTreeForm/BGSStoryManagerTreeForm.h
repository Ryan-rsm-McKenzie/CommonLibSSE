#pragma once

#include "RE/BSTArray.h"
#include "RE/FormTypes.h"
#include "RE/TESForm.h"


namespace RE
{
	class BGSStoryManagerBranchNode;
	class BGSStoryManagerQuestNode;
	class BGSStoryManagerTreeForm;
	class PeriodicUpdateTimer;
	class TESCondition;


	class BGSStoryManagerTreeVisitor
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSStoryManagerTreeVisitor;


		enum class VisitControl : UInt32
		{
		};


		virtual ~BGSStoryManagerTreeVisitor();	// 00

		// add
		virtual VisitControl VisitBranchNode(BGSStoryManagerBranchNode& a_node);			 // 01
		virtual VisitControl VisitQuestNode(BGSStoryManagerQuestNode& a_node, bool a_arg2);	 // 02
		virtual VisitControl VisitQuest(TESQuest& a_quest);									 // 03
		virtual void		 Revert();														 // 04


		// members
		PeriodicUpdateTimer*			   timer;				// 08
		SInt32							   currentCursorDepth;	// 10
		UInt32							   pad14;				// 14
		BGSStoryManagerQuestNode*		   lastQuestParent;		// 18
		BSTArray<BGSStoryManagerTreeForm*> cursorAncestry;		// 20
		UInt32							   queryID;				// 38
		UInt32							   pad3C;				// 3C
	};
	STATIC_ASSERT(sizeof(BGSStoryManagerTreeVisitor) == 0x40);


	class BGSStoryManagerTreeForm : public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSStoryManagerTreeForm;


		virtual ~BGSStoryManagerTreeForm();	 // 00

		// add
		virtual UInt32									 QChildCount() const;										// 3B - { return 0; }
		virtual BGSStoryManagerTreeForm*				 GetChild(UInt32 a_idx) const;								// 3C - { return 0; }
		virtual TESCondition*							 QConditions() = 0;											// 3D
		virtual BGSStoryManagerTreeVisitor::VisitControl AcceptVisitor(BGSStoryManagerTreeVisitor& a_visitor) = 0;	// 3E


		// members
		UInt32 lastVisitorID;  // 20
		UInt32 pad24;		   // 24
	};
	STATIC_ASSERT(sizeof(BGSStoryManagerTreeForm) == 0x28);
}
