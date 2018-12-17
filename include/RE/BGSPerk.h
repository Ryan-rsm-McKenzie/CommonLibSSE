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
		bool					trait;			// 50
		UInt8					level;			// 51
		UInt8					numRanks;		// 52
		bool					playable;		// 53
		bool					hidden;			// 54
		UInt8					pad55[3];		// 55
		Condition*				conditions;		// 58
		BSTArray<BGSPerkEntry*>	perkEntries;	// 60
		BGSPerk*				nextPerk;		// 78
	};
	STATIC_ASSERT(sizeof(BGSPerk) == 0x80);
}
