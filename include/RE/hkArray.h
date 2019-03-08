#pragma once


namespace RE
{
	template <class T>
	class hkArrayBase
	{
	public:

	protected:
		enum
		{
			kCapacityMask = 0x3FFFFFFF,
			kFlagMask = 0xC0000000,
			kDontDeallocFlag = (UInt32)1 << 31,
			kForceSigned = -1
		};


		T*		data;
		SInt32	size;
		SInt32	capacityAndFlags;
	};
	STATIC_ASSERT(sizeof(hkArrayBase<void*>) == 0x10);


	template <class T, class Allocator = void>
	class hkArray : public hkArrayBase<T>
	{
	public:
	};
	STATIC_ASSERT(sizeof(hkArray<void*>) == 0x10);
}
