#pragma once

#include "RE/B/BSLightingShaderMaterialBase.h"
#include "RE/N/NiColor.h"

namespace RE
{
	class BSLightingShaderMaterialHairTint : public BSLightingShaderMaterialBase
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSLightingShaderMaterialHairTint;

		virtual ~BSLightingShaderMaterialHairTint();  // 00

		// override (BSLightingShaderMaterialBase)
		virtual BSShaderMaterial* Create() override;								// 01
		virtual void			  CopyMembers(BSShaderMaterial* a_other) override;	// 02
		virtual std::uint32_t	  ComputeCRC32(void) override;						// 04
		virtual Feature			  GetFeature() const override;						// 06 - { return Feature::kHairTint; }
		virtual void			  SaveBinary(void) override;						// 0C
		virtual void			  LoadBinary(void) override;						// 0D

		// members
		NiColor		  tintColor;  // A0
		std::uint32_t padAC;	  // AC
	};
	static_assert(sizeof(BSLightingShaderMaterialHairTint) == 0xB0);
}
