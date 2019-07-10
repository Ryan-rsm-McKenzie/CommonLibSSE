#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ProcessLists__GetActorsFilter


namespace RE
{
	namespace ProcessLists
	{
		class GetActorsFilter
		{
		public:
			inline static const void* RTTI = RTTI_ProcessLists__GetActorsFilter;


			virtual ~GetActorsFilter();		// 00

			// add
			virtual void Unk_01(void) = 0;	// 01
		};
		STATIC_ASSERT(sizeof(GetActorsFilter) == 0x8);
	}
}
