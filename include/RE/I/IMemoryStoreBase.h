#pragma once

namespace RE
{
	struct MemoryStats
	{
	public:
		// members
		const char*   name;           // 00
		std::size_t   usedSize;       // 08
		std::size_t   committedSize;  // 10
		std::size_t   reservedSize;   // 18
		std::uint32_t overhead;       // 20
		std::uint32_t pad24;          // 24
		std::size_t   freeSize;       // 28
	};
	static_assert(sizeof(MemoryStats) == 0x30);

	class IMemoryStoreBase
	{
	public:
		inline static constexpr auto RTTI = RTTI_IMemoryStoreBase;

		virtual ~IMemoryStoreBase() = default;  // 00

		// add
		virtual std::size_t Size(const void* a_mem) const = 0;                 // 01
		virtual void        GetMemoryStats(MemoryStats* a_stats) = 0;          // 02
		virtual bool        ContainsBlockImpl(const void* a_block) const = 0;  // 03
	};
	static_assert(sizeof(IMemoryStoreBase) == 0x8);
}
