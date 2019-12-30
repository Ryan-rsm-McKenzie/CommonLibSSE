#pragma once

#include "RE/BSLightingShaderMaterialBase.h"
#include "RE/NiSmartPointer.h"


namespace RE
{
	class NiSourceTexture;


	class BSLightingShaderMaterialFacegen : public BSLightingShaderMaterialBase
	{
	public:
		inline static const void* RTTI = RTTI_BSLightingShaderMaterialFacegen;


		virtual ~BSLightingShaderMaterialFacegen();										// 00

		// override (BSLightingShaderMaterialBase)
		virtual BSShaderMaterial*	CreateNew() override = 0;							// 01
		virtual void				CopyMembers(BSShaderMaterial* a_other) override;	// 02
		virtual UInt32				ComputeCRC32(void) override;						// 04
		virtual Type				GetType() const override;							// 06 - { return Type::kFaceGen; }
		virtual void				Unk_08(void) override;								// 08
		virtual void				Unk_09(void) override;								// 09
		virtual void				Unk_0A(void) override;								// 0A
		virtual void				Unk_0B(void) override;								// 0B


		// members
		NiPointer<NiSourceTexture>	tintTexture;		// A0
		NiPointer<NiSourceTexture>	detailTexture;		// A8
		NiPointer<NiSourceTexture>	subsurfaceTexture;	// B0
	};
	STATIC_ASSERT(sizeof(BSLightingShaderMaterialFacegen) == 0xB8);
}
