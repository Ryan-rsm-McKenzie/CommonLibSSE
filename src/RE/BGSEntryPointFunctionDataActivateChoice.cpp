#include "RE/BGSEntryPointFunctionDataActivateChoice.h"


namespace RE
{
	bool BGSEntryPointFunctionDataActivateChoice::ReplacesDefault() const
	{
		return (flags1 & Flag1::kReplaceDefault) != Flag1::kNone;
	}


	bool BGSEntryPointFunctionDataActivateChoice::RunsImmediately() const
	{
		return (flags1 & Flag1::kRunImmediately) != Flag1::kNone;
	}
}
