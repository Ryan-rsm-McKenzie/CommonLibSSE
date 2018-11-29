#include "RE/MagicTarget.h"

#include "skse64_common/Relocation.h"  // RelocAddr

#include "RE/ActiveEffect.h"  // ActiveEffect
#include "RE/EffectSetting.h"  // EffectSetting
#include "RE/BSTList.h"  // BSSimpleList
#include "RE/Offsets.h"


namespace RE
{
	bool MagicTarget::HasMagicEffect(EffectSetting* a_effect)
	{
		typedef bool _HasMagicEffect_t(MagicTarget* a_this, EffectSetting* a_effect);
		static RelocAddr<_HasMagicEffect_t*> _HasMagicEffect(MAGIC_TARGET_HAS_MAGIC_EFFECT);
		return _HasMagicEffect(this, a_effect);
	}


	bool MagicTarget::HasEffectWithArchetype(EffectSetting::Properties::Archetype a_type)
	{
		BSSimpleList<ActiveEffect*>* effects = GetActiveEffects();
		if (!effects) {
			return false;
		}

		EffectSetting* setting = 0;
		for (auto& effect : *effects) {
			setting = effect ? effect->GetBaseObject() : 0;
			if (setting && setting->HasArchetype(a_type)) {
				return true;
			}
		}
		return false;
	}


	void MagicTarget::DispellEffectsWithArchetype(EffectSetting::Properties::Archetype a_type, bool a_force)
	{
		BSSimpleList<ActiveEffect*>* effects = GetActiveEffects();
		if (!effects) {
			return;
		}

		EffectSetting* setting = 0;
		for (auto& effect : *effects) {
			setting = effect ? effect->GetBaseObject() : 0;
			if (setting && setting->HasArchetype(a_type)) {
				effect->Dispell(a_force);
			}
		}
	}
}
