#include "RE/INISettingCollection.h"

#include "skse64/GameSettings.h"  // g_iniSettingCollection

#include <string.h>  // _stricmp


namespace RE
{
	INISettingCollection* INISettingCollection::GetSingleton()
	{
		return *unrestricted_cast<INISettingCollection**>(g_iniSettingCollection.GetUIntPtr());
	}


	Setting* INISettingCollection::GetSetting(const char* a_name)
	{
		for (auto& setting : settings) {
			if (_stricmp(setting->name, a_name) == 0) {
				return setting;
			}
		}
		return 0;
	}
}
