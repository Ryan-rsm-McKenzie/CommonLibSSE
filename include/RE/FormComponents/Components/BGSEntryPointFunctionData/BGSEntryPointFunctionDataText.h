#pragma once

#include "RE/BGSEntryPointFunctionData.h"
#include "RE/BSFixedString.h"


namespace RE
{
	class BGSEntryPointFunctionDataText : public BGSEntryPointFunctionData
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSEntryPointFunctionDataText;


		virtual ~BGSEntryPointFunctionDataText();  // 00

		// override (BGSEntryPointFunctionData)
		virtual FunctionType GetType() const override;					 // 01 - { return kText; }
		virtual bool		 LoadFunctionData(TESFile* a_mod) override;	 // 02


		// members
		BSFixedString text;	 // 08
	};
	STATIC_ASSERT(sizeof(BGSEntryPointFunctionDataText) == 0x10);
}
