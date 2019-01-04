#include "RE/ActiveEffect.h"

#include "RE/Effect.h"  // Effect
#include "RE/Offsets.h"


namespace RE
{
	EffectSetting* ActiveEffect::GetBaseObject() const
	{
		return effect->baseEffect;
	}


	bool ActiveEffect::Dispell(bool a_force)
	{
		typedef bool _Dispell_t(ActiveEffect* a_this, bool a_force);
		RelocAddr<_Dispell_t*> _Dispell(ACTIVE_EFFECT_DISPELL);
		return _Dispell(this, a_force);
	}
}
