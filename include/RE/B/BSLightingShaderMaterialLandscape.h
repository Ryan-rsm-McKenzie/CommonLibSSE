#pragma once

#include "RE/B/BSLightingShaderMaterialBase.h"
#include "RE/N/NiColor.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class NiSourceTexture;

	class BSLightingShaderMaterialLandscape : public BSLightingShaderMaterialBase
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSLightingShaderMaterialLandscape;
		inline static constexpr auto VTABLE = VTABLE_BSLightingShaderMaterialLandscape;
		inline static constexpr auto FEATURE = Feature::kMultiTexLandLODBlend;

		virtual ~BSLightingShaderMaterialLandscape();  // 00

		// override (BSLightingShaderMaterialBase)
		virtual BSShaderMaterial* Create() override;                                                                                                                 // 01
		virtual void              CopyMembers(BSShaderMaterial* a_src) override;                                                                                     // 02
		virtual Feature           GetFeature() const override;                                                                                                       // 06 - { return Feature::kMultiTexLandLODBlend; }
		virtual void              ClearTextures() override;                                                                                                          // 09
		virtual void              ReceiveValuesFromRootMaterial(bool a_skinned, bool a_rimLighting, bool a_softLighting, bool a_backLighting, bool a_MSN) override;  // 0A
		virtual void              GetTextures(void) override;                                                                                                        // 0B

		// members
		std::uint32_t              numLandscapeTextures;        // 0A0
		std::uint32_t              pad0A4;                      // 0A4
		NiPointer<NiSourceTexture> landscapeDiffuseTexture[5];  // 0A8
		NiPointer<NiSourceTexture> landscapeNormalTexture[5];   // 0D0
		NiPointer<NiSourceTexture> terrainOverlayTexture;       // 0F8
		NiPointer<NiSourceTexture> terrainNoiseTexture;         // 100
		NiColorA                   landBlendParams;             // 108
		float                      textureIsSnow[6];            // 118
		float                      textureIsSpecPower[6];       // 130
		float                      terrainTexOffsetX;           // 148
		float                      terrainTexOffsetY;           // 14C
		float                      terrainTexFade;              // 150
		std::uint32_t              pad154;                      // 154

	protected:
		BSLightingShaderMaterialLandscape* ctor()
		{
			using func_t = decltype(&BSLightingShaderMaterialLandscape::ctor);
			REL::Relocation<func_t> func{ REL::ID(100102) };
			return func(this);
		}
		friend class BSLightingShaderMaterialBase;
	};
	static_assert(sizeof(BSLightingShaderMaterialLandscape) == 0x158);
}
