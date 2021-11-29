#pragma once

#include "RE/B/BSAtomic.h"
#include "RE/I/IMemoryHeap.h"

namespace RE
{
	class ZeroOverheadHeap : public IMemoryHeap
	{
	public:
		inline static constexpr auto RTTI = RTTI_ZeroOverheadHeap;

		~ZeroOverheadHeap() override;  // 00

		// override (IMemoryHeap)
		std::size_t   Size(const void* a_block) const override;                                      // 01
		void          GetMemoryStats(MemoryStats* a_stats) override;                                 // 02
		bool          ContainsBlockImpl(const void* a_block) const override;                         // 03
		void*         AllocateAlignImpl(std::size_t a_size, std::uint32_t a_alignment) override;     // 04
		const char*   GetName() const override;                                                      // 07 - { return name; }
		void*         Allocate(std::size_t a_size, std::uint32_t a_alignment) override;              // 08
		void          Deallocate(void* a_pointer, std::uint32_t) override;                           // 09 - { return; }
		bool          PointerInHeap(const void* a_pointer) const override;                           // 0A
		std::size_t   TotalSize(const void* a_pointer) const override;                               // 0B
		void          GetHeapStats(HeapStats* a_stats, bool a_fullBlockInfo) override;               // 0C
		bool          ShouldTrySmallBlockPools(std::size_t a_size, MEM_CONTEXT a_context) override;  // 0D - { return 0; }
		std::uint32_t GetPageSize() const override;                                                  // 0E - { return 0; }

		// members
		std::size_t        memSize;      // 08
		const char*        name;         // 10
		void*              memoryBase;   // 18
		void*              nextFreeMem;  // 20
		std::uint32_t      unk28;        // 28
		mutable BSSpinLock unk2C;        // 2C
		std::uint32_t      unk34;        // 34
	};
	static_assert(sizeof(ZeroOverheadHeap) == 0x38);
}
