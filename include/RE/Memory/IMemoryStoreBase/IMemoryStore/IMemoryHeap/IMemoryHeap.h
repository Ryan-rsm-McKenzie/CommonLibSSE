#pragma once

#include "RE/Memory/IMemoryStoreBase/IMemoryStore/IMemoryStore.h"


namespace RE
{
	enum class MEM_CONTEXT
	{
	};


	struct HeapStats
	{
	public:
		// members
		const char*	 heapName;				// 00
		std::size_t	 memHeapSize;			// 08
		std::size_t	 memHeapCommitted;		// 10
		std::size_t	 memAllocatedToBlocks;	// 18
		std::int32_t numBlocks;				// 20
		std::int32_t numFreeBlocks;			// 24
		std::size_t	 memFreeInBlocks;		// 28
		std::size_t	 memUsedInBlocks;		// 30
		std::size_t	 smallestFreeBlock;		// 38
		std::size_t	 largestFreeBlock;		// 40
		std::size_t	 heapOverhead;			// 48
		std::size_t	 freeListOverhead;		// 50
		std::size_t	 blockOverhead;			// 58
		std::size_t	 totalFree;				// 60
	};
	static_assert(sizeof(HeapStats) == 0x68);


	class IMemoryHeap : public IMemoryStore
	{
	public:
		inline static constexpr auto RTTI = RTTI_IMemoryHeap;


		virtual ~IMemoryHeap();	 // 00

		// override (IMemoryStore)
		virtual bool  ContainsBlockImpl(const void* a_block) const override;					  // 03
		virtual void* AllocateAlignImpl(std::size_t a_size, std::uint32_t a_alignment) override;  // 04
		virtual void  DeallocateAlignImpl(void* a_freeBlock) override;							  // 05

		// add
		virtual const char*	  GetName() const = 0;														// 07
		virtual void*		  Allocate(std::size_t a_size, std::uint32_t a_alignment) = 0;				// 08
		virtual void		  Deallocate(void* a_pointer, std::uint32_t) = 0;							// 09
		virtual bool		  PointerInHeap(const void* a_pointer) const = 0;							// 0A
		virtual std::size_t	  TotalSize(const void* a_pointer) const = 0;								// 0B
		virtual void		  GetHeapStats(HeapStats* a_stats, bool a_fullBlockInfo) = 0;				// 0C
		virtual bool		  ShouldTrySmallBlockPools(std::size_t a_size, MEM_CONTEXT a_context) = 0;	// 0D
		virtual std::uint32_t GetPageSize() const = 0;													// 0E
	};
	static_assert(sizeof(IMemoryHeap) == 0x8);
}
