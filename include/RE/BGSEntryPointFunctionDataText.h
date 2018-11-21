#pragma once

#include "skse64/GameTypes.h"  // BSFixedString

#include "RE/BGSEntryPointFunctionData.h"  // BGSEntryPointFunctionData


namespace RE
{
	class BGSEntryPointFunctionDataText : public BGSEntryPointFunctionData
	{
	public:
		virtual ~BGSEntryPointFunctionDataText();

		virtual UInt32 GetType() const override;


		// members
		BSFixedString text;
	};
}
