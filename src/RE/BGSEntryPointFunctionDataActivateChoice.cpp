#include "RE/BGSEntryPointFunctionDataActivateChoice.h"  // BGSEntryPointFunctionDataActivateChoice


namespace RE
{
	bool BGSEntryPointFunctionDataActivateChoice::RunsImmediately() const
	{
		return (flags1 & kFlag_RunImmediately) != 0;
	}


	bool BGSEntryPointFunctionDataActivateChoice::ReplacesDefault() const
	{
		return (flags1 & kFlag_ReplaceDefault) != 0;
	}
}
