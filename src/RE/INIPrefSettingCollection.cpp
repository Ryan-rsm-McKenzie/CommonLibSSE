#include "RE/INIPrefSettingCollection.h"

#include "skse64/GameSettings.h"  // g_iniPrefSettingCollection


namespace RE
{
	INIPrefSettingCollection* INIPrefSettingCollection::GetSingleton()
	{
		return *unrestricted_cast<INIPrefSettingCollection**>(g_iniPrefSettingCollection.GetUIntPtr());
	}
}
