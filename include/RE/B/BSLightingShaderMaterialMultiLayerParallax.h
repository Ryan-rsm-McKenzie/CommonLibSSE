#pragma once

#include "RE/B/BSLightingShaderMaterialBase.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class NiSourceTexture;

	class BSLightingShaderMaterialMultiLayerParallax : public BSLightingShaderMaterialBase
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSLightingShaderMaterialMultiLayerParallax;

		~BSLightingShaderMaterialMultiLayerParallax() override;  // 00

		// override (BSLightingShaderMaterialBase)
		BSShaderMaterial* Create() override;                              // 01
		void              CopyMembers(BSShaderMaterial* a_src) override;  // 02
		std::uint32_t     ComputeCRC32() override;                    // 04
		Feature           GetFeature() const override;                    // 06 - { return Feature::kMultilayerParallax; }
		void              OnLoadTextureSet() override;                // 08
		void              ClearTextures() override;                   // 09
		void              ReceiveValuesFromRootMaterial() override;   // 0A
		void              GetTextures() override;                     // 0B
		void              SaveBinary() override;                      // 0C
		void              LoadBinary() override;                      // 0D

		// members
		NiPointer<NiSourceTexture> layerTexture;              // A0
		NiPointer<NiSourceTexture> envTexture;                // A8
		NiPointer<NiSourceTexture> envMaskTexture;            // B0
		float                      parallaxLayerThickness;    // B8
		float                      parallaxRefractionScale;   // BC
		float                      parallaxInnerLayerUScale;  // C0
		float                      parallaxInnerLayerVScale;  // C4
		float                      envmapScale;               // C8
		std::uint32_t              padCC;                     // CC
	};
	static_assert(sizeof(BSLightingShaderMaterialMultiLayerParallax) == 0xD0);
}
