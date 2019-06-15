#pragma once

#include "skse64/GameRTTI.h"  // RTTI_hkBaseObject


namespace RE
{
	class hkBaseObject
	{
	public:
		inline static const void* RTTI = RTTI_hkBaseObject;


		virtual ~hkBaseObject();	// 00
	};
	STATIC_ASSERT(sizeof(hkBaseObject) == 0x8);
}
