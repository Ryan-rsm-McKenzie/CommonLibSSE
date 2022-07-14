#pragma once

#include "RE/B/BSLightingShaderMaterialBase.h"

namespace RE
{
	class BSLightingShaderMaterial : public BSLightingShaderMaterialBase
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSLightingShaderMaterial;
		inline static constexpr auto VTABLE = VTABLE_BSLightingShaderMaterial;
		inline static constexpr auto FEATURE = Feature::kDefault;

		~BSLightingShaderMaterial() override;  // 00

		// override (BSLightingShaderMaterialBase)
		BSShaderMaterial* Create() override;            // 01
		Feature           GetFeature() const override;  // 06 - { return Feature::kDefault; }

	protected:
		BSLightingShaderMaterial* Ctor()
		{
			using func_t = decltype(&BSLightingShaderMaterial::Ctor);
			REL::Relocation<func_t> func{ REL::ID(106711) };
			return func(this);
		}
		friend class BSLightingShaderMaterialBase;
	};
	static_assert(sizeof(BSLightingShaderMaterial) == 0xA0);
}
