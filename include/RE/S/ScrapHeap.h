#pragma once

#include "RE/I/IMemoryStore.h"

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

		virtual ~ScrapHeap() { WinAPI::VirtualFree(baseAddress, 0, WinAPI::MEM_RELEASE); }	// 00

		// override (IMemoryStore)
		virtual std::size_t Size(void const* a_mem) const override { return *static_cast<const std::size_t*>(a_mem) & ~(std::size_t{ 3 } << 62); }	// 01
		virtual void		GetMemoryStats(MemoryStats*) override { return; }																		// 02
		virtual bool		ContainsBlockImpl(const void* a_block) const override { return baseAddress <= a_block && a_block <= endAddress; }		// 03
		virtual void*		AllocateAlignImpl(std::size_t a_size, std::uint32_t a_alignment) override { return Allocate(a_size, a_alignment); }		// 04
		virtual void		DeallocateAlignImpl(void*& a_block) override { Deallocate(a_block), a_block = nullptr; }								// 05

		void* Allocate(std::size_t a_size, std::size_t a_alignment);
		void  Deallocate(void* a_mem);

		// members
		FreeBlock*	  smallBlocks[6]{ nullptr };  // 08
		FreeTreeNode* freeList{ nullptr };		  // 38
		Block*		  lastBlock{ nullptr };		  // 40
		void*		  baseAddress{ nullptr };	  // 48
		void*		  endAddress{ nullptr };	  // 50
		void*		  commitEnd{ nullptr };		  // 58
		std::size_t	  reserveSize{ 1 << 26 };	  // 60
		std::size_t	  minCommit{ 1 << 17 };		  // 68
		std::size_t	  totalAllocated{ 0 };		  // 70
		std::uint32_t keepPagesRequest{ 0 };	  // 78
		std::uint32_t totalFreeBlocks{ 0 };		  // 7C
		std::uint32_t freeSmallBlocks{ 0 };		  // 80
		std::uint32_t totalAllocatedBlocks{ 0 };  // 84
		std::uint32_t pmpBarrier{ 0 };			  // 88
	};
	static_assert(sizeof(ScrapHeap) == 0x90);
}
