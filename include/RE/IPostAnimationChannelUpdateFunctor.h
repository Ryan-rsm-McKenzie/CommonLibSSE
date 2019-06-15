#pragma once

#include "skse64/GameRTTI.h"  // RTTI_IPostAnimationChannelUpdateFunctor


namespace RE
{
	class IPostAnimationChannelUpdateFunctor
	{
	public:
		inline static const void* RTTI = RTTI_IPostAnimationChannelUpdateFunctor;


		virtual ~IPostAnimationChannelUpdateFunctor();	// 00

		// add
		virtual void Unk_01(void);						// 01
	};
	STATIC_ASSERT(sizeof(IPostAnimationChannelUpdateFunctor) == 0x8);
}
