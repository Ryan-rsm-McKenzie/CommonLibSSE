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

	void* hkpWorldObject::GetPropertyValue(std::uint32_t a_key) const
	{
		auto size = properties.size();
		if (size > 0) {
			for (auto property : properties) {
				if (property.key == a_key) {
					return reinterpret_cast<void*>(property.value.data);
				}
			}
		}

		return nullptr;
	}
}
