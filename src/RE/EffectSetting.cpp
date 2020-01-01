#include "RE/EffectSetting.h"


namespace RE
{
	ActorValue EffectSetting::GetMagickSkill() const
	{
		return data.associatedSkill;
	}


	UInt32 EffectSetting::GetMinimumSkillLevel() const
	{
		return data.minimumSkill;
	}


	bool EffectSetting::HasArchetype(Archetype a_type) const
	{
		return data.archetype == a_type;
	}
}
