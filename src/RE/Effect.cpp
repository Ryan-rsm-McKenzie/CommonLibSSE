#include "RE/Effect.h"


namespace RE
{
	Effect::EffectItem::EffectItem() :
		magnitude(0.0),
		area(0),
		duration(0)
	{}


	Effect::Effect() :
		effectItem(),
		pad0C(0),
		baseEffect(0),
		cost(0.0),
		pad1C(0),
		conditions()
	{}
}
