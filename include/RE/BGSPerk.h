#pragma once

#include "RE/BSTArray.h"  // BSTArray
#include "RE/Condition.h"  // Condition
#include "RE/FormTypes.h"  // FormType
#include "RE/PerkRankVisitor.h"  // PerkRankVisitor
#include "RE/TESDescription.h"  // TESDescription
#include "RE/TESForm.h"  // TESForm
#include "RE/TESFullName.h"  // TESFullName
#include "RE/TESIcon.h"  // TESIcon


namespace RE
{
	class BGSPerkEntry;


	class BGSPerk :
		public TESForm,			// 00
		public TESFullName,		// 20
		public TESDescription,	// 30
		public TESIcon			// 40
	{
	public:
		enum { kTypeID = FormType::Perk };


		class FindPerkInRanksVisitor : public PerkRankVisitor
		{
		public:
			virtual bool operator()(const BGSPerkRankArray::Entry* a_entry) override;	// 00
		};


		class ApplyPerksVisitor : public PerkRankVisitor
		{
		public:
			virtual bool operator()(const BGSPerkRankArray::Entry* a_entry) override;	// 00
		};


		class AddPerkVisitor : public PerkRankVisitor
		{
		public:
			virtual bool operator()(const BGSPerkRankArray::Entry* a_entry) override;	// 00
		};


		virtual ~BGSPerk();									// 00

		// override (TESForm)
		virtual void	InitDefaults() override;			// 04
		virtual bool	LoadForm(TESFile* a_mod) override;	// 06
		virtual void	InitItem() override;				// 13


		// members
		bool					trait;			// 50
		UInt8					level;			// 51
		UInt8					numRanks;		// 52
		bool					playable;		// 53
		bool					hidden;			// 54
		UInt8					pad55;			// 55
		UInt16					pad56;			// 56
		Condition				conditions;		// 58
		BSTArray<BGSPerkEntry*>	perkEntries;	// 60
		BGSPerk*				nextPerk;		// 78
	};
	STATIC_ASSERT(sizeof(BGSPerk) == 0x80);
}
