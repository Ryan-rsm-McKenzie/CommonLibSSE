#pragma once

#include "RE/B/BSLightingShaderMaterialBase.h"

namespace RE
{
	class BSLightingShaderMaterial : public BSLightingShaderMaterialBase
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSLightingShaderMaterial;

		virtual ~BSLightingShaderMaterial();  // 00

		// override (BSLightingShaderMaterialBase)
		virtual BSShaderMaterial* Create() override;			// 01
		virtual Feature			  GetFeature() const override;	// 06 - { return Feature::kDefault; }
	};
	static_assert(sizeof(BSLightingShaderMaterial) == 0xA0);
}
