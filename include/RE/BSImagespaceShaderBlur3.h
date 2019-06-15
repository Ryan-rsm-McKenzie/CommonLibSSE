#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSImagespaceShaderBlur3

#include "RE/BSImagespaceShader.h"  // BSImagespaceShader


namespace RE
{
	class BSImagespaceShaderBlur3 : public BSImagespaceShader
	{
	public:
		inline static const void* RTTI = RTTI_BSImagespaceShaderBlur3;


		virtual ~BSImagespaceShaderBlur3();	// 00

		// override (BSImagespaceShader)
		virtual void Unk_0D(void) override;	// 0D
	};
	STATIC_ASSERT(sizeof(BSImagespaceShaderBlur3) == 0x1A8);
}
