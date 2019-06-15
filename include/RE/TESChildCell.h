#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESChildCell


namespace RE
{
	class TESChildCell
	{
	public:
		inline static const void* RTTI = RTTI_TESChildCell;


		virtual ~TESChildCell();		// 00

		// add
		virtual void Unk_01(void) = 0;	// 01
	};
	STATIC_ASSERT(sizeof(TESChildCell) == 0x8);
}
