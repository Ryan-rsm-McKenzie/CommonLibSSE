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

	std::uint64_t hkpWorldObject::GetPropertyValue(std::uint32_t a_key) const
	{
		auto size = this->properties.size();
		if (size > 0) {
			for (auto property : this->properties) {
				if (property.key == a_key) {
					return property.value.data;
				}
			}
		}

		return 0;
	}
}
