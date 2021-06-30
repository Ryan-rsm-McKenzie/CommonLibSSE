#pragma once

#include "RE/B/BSImagespaceShader.h"

namespace RE
{
	class BSImagespaceShaderBlur3 : public BSImagespaceShader
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSImagespaceShaderBlur3;

		~BSImagespaceShaderBlur3() override;  // 00

		// override (BSImagespaceShader)
		void Unk_0D(void) override;  // 0D
	};
	static_assert(sizeof(BSImagespaceShaderBlur3) == 0x1A8);
}
