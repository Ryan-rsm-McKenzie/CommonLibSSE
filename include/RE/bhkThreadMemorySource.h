#pragma once

#include "skse64/GameRTTI.h"  // RTTI_bhkThreadMemorySource

#include "RE/hkMemoryAllocator.h"  // hkMemoryAllocator
#include "RE/IMemoryHeap.h"  // IMemoryHeap


namespace RE
{
	class bhkThreadMemorySource :
		public hkMemoryAllocator,	// 00
		public IMemoryHeap			// 08
	{
	public:
		inline static const void* RTTI = RTTI_bhkThreadMemorySource;


		virtual ~bhkThreadMemorySource();																			// 00

		// override (hkMemoryAllocator)
		virtual void*		BlockAlloc(SInt32 a_numBytes) override;													// 01
		virtual void		BlockFree(void* a_ptr, SInt32 a_numBytes) override;										// 02
		virtual void*		BufAlloc(SInt32& a_reqNumBytesInOut) override;											// 03
		virtual void		BufFree(void* a_ptr, SInt32 a_numBytes) override;										// 04
		virtual void*		BufRealloc(void* a_ptrOld, SInt32 a_oldNumBytes, SInt32& a_reqNumBytesInOut) override;	// 05
		virtual void		BlockAllocBatch(void** a_ptrsOut, SInt32 a_numPtrs, SInt32 a_blockSize) override;		// 06
		virtual void		BlockFreeBatch(void** a_ptrsIn, SInt32 a_numPtrs, SInt32 a_blockSize) override;			// 07
		virtual void		GetMemoryStatistics(MemoryStatistics& a_usage) override;								// 08
		virtual SInt32		GetAllocatedSize(const void* a_obj, SInt32 a_numBytes) override;						// 09

		// override (IMemoryHeap)
		virtual void		Unk_01(void) override;																	// 01
		virtual void		Unk_02(void) override;																	// 02
		virtual const char*	GetName() override;																		// 07 - { return bhkThreadMemorySource; }
		virtual void		Unk_08(void) override;																	// 08
		virtual void		Unk_09(void) override;																	// 09
		virtual bool		IsCommittedInHeap(void* a_memory) override;												// 0A
		virtual void		Unk_0B(void) override;																	// 0B
		virtual void		Unk_0C(void) override;																	// 0C
		virtual void		Unk_0D(void) override;																	// 0D
		virtual void		Unk_0E(void) override;																	// 0E


		// members
		CRITICAL_SECTION	unk10;				// 10
		UInt64				unk38;				// 38
		UInt64				unk40;				// 40
		UInt64				unk48;				// 48
		UInt64				unk50;				// 50
		UInt64				unk58;				// 58
		UInt64				unk60;				// 60
		UInt64				unk68;				// 68
		void*				reservedMem;		// 70
		void*				committedMem;		// 78
		UInt64				unk80;				// 80
		UInt64				unk88;				// 88
		UInt64				unk90;				// 90
		UInt64				unk98;				// 98
		UInt64				unkA0;				// A0
		UInt64				unkA8;				// A8
		UInt64				unkB0;				// B0
		UInt32				reservedMemSize;	// B8
		UInt32				unkBC;				// BC
		UInt32				unkC0;				// C0
		UInt32				unkC4;				// C4
		UInt32				unkC8;				// C8
		UInt32				unkCC;				// CC
		UInt8				unkD0;				// D0
		UInt8				unkD1;				// D1
		UInt16				unkD2;				// D2
		UInt32				unkD4;				// D4
	};
	STATIC_ASSERT(sizeof(bhkThreadMemorySource) == 0xD8);
}
