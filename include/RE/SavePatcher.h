#pragma once

#include "skse64/GameRTTI.h"  // RTTI_SkyrimScript__SavePatcher


namespace RE
{
	namespace SkyrimScript
	{
		class SavePatcher
		{
		public:
			inline static const void* RTTI = RTTI_SkyrimScript__SavePatcher;


			virtual ~SavePatcher();	// 00
		};
		STATIC_ASSERT(sizeof(SavePatcher) == 0x8);
	}
}
