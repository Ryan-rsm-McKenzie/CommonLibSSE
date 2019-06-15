#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSEntryPointPerkEntry

#include "RE/BGSPerkEntry.h"  // RE::BGSPerkEntry
#include "RE/FormTypes.h"  // BGSPerk, TESObjectREFR


namespace RE
{
	class BGSEntryPointFunctionData;
	class Condition;


	class BGSEntryPointPerkEntry : public BGSPerkEntry
	{
	public:
		inline static const void* RTTI = RTTI_BGSEntryPointPerkEntry;


		struct EntryData	// DATA
		{
			enum class Function : UInt8
			{
				kSetValue = 1,
				kAddValue = 2,
				kMultiplyValue = 3,
				kAddRangeToValue = 4,
				kAddActorValueMult = 5,
				kAbsoluteValue = 6,
				kNegativeAbsoluteValue = 7,
				kAddLeveledList = 8,
				kAddActivateChoice = 9,
				kSelectSpell = 10,
				kSelectText = 11,
				kSetToActorValueMult = 12,
				kMultiplyActorValueMult = 13,
				kMultiply1PlusActorValueMult = 14,
				kSetText = 15
			};


			EntryPoint	entryPoint;	// 0
			Function	function;	// 1
			UInt8		numArgs;	// 2
			UInt8		unk3;		// 3
			UInt32		unk4;		// 4
		};
		STATIC_ASSERT(sizeof(EntryData) == 0x8);


		// override (BGSPerkEntry)
		virtual bool						EvaluateConditions(UInt32 a_numArgs, void* a_args) override;	// 00
		virtual EntryPoint					GetEntryPoint() const override;									// 01 { return entryPoint; }
		virtual BGSEntryPointFunctionData*	GetFunctionData() const override;								// 02 { return functionData; }

		virtual ~BGSEntryPointPerkEntry();																	// 03

		virtual Type						GetType() const override;										// 04 - { return kEntryPoint; }
		virtual void						ReleaseRefs() override;											// 05
		virtual void						ResolveForms(TESFile* a_mod) override;							// 06
		virtual bool						LoadPerk(TESFile* a_mod) override;								// 07
		virtual void						SetPerk(BGSPerk* a_perk) override;								// 08
		virtual void						Unk_09(void) override;											// 09
		virtual void						Unk_0A(void) override;											// 0A
		virtual void						Unk_0B(void) override;											// 0B

		bool								IsEntryPoint(EntryPoint a_entryPoint) const;
		UInt32								GetNumConditions() const;


		// members
		EntryData					entryData;			// 10 - DATA
		BGSEntryPointFunctionData*	functionData;		// 18
		Condition*					conditions;			// 20
		BGSPerk*					perk;				// 28
	};
	STATIC_ASSERT(sizeof(BGSEntryPointPerkEntry) == 0x30);
}
