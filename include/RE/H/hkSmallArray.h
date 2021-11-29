#pragma once

namespace RE
{
	template <class T>
	class hkSmallArray
	{
		enum class CapacityAndFlags
		{
			kCapacityMask = 0x3FFF,
			kFlagMask = 0xC000,
			kNoDealloc = 0x8000,
			kLocked = 0x4000,
			kForceSigned = static_cast<std::underlying_type_t<CapacityAndFlags>>(-1)
		};

		T*                                                data;              // 00
		std::uint16_t                                     size;              // 08
		stl::enumeration<CapacityAndFlags, std::uint16_t> capacityAndFlags;  // 0A
		std::uint32_t                                     pad0C;             // 0C
	};
	static_assert(sizeof(hkSmallArray<void*>) == 0x10);
}
