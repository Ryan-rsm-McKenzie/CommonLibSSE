#pragma once

#include "RE/B/BSLightingShaderMaterialBase.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class NiSourceTexture;

	class BSLightingShaderMaterialEnvmap : public BSLightingShaderMaterialBase
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSLightingShaderMaterialEnvmap;

		~BSLightingShaderMaterialEnvmap() override;  // 00

		// override (BSLightingShaderMaterialBase)
		BSShaderMaterial* Create() override;                                // 01
		void              CopyMembers(BSShaderMaterial* a_other) override;  // 02
		std::uint32_t     ComputeCRC32() override;                      // 04
		Feature           GetFeature() const override;                      // 06 - { return Feature::kEnvironmentMap; }
		void              OnLoadTextureSet() override;                  // 08
		void              ClearTextures() override;                     // 09
		void              ReceiveValuesFromRootMaterial() override;     // 0A
		void              GetTextures() override;                       // 0B
		void              SaveBinary() override;                        // 0C
		void              LoadBinary() override;                        // 0D

		// members
		NiPointer<NiSourceTexture> envTexture;      // A0
		NiPointer<NiSourceTexture> envMaskTexture;  // A8
		float                      envMapScale;     // B0
		std::uint32_t              padB4;           // B4
	};
	static_assert(sizeof(BSLightingShaderMaterialEnvmap) == 0xB8);
}
