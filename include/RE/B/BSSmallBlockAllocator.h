#pragma once

#include "RE/B/BSAtomic.h"
#include "RE/I/IMemoryStore.h"

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
		static_assert(sizeof(FreeBlock) == 0x8);

		struct BlockPage
		{
		public:
			// members
			BlockPage*    left;       // 00
			BlockPage*    right;      // 08
			FreeBlock*    blocks;     // 10
			std::uint16_t totalElem;  // 18
			std::uint16_t freeElem;   // 1A
			std::uint32_t pad1C;      // 1C
		};
		static_assert(sizeof(BlockPage) == 0x20);

		struct Pool
		{
		public:
			// members
			BlockPage*        pageList;              // 00
			BlockPage*        currAlloc;             // 08
			std::uint32_t     totalFreeBlocks;       // 10
			std::uint32_t     totalAllocatedBlocks;  // 14
			std::uint32_t     totalBytes;            // 18
			std::uint32_t     elementSize;           // 1C
			BSCriticalSection lock;                  // 20
		};
		static_assert(sizeof(Pool) == 0x48);
	}

	struct BlockPageInternal
	{
	public:
		// members
		BlockPageInternal*                    left;       // 00
		BlockPageInternal*                    right;      // 08
		BSSmallBlockAllocatorUtil::FreeBlock* blocks;     // 10
		std::uint16_t                         totalElem;  // 18
		std::uint16_t                         freeElem;   // 1A
		std::uint16_t                         elemSize;   // 1C
		std::uint16_t                         check;      // 1E
	};
	static_assert(sizeof(BlockPageInternal) == 0x20);

	class BSSmallBlockAllocator : public IMemoryStore
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSSmallBlockAllocator;

		struct Pool : public BSSmallBlockAllocatorUtil::Pool
		{
		public:
		};
		static_assert(sizeof(Pool) == 0x48);

		struct MegaBlockPage
		{
		public:
			// members
			char                                  mem[sizeof(BlockPageInternal[255]) * 256];  // 000000
			BlockPageInternal                     blockPages[255];                            // 1FE000
			MegaBlockPage*                        left;                                       // 1FFFE0
			MegaBlockPage*                        right;                                      // 1FFFE8
			BSSmallBlockAllocatorUtil::BlockPage* freeBlockPages;                             // 1FFFF0
			std::uint16_t                         numFreeBlockPages;                          // 1FFFF8
			std::uint16_t                         nextBlockPageAlloc;                         // 1FFFFA
			bool                                  decommitted;                                // 1FFFFC
			std::uint8_t                          pad1FFFFD;                                  // 1FFFFD
			std::uint16_t                         pad1FFFFE;                                  // 1FFFFE
		};
		static_assert(sizeof(MegaBlockPage) == 0x200000);

		~BSSmallBlockAllocator() override;  // 00

		// override (IMemoryStore)
		std::size_t Size(const void* a_block) const override;                                   // 01
		void        GetMemoryStats(MemoryStats* a_stats) override;                              // 02
		bool        ContainsBlockImpl(const void* a_block) const override;                      // 03
		void*       AllocateAlignImpl(std::size_t a_size, std::uint32_t a_alignment) override;  // 04
		void        DeallocateAlignImpl(void*& a_freeBlock) override;                           // 05
		void*       TryAllocateImpl(std::size_t a_size, std::uint32_t a_alignment) override;    // 06

		// members
		Pool              pools[64];            // 0008
		BSCriticalSection lock;                 // 1208
		std::uint32_t     addressSpaceSize;     // 1230
		std::uint32_t     pad1234;              // 1234
		char*             allocBase;            // 1238
		char*             blockPageCommitMin;   // 1240
		char*             blockPageCommit;      // 1248
		MegaBlockPage*    megaBlockPageList;    // 1250
		MegaBlockPage*    megaBlockCurrAlloc;   // 1258
		std::uint32_t     totalFreeBlockPages;  // 1260
		bool              allowDecommits;       // 1264
		std::uint8_t      pad1265;              // 1265
		std::uint16_t     pad1266;              // 1266
	};
	static_assert(sizeof(BSSmallBlockAllocator) == 0x1268);
}
