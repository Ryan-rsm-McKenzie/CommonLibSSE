#pragma once

#include "skse64/GameRTTI.h"  // RTTI_IMemoryHeap

#include "RE/IMemoryStore.h"  // IMemoryStore


namespace RE
{
	class IMemoryHeap : public IMemoryStore
	{
	public:
		inline static const void* RTTI = RTTI_IMemoryHeap;


		virtual ~IMemoryHeap();															// 00

		// override (IMemoryStore)
		virtual void		Unk_03(void) override;										// 03
		virtual void*		Allocate(std::size_t a_size, UInt32 a_alignment) override;	// 04
		virtual void		Free(void* a_memory) override;								// 05

		// add
		virtual const char*	GetName() = 0;												// 07
		virtual void		Unk_08(void) = 0;											// 08
		virtual void		Unk_09(void) = 0;											// 09
		virtual bool		IsCommittedInHeap(void* a_memory) = 0;						// 0A
		virtual void		Unk_0B(void) = 0;											// 0B
		virtual void		Unk_0C(void) = 0;											// 0C
		virtual void		Unk_0D(void) = 0;											// 0D
		virtual void		Unk_0E(void) = 0;											// 0E
	};
	STATIC_ASSERT(sizeof(IMemoryHeap) == 0x8);
}
