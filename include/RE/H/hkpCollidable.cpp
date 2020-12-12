#include "RE/BSHavok/hkpCdBody/hkpCollidable/hkpCollidable.h"


namespace RE
{
	void* hkpCollidable::GetOwner() const
	{
		return const_cast<void*>(adjust_pointer<const void>(this, ownerOffset));
	}
}
