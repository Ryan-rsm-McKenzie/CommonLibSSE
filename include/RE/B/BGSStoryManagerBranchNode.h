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
		inline static constexpr auto VTABLE = VTABLE_BGSStoryManagerBranchNode;
		inline static constexpr auto FORMTYPE = FormType::StoryManagerBranchNode;

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};

		~BGSStoryManagerBranchNode() override;  // 00

		// override (BGSStoryManagerNodeBase)
		void                                     ClearData() override;                                           // 05 - { BGSStoryManagerNodeBase::ClearData(); }
		void                                     InitItemImpl() override;                                        // 13
		std::uint32_t                            QChildCount() const override;                                   // 3B - { return nodeChildren.size(); }
		BGSStoryManagerTreeForm*                 GetChild(std::uint32_t a_idx) const override;                   // 3C - { return children[a_idx]; }
		BGSStoryManagerTreeVisitor::VisitControl AcceptVisitor(BGSStoryManagerTreeVisitor& a_visitor) override;  // 3E - { return a_visitor->VisitBranchNode(this); }

		// members
		BSTArray<BGSStoryManagerNodeBase*> children;  // 48
	};
	static_assert(sizeof(BGSStoryManagerBranchNode) == 0x60);
}
