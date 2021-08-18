#pragma once

#include "RE/B/BSLightingShaderMaterialBase.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class NiSourceTexture;

	class BSLightingShaderMaterialParallaxOcc : public BSLightingShaderMaterialBase
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSLightingShaderMaterialParallaxOcc;
		inline static constexpr auto VTABLE = VTABLE_BSLightingShaderMaterialParallaxOcc;
		inline static constexpr auto FEATURE = Feature::kParallaxOcc;

		~BSLightingShaderMaterialParallaxOcc() override;  // 00

		// override (BSLightingShaderMaterialBase)
		BSShaderMaterial* Create() override;                                                                                                                 // 01
		void              CopyMembers(BSShaderMaterial* a_src) override;                                                                                     // 02
		std::uint32_t     ComputeCRC32(void) override;                                                                                                       // 04
		Feature           GetFeature() const override;                                                                                                       // 06 - { return Feature::kParallaxOcc; }
		void              OnLoadTextureSet(std::uint64_t a_arg1, BSTextureSet* a_textureSet) override;                                                       // 08
		void              ClearTextures() override;                                                                                                          // 09
		void              ReceiveValuesFromRootMaterial(bool a_skinned, bool a_rimLighting, bool a_softLighting, bool a_backLighting, bool a_MSN) override;  // 0A
		void              GetTextures(void) override;                                                                                                        // 0B
		void              SaveBinary(NiStream& a_stream) override;                                                                                           // 0C
		void              LoadBinary(NiStream& a_stream) override;                                                                                           // 0D

		// members
		NiPointer<NiSourceTexture> heightTexture;         // A0
		float                      parallaxOccMaxPasses;  // A8
		float                      parallaxOccScale;      // AC

	protected:
		BSLightingShaderMaterialParallaxOcc* ctor()
		{
			using func_t = decltype(&BSLightingShaderMaterialParallaxOcc::ctor);
			REL::Relocation<func_t> func{ REL::ID(100065) };
			return func(this);
		}
		friend class BSLightingShaderMaterialBase;
	};
	static_assert(sizeof(BSLightingShaderMaterialParallaxOcc) == 0xB0);
}
