#pragma once

#include "skse64/GameTypes.h"  // BSFixedString

#include "RE/BGSEntryPointFunctionData.h"  // BGSEntryPointFunctionData

class BGSPerk;
class SpellItem;


namespace RE
{
	class BGSEntryPointFunctionDataActivateChoice : public BGSEntryPointFunctionData
	{
	public:
		enum Flags : UInt32
		{
			kFlag_RunImmediately = 1,
			kFlag_ReplaceDefault = 2
		};


		virtual ~BGSEntryPointFunctionDataActivateChoice();


		// members
		BSFixedString	label;
		BGSPerk*		perk;
		SpellItem*		appliedSpell;
		UInt32			flags;
		UInt32			unk14;
	};
}
