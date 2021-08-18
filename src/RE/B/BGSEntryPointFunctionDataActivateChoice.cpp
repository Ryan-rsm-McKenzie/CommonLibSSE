#include "RE/B/BGSEntryPointFunctionDataActivateChoice.h"

namespace RE
{
	bool BGSEntryPointFunctionDataActivateChoice::ReplacesDefault() const
	{
		return flags1.all(Flag1::kReplaceDefault);
	}

	bool BGSEntryPointFunctionDataActivateChoice::RunsImmediately() const
	{
		return flags1.all(Flag1::kRunImmediately);
	}
}
