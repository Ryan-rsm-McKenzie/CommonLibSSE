#pragma once


namespace RE
{
	struct MemoryStats
	{
	public:
		// members
		const char* name;			// 00
		std::size_t usedSize;		// 08
		std::size_t committedSize;	// 10
		std::size_t reservedSize;	// 18
		UInt32		overhead;		// 20
		UInt32		pad24;			// 24
		std::size_t freeSize;		// 28
	};
	STATIC_ASSERT(sizeof(MemoryStats) == 0x30);


	class IMemoryStoreBase
	{
	public:
		inline static constexpr auto RTTI = RTTI_IMemoryStoreBase;


		virtual ~IMemoryStoreBase();  // 00

		// add
		virtual std::size_t Size(const void* a_block) const = 0;			   // 01
		virtual void		GetMemoryStats(MemoryStats* a_stats) = 0;		   // 02
		virtual bool		ContainsBlockImpl(const void* a_block) const = 0;  // 03
	};
	STATIC_ASSERT(sizeof(IMemoryStoreBase) == 0x8);
}
