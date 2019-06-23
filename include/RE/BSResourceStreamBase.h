#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSResource__StreamBase


namespace RE
{
	namespace BSResource
	{
		class StreamBase
		{
		public:
			inline static const void* RTTI = RTTI_BSResource__StreamBase;


			virtual ~StreamBase();				// 00

			// add
			virtual void	Unk_01(void) = 0;	// 01
			virtual void	Unk_02(void) = 0;	// 02
			virtual void	Unk_03(void);		// 03 - { return 0; }
			virtual void	Unk_04(void);		// 04 - { return 8; }


			// members
			UInt32	unk08;	// 08
			UInt32	unk0C;	// 0C - related to ref counting
		};
		STATIC_ASSERT(sizeof(StreamBase) == 0x10);
	}
}
