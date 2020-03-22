#pragma once

#include "RE/BSAtomic.h"
#include "RE/IMemoryStoreBase.h"


namespace RE
{
	namespace CompactingStore
	{
		class BlockHeader;
		class FreeBlock;
		class StoreBlock;


		class Store : public IMemoryStoreBase
		{
		public:
			inline static constexpr auto RTTI = RTTI_CompactingStore__Store;


			virtual ~Store();  // 00

			// override (IMemoryStoreBase)
			virtual std::size_t Size(const void* a_block) const override;				// 01
			virtual void		GetMemoryStats(MemoryStats* a_stats) override;			// 02
			virtual bool		ContainsBlockImpl(const void* a_block) const override;	// 03


			// members
			BSNonReentrantSpinLock lock;
			void*				   allocBase;
			void*				   allocEndMin;
			void*				   allocEnd;
			void*				   storeEnd;
			BlockHeader*		   lastBlock;
			FreeBlock*			   smallFree[66];
			FreeBlock*			   currentFree;
			FreeBlock*			   nextMerge;
			StoreBlock*			   storeBlockMin;
			StoreBlock*			   nextStoreBlock;
			StoreBlock*			   freeStoreBlockList;
			UInt32				   currentThread;
			std::size_t			   allocated;
			UInt32				   numAllocatedBlocks;
			std::size_t			   free;
			UInt32				   numFreeBlocks;
			UInt32				   compacted;
			UInt32				   batchDeallocateTlsSlot;
		};
		STATIC_ASSERT(sizeof(Store) == 0x2A0);
	}
}
