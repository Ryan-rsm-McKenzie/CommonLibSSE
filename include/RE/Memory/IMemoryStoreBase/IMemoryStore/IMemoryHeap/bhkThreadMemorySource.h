#pragma once

#include "RE/IMemoryHeap.h"
#include "RE/hkMemoryAllocator.h"


namespace RE
{
	class HeapBlock;
	class HeapBlockFreeHead;


	class bhkThreadMemorySource :
		public hkMemoryAllocator,  // 00
		public IMemoryHeap		   // 08
	{
	public:
		inline static constexpr auto RTTI = RTTI_bhkThreadMemorySource;


		struct FreeBlock
		{
		public:
			// members
			FreeBlock* next;  // 0
		};
		STATIC_ASSERT(sizeof(FreeBlock) == 0x8);


		struct BlockPage
		{
		public:
			// members
			BlockPage* left;	   // 00
			BlockPage* right;	   // 08
			FreeBlock* blocks;	   // 10
			UInt16	   totalElem;  // 18
			UInt16	   freeElem;   // 1A
			UInt32	   pad1C;	   // 1C
		};
		STATIC_ASSERT(sizeof(BlockPage) == 0x20);


		struct Row
		{
		public:
			// members
			BlockPage* pageList;			  // 00
			BlockPage* currAlloc;			  // 08
			SInt32	   totalFreeBlocks;		  // 10
			SInt32	   totalAllocatedBlocks;  // 14
			SInt32	   totalBytes;			  // 18
			SInt32	   elemSize;			  // 1C
		};
		STATIC_ASSERT(sizeof(Row) == 0x20);


		struct MegaBlockPage
		{
		public:
			// members
			char		   mem[sizeof(BlockPage[255]) * 256];  // 000000
			BlockPage	   blockPages[255];					   // 1FE000
			MegaBlockPage* left;							   // 1FFFE0
			MegaBlockPage* right;							   // 1FFFE8
			BlockPage*	   freeBlockPages;					   // 1FFFF0
			UInt16		   numFreeBlockPages;				   // 1FFFF8
			UInt16		   nextBlockPageAlloc;				   // 1FFFFA
			bool		   decommitted;						   // 1FFFFC
			UInt8		   pad1FFFFD;						   // 1FFFFD
			UInt16		   pad1FFFFE;						   // 1FFFFE
		};
		STATIC_ASSERT(sizeof(MegaBlockPage) == 0x200000);


		virtual ~bhkThreadMemorySource();  // 00

		// override (hkMemoryAllocator)
		virtual void*  BlockAlloc(SInt32 a_numBytes) override;												   // 01
		virtual void   BlockFree(void* a_ptr, SInt32 a_numBytes) override;									   // 02
		virtual void*  BufAlloc(SInt32& a_reqNumBytesInOut) override;										   // 03
		virtual void   BufFree(void* a_ptr, SInt32 a_numBytes) override;									   // 04
		virtual void*  BufRealloc(void* a_ptrOld, SInt32 a_oldNumBytes, SInt32& a_reqNumBytesInOut) override;  // 05
		virtual void   BlockAllocBatch(void** a_ptrsOut, SInt32 a_numPtrs, SInt32 a_blockSize) override;	   // 06
		virtual void   BlockFreeBatch(void** a_ptrsIn, SInt32 a_numPtrs, SInt32 a_blockSize) override;		   // 07
		virtual void   GetMemoryStatistics(MemoryStatistics& a_usage) override;								   // 08
		virtual SInt32 GetAllocatedSize(const void* a_obj, SInt32 a_numBytes) override;						   // 09

		// override (IMemoryHeap)
		virtual std::size_t Size(const void* a_block) const override;									   // 01
		virtual void		GetMemoryStats(MemoryStats* a_stats) override;								   // 02
		virtual const char* GetName() const override;													   // 07 - { return "bhkThreadMemorySource"; }
		virtual void*		Allocate(std::size_t a_size, UInt32 a_alignment) override;					   // 08
		virtual void		Deallocate(void* a_pointer, UInt32) override;								   // 09
		virtual bool		PointerInHeap(const void* a_pointer) const override;						   // 0A
		virtual std::size_t TotalSize(const void* a_pointer) const override;							   // 0B
		virtual void		GetHeapStats(HeapStats* a_stats, bool a_fullBlockInfo) override;			   // 0C
		virtual bool		ShouldTrySmallBlockPools(std::size_t a_size, MEM_CONTEXT a_context) override;  // 0D
		virtual UInt32		GetPageSize() const override;												   // 0E


		// members
		BSCriticalSection  lock;					// 10
		Row*			   rows;					// 38
		UInt16*			   smallRowIndexes;			// 40
		UInt16*			   largeRowIndexes;			// 48
		HeapBlock**		   lists;					// 50
		HeapBlockFreeHead* largeFreeTrees;			// 58
		HeapBlock*		   firstBlock;				// 60
		HeapBlock*		   lastBlock;				// 68
		void*			   memoryRoot;				// 70
		char*			   allocBase;				// 78
		char*			   blockStart;				// 80
		char*			   allocEnd;				// 88
		char*			   commitEnd;				// 90
		char*			   blockPageCommit;			// 98
		char*			   addressSpaceEnd;			// A0
		MegaBlockPage*	   megaBlockPageList;		// A8
		MegaBlockPage*	   currMegaBlockPageAlloc;	// B0
		SInt32			   addressSpaceSize;		// B8
		SInt32			   totalFreeBlockPages;		// BC
		UInt32			   usedRows;				// C0
		SInt32			   totalAllocated;			// C4
		SInt32			   totalFreeBlocks;			// C8
		SInt32			   totalBlocks;				// CC
		bool			   allowDecommits;			// D0
		UInt8			   padD1;					// D1
		UInt16			   padD2;					// D2
		UInt32			   padD4;					// D4
	};
	STATIC_ASSERT(sizeof(bhkThreadMemorySource) == 0xD8);
}
