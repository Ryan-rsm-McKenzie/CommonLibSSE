#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSScript__IStackCallbackSaveInterface


namespace RE
{
	namespace BSScript
	{
		class IStackCallbackSaveInterface
		{
		public:
			inline static const void* RTTI = RTTI_BSScript__IStackCallbackSaveInterface;


			virtual ~IStackCallbackSaveInterface();	// 00

			// add
			virtual void	Unk_01(void) = 0;		// 01
			virtual void	Unk_02(void) = 0;		// 02
		};
		STATIC_ASSERT(sizeof(IStackCallbackSaveInterface) == 0x8);
	}
}
