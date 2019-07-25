#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ZeroOverheadHeap

#include "RE/BSLock.h"  // BSUniqueLock
#include "RE/IMemoryHeap.h"  // IMemoryHeap


namespace RE
{
	class ZeroOverheadHeap : public IMemoryHeap
	{
	public:
		inline static const void* RTTI = RTTI_ZeroOverheadHeap;


		virtual ~ZeroOverheadHeap();													// 00

		// override (IMemoryHeap)
		virtual void		Unk_01(void) override;										// 01
		virtual void		Unk_02(void) override;										// 02
		virtual void		Unk_03(void) override;										// 03
		virtual void*		Allocate(std::size_t a_size, UInt32 a_alignment) override;	// 04
		virtual const char*	GetName() override;											// 07 - { return name; }
		virtual void		Unk_08(void) override;										// 08
		virtual void		Unk_09(void) override;										// 09 - { return; }
		virtual bool		IsCommittedInHeap(void* a_mem) override;					// 0A
		virtual void		Unk_0B(void) override;										// 0B
		virtual void		Unk_0C(void) override;										// 0C
		virtual void		Unk_0D(void) override;										// 0D - { return 0; }
		virtual void		Unk_0E(void) override;										// 0E - { return 0; }


		// members
		std::size_t				memSize;		// 08
		const char*				name;			// 10
		void*					memoryBase;		// 18
		void*					nextFreeMem;	// 20
		UInt32					unk28;			// 28
		mutable BSUniqueLock	unk2C;			// 2C
		UInt32					unk34;			// 34
	};
	STATIC_ASSERT(sizeof(ZeroOverheadHeap) == 0x38);
}
