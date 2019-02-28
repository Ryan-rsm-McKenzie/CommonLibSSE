#include "RE/TESSoulGem.h"


namespace RE
{
	SoulLevel TESSoulGem::GetContainedSoul() const
	{
		return containedSoul;
	}


	SoulLevel TESSoulGem::GetMaximumCapacity() const
	{
		return maximumCapacity;
	}
}
