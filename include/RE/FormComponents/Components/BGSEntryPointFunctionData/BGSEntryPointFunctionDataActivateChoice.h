#pragma once

#include "RE/BGSEntryPointFunctionData.h"
#include "RE/BSFixedString.h"
#include "RE/FormTypes.h"


namespace RE
{
	class BGSEntryPointFunctionDataActivateChoice : public BGSEntryPointFunctionData
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSEntryPointFunctionDataActivateChoice;


		enum class Flag1 : UInt16
		{
			kNone = 0,
			kRunImmediately = 1,
			kReplaceDefault = 2
		};


		virtual ~BGSEntryPointFunctionDataActivateChoice();	 // 00

		// override (BGSEntryPointFunctionData)
		virtual FunctionType GetType() const override;					 // 01 - { return kDataActivateChoice; }
		virtual bool		 LoadFunctionData(TESFile* a_mod) override;	 // 02
		virtual void		 ResolveForms(TESFile* a_mod) override;		 // 03
		virtual void		 Unk_05(void) override;						 // 05
		virtual void		 SetPerk(BGSPerk* a_perk) override;			 // 06 - { perk = a_perk; }
		virtual BGSPerk*	 GetPerk() override;						 // 07 - { return perk; }

		bool ReplacesDefault() const;
		bool RunsImmediately() const;


		// members
		BSFixedString label;		 // 08
		BGSPerk*	  perk;			 // 10
		SpellItem*	  appliedSpell;	 // 18
		Flag1		  flags1;		 // 20
		UInt16		  flags2;		 // 22
		UInt32		  pad24;		 // 24
	};
	STATIC_ASSERT(sizeof(BGSEntryPointFunctionDataActivateChoice) == 0x28);
}
