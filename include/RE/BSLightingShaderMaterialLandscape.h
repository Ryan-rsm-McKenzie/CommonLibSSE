#pragma once

#include "RE/BSLightingShaderMaterialBase.h"  
#include "RE/BSTextureSet.h"  
#include "RE/NiColor.h" 


namespace RE
{
	class BSLightingShaderMaterialLandscape : public BSLightingShaderMaterialBase
	{
	public:
		inline static const void* RTTI = RTTI_BSLightingShaderMaterialLandscape;

		virtual ~BSLightingShaderMaterialLandscape();						// 00

		// override (BSLightingShaderMaterialBase)
		virtual BSShaderMaterial*	Create() override;						// 01
		virtual void				Copy(BSShaderMaterial* a_src) override;	// 02
		virtual void				Unk_04(void) override;					// 04
		virtual Type				GetType() const override;				// 06 - { return Type::kLandscape; }

		// override (BSLightingShaderMaterialBase)
		virtual void				ReleaseTextures(void) override; 																		//09 - ReleaseRefs	
		virtual void				Unk_0A(UInt8 unk1, UInt8 unk2, UInt8 unk3, UInt8 unk4, UInt8 unk5, UInt32 unk6, UInt32 unk7) override;	//0A - AddRefs
		virtual void				Unk_0B(void* unk1, UInt32 unk2) override;																//0B


		// members
		UInt32 uiNumLandscapeTextures;
		NiPointer<NiTexture> spLandscapeDiffuseTexture[5];
		NiPointer<NiTexture> spLandscapeNormalTexture[5];
		NiPointer<NiTexture> spTerrainOverlayTexture;
		NiPointer<NiTexture> spTerrainNoiseTexture;
		NiColorA kLandBlendParams;
		float fTextureIsSnow[6];
		float fTextureIsSpecPower[6];
		float fTerrainTexOffsetX;
		float fTerrainTexOffsetY;
		float fTerrainTexFade;

	};
	STATIC_ASSERT(sizeof(BSLightingShaderMaterialLandscape) == 0x158);
}