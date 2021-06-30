#pragma once

#include "RE/B/BSLightingShaderMaterialBase.h"
#include "RE/N/NiColor.h"

namespace RE
{
	class BSLightingShaderMaterialSnow : public BSLightingShaderMaterialBase
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSLightingShaderMaterialSnow;

		~BSLightingShaderMaterialSnow() override;  // 00

		// override (BSLightingShaderMaterialBase)
		BSShaderMaterial* Create() override;                              // 01
		void              CopyMembers(BSShaderMaterial* a_src) override;  // 02
		std::uint32_t     ComputeCRC32(void) override;                    // 04
		Feature           GetFeature() const override;                    // 06 - { return Feature::kMultiIndexTriShapeSnow; }
		void              SaveBinary(void) override;                      // 0C
		void              LoadBinary(void) override;                      // 0D

		// members
		NiColorA sparkleParams;  // A0
	};
	static_assert(sizeof(BSLightingShaderMaterialSnow) == 0xB0);
}
