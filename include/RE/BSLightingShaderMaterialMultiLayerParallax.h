#pragma once

#include "RE/BSLightingShaderMaterialBase.h"
#include "RE/NiSmartPointer.h"


namespace RE
{
	class NiSourceTexture;


	class BSLightingShaderMaterialMultiLayerParallax : public BSLightingShaderMaterialBase
	{
	public:
		inline static const void* RTTI = RTTI_BSLightingShaderMaterialMultiLayerParallax;


		virtual ~BSLightingShaderMaterialMultiLayerParallax();						// 00

		// override (BSLightingShaderMaterialBase)
		virtual BSShaderMaterial*	CreateNew() override = 0;						// 01
		virtual void				CopyMembers(BSShaderMaterial* a_src) override;	// 02
		virtual UInt32				ComputeCRC32(void) override;					// 04
		virtual Type				GetType() const override;						// 06 - { return Type::kMultilayerParallax; }
		virtual void				Unk_08(void) override;							// 08
		virtual void				Unk_09(void) override;							// 09
		virtual void				Unk_0A(void) override;							// 0A
		virtual void				Unk_0B(void) override;							// 0B
		virtual void				Unk_0C(void) override;							// 0C
		virtual void				Unk_0D(void) override;							// 0D


		// members
		NiPointer<NiSourceTexture>	layerTexture;				// A0
		NiPointer<NiSourceTexture>	envTexture;					// A8
		NiPointer<NiSourceTexture>	envMaskTexture;				// B0
		float						parallaxLayerThickness;		// B8
		float						parallaxRefractionScale;	// BC
		float						parallaxInnerLayerUScale;	// C0
		float						parallaxInnerLayerVScale;	// C4
		float						envmapScale;				// C8
		UInt32						padCC;						// CC
	};
	STATIC_ASSERT(sizeof(BSLightingShaderMaterialMultiLayerParallax) == 0xD0);
}
