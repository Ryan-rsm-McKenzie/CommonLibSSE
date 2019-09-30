#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSLightingShaderMaterial

#include "RE/BSLightingShaderMaterialBase.h"  // BSLightingShaderMaterialBase


namespace RE
{
	class BSLightingShaderMaterial : public BSLightingShaderMaterialBase
	{
	public:
		inline static const void* RTTI = RTTI_BSLightingShaderMaterial;


		virtual ~BSLightingShaderMaterial();					// 00

		// override (BSLightingShaderMaterialBase)
		virtual BSShaderMaterial*	Create() override;			// 01
		virtual Type				GetType() const override;	// 06 - { return Type::kDefault; }
	};
	STATIC_ASSERT(sizeof(BSLightingShaderMaterial) == 0xA0);
}
