#pragma once

#include "RE/B/BGSStoryManagerNodeBase.h"
#include "RE/B/BSTArray.h"
#include "RE/F/FormTypes.h"

namespace RE
{
	class BGSStoryManagerBranchNode : public BGSStoryManagerNodeBase
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSStoryManagerBranchNode;
		inline static constexpr auto FORMTYPE = FormType::StoryManagerBranchNode;

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};

		virtual ~BGSStoryManagerBranchNode();  // 00

		// override (BGSStoryManagerNodeBase)
		virtual void									 ClearData() override;											 // 05 - { BGSStoryManagerNodeBase::ClearData(); }
		virtual void									 InitItemImpl() override;										 // 13
		virtual std::uint32_t							 QChildCount() const override;									 // 3B - { return nodeChildren.size(); }
		virtual BGSStoryManagerTreeForm*				 GetChild(std::uint32_t a_idx) const override;					 // 3C - { return children[a_idx]; }
		virtual BGSStoryManagerTreeVisitor::VisitControl AcceptVisitor(BGSStoryManagerTreeVisitor& a_visitor) override;	 // 3E - { return a_visitor->VisitBranchNode(this); }

		// members
		BSTArray<BGSStoryManagerNodeBase*> children;  // 48
	};
	static_assert(sizeof(BGSStoryManagerBranchNode) == 0x60);
}
