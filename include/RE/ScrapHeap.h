#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ScrapHeap

#include "RE/IMemoryStore.h"  // IMemoryStore


namespace RE
{
	class ScrapHeap : public IMemoryStore
	{
	public:
		inline static const void* RTTI = RTTI_ScrapHeap;


		virtual ~ScrapHeap();														// 00

		// override (IMemoryStore)
		virtual void	Unk_01(void) override;										// 01
		virtual void	Unk_02(void) override;										// 02 - { return; }
		virtual void	Unk_03(void) override;										// 03
		virtual void*	Allocate(std::size_t a_size, UInt32 a_alignment) override;	// 04
		virtual void	Free(void* a_memory) override;								// 05

		// members
		UInt64		unk08;				// 08
		UInt64		unk10;				// 10
		UInt64		unk18;				// 18
		UInt64		unk20;				// 20
		UInt64		unk28;				// 28
		UInt64		unk30;				// 30
		UInt64		unk38;				// 38
		UInt64		unk40;				// 40
		void*		reservedMem;		// 48
		void*		unk50;				// 50
		void*		committedMemEnd;	// 58
		std::size_t	reservedSize;		// 60
		std::size_t	committedSize;		// 68
		UInt64		unk70;				// 70
		UInt64		unk78;				// 78
		UInt64		unk80;				// 80
		UInt64		unk88;				// 88
	};
	STATIC_ASSERT(sizeof(ScrapHeap) == 0x90);
}
