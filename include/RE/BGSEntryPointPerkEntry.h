#pragma once

#include "RE/BGSPerkEntry.h"  // RE::BGSPerkEntry
#include "RE/FormTypes.h"  // BGSPerk, TESObjectREFR


namespace RE
{
	class BGSEntryPointFunctionData;
	class Condition;


	class BGSEntryPointPerkEntry : public BGSPerkEntry
	{
	public:
		// override (BGSPerkEntry)
		virtual bool						CanProcess(UInt32 a_numArgs, void* a_args) override;	// 00
		virtual EntryPointType				GetType() const override;								// 01 { return type; }
		virtual BGSEntryPointFunctionData*	GetFunctionData() const override;						// 02 { return functionData; }

		virtual ~BGSEntryPointPerkEntry();															// 03

		virtual UInt32						GetNumConditions() const override;						// 04 - { return 2; }
		virtual bool						Load(TESFile* a_mod) override;							// 07 - { return true; }
		virtual void						SetPerk(BGSPerk* a_perk) override;						// 08

		bool								HasType(EntryPointType a_type);


		// members
		UInt8						unk10;				// 10
		EntryPointType				type;				// 11
		UInt8						numArgs;			// 12
		UInt8						pad13;				// 13
		UInt32						pad14;				// 14
		BGSEntryPointFunctionData*	functionData;		// 18
		Condition*					conditions;			// 20
		BGSPerk*					perk;				// 28
	};
	STATIC_ASSERT(sizeof(BGSEntryPointPerkEntry) == 0x30);
}
