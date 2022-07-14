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
		inline static constexpr auto VTABLE = VTABLE_BSLightingShaderMaterialParallax;
		inline static constexpr auto FEATURE = Feature::kParallax;

		~BSLightingShaderMaterialParallax() override;  // 00

		// override (BSLightingShaderMaterialBase)
		BSShaderMaterial* Create() override;                                                                                                                 // 01
		void              CopyMembers(BSShaderMaterial* a_src) override;                                                                                     // 02
		std::uint32_t     ComputeCRC32(void) override;                                                                                                       // 04
		Feature           GetFeature() const override;                                                                                                       // 06 - { return Type::kParallax; }
		void              OnLoadTextureSet(std::uint64_t a_arg1, BSTextureSet* a_textureSet) override;                                                       // 08
		void              ClearTextures() override;                                                                                                          // 09
		void              ReceiveValuesFromRootMaterial(bool a_skinned, bool a_rimLighting, bool a_softLighting, bool a_backLighting, bool a_MSN) override;  // 0A
		void              GetTextures(void) override;                                                                                                        // 0B

		// members
		NiPointer<NiSourceTexture> heightTexture;  // A0

	protected:
		BSLightingShaderMaterialParallax* Ctor()
		{
			using func_t = decltype(&BSLightingShaderMaterialParallax::Ctor);
			REL::Relocation<func_t> func{ REL::ID(106762) };
			return func(this);
		}
		friend class BSLightingShaderMaterialBase;
	};
	static_assert(sizeof(BSLightingShaderMaterialParallax) == 0xA8);
}
