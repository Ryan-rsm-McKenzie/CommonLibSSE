#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSLightingShaderMaterialHairTint
#include "RE/BSLightingShaderMaterialBase.h"  // BSLightingShaderMaterialBase
#include "RE/NiColor.h" // NiColor


namespace RE
{
	class BSLightingShaderMaterialSnow : public BSLightingShaderMaterialBase
	{
	public:
		inline static const void* RTTI = RTTI_BSLightingShaderMaterialSnow;

		virtual ~BSLightingShaderMaterialSnow();							// 00

		// override (BSShaderMaterialBase)
		virtual BSShaderMaterial*	Create() override;						// 01
		virtual void				Copy(BSShaderMaterial* a_src) override;	// 02
		virtual void				Unk_04(void) override;					// 04
		virtual Type				GetType() const override;				// 06 - { return Type::kSnow; }


		// members
		NiColorA kSparkleParams;

	};
	STATIC_ASSERT(sizeof(BSLightingShaderMaterialSnow) == 0xB0);
}