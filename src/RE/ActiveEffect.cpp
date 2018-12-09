#include "RE/ActiveEffect.h"

#include "RE/EffectItem.h"  // EffectItem
#include "RE/Offsets.h"


namespace RE
{
	EffectSetting* ActiveEffect::GetBaseObject() const
	{
		return effect->mgef;
	}


	bool ActiveEffect::Dispell(bool a_force)
	{
		typedef bool _Dispell_t(ActiveEffect* a_this, bool a_force);
		RelocAddr<_Dispell_t*> _Dispell(ACTIVE_EFFECT_DISPELL);
		return _Dispell(this, a_force);
	}
}
