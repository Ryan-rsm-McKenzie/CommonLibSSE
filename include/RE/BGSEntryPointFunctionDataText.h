#pragma once

#include "skse64/GameTypes.h"  // BSFixedString

#include "RE/BGSEntryPointFunctionData.h"  // BGSEntryPointFunctionData


namespace RE
{
	class BGSEntryPointFunctionDataText : public BGSEntryPointFunctionData
	{
	public:
		// override (BGSEntryPointFunctionData)
		virtual FunctionType GetType() const override;	// 1

		// add
		virtual ~BGSEntryPointFunctionDataText();		// 0


		// members
		BSFixedString text;	// 8
	};
}
