#pragma once

#include "RE/BSLightingShaderMaterialBase.h" 
#include "RE/BSTextureSet.h"  


namespace RE
{
	class BSLightingShaderMaterialMultiLayerParallax : public BSLightingShaderMaterialBase
	{
	public:
		inline static const void* RTTI = RTTI_BSLightingShaderMaterialMultiLayerParallax;


		virtual ~BSLightingShaderMaterialMultiLayerParallax();						// 00

		// override (BSShaderMaterial)
		virtual BSShaderMaterial*   Create() override;						// 01
		virtual void				Copy(BSShaderMaterial* a_src) override;	// 02
		virtual void				Unk_04(void) override;					// 04
		virtual Type				GetType() const override;				// 06 - { return Type::kMultilayerParallax; }

		// override (BSLightingShaderMaterialBase)
		virtual void				SetTexture(UInt32 index, BSTextureSet* texture, SInt32 unk1) override;									//08
		virtual void				ReleaseTextures(void) override; 																		//09 - ReleaseRefs	
		virtual void				Unk_0A(UInt8 unk1, UInt8 unk2, UInt8 unk3, UInt8 unk4, UInt8 unk5, UInt32 unk6, UInt32 unk7) override;	//0A - AddRefs
		virtual void				Unk_0B(void* unk1, UInt32 unk2) override;																//0B
		virtual void				Unk_0C(void) override;																					//0C
		virtual void				Unk_0D(void) override;																					//0D


		// members
		NiPointer<NiTexture> spLayerTexture;			// A0
		NiPointer<NiTexture> spEnvTexture;				// A8
		NiPointer<NiTexture> spEnvMaskTexture;			// B0
		float fParallaxLayerThickness;					// B8
		float fParallaxRefractionScale;					// BC
		float fParallaxInnerLayerUScale;				// C0
		float fParallaxInnerLayerVScale;				// C4
		float fEnvmapScale;								// C8
	};
	STATIC_ASSERT(sizeof(BSLightingShaderMaterialMultiLayerParallax) == 0xD0);
}
