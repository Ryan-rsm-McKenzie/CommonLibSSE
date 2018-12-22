#include "RE/TESWorldSpace.h"


namespace RE
{
	float TESWorldSpace::ObjectBounds::Bounds::X() const
	{
		return x / 4096.0;
	}


	float TESWorldSpace::ObjectBounds::Bounds::Y() const
	{
		return y / 4096.0;
	}
}
