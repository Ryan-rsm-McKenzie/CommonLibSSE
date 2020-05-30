#include "RE/INIPrefSettingCollection.h"


namespace RE
{
	INIPrefSettingCollection* INIPrefSettingCollection::GetSingleton()
	{
		REL::Offset<INIPrefSettingCollection**> singleton(Offset::INIPrefSettingCollection::Singleton);
		return *singleton;
	}
}
