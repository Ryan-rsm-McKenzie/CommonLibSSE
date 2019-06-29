#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSScript__IMemoryPagePolicy


namespace RE
{
	namespace BSScript
	{
		struct IMemoryPagePolicy
		{
		public:
			inline static const void* RTTI = RTTI_BSScript__IMemoryPagePolicy;


			virtual ~IMemoryPagePolicy();		// 00

			// add
			virtual void	Unk_01(void) = 0;	// 01
			virtual void	Unk_02(void) = 0;	// 02
			virtual void	Unk_03(void) = 0;	// 03
			virtual void	Unk_04(void) = 0;	// 04
		};
		STATIC_ASSERT(sizeof(IMemoryPagePolicy) == 0x8);
	}
}
