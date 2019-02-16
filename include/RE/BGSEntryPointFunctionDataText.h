#pragma once

#include "RE/BGSEntryPointFunctionData.h"  // BGSEntryPointFunctionData
#include "RE/BSFixedString.h"  // BSFixedString


namespace RE
{
	class BGSEntryPointFunctionDataText : public BGSEntryPointFunctionData
	{
	public:
		virtual ~BGSEntryPointFunctionDataText();				// 00

		// override (BGSEntryPointFunctionData)
		virtual FunctionType	GetType() const override;		// 01 - { return kDataText; }
		virtual bool			Load(TESFile* a_mod) override;	// 02


		// members
		BSFixedString text;	// 08
	};
	STATIC_ASSERT(sizeof(BGSEntryPointFunctionDataText) == 0x10);
}
