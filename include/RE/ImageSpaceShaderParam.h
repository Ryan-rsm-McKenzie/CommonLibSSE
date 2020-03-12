#pragma once

#include "RE/ImageSpaceEffectParam.h"
#include "RE/NiSmartPointer.h"
#include "RE/NiTArray.h"
#include "RE/NiTexture.h"


namespace RE
{
	class ImageSpaceShaderParam : public ImageSpaceEffectParam
	{
	public:
		inline static constexpr auto RTTI = RTTI_ImageSpaceShaderParam;


		virtual ~ImageSpaceShaderParam();  // 00


		// members
		UInt64								 unk08;	 // 08
		UInt64								 unk10;	 // 10
		UInt64								 unk18;	 // 18
		UInt64								 unk20;	 // 20
		UInt64								 unk28;	 // 28
		void*								 unk30;	 // 30
		UInt64								 unk38;	 // 38
		void*								 unk40;	 // 40
		UInt64								 unk48;	 // 48
		NiTObjectArray<NiPointer<NiTexture>> unk50;	 // 50
		NiTPrimitiveArray<UInt32>			 unk68;	 // 68 - NiTPrimitiveArray<enum BSGraphics::TextureFilterMode>
	};
	STATIC_ASSERT(sizeof(ImageSpaceShaderParam) == 0x80);
}
