#include "RE/INISettingCollection.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	INISettingCollection* INISettingCollection::GetSingleton()
	{
		REL::Offset<INISettingCollection**> singleton(Offset::INISettingCollection::Singleton);
		return *singleton;
	}


	Setting* INISettingCollection::GetSetting(const char* a_name)
	{
		for (auto& setting : settings) {
			if (_stricmp(setting->name, a_name) == 0) {
				return setting;
			}
		}
		return nullptr;
	}
}
