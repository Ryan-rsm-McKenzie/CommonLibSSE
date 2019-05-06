#pragma once


namespace RE
{
	template <class T>
	class hkSmallArray
	{
		enum class CapacityAndFlags : UInt16
		{
			kCapacityMask = 0x3FFF,
			kFlagMask = 0xC000,
			kNoDealloc = 0x8000,
			kLocked = 0x4000,
			kForceSigned = static_cast<UInt16>(-1)
		};


		T*					data;				// 00
		UInt16				size;				// 08
		CapacityAndFlags	capacityAndFlags;	// 0A
		UInt32				pad0C;				// 0C
	};
	STATIC_ASSERT(sizeof(hkSmallArray<void*>) == 0x10);
}
