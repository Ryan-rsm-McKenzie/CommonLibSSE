#pragma once

#include "skse64/GameRTTI.h"  // RTTI_hkMemoryAllocator

#include "RE/hkBaseTypes.h"  // hkResult


namespace RE
{
	class hkMemoryAllocator
	{
	public:
		inline static const void* RTTI = RTTI_hkMemoryAllocator;


		using MemoryWalkCallback = void(void* a_start, std::size_t a_size, bool a_allocated, SInt32 a_pool, void* a_param);


		enum class MemoryState : UInt32
		{
			kOK,
			kOutOfMemory
		};


		struct MemoryStatistics
		{
			static constexpr SInt64 INFINITE_SIZE = -1;


			// members
			SInt64	allocated;		// 00
			SInt64	inUse;			// 08
			SInt64	peakInUse;		// 10
			SInt64	available;		// 18
			SInt64	totalAvailable;	// 20
			SInt64	largestBlock;	// 28
		};
		STATIC_ASSERT(sizeof(MemoryStatistics) == 0x30);


		struct ExtendedInterface
		{
			virtual ~ExtendedInterface();														// 00

			// add
			virtual void		GarbageCollect() = 0;											// 01
			virtual void		IncrementalGarbageCollect(SInt32 a_numBlocks) = 0;				// 02
			virtual hkResult	SetMemorySoftLimit(std::size_t a_maxMemory) = 0;				// 03
			virtual std::size_t	GetMemorySoftLimit() const = 0;									// 04
			virtual bool		CanAllocTotal(SInt32 a_numBytes) = 0;							// 05
			virtual hkResult	WalkMemory(MemoryWalkCallback* a_callback, void* a_param) = 0;	// 06
		};
		STATIC_ASSERT(sizeof(ExtendedInterface) == 0x8);


		virtual ~hkMemoryAllocator();																	// 00

		// add
		virtual void*	BlockAlloc(SInt32 a_numBytes) = 0;												// 01
		virtual void	BlockFree(void* a_ptr, SInt32 a_numBytes) = 0;									// 02
		virtual void*	BufAlloc(SInt32& a_reqNumBytesInOut);											// 03
		virtual void	BufFree(void* a_ptr, SInt32 a_numBytes);										// 04
		virtual void*	BufRealloc(void* a_ptrOld, SInt32 a_oldNumBytes, SInt32& a_reqNumBytesInOut);	// 05
		virtual void	BlockAllocBatch(void** a_ptrsOut, SInt32 a_numPtrs, SInt32 a_blockSize);		// 06
		virtual void	BlockFreeBatch(void** a_ptrsIn, SInt32 a_numPtrs, SInt32 a_blockSize);			// 07
		virtual void	GetMemoryStatistics(MemoryStatistics& a_usage) = 0;								// 08
		virtual SInt32	GetAllocatedSize(const void* a_obj, SInt32 a_numBytes) = 0;						// 09
		virtual void	ResetPeakMemoryStatistics();													// 0A - { return; }
	};
	STATIC_ASSERT(sizeof(hkMemoryAllocator) == 0x8);
}
