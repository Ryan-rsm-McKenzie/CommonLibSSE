#include "RE/B/bhkWorld.h"

namespace RE
{
	float bhkWorld::GetWorldScale()
	{
		REL::Relocation<float*> worldScale{ REL::ID(231896) };
		return *worldScale;
	}

	float bhkWorld::GetWorldScaleInverse()
	{
		REL::Relocation<float*> worldScaleInverse{ REL::ID(230692) };
		return *worldScaleInverse;
	}
}
