#include "RE/EffectSetting.h"


namespace RE
{
	UInt32 EffectSetting::GetSchool()
	{
		return properties.school;
	}


	UInt32 EffectSetting::GetLevel()
	{
		return properties.level;
	}


	bool EffectSetting::HasArchetype(Properties::Archetype a_type)
	{
		return properties.archetype == a_type;
	}
}
