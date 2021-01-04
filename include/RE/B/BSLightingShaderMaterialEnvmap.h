#pragma once

#include "RE/B/BSLightingShaderMaterialBase.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class NiSourceTexture;

	class BSLightingShaderMaterialEnvmap : public BSLightingShaderMaterialBase
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSLightingShaderMaterialEnvmap;

		virtual ~BSLightingShaderMaterialEnvmap();	// 00

		// override (BSLightingShaderMaterialBase)
		virtual BSShaderMaterial* Create() override;								// 01
		virtual void			  CopyMembers(BSShaderMaterial* a_other) override;	// 02
		virtual std::uint32_t	  ComputeCRC32(void) override;						// 04
		virtual Feature			  GetFeature() const override;						// 06 - { return Feature::kEnvironmentMap; }
		virtual void			  OnLoadTextureSet(void) override;					// 08
		virtual void			  ClearTextures(void) override;						// 09
		virtual void			  ReceiveValuesFromRootMaterial(void) override;		// 0A
		virtual void			  GetTextures(void) override;						// 0B
		virtual void			  SaveBinary(void) override;						// 0C
		virtual void			  LoadBinary(void) override;						// 0D

		// members
		NiPointer<NiSourceTexture> envTexture;		// A0
		NiPointer<NiSourceTexture> envMaskTexture;	// A8
		float					   envMapScale;		// B0
		std::uint32_t			   padB4;			// B4
	};
	static_assert(sizeof(BSLightingShaderMaterialEnvmap) == 0xB8);
}
