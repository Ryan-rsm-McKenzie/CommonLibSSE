#include "RE/MagicTarget.h"

#include "RE/ActiveEffect.h"  // ActiveEffect
#include "RE/EffectSetting.h"  // EffectSetting


namespace RE
{
	bool MagicTarget::HasEffectWithArchetype(EffectSetting::Properties::Archetype a_type)
	{
		tList<ActiveEffect>* effects = GetActiveEffects();
		if (!effects) {
			return false;
		}

		ActiveEffect* effect = 0;
		EffectSetting* setting = 0;
		for (UInt32 i = 0; i < effects->Count(); ++i) {
			effect = effects->GetNthItem(i);
			setting = effect ? effect->GetBaseObject() : 0;
			if (setting && setting->HasArchetype(a_type)) {
				return true;
			}
		}
		return false;
	}


	void MagicTarget::DispellEffectsWithArchetype(EffectSetting::Properties::Archetype a_type, bool a_force)
	{
		tList<ActiveEffect>* effects = GetActiveEffects();
		if (!effects) {
			return;
		}

		ActiveEffect* effect = 0;
		EffectSetting* setting = 0;
		for (UInt32 i = 0; i < effects->Count(); ++i) {
			effect = effects->GetNthItem(i);
			setting = effect ? effect->GetBaseObject() : 0;
			if (setting && setting->HasArchetype(a_type)) {
				effect->Dispell(a_force);
			}
		}
		return;
	}
}
