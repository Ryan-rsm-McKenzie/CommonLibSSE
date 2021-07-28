#include "RE/H/hkpWorldObject.h"

namespace RE
{
	const hkpCollidable* hkpWorldObject::GetCollidable() const
	{
		return &collidable;
	}

	hkpCollidable* hkpWorldObject::GetCollidableRW()
	{
		return &collidable;
	}
}
