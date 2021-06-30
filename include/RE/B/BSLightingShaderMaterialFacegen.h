#pragma once

#include "RE/B/BSLightingShaderMaterialBase.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class NiSourceTexture;

	class BSLightingShaderMaterialFacegen : public BSLightingShaderMaterialBase
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSLightingShaderMaterialFacegen;

		~BSLightingShaderMaterialFacegen() override;  // 00

		// override (BSLightingShaderMaterialBase)
		BSShaderMaterial* Create() override;                                // 01
		void              CopyMembers(BSShaderMaterial* a_other) override;  // 02
		std::uint32_t     ComputeCRC32(void) override;                      // 04
		Feature           GetFeature() const override;                      // 06 - { return Feature::kFaceGen; }
		void              OnLoadTextureSet(void) override;                  // 08
		void              ClearTextures(void) override;                     // 09
		void              ReceiveValuesFromRootMaterial(void) override;     // 0A
		void              GetTextures(void) override;                       // 0B

		// members
		NiPointer<NiSourceTexture> tintTexture;        // A0
		NiPointer<NiSourceTexture> detailTexture;      // A8
		NiPointer<NiSourceTexture> subsurfaceTexture;  // B0
	};
	static_assert(sizeof(BSLightingShaderMaterialFacegen) == 0xB8);
}
