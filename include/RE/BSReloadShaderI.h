#pragma once

#include "RE/ImageSpaceEffect.h"  // ImageSpaceEffect


namespace RE
{
	class BSReloadShaderI
	{
	public:
		virtual void Unk_00(void);	// 00 - pure
	};
	STATIC_ASSERT(sizeof(BSReloadShaderI) == 0x8);
}
