#pragma once

#include "RE/B/BSLightingShaderMaterialBase.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class NiSourceTexture;

	class BSLightingShaderMaterialParallax : public BSLightingShaderMaterialBase
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSLightingShaderMaterialParallax;

		virtual ~BSLightingShaderMaterialParallax();  // 00

		// override (BSLightingShaderMaterialBase)
		virtual BSShaderMaterial* Create() override;							  // 01
		virtual void			  CopyMembers(BSShaderMaterial* a_src) override;  // 02
		virtual std::uint32_t	  ComputeCRC32(void) override;					  // 04
		virtual Feature			  GetFeature() const override;					  // 06 - { return Type::kParallax; }
		virtual void			  OnLoadTextureSet(void) override;				  // 08
		virtual void			  ClearTextures(void) override;					  // 09
		virtual void			  ReceiveValuesFromRootMaterial(void) override;	  // 0A
		virtual void			  GetTextures(void) override;					  // 0B

		// members
		NiPointer<NiSourceTexture> heightTexture;  // A0
	};
	static_assert(sizeof(BSLightingShaderMaterialParallax) == 0xA8);
}
