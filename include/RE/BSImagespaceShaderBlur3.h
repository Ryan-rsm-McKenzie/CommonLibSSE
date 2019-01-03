#pragma once

#include "RE/BSImagespaceShader.h"  // BSImagespaceShader


namespace RE
{
	class BSImagespaceShaderBlur3 : public BSImagespaceShader
	{
	public:
		virtual ~BSImagespaceShaderBlur3();	// 00
	};
	STATIC_ASSERT(sizeof(BSImagespaceShaderBlur3) == 0x1A8);
}
