#pragma once

#include "RE/BSLightingShaderMaterialBase.h"
#include "RE/NiColor.h"


namespace RE
{
	class BSLightingShaderMaterialSnow : public BSLightingShaderMaterialBase
	{
	public:
		inline static const void* RTTI = RTTI_BSLightingShaderMaterialSnow;


		virtual ~BSLightingShaderMaterialSnow();									// 00

		// override (BSLightingShaderMaterialBase)
		virtual BSShaderMaterial*	CreateNew() override = 0;						// 01
		virtual void				CopyMembers(BSShaderMaterial* a_src) override;	// 02
		virtual UInt32				ComputeCRC32(void) override;					// 04
		virtual Type				GetType() const override;						// 06 - { return Type::kMultiIndexTriShapeSnow; }
		virtual void				Unk_0C(void) override;							// 0C
		virtual void				Unk_0D(void) override;							// 0D


		// members
		NiColorA sparkleParams;	// A0
	};
	STATIC_ASSERT(sizeof(BSLightingShaderMaterialSnow) == 0xB0);
}
