#pragma once

#include "RE/IMemoryStore.h"


namespace RE
{
	class ScrapHeap : public IMemoryStore
	{
	public:
		inline static constexpr auto RTTI = RTTI_ScrapHeap;


		struct Block
		{
		public:
			// members
			std::size_t sizeFlags;	// 00
			Block*		prev;		// 08
		};
		STATIC_ASSERT(sizeof(Block) == 0x10);


		struct FreeBlock : public Block
		{
		public:
			// members
			FreeBlock* left;   // 10
			FreeBlock* right;  // 18
		};
		STATIC_ASSERT(sizeof(FreeBlock) == 0x20);


		struct FreeTreeNode : public Block
		{
		public:
			// members
			FreeTreeNode** root;			// 10
			FreeTreeNode*  leftNode;		// 18
			FreeTreeNode*  rightNode;		// 20
			std::size_t	   parentAndBlack;	// 28
		};
		STATIC_ASSERT(sizeof(FreeTreeNode) == 0x30);


		virtual ~ScrapHeap();  // 00

		// override (IMemoryStore)
		virtual std::size_t Size(const void* a_block) const override;							 // 01
		virtual void		GetMemoryStats(MemoryStats* a_stats) override;						 // 02 - { return; }
		virtual bool		ContainsBlockImpl(const void* a_block) const override;				 // 03
		virtual void*		AllocateAlignImpl(std::size_t a_size, UInt32 a_alignment) override;	 // 04
		virtual void		DeallocateAlignImpl(void* a_freeBlock) override;					 // 05


		// members
		FreeBlock*	  smallBlocks[6];		 // 08
		FreeTreeNode* freeList;				 // 38
		Block*		  lastBlock;			 // 40
		void*		  baseAddress;			 // 48
		void*		  endAddress;			 // 50
		void*		  commitEnd;			 // 58
		std::size_t	  reserveSize;			 // 60
		std::size_t	  minCommit;			 // 68
		std::size_t	  totalAllocated;		 // 70
		UInt32		  keepPagesRequest;		 // 78
		UInt32		  totalFreeBlocks;		 // 7C
		UInt32		  freeSmallBlocks;		 // 80
		UInt32		  totalAllocatedBlocks;	 // 84
		UInt32		  pmpBarrier;			 // 88
		UInt32		  pad8C;				 // 8C
	};
	STATIC_ASSERT(sizeof(ScrapHeap) == 0x90);
}
