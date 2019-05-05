#pragma once


namespace RE
{
	template <class T>
	class hkArrayBase
	{
	public:
		enum
		{
			kCapacityMask = 0x3FFFFFFF,
			kFlagMask = 0xC0000000,
			kDontDeallocFlag = (UInt32)1 << 31,
			kForceSigned = -1
		};


		T*		data;				// 00
		SInt32	size;				// 08
		SInt32	capacityAndFlags;	// 0C
	};
	STATIC_ASSERT(sizeof(hkArrayBase<void*>) == 0x10);


	template <class T, class Allocator = void>
	class hkArray : public hkArrayBase<T>
	{
	public:
	};
	STATIC_ASSERT(sizeof(hkArray<void*>) == 0x10);


	template <class T, std::size_t N, class Allocator = void>
	class hkInplaceArray : public hkArray<T, Allocator>
	{
	public:
		T storage[N];	// 10
	};
}
