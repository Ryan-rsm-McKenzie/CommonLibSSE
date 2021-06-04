#pragma once

namespace RE
{
	class BSBitFieldHeapAllocator
	{
	public:
		// members
		std::uint32_t* data;  // 0
	};
	static_assert(sizeof(BSBitFieldHeapAllocator) == 0x8);

	template <class Allocator = BSBitFieldHeapAllocator>
	class BSBitField : public Allocator
	{
	public:
		union Buffer
		{
			std::uint32_t  local;
			std::uint32_t* heap;
		};

		// members
		Buffer        buffer;
		std::uint32_t size;
	};
	static_assert(sizeof(BSBitField<>) == 0x18);
}
