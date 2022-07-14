#include "RE/H/hkpWorldObject.h"

#include "RE/T/TESHavokUtilities.h"

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

	const hkpShape* hkpWorldObject::GetShape() const
	{
		const auto hkpCollidable = GetCollidable();
		return hkpCollidable ? hkpCollidable->GetShape() : nullptr;
	}

	TESObjectREFR* hkpWorldObject::GetUserData() const
	{
		const auto hkpCollidable = GetCollidable();
		return hkpCollidable ? TESHavokUtilities::FindCollidableRef(*hkpCollidable) : nullptr;
	}
}
