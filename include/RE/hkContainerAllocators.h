#pragma once

#include "skse64/GameRTTI.h"  // RTTI_hkContainerHeapAllocator__Allocator

#include "RE/hkMemoryAllocator.h"  // hkMemoryAllocator


namespace RE
{
	struct hkContainerHeapAllocator
	{
		struct Allocator : public hkMemoryAllocator
		{
			inline static const void* RTTI = RTTI_hkContainerHeapAllocator__Allocator;


			virtual ~Allocator();																// 00

			virtual void*	BlockAlloc(SInt32 a_numBytes) override;								// 01
			virtual void	BlockFree(void* a_ptr, SInt32 a_numBytes) override;					// 02
			virtual void*	BufAlloc(SInt32& a_reqNumBytesInOut) override;						// 03
			virtual void	BufFree(void* a_ptr, SInt32 a_numBytes) override;					// 04
			virtual void	GetMemoryStatistics(MemoryStatistics& a_usage) override;			// 08
			virtual SInt32	GetAllocatedSize(const void* a_obj, SInt32 a_numBytes) override;	// 09
		};
		STATIC_ASSERT(sizeof(Allocator) == 0x8);


		static Allocator* GetSingleton();
	};
	STATIC_ASSERT(sizeof(hkContainerHeapAllocator) == 0x1);
}
