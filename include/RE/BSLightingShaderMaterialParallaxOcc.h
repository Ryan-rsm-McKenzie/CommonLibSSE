#pragma once

#include "RE/BSLightingShaderMaterialBase.h"
#include "RE/NiSmartPointer.h"


namespace RE
{
	class NiSourceTexture;


	class BSLightingShaderMaterialParallaxOcc : public BSLightingShaderMaterialBase
	{
	public:
		inline static const void* RTTI = RTTI_BSLightingShaderMaterialParallaxOcc;


		virtual ~BSLightingShaderMaterialParallaxOcc();								// 00

		// override (BSLightingShaderMaterialBase)
		virtual BSShaderMaterial*	CreateNew() override = 0;						// 01
		virtual void				CopyMembers(BSShaderMaterial* a_src) override;	// 02
		virtual UInt32				ComputeCRC32(void) override;					// 04
		virtual Type				GetType() const override;						// 06 - { return Type::kParallaxOcc; }
		virtual void				Unk_08(void) override;							// 08
		virtual void				Unk_09(void) override;							// 09
		virtual void				Unk_0A(void) override;							// 0A
		virtual void				Unk_0B(void) override;							// 0B
		virtual void				Unk_0C(void) override;							// 0C
		virtual void				Unk_0D(void) override;							// 0D


		// members
		NiPointer<NiSourceTexture>	heightTexture;			// A0
		float						parallaxOccMaxPasses;	// A8
		float						parallaxOccScale;		// AC
	};
	STATIC_ASSERT(sizeof(BSLightingShaderMaterialParallaxOcc) == 0xB0);
}
