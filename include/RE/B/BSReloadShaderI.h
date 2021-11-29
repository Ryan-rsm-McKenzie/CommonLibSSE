#pragma once

#include "RE/I/ImageSpaceEffect.h"

namespace RE
{
	class BSReloadShaderI
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSReloadShaderI;

		virtual void Unk_00(void) = 0;  // 00
	};
	static_assert(sizeof(BSReloadShaderI) == 0x8);
}
