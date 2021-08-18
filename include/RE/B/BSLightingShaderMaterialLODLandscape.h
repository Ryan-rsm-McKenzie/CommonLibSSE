#pragma once

#include "RE/B/BSLightingShaderMaterialBase.h"

namespace RE
{
	class NiSourceTexture;

	class BSLightingShaderMaterialLODLandscape : public BSLightingShaderMaterialBase
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSLightingShaderMaterialLODLandscape;
		inline static constexpr auto VTABLE = VTABLE_BSLightingShaderMaterialLODLandscape;
		inline static constexpr auto FEATURE = Feature::kLODLandNoise;

		~BSLightingShaderMaterialLODLandscape() override;  // 00

		// override (BSLightingShaderMaterialBase)
		BSShaderMaterial* Create() override;                                                                                                                 // 01
		void              CopyMembers(BSShaderMaterial* a_src) override;                                                                                     // 02
		Feature           GetFeature() const override;                                                                                                       // 06 - { return Feature::kLODLandNoise; }
		void              ClearTextures() override;                                                                                                          // 09
		void              ReceiveValuesFromRootMaterial(bool a_skinned, bool a_rimLighting, bool a_softLighting, bool a_backLighting, bool a_MSN) override;  // 0A
		void              GetTextures(void) override;                                                                                                        // 0B

		// members
		NiPointer<NiSourceTexture> parentDiffuseTexture;   // A0
		NiPointer<NiSourceTexture> parentNormalTexture;    // A8
		NiPointer<NiSourceTexture> landscapeNoiseTexture;  // B0
		float                      terrainTexOffsetX;      // B4
		float                      terrainTexOffsetY;      // B8
		float                      terrainTexFade;         // BC

	protected:
		BSLightingShaderMaterialLODLandscape* ctor()
		{
			using func_t = decltype(&BSLightingShaderMaterialLODLandscape::ctor);
			REL::Relocation<func_t> func{ REL::ID(100110) };
			return func(this);
		}
		friend class BSLightingShaderMaterialBase;
	};
	static_assert(sizeof(BSLightingShaderMaterialLODLandscape) == 0xC8);
}
