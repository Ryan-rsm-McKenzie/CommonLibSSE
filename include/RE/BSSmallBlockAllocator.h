#pragma once

#include "RE/BSAtomic.h"
#include "RE/IMemoryStore.h"


namespace RE
{
	namespace BSSmallBlockAllocatorUtil
	{
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


		struct Pool
		{
		public:
			// members
			BlockPage*		  pageList;				 // 00
			BlockPage*		  currAlloc;			 // 08
			UInt32			  totalFreeBlocks;		 // 10
			UInt32			  totalAllocatedBlocks;	 // 14
			UInt32			  totalBytes;			 // 18
			UInt32			  elementSize;			 // 1C
			BSCriticalSection lock;					 // 20
		};
		STATIC_ASSERT(sizeof(Pool) == 0x48);
	}


	struct BlockPageInternal
	{
	public:
		// members
		BlockPageInternal*					  left;		  // 00
		BlockPageInternal*					  right;	  // 08
		BSSmallBlockAllocatorUtil::FreeBlock* blocks;	  // 10
		UInt16								  totalElem;  // 18
		UInt16								  freeElem;	  // 1A
		UInt16								  elemSize;	  // 1C
		UInt16								  check;	  // 1E
	};
	STATIC_ASSERT(sizeof(BlockPageInternal) == 0x20);


	class BSSmallBlockAllocator : public IMemoryStore
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSSmallBlockAllocator;


		struct Pool : public BSSmallBlockAllocatorUtil::Pool
		{
		public:
		};
		STATIC_ASSERT(sizeof(Pool) == 0x48);


		struct MegaBlockPage
		{
		public:
			// members
			char								  mem[sizeof(BlockPageInternal[255]) * 256];  // 000000
			BlockPageInternal					  blockPages[255];							  // 1FE000
			MegaBlockPage*						  left;										  // 1FFFE0
			MegaBlockPage*						  right;									  // 1FFFE8
			BSSmallBlockAllocatorUtil::BlockPage* freeBlockPages;							  // 1FFFF0
			UInt16								  numFreeBlockPages;						  // 1FFFF8
			UInt16								  nextBlockPageAlloc;						  // 1FFFFA
			bool								  decommitted;								  // 1FFFFC
			UInt8								  pad1FFFFD;								  // 1FFFFD
			UInt16								  pad1FFFFE;								  // 1FFFFE
		};
		STATIC_ASSERT(sizeof(MegaBlockPage) == 0x200000);


		virtual ~BSSmallBlockAllocator();  // 00

		// override (IMemoryStore)
		virtual std::size_t Size(const void* a_block) const override;							 // 01
		virtual void		GetMemoryStats(MemoryStats* a_stats) override;						 // 02
		virtual bool		ContainsBlockImpl(const void* a_block) const override;				 // 03
		virtual void*		AllocateAlignImpl(std::size_t a_size, UInt32 a_alignment) override;	 // 04
		virtual void		DeallocateAlignImpl(void* a_freeBlock) override;					 // 05
		virtual void*		TryAllocateImpl(std::size_t a_size, UInt32 a_alignment) override;	 // 06


		// members
		Pool			  pools[64];			// 0008
		BSCriticalSection lock;					// 1208
		UInt32			  addressSpaceSize;		// 1230
		UInt32			  pad1234;				// 1234
		char*			  allocBase;			// 1238
		char*			  blockPageCommitMin;	// 1240
		char*			  blockPageCommit;		// 1248
		MegaBlockPage*	  megaBlockPageList;	// 1250
		MegaBlockPage*	  megaBlockCurrAlloc;	// 1258
		UInt32			  totalFreeBlockPages;	// 1260
		bool			  allowDecommits;		// 1264
		UInt8			  pad1265;				// 1265
		UInt16			  pad1266;				// 1266
	};
	STATIC_ASSERT(sizeof(BSSmallBlockAllocator) == 0x1268);
}
