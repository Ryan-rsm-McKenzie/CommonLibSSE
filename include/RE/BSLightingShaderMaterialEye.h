#pragma once

#include "RE/BSLightingShaderMaterialBase.h"
#include "RE/NiPoint3.h"
#include "RE/NiSmartPointer.h"


namespace RE
{
	class NiSourceTexture;


	class BSLightingShaderMaterialEye : public BSLightingShaderMaterialBase
	{
	public:
		inline static const void* RTTI = RTTI_BSLightingShaderMaterialEye;


		virtual ~BSLightingShaderMaterialEye();											// 00

		// override (BSLightingShaderMaterialBase)
		virtual BSShaderMaterial*	CreateNew() override = 0;							// 01
		virtual void				CopyMembers(BSShaderMaterial* a_other) override;	// 02
		virtual UInt32				ComputeCRC32(void) override;						// 04
		virtual Type				GetType() const override;							// 06 - { return Type::kEye; }
		virtual void				Unk_08(void) override;								// 08
		virtual void				Unk_09(void) override;								// 09
		virtual void				Unk_0A(void) override;								// 0A
		virtual void				Unk_0B(void) override;								// 0B
		virtual void				Unk_0C(void) override;								// 0C
		virtual void				Unk_0D(void) override;								// 0D


		// members
		NiPointer<NiSourceTexture>	envTexture;		// A0
		NiPointer<NiSourceTexture>	envMaskTexture;	// A8
		float						envMapScale;	// B0
		NiPoint3					eyeCenter[2];	// B4
		UInt32						padC8;			// CC
	};
	STATIC_ASSERT(sizeof(BSLightingShaderMaterialEye) == 0xD0);
}
