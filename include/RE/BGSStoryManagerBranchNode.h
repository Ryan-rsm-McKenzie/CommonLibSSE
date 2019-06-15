#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSStoryManagerBranchNode

#include "RE/BGSStoryManagerNodeBase.h"  // BGSStoryManagerNodeBase
#include "RE/BSTArray.h"  // BSTArray
#include "RE/FormTypes.h"  // FormType


namespace RE
{
	class BGSStoryManagerBranchNode : public BGSStoryManagerNodeBase
	{
	public:
		inline static const void* RTTI = RTTI_BGSStoryManagerBranchNode;


		enum { kTypeID = FormType::StoryManagerBranchNode };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~BGSStoryManagerBranchNode();									// 00

		// override (BGSStoryManagerNodeBase)
		virtual void						ReleaseManagedData() override;		// 05 - { BGSStoryManagerNodeBase::ReleaseManagedData(); }
		virtual void						InitItem() override;				// 13
		virtual UInt32						GetNumChildren() const override;	// 3B - { return children.size(); }
		virtual BGSStoryManagerEventNode*	GetNthChild(UInt32 a_idx) override;	// 3C - { return children[a_idx]; }
		virtual void						Unk_3E(void) override;				// 3E - { return a_arg1->Unk_01(this); }


		// members
		BSTArray<BGSStoryManagerEventNode*> children;	// 48
	};
	STATIC_ASSERT(sizeof(BGSStoryManagerBranchNode) == 0x60);
}
