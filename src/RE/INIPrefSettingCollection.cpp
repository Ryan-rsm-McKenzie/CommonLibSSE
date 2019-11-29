#include "RE/INIPrefSettingCollection.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	INIPrefSettingCollection* INIPrefSettingCollection::GetSingleton()
	{
		REL::Offset<INIPrefSettingCollection**> singleton(Offset::INIPrefSettingCollection::Singleton);
		return *singleton;
	}
}
