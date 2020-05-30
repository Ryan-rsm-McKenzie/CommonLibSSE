#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/TESObjectMISC/TESSoulGem.h"


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
