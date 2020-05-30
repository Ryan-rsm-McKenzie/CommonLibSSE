#pragma once


namespace RE
{
	class BSBitFieldHeapAllocator
	{
	public:
		// members
		UInt32* data;  // 0
	};
	STATIC_ASSERT(sizeof(BSBitFieldHeapAllocator) == 0x8);


	template <class Allocator = BSBitFieldHeapAllocator>
	class BSBitField : public Allocator
	{
	public:
		union Buffer
		{
			UInt32	local;
			UInt32* heap;
		};


		// members
		Buffer buffer;
		UInt32 size;
	};
	STATIC_ASSERT(sizeof(BSBitField<>) == 0x18);
}
