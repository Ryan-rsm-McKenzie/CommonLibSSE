#include "RE/I/INIPrefSettingCollection.h"

namespace RE
{
	INIPrefSettingCollection* INIPrefSettingCollection::GetSingleton()
	{
		REL::Relocation<INIPrefSettingCollection**> singleton{ Offset::INIPrefSettingCollection::Singleton };
		return *singleton;
	}
}
