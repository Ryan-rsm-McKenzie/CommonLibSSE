#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSEntryPointFunctionDataText

#include "RE/BGSEntryPointFunctionData.h"  // BGSEntryPointFunctionData
#include "RE/BSFixedString.h"  // BSFixedString


namespace RE
{
	class BGSEntryPointFunctionDataText : public BGSEntryPointFunctionData
	{
	public:
		inline static const void* RTTI = RTTI_BGSEntryPointFunctionDataText;


		virtual ~BGSEntryPointFunctionDataText();							// 00

		// override (BGSEntryPointFunctionData)
		virtual FunctionType	GetType() const override;					// 01 - { return kText; }
		virtual bool			LoadFunctionData(TESFile* a_mod) override;	// 02


		// members
		BSFixedString text;	// 08
	};
	STATIC_ASSERT(sizeof(BGSEntryPointFunctionDataText) == 0x10);
}
