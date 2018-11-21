#include "RE/BGSEntryPointPerkEntry.h"


namespace RE
{
	bool BGSEntryPointPerkEntry::HasType(EntryPointType a_type)
	{
		return (type & a_type) != 0;
	}
}
