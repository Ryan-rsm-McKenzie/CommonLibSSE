#include "RE/GameSettingCollection.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	GameSettingCollection* GameSettingCollection::GetSingleton()
	{
		REL::Offset<GameSettingCollection**> singleton(Offset::GameSettingCollection::Singleton);
		return *singleton;
	}


	Setting* GameSettingCollection::GetSetting(const char* a_name)
	{
		return settings.find(a_name).first;
	}
}
