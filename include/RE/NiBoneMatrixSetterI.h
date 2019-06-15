#pragma once

#include "skse64/GameRTTI.h"  // RTTI_NiBoneMatrixSetterI


namespace RE
{
	class NiBoneMatrixSetterI
	{
	public:
		inline static const void* RTTI = RTTI_NiBoneMatrixSetterI;


		virtual ~NiBoneMatrixSetterI();	// 00

		// add
		virtual void Unk_01(void);		// 01
	};
	STATIC_ASSERT(sizeof(NiBoneMatrixSetterI) == 0x8);
}
