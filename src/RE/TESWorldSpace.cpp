#include "RE/TESWorldSpace.h"


namespace RE
{
	float TESWorldSpace::ObjectBounds::Bounds::GetX() const
	{
		return x / 4096.0;
	}


	float TESWorldSpace::ObjectBounds::Bounds::GetY() const
	{
		return y / 4096.0;
	}


	bool TESWorldSpace::HasMaxHeightData() const
	{
		return maxHeightData != 0;
	}
}
