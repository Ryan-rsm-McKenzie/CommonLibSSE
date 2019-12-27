#pragma once

#include "RE/BSLightingShaderMaterialBase.h" 
#include "RE/BSTextureSet.h"


namespace RE
{
	class BSLightingShaderMaterialParallax : public BSLightingShaderMaterialBase
	{
	public:
		inline static const void* RTTI = RTTI_BSLightingShaderMaterialParallax;

		virtual ~BSLightingShaderMaterialParallax();						// 00

		// override (BShaderMaterialBase)
		virtual BSShaderMaterial*   Create() override;						// 01
		virtual void				Copy(BSShaderMaterial* a_src) override;	// 02
		virtual void				Unk_04(void) override;					// 04
		virtual Type				GetType() const override;				// 06 - { return Type::kParallax; }

		// override (BSLightingShaderMaterialBase)
		virtual void				SetTexture(UInt32 index, BSTextureSet* texture, SInt32 unk1) override;									//08
		virtual void				ReleaseTextures(void) override; 																		//09 - ReleaseRefs	
		virtual void				Unk_0A(UInt8 unk1, UInt8 unk2, UInt8 unk3, UInt8 unk4, UInt8 unk5, UInt32 unk6, UInt32 unk7) override;	//0A - AddRefs
		virtual void				Unk_0B(void* unk1, UInt32 unk2) override;																//0B


		// members
		NiPointer<NiTexture> spHeightTexture;
	};
	STATIC_ASSERT(sizeof(BSLightingShaderMaterialParallax) == 0xA8);
}