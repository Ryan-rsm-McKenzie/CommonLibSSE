#include "RE/BGSEntryPointPerkEntry.h"


namespace RE
{
	bool BGSEntryPointPerkEntry::IsType(EntryPointType a_type)
	{
		return type == a_type;
	}
}
