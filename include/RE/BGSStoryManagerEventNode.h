#pragma once

#include "RE/BGSStoryManagerBranchNode.h"
#include "RE/BSString.h"
#include "RE/BSTArray.h"
#include "RE/FormTypes.h"


namespace RE
{
	class BGSStoryManagerEventNode : public BGSStoryManagerBranchNode
	{
	public:
		inline static const void* RTTI = RTTI_BGSStoryManagerEventNode;


		enum { kTypeID = FormType::StoryManagerEventNode };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		struct Type	// ENAM
		{
			struct UnkData
			{
				UInt32		unk00;		// 00
				char		unk04[2];	// 04
				UInt16		unk06;		// 06
				BSString	unk08;		// 08
			};
			STATIC_ASSERT(sizeof(UnkData) == 0x18);


			char				code[4];	// 00
			UInt32				unk04;		// 04
			BSTArray<UnkData>*	unk08;		// 08
			BSString			fullName;	// 10
			UInt64				unk28;		// 20
		};
		STATIC_ASSERT(sizeof(Type) == 0x28);


		virtual ~BGSStoryManagerEventNode();					// 00

		// override (BGSStoryManagerBranchNode)
		virtual void		InitDefaults() override;			// 04
		virtual void		ReleaseManagedData() override;		// 05 - { BGSStoryManagerNodeBase::ReleaseManagedData(); }
		virtual bool		LoadForm(TESFile* a_mod) override;	// 06
		virtual void		InitItem() override;				// 13
		virtual const char*	GetEditorID() override;				// 32 - { if (!((flags >> 3) & 1)) return "(Uninitialized event node)"; return type ? type->fullName.c_str() : "(No event)"; }


		// members
		Type* type;	// 60 - ENAM - a reference to an entry in a global hash map
	};
	STATIC_ASSERT(sizeof(BGSStoryManagerEventNode) == 0x68);
}
