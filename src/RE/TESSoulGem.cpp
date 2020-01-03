#include "RE/TESSoulGem.h"


namespace RE
{
	SOUL_LEVEL TESSoulGem::GetContainedSoul() const
	{
		return currentSoul;
	}


	SOUL_LEVEL TESSoulGem::GetMaximumCapacity() const
	{
		return soulCapacity;
	}
}
