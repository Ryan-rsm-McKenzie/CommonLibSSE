#pragma once

#include "skse64/GameRTTI.h"  // RTTI_IMemoryStoreBase


namespace RE
{
	class IMemoryStoreBase
	{
	public:
		inline static const void* RTTI = RTTI_IMemoryStoreBase;


		virtual ~IMemoryStoreBase();		// 00

		// add
		virtual void	Unk_01(void) = 0;	// 01
		virtual void	Unk_02(void) = 0;	// 02
		virtual void	Unk_03(void) = 0;	// 03
	};
	STATIC_ASSERT(sizeof(IMemoryStoreBase) == 0x8);
}
