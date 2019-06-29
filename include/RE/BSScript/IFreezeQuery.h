#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSScript__IFreezeQuery


namespace RE
{
	namespace BSScript
	{
		class IFreezeQuery
		{
		public:
			inline static const void* RTTI = RTTI_BSScript__IFreezeQuery;


			virtual ~IFreezeQuery();		// 00

			// add
			virtual void Unk_01(void) = 0;	// 00
		};
		STATIC_ASSERT(sizeof(IFreezeQuery) == 0x8);
	}
}
