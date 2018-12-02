#pragma once

#include "RE/BGSEntryPointFunctionData.h"  // BGSEntryPointFunctionData
#include "RE/BSFixedString.h"  // BSFixedString

class BGSPerk;
class SpellItem;


namespace RE
{
	class BGSEntryPointFunctionDataActivateChoice : public BGSEntryPointFunctionData
	{
	public:
		enum Flags1 : UInt16
		{
			kFlag_RunImmediately = 1,
			kFlag_ReplaceDefault = 2
		};


		// override (BGSEntryPointFunctionData)
		virtual FunctionType GetType() const override;		// 1

		// add
		virtual ~BGSEntryPointFunctionDataActivateChoice();	// 0

		bool	RunsImmediately() const;
		bool	ReplacesDefault() const;


		// members
		BSFixedString	label;			// 08
		BGSPerk*		perk;			// 10
		SpellItem*		appliedSpell;	// 18
		Flags1			flags1;			// 20
		UInt16			flags2;			// 22
		UInt32			pad24;			// 24
	};
}
