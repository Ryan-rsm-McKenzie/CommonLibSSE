#include "RE/GlobalLookupInfo.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	GlobalLookupInfo* GlobalLookupInfo::GetSingleton()
	{
		REL::Offset<GlobalLookupInfo*> singleton(RE::Offset::GlobalLookupInfo::Singleton);
		return singleton.GetType();
	}
}
