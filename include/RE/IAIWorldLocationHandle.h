#pragma once

#include "skse64/GameRTTI.h"  // RTTI_IAIWorldLocationHandle


namespace RE
{
	class IAIWorldLocationHandle
	{
	public:
		inline static const void* RTTI = RTTI_IAIWorldLocationHandle;


		virtual ~IAIWorldLocationHandle();	// 00

		// add
		virtual void	Unk_00(void) = 0;	// 00
		virtual void	Unk_01(void);		// 01 - { return 0; }
		virtual void	Unk_02(void) = 0;	// 02
	};
	STATIC_ASSERT(sizeof(IAIWorldLocationHandle) == 0x8);
}
