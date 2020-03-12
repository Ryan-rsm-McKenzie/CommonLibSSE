#pragma once

#include "RE/BGSStoryManagerBranchNode.h"
#include "RE/BSString.h"
#include "RE/BSTArray.h"
#include "RE/FormTypes.h"


namespace RE
{
	struct BGSStoryEventMember
	{
		enum class DATA_TYPE : UInt32
		{
		};


		DATA_TYPE type;		 // 00
		UInt32	  uniqueID;	 // 04
		BSString  name;		 // 08
	};
	STATIC_ASSERT(sizeof(BGSStoryEventMember) == 0x18);


	struct BGSRegisteredStoryEvent	// ENAM
	{
		char						   uniqueID[4];	 // 00
		UInt32						   pad04;		 // 04
		BSTArray<BGSStoryEventMember>* members;		 // 08
		BSString					   name;		 // 10
		bool						   immediate;	 // 20
		UInt8						   pad21;		 // 21
		UInt16						   pad22;		 // 22
		UInt32						   pad24;		 // 24
	};
	STATIC_ASSERT(sizeof(BGSRegisteredStoryEvent) == 0x28);


	class BGSStoryManagerEventNode : public BGSStoryManagerBranchNode
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSStoryManagerEventNode;
		inline static constexpr auto FORMTYPE = FormType::StoryManagerEventNode;


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~BGSStoryManagerEventNode();  // 00

		// override (BGSStoryManagerBranchNode)
		virtual void		InitializeData() override;		   // 04
		virtual void		ClearData() override;			   // 05 - { BGSStoryManagerNodeBase::ClearData(); }
		virtual bool		Load(TESFile* a_mod) override;	   // 06
		virtual void		InitItemImpl() override;		   // 13
		virtual const char* GetFormEditorID() const override;  // 32 - { if (!((flags >> 3) & 1)) return "(Uninitialized event node)"; return event ? event->name.c_str() : "(No event)"; }


		// members
		const BGSRegisteredStoryEvent* event;  // 60 - ENAM
	};
	STATIC_ASSERT(sizeof(BGSStoryManagerEventNode) == 0x68);
}
