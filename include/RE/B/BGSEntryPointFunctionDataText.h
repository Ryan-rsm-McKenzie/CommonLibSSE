#pragma once

#include "RE/B/BGSEntryPointFunctionData.h"
#include "RE/B/BSFixedString.h"

namespace RE
{
	class BGSEntryPointFunctionDataText : public BGSEntryPointFunctionData
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSEntryPointFunctionDataText;

		~BGSEntryPointFunctionDataText() override;  // 00

		// override (BGSEntryPointFunctionData)
		FunctionType GetType() const override;                   // 01 - { return kText; }
		bool         LoadFunctionData(TESFile* a_mod) override;  // 02

		// members
		BSFixedString text;  // 08
	};
	static_assert(sizeof(BGSEntryPointFunctionDataText) == 0x10);
}
