#pragma once

#include "RE/BSLightingShaderMaterialBase.h"
#include "RE/NiColor.h"


namespace RE
{
	class BSLightingShaderMaterialFacegenTint : public BSLightingShaderMaterialBase
	{
	public:
		inline static const void* RTTI = RTTI_BSLightingShaderMaterialFacegenTint;


		virtual ~BSLightingShaderMaterialFacegenTint();									// 00

		// override (BSLightingShaderMaterialBase)
		virtual BSShaderMaterial*	CreateNew() override = 0;							// 01
		virtual void				CopyMembers(BSShaderMaterial* a_other) override;	// 02
		virtual UInt32				ComputeCRC32(void) override;						// 04
		virtual Type				GetType() const override;							// 06 - { return Type::kFaceGenRGBTint; }
		virtual void				Unk_0C(void) override;								// 0C
		virtual void				Unk_0D(void) override;								// 0D


		// members
		NiColor	tintColor;	// A0
		UInt32	padAC;		// AC
	};
	STATIC_ASSERT(sizeof(BSLightingShaderMaterialFacegenTint) == 0xB0);
}
