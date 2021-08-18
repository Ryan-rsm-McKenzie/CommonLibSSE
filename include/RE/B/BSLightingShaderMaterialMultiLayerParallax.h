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
		inline static constexpr auto VTABLE = VTABLE_BSLightingShaderMaterialMultiLayerParallax;
		inline static constexpr auto FEATURE = Feature::kMultilayerParallax;

		~BSLightingShaderMaterialMultiLayerParallax() override;  // 00

		// override (BSLightingShaderMaterialBase)
		virtual BSShaderMaterial* Create() override;                                                                                                                 // 01
		void                      CopyMembers(BSShaderMaterial* a_src) override;                                                                                     // 02
		std::uint32_t             ComputeCRC32(void) override;                                                                                                       // 04
		Feature                   GetFeature() const override;                                                                                                       // 06 - { return Feature::kMultilayerParallax; }
		void                      OnLoadTextureSet(std::uint64_t a_arg1, BSTextureSet* a_textureSet) override;                                                       // 08
		void                      ClearTextures() override;                                                                                                          // 09
		void                      ReceiveValuesFromRootMaterial(bool a_skinned, bool a_rimLighting, bool a_softLighting, bool a_backLighting, bool a_MSN) override;  // 0A
		void                      GetTextures(void) override;                                                                                                        // 0B
		void                      SaveBinary(NiStream& a_stream) override;                                                                                           // 0C
		void                      LoadBinary(NiStream& a_stream) override;                                                                                           // 0D

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

	protected:
		BSLightingShaderMaterialMultiLayerParallax* ctor()
		{
			using func_t = decltype(&BSLightingShaderMaterialMultiLayerParallax::ctor);
			REL::Relocation<func_t> func{ REL::ID(100125) };
			return func(this);
		}
		friend class BSLightingShaderMaterialBase;
	};
	static_assert(sizeof(BSLightingShaderMaterialMultiLayerParallax) == 0xD0);
}
