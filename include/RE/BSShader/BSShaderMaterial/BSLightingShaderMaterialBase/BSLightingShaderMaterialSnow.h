#pragma once

#include "RE/BSLightingShaderMaterialBase.h"
#include "RE/NiColor.h"


namespace RE
{
	class BSLightingShaderMaterialSnow : public BSLightingShaderMaterialBase
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSLightingShaderMaterialSnow;


		virtual ~BSLightingShaderMaterialSnow();  // 00

		// override (BSLightingShaderMaterialBase)
		virtual BSShaderMaterial* Create() override;							  // 01
		virtual void			  CopyMembers(BSShaderMaterial* a_src) override;  // 02
		virtual UInt32			  ComputeCRC32(void) override;					  // 04
		virtual Feature			  GetFeature() const override;					  // 06 - { return Feature::kMultiIndexTriShapeSnow; }
		virtual void			  SaveBinary(void) override;					  // 0C
		virtual void			  LoadBinary(void) override;					  // 0D


		// members
		NiColorA sparkleParams;	 // A0
	};
	STATIC_ASSERT(sizeof(BSLightingShaderMaterialSnow) == 0xB0);
}
