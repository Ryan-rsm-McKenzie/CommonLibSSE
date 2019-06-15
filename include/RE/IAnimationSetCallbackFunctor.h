#pragma once

#include "skse64/GameRTTI.h"  // RTTI_IAnimationSetCallbackFunctor


namespace RE
{
	class IAnimationSetCallbackFunctor
	{
	public:
		inline static const void* RTTI = RTTI_IAnimationSetCallbackFunctor;


		virtual ~IAnimationSetCallbackFunctor();	// 00

		// add
		virtual void Unk_01(void);					// 01
	};
	STATIC_ASSERT(sizeof(IAnimationSetCallbackFunctor) == 0x8);
}
