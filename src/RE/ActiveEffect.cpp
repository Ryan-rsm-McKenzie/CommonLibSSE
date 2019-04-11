#include "RE/ActiveEffect.h"

#include "RE/Effect.h"  // Effect
#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	EffectSetting* ActiveEffect::GetBaseEffect() const
	{
		return effect->baseEffect;
	}


	bool ActiveEffect::Dispell(bool a_force)
	{
		using func_t = function_type_t<decltype(&ActiveEffect::Dispell)>;
		REL::Offset<func_t*> func(Offset::ActiveEffect::Dispell);
		return func(this, a_force);
	}
}
