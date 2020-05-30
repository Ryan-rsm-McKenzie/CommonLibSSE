#pragma once

#include "RE/BSAtomic.h"
#include "RE/IMemoryHeap.h"


namespace RE
{
	class ZeroOverheadHeap : public IMemoryHeap
	{
	public:
		inline static constexpr auto RTTI = RTTI_ZeroOverheadHeap;


		virtual ~ZeroOverheadHeap();  // 00

		// override (IMemoryHeap)
		virtual std::size_t Size(const void* a_block) const override;									   // 01
		virtual void		GetMemoryStats(MemoryStats* a_stats) override;								   // 02
		virtual bool		ContainsBlockImpl(const void* a_block) const override;						   // 03
		virtual void*		AllocateAlignImpl(std::size_t a_size, UInt32 a_alignment) override;			   // 04
		virtual const char* GetName() const override;													   // 07 - { return name; }
		virtual void*		Allocate(std::size_t a_size, UInt32 a_alignment) override;					   // 08
		virtual void		Deallocate(void* a_pointer, UInt32) override;								   // 09 - { return; }
		virtual bool		PointerInHeap(const void* a_pointer) const override;						   // 0A
		virtual std::size_t TotalSize(const void* a_pointer) const override;							   // 0B
		virtual void		GetHeapStats(HeapStats* a_stats, bool a_fullBlockInfo) override;			   // 0C
		virtual bool		ShouldTrySmallBlockPools(std::size_t a_size, MEM_CONTEXT a_context) override;  // 0D - { return 0; }
		virtual UInt32		GetPageSize() const override;												   // 0E - { return 0; }


		// members
		std::size_t		   memSize;		 // 08
		const char*		   name;		 // 10
		void*			   memoryBase;	 // 18
		void*			   nextFreeMem;	 // 20
		UInt32			   unk28;		 // 28
		mutable BSSpinLock unk2C;		 // 2C
		UInt32			   unk34;		 // 34
	};
	STATIC_ASSERT(sizeof(ZeroOverheadHeap) == 0x38);
}
