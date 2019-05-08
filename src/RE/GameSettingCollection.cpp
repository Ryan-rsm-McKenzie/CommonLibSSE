#include "RE/GameSettingCollection.h"

#include "skse64/GameSettings.h"  // g_gameSettingCollection


namespace RE
{
	GameSettingCollection* GameSettingCollection::GetSingleton()
	{
		return *unrestricted_cast<GameSettingCollection**>(g_gameSettingCollection.GetUIntPtr());
	}


	Setting* GameSettingCollection::GetSetting(const char* a_name)
	{
		return settings.find(a_name).first;
	}
}
