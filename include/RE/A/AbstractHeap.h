#pragma once

#include "RE/B/BSAtomic.h"
#include "RE/I/IMemoryHeap.h"

namespace RE
{
	class HeapBlock;
	class HeapBlockFreeHead;

	class AbstractHeap : public IMemoryHeap
	{
	public:
		inline static constexpr auto RTTI = RTTI_AbstractHeap;

		virtual ~AbstractHeap();  // 00

		// override (IMemoryHeap)
		virtual void		  GetMemoryStats(MemoryStats* a_stats) override;								 // 02
		virtual void*		  AllocateAlignImpl(std::size_t a_size, std::uint32_t a_alignment) override;	 // 04
		virtual void*		  TryAllocateImpl(std::size_t a_size, std::uint32_t a_alignment) override;		 // 06
		virtual const char*	  GetName() const override;														 // 07 - { return name; }
		virtual bool		  PointerInHeap(const void* a_pointer) const override;							 // 0A
		virtual void		  GetHeapStats(HeapStats* a_stats, bool a_fullBlockInfo) override;				 // 0C
		virtual bool		  ShouldTrySmallBlockPools(std::size_t a_size, MEM_CONTEXT a_context) override;	 // 0D - { return true; }
		virtual std::uint32_t GetPageSize() const override;													 // 0E - { return pageSize; }

		// add
		virtual void*		DoHeapAllocation(std::size_t a_size, std::size_t a_initialSize) = 0;					   // 0F
		virtual void		DoHeapFree(void* a_ptr) = 0;															   // 10
		virtual std::size_t CreateMorePages(void* a_memory, std::size_t a_currentSize, std::size_t a_requestedBytes);  // 11 - { return 0; }
		virtual std::size_t CleanExtraPages(void* a_memory, std::size_t a_currentSize, std::size_t a_freeBytes);	   // 12 - { return 0; }
		virtual void		DecommitPages(HeapBlock* a_block);														   // 13 - { return; }
		virtual void		CommitPages(HeapBlock*, std::size_t);													   // 14 - { return; }

		// members
		BSCriticalSection  criticalSection;		// 008
		const char*		   name;				// 030
		std::size_t		   minFreeBlockSize;	// 038
		std::uint32_t	   pageSize;			// 040
		std::uint32_t	   pageSizeFlag;		// 040
		std::size_t		   memHeapSize;			// 048
		std::size_t		   initialSize;			// 050
		std::size_t		   currentSize;			// 058
		std::size_t		   wastedMemory;		// 060
		std::size_t		   memAllocated;		// 068
		std::size_t		   memAllocatedHigh;	// 070
		std::size_t		   blockMemAllocated;	// 078
		char*			   memHeap;				// 080
		std::int32_t	   numBlocks;			// 088
		std::uint32_t	   pad08C;				// 08C
		HeapBlock*		   blockHead;			// 090
		HeapBlock*		   blockTail;			// 098
		std::int32_t	   numFreeBlocks;		// 0A0
		bool			   allowDecommits;		// 0A4
		bool			   supportsSwapping;	// 0A5
		std::uint16_t	   pad0A0;				// 0A6
		HeapBlock*		   smallFreeLists[32];	// 0A8
		HeapBlockFreeHead* largeFreeTrees[32];	// 1A8
	};
	static_assert(sizeof(AbstractHeap) == 0x2A8);
}
