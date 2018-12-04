#pragma once

#include "skse64/GameFormComponents.h"  // TESFullName, TESDescription, TESIcon

#include "RE/BSTArray.h"  // BSTArray
#include "RE/PerkRankVisitor.h"  // PerkRankVisitor
#include "RE/TESForm.h"  // TESForm


namespace RE
{
	class BGSPerkEntry;


	class BGSPerk :
		public TESForm,
		public TESFullName,
		public TESDescription,
		public TESIcon
	{
	public:
		enum { kTypeID = FormType::Perk };


		class FindPerkInRanksVisitor : public PerkRankVisitor
		{
		public:
			virtual void Visit();	// 0
		};


		class ApplyPerksVisitor : public PerkRankVisitor
		{
		public:
			virtual void Visit();	// 0
		};


		class AddPerkVisitor : public PerkRankVisitor
		{
		public:
			virtual void Visit();	// 0
		};


		// members
		UInt8					unk30;			// 50
		UInt8					unk31;			// 51
		UInt8					unk32;			// 52 - init'd to 1
		UInt8					unk33;			// 53 - init'd to 1
		UInt8					unk34;			// 54
		UInt8					pad55[3];		// 55
		Condition*				conditions;		// 58
		BSTArray<BGSPerkEntry*>	perkEntries;	// 60
		BGSPerk*				nextPerk;		// 78
	};
	STATIC_ASSERT(sizeof(BGSPerk) == 0x80);

}
