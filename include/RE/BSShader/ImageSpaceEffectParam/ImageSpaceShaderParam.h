#pragma once

#include "RE/BSShader/ImageSpaceEffectParam/ImageSpaceEffectParam.h"
#include "RE/NetImmerse/NiRefObject/NiObject/NiTexture/NiTexture.h"
#include "RE/NetImmerse/NiSmartPointer.h"
#include "RE/NetImmerse/NiTArray.h"


namespace RE
{
	class ImageSpaceShaderParam : public ImageSpaceEffectParam
	{
	public:
		inline static constexpr auto RTTI = RTTI_ImageSpaceShaderParam;


		virtual ~ImageSpaceShaderParam();  // 00


		// members
		std::uint64_t						 unk08;	 // 08
		std::uint64_t						 unk10;	 // 10
		std::uint64_t						 unk18;	 // 18
		std::uint64_t						 unk20;	 // 20
		std::uint64_t						 unk28;	 // 28
		void*								 unk30;	 // 30
		std::uint64_t						 unk38;	 // 38
		void*								 unk40;	 // 40
		std::uint64_t						 unk48;	 // 48
		NiTObjectArray<NiPointer<NiTexture>> unk50;	 // 50
		NiTPrimitiveArray<std::uint32_t>	 unk68;	 // 68 - NiTPrimitiveArray<enum BSGraphics::TextureFilterMode>
	};
	static_assert(sizeof(ImageSpaceShaderParam) == 0x80);
}
