#pragma once

#include "RE/B/BSLightingShaderMaterialBase.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class NiSourceTexture;

	class BSLightingShaderMaterialParallax : public BSLightingShaderMaterialBase
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSLightingShaderMaterialParallax;

		~BSLightingShaderMaterialParallax() override;  // 00

		// override (BSLightingShaderMaterialBase)
		BSShaderMaterial* Create() override;                              // 01
		void              CopyMembers(BSShaderMaterial* a_src) override;  // 02
		std::uint32_t     ComputeCRC32() override;                    // 04
		Feature           GetFeature() const override;                    // 06 - { return Type::kParallax; }
		void              OnLoadTextureSet() override;                // 08
		void              ClearTextures() override;                   // 09
		void              ReceiveValuesFromRootMaterial() override;   // 0A
		void              GetTextures() override;                     // 0B

		// members
		NiPointer<NiSourceTexture> heightTexture;  // A0
	};
	static_assert(sizeof(BSLightingShaderMaterialParallax) == 0xA8);
}
