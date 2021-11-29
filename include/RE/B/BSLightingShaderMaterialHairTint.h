#pragma once

#include "RE/B/BSLightingShaderMaterialBase.h"
#include "RE/N/NiColor.h"

namespace RE
{
	class BSLightingShaderMaterialHairTint : public BSLightingShaderMaterialBase
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSLightingShaderMaterialHairTint;

		~BSLightingShaderMaterialHairTint() override;  // 00

		// override (BSLightingShaderMaterialBase)
		BSShaderMaterial* Create() override;                                // 01
		void              CopyMembers(BSShaderMaterial* a_other) override;  // 02
		std::uint32_t     ComputeCRC32(void) override;                      // 04
		Feature           GetFeature() const override;                      // 06 - { return Feature::kHairTint; }
		void              SaveBinary(void) override;                        // 0C
		void              LoadBinary(void) override;                        // 0D

		// members
		NiColor       tintColor;  // A0
		std::uint32_t padAC;      // AC
	};
	static_assert(sizeof(BSLightingShaderMaterialHairTint) == 0xB0);
}
