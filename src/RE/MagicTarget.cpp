#include "RE/MagicTarget.h"

#include "RE/ActiveEffect.h"
#include "RE/EffectSetting.h"
#include "RE/BSTList.h"
#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	bool MagicTarget::HasMagicEffect(EffectSetting* a_effect)
	{
		using func_t = function_type_t<decltype(&MagicTarget::HasMagicEffect)>;
		REL::Offset<func_t*> func(Offset::MagicTarget::HasMagicEffect);
		return func(this, a_effect);
	}


	bool MagicTarget::HasEffectWithArchetype(Archetype a_type)
	{
		auto effects = GetActiveEffects();
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


	void MagicTarget::DispellEffectsWithArchetype(Archetype a_type, bool a_force)
	{
		auto effects = GetActiveEffects();
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
