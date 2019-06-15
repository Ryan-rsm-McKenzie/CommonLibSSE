#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSScript__IVMDebugInterface


namespace RE
{
	namespace BSScript
	{
		class IVMDebugInterface
		{
		public:
			inline static const void* RTTI = RTTI_BSScript__IVMDebugInterface;


			virtual ~IVMDebugInterface();	// 00

			// add
			virtual void Unk_01(void) = 0;	// 01
		};
		STATIC_ASSERT(sizeof(IVMDebugInterface) == 0x8);
	}
}
