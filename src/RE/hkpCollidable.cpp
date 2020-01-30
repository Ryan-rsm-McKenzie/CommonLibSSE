#include "RE/hkpCollidable.h"


namespace RE
{
	void* hkpCollidable::GetOwner() const
	{
		return const_cast<char*>(reinterpret_cast<const char*>(this) + ownerOffset);
	}
}
