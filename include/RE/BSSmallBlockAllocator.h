#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSSmallBlockAllocator

#include "RE/IMemoryStore.h"  // IMemoryStore


namespace RE
{
	class BSSmallBlockAllocator : public IMemoryStore
	{
	public:
		inline static const void* RTTI = RTTI_BSSmallBlockAllocator;


		struct UnkData
		{
			UInt64				unk00;	// 00
			UInt64				unk08;	// 08
			UInt64				unk10;	// 10
			UInt64				unk18;	// 18
			CRITICAL_SECTION	unk20;	// 20
		};
		STATIC_ASSERT(sizeof(UnkData) == 0x48);


		virtual ~BSSmallBlockAllocator();											// 00

		// override (IMemoryStore)
		virtual	void	Unk_01(void) override;										// 01
		virtual	void	Unk_02(void) override;										// 02
		virtual	void	Unk_03(void) override;										// 03
		virtual	void*	Allocate(std::size_t a_size, UInt32 a_alignment) override;	// 04
		virtual	void	Free(void* a_memory) override;								// 05
		virtual	void	Unk_06(void) override;										// 06


		// members
		UnkData				unk0008[0x40];	// 0008
		CRITICAL_SECTION	unk1208;		// 1208
		std::size_t			memSize;		// 1230
		void*				memory;			// 1238
		UInt64				unk1240;		// 1240
		UInt64				unk1248;		// 1248
		UInt64				unk1250;		// 1250
		UInt64				unk1258;		// 1258
		UInt32				unk1260;		// 1260
		UInt8				unk1264;		// 1264
		UInt8				unk1265;		// 1265
		UInt16				unk1266;		// 1266
	};
	STATIC_ASSERT(sizeof(BSSmallBlockAllocator) == 0x1268);
}
