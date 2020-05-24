#include "RE/hkpCollidable.h"


namespace RE
{
	void* hkpCollidable::GetOwner() const
	{
		return const_cast<char*>(adjust_pointer<char>(this, ownerOffset));
	}
}
