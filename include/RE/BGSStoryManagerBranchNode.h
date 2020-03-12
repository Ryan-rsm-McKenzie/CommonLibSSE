#pragma once

#include "RE/BGSStoryManagerNodeBase.h"
#include "RE/BSTArray.h"
#include "RE/FormTypes.h"


namespace RE
{
	class BGSStoryManagerBranchNode : public BGSStoryManagerNodeBase
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSStoryManagerBranchNode;
		inline static constexpr auto FORMTYPE = FormType::StoryManagerBranchNode;


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~BGSStoryManagerBranchNode();  // 00

		// override (BGSStoryManagerNodeBase)
		virtual void									 ClearData() override;											 // 05 - { BGSStoryManagerNodeBase::ClearData(); }
		virtual void									 InitItemImpl() override;										 // 13
		virtual UInt32									 QChildCount() const override;									 // 3B - { return nodeChildren.size(); }
		virtual BGSStoryManagerTreeForm*				 GetChild(UInt32 a_idx) const override;							 // 3C - { return children[a_idx]; }
		virtual BGSStoryManagerTreeVisitor::VisitControl AcceptVisitor(BGSStoryManagerTreeVisitor& a_visitor) override;	 // 3E - { return a_visitor->VisitBranchNode(this); }


		// members
		BSTArray<BGSStoryManagerNodeBase*> children;  // 48
	};
	STATIC_ASSERT(sizeof(BGSStoryManagerBranchNode) == 0x60);
}
