#include "RE/BSMain/SettingCollection/INIPrefSettingCollection.h"


namespace RE
{
	INIPrefSettingCollection* INIPrefSettingCollection::GetSingleton()
	{
		REL::Offset<INIPrefSettingCollection**> singleton(Offset::INIPrefSettingCollection::Singleton);
		return *singleton;
	}
}
