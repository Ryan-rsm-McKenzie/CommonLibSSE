#include "RE/B/bhkWorld.h"

namespace RE
{
	float bhkWorld::GetWorldScale()
	{
		REL::Relocation<float*> worldScale{ Offset::bhkWorld::WorldScale };
		return *worldScale;
	}

	float bhkWorld::GetWorldScaleInverse()
	{
		REL::Relocation<float*> worldScaleInverse{ Offset::bhkWorld::WorldScaleInverse };
		return *worldScaleInverse;
	}
}
