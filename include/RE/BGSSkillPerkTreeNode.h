#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSSkillPerkTreeNode

#include "RE/BSTArray.h"  // BSTArray
#include "RE/FormTypes.h"  // ActorValueInfo, BGSPerk


namespace RE
{
	class BGSSkillPerkTreeNode
	{
	public:
		inline static const void* RTTI = RTTI_BGSSkillPerkTreeNode;


		virtual ~BGSSkillPerkTreeNode();	// 00


		// members
		UInt32							index;				// 08 - INAM
		UInt32							unk0C;				// 0C
		BSTArray<BGSSkillPerkTreeNode*>	children;			// 10 - CNAM
		BSTArray<BGSSkillPerkTreeNode*>	parents;			// 28
		BGSPerk*						perk;				// 40 - PNAM
		UInt32							unk48;				// 48 - FNAM
		UInt32							perkGridX;			// 4C - XNAM
		UInt32							perkGridY;			// 50 - YNAM
		UInt32							unk54;				// 54
		ActorValueInfo*					associatedSkill;	// 58 - SNAM
		float							horizontalPosition;	// 60 - HNAM
		float							verticalPosition;	// 64 - VNAM
	};
	STATIC_ASSERT(sizeof(BGSSkillPerkTreeNode) == 0x68);
}
