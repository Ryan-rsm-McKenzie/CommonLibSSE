#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ImageSpaceShaderParam

#include "RE/ImageSpaceEffectParam.h"  // ImageSpaceEffectParam
#include "RE/NiTArray.h"  // NiTObjectArray
#include "RE/NiSmartPointer.h"  // NiPointer
#include "RE/NiTexture.h"  // NiTexture


namespace RE
{
	class ImageSpaceShaderParam : public ImageSpaceEffectParam
	{
	public:
		inline static const void* RTTI = RTTI_ImageSpaceShaderParam;


		virtual ~ImageSpaceShaderParam();	// 00


		// members
		UInt64									unk08;	// 08
		UInt64									unk10;	// 10
		UInt64									unk18;	// 18
		UInt64									unk20;	// 20
		UInt64									unk28;	// 28
		UInt64									unk30;	// 30
		UInt64									unk38;	// 38
		UInt64									unk40;	// 40
		UInt64									unk48;	// 48
		NiTObjectArray<NiPointer<NiTexture>>	unk50;	// 50
		NiTPrimitiveArray<UInt32>				unk68;	// 68 - NiTPrimitiveArray<enum BSGraphics::TextureFilterMode>
	};
	STATIC_ASSERT(sizeof(ImageSpaceShaderParam) == 0x80);
}
