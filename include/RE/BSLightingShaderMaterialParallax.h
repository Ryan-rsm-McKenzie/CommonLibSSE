#pragma once

#include "RE/BSLightingShaderMaterialBase.h"
#include "RE/NiSmartPointer.h"


namespace RE
{
	class NiSourceTexture;


	class BSLightingShaderMaterialParallax : public BSLightingShaderMaterialBase
	{
	public:
		inline static const void* RTTI = RTTI_BSLightingShaderMaterialParallax;


		virtual ~BSLightingShaderMaterialParallax();								// 00

		// override (BSLightingShaderMaterialBase)
		virtual BSShaderMaterial*	CreateNew() override = 0;						// 01
		virtual void				CopyMembers(BSShaderMaterial* a_src) override;	// 02
		virtual UInt32				ComputeCRC32(void) override;					// 04
		virtual Type				GetType() const override;						// 06 - { return Type::kParallax; }
		virtual void				Unk_08(void) override;							// 08
		virtual void				Unk_09(void) override;							// 09
		virtual void				Unk_0A(void) override;							// 0A
		virtual void				Unk_0B(void) override;							// 0B


		// members
		NiPointer<NiSourceTexture> heightTexture;	// A0
	};
	STATIC_ASSERT(sizeof(BSLightingShaderMaterialParallax) == 0xA8);
}
