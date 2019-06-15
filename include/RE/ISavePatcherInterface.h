#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSScript__ISavePatcherInterface


namespace RE
{
	namespace BSScript
	{
		class ISavePatcherInterface
		{
		public:
			inline static const void* RTTI = RTTI_BSScript__ISavePatcherInterface;


			virtual ~ISavePatcherInterface();	// 00

			// add
			virtual void Unk_01(void) = 0;		// 01
		};
		STATIC_ASSERT(sizeof(ISavePatcherInterface) == 0x8);
	}
}
