#include "RE/BGSEntryPointFunctionDataActivateChoice.h"  // BGSEntryPointFunctionDataActivateChoice


namespace RE
{
	bool BGSEntryPointFunctionDataActivateChoice::RunsImmediately() const
	{
		return (flags1 & Flag1::kRunImmediately) != Flag1::kNone;
	}


	bool BGSEntryPointFunctionDataActivateChoice::ReplacesDefault() const
	{
		return (flags1 & Flag1::kReplaceDefault) != Flag1::kNone;
	}
}
