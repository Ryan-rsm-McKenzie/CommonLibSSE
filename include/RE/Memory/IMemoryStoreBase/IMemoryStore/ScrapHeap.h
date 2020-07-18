#pragma once

#include "RE/Memory/IMemoryStoreBase/IMemoryStore/IMemoryStore.h"


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
		static_assert(sizeof(Block) == 0x10);


		struct FreeBlock : public Block
		{
		public:
			// members
			FreeBlock* left;   // 10
			FreeBlock* right;  // 18
		};
		static_assert(sizeof(FreeBlock) == 0x20);


		struct FreeTreeNode : public Block
		{
		public:
			// members
			FreeTreeNode** root;			// 10
			FreeTreeNode*  leftNode;		// 18
			FreeTreeNode*  rightNode;		// 20
			std::size_t	   parentAndBlack;	// 28
		};
		static_assert(sizeof(FreeTreeNode) == 0x30);


		virtual ~ScrapHeap();  // 00

		// override (IMemoryStore)
		virtual std::size_t Size(const void* a_block) const override;									// 01
		virtual void		GetMemoryStats(MemoryStats* a_stats) override;								// 02 - { return; }
		virtual bool		ContainsBlockImpl(const void* a_block) const override;						// 03
		virtual void*		AllocateAlignImpl(std::size_t a_size, std::uint32_t a_alignment) override;	// 04
		virtual void		DeallocateAlignImpl(void* a_freeBlock) override;							// 05

		void* Allocate(std::size_t a_size, std::size_t a_alignment);
		void  Deallocate(void* a_mem);


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
		std::uint32_t keepPagesRequest;		 // 78
		std::uint32_t totalFreeBlocks;		 // 7C
		std::uint32_t freeSmallBlocks;		 // 80
		std::uint32_t totalAllocatedBlocks;	 // 84
		std::uint32_t pmpBarrier;			 // 88
		std::uint32_t pad8C;				 // 8C
	};
	static_assert(sizeof(ScrapHeap) == 0x90);
}
