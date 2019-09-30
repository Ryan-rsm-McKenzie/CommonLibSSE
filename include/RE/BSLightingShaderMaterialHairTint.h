#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSLightingShaderMaterialHairTint

#include "RE/BSLightingShaderMaterialBase.h"  // BSLightingShaderMaterialBase
#include "RE/NiColor.h"  // NiColor


namespace RE
{
	class BSLightingShaderMaterialHairTint : public BSLightingShaderMaterialBase
	{
	public:
		inline static const void* RTTI = RTTI_BSLightingShaderMaterialHairTint;


		virtual ~BSLightingShaderMaterialHairTint();						// 00

		// override (BSLightingShaderMaterialBase)
		virtual BSShaderMaterial*	Create() override;						// 01
		virtual void				Copy(BSShaderMaterial* a_src) override;	// 02
		virtual void				Unk_04(void) override;					// 04
		virtual Type				GetType() const override;				// 06 - { return Type::kHairTint; }
		virtual void				Unk_0C(void) override;					// 0C
		virtual void				Unk_0D(void) override;					// 0D


		// members
		NiColor	tintColor;	// A0
		UInt32	padAC;		// AC
	};
	STATIC_ASSERT(sizeof(BSLightingShaderMaterialHairTint) == 0xB0);
}
