#include "RE/ActiveEffect.h"

#include "RE/Offsets.h"


namespace RE
{
	EffectSetting* ActiveEffect::GetBaseObject() const
	{
		return effect->mgef;
	}


	bool ActiveEffect::Dispell(bool a_force)
	{
		return _Dispell(this, a_force);
	}


	RelocAddr<ActiveEffect::_Dispell_t*> ActiveEffect::_Dispell(ACTIVE_EFFECT_DISPELL);
}
