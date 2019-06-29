#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSScript__IProfilePolicy


namespace RE
{
	namespace BSScript
	{
		class IProfilePolicy
		{
		public:
			inline static const void* RTTI = RTTI_BSScript__IProfilePolicy;


			virtual ~IProfilePolicy();			// 00

			// add
			virtual void	Unk_01(void) = 0;	// 01
			virtual void	Unk_02(void) = 0;	// 02
			virtual void	Unk_03(void) = 0;	// 03
			virtual void	Unk_04(void) = 0;	// 04
		};
		STATIC_ASSERT(sizeof(IProfilePolicy) == 0x8);
	}
}
