#pragma once

#include "skse64/GameRTTI.h"  // RTTI_IMapCameraCallbacks


namespace RE
{
	struct IMapCameraCallbacks
	{
		inline static const void* RTTI = RTTI_IMapCameraCallbacks;


		// add
		virtual void	Unk_00(void);	// 00
		virtual void	Unk_01(void);	// 01

		virtual ~IMapCameraCallbacks();	// 02
	};
	STATIC_ASSERT(sizeof(IMapCameraCallbacks) == 0x8);
}
