#pragma once

#include "RE/B/BSLightingShaderMaterialBase.h"

namespace RE
{
	class BSLightingShaderMaterial : public BSLightingShaderMaterialBase
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSLightingShaderMaterial;

		~BSLightingShaderMaterial() override;  // 00

		// override (BSLightingShaderMaterialBase)
		BSShaderMaterial* Create() override;            // 01
		Feature           GetFeature() const override;  // 06 - { return Feature::kDefault; }
	};
	static_assert(sizeof(BSLightingShaderMaterial) == 0xA0);
}
