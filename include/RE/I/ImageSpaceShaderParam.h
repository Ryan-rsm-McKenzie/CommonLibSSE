#pragma once

#include "RE/I/ImageSpaceEffectParam.h"
#include "RE/N/NiSmartPointer.h"
#include "RE/N/NiTArray.h"
#include "RE/N/NiTexture.h"

namespace RE
{
	class ImageSpaceShaderParam : public ImageSpaceEffectParam
	{
	public:
		inline static constexpr auto RTTI = RTTI_ImageSpaceShaderParam;

		~ImageSpaceShaderParam() override;  // 00

		// members
		std::uint64_t                        unk08;  // 08
		std::uint64_t                        unk10;  // 10
		std::uint64_t                        unk18;  // 18
		std::uint64_t                        unk20;  // 20
		std::uint64_t                        unk28;  // 28
		void*                                unk30;  // 30
		std::uint64_t                        unk38;  // 38
		void*                                unk40;  // 40
		std::uint64_t                        unk48;  // 48
		NiTObjectArray<NiPointer<NiTexture>> unk50;  // 50
		NiTPrimitiveArray<std::uint32_t>     unk68;  // 68 - NiTPrimitiveArray<enum BSGraphics::TextureFilterMode>
	};
	static_assert(sizeof(ImageSpaceShaderParam) == 0x80);
}
