#pragma once

#include "RE/B/BSLightingShaderMaterialBase.h"
#include "RE/N/NiPoint3.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class NiSourceTexture;

	class BSLightingShaderMaterialEye : public BSLightingShaderMaterialBase
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSLightingShaderMaterialEye;

		~BSLightingShaderMaterialEye() override;  // 00

		// override (BSLightingShaderMaterialBase)
		BSShaderMaterial* Create() override;                                // 01
		void              CopyMembers(BSShaderMaterial* a_other) override;  // 02
		std::uint32_t     ComputeCRC32(void) override;                      // 04
		Feature           GetFeature() const override;                      // 06 - { return Feature::kEye; }
		void              OnLoadTextureSet(void) override;                  // 08
		void              ClearTextures(void) override;                     // 09
		void              ReceiveValuesFromRootMaterial(void) override;     // 0A
		void              GetTextures(void) override;                       // 0B
		void              SaveBinary(void) override;                        // 0C
		void              LoadBinary(void) override;                        // 0D

		// members
		NiPointer<NiSourceTexture> envTexture;      // A0
		NiPointer<NiSourceTexture> envMaskTexture;  // A8
		float                      envMapScale;     // B0
		NiPoint3                   eyeCenter[2];    // B4
		std::uint32_t              padC8;           // CC
	};
	static_assert(sizeof(BSLightingShaderMaterialEye) == 0xD0);
}
