#pragma once

#include "skse64/GameRTTI.h"  // RTTI_MemoryHeap

#include "RE/AbstractHeap.h"  // AbstractHeap


namespace RE
{
	class MemoryHeap : public AbstractHeap
	{
	public:
		inline static const void* RTTI = RTTI_MemoryHeap;


		virtual ~MemoryHeap();					// 00

		// override (AbstractHeap)
		virtual void	Unk_01(void) override;	// 01
		virtual void	Unk_08(void) override;	// 08
		virtual void	Unk_09(void) override;	// 09
		virtual void	Unk_0B(void) override;	// 0B
		virtual void	Unk_0C(void) override;	// 0C
		virtual void	Unk_0F(void) override;	// 0F
		virtual void	Unk_10(void) override;	// 10
		virtual void	Unk_11(void) override;	// 11
		virtual void	Unk_12(void) override;	// 12
		virtual void	Unk_13(void) override;	// 13


		// members
		bool	unk2A8;	// 2A8
		UInt8	unk2A9;	// 2A9
		UInt16	unk2AA;	// 2AA
		UInt32	unk2AC;	// 2AC
	};
	STATIC_ASSERT(sizeof(MemoryHeap) == 0x2B0);
}
