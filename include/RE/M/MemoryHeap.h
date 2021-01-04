#pragma once

#include "RE/A/AbstractHeap.h"

namespace RE
{
	class MemoryHeap : public AbstractHeap
	{
	public:
		inline static constexpr auto RTTI = RTTI_MemoryHeap;

		virtual ~MemoryHeap();	// 00

		// override (AbstractHeap)
		virtual std::size_t Size(const void* a_block) const override;															// 01
		virtual void*		Allocate(std::size_t a_size, std::uint32_t a_alignment) override;									// 08
		virtual void		Deallocate(void* a_pointer, std::uint32_t) override;												// 09
		virtual std::size_t TotalSize(const void* a_pointer) const override;													// 0B
		virtual void		GetHeapStats(HeapStats* a_stats, bool a_fullBlockInfo) override;									// 0C
		virtual void*		DoHeapAllocation(std::size_t a_size, std::size_t a_initialSize) override;							// 0F
		virtual void		DoHeapFree(void* a_ptr) override;																	// 10
		virtual std::size_t CreateMorePages(void* a_memory, std::size_t a_currentSize, std::size_t a_requestedBytes) override;	// 11
		virtual std::size_t CleanExtraPages(void* a_memory, std::size_t a_currentSize, std::size_t a_freeBytes) override;		// 12
		virtual void		DecommitPages(HeapBlock* a_block) override;															// 13

		// members
		bool		  deletingHeap;	 // 2A8
		std::uint8_t  pad2A9;		 // 2A9
		std::uint16_t pad2AA;		 // 2AA
		std::uint32_t pad2AC;		 // 2AC
	};
	static_assert(sizeof(MemoryHeap) == 0x2B0);
}
