#pragma once

#include "RE/B/BSLightingShaderMaterialBase.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class NiSourceTexture;

	class BSLightingShaderMaterialFacegen : public BSLightingShaderMaterialBase
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSLightingShaderMaterialFacegen;
		inline static constexpr auto VTABLE = VTABLE_BSLightingShaderMaterialFacegen;
		inline static constexpr auto FEATURE = Feature::kFaceGen;

		virtual ~BSLightingShaderMaterialFacegen();  // 00

		// override (BSLightingShaderMaterialBase)
		virtual BSShaderMaterial* Create() override;                                                                                                                 // 01
		virtual void              CopyMembers(BSShaderMaterial* a_other) override;                                                                                   // 02
		virtual std::uint32_t     ComputeCRC32(void) override;                                                                                                       // 04
		virtual Feature           GetFeature() const override;                                                                                                       // 06 - { return Feature::kFaceGen; }
		virtual void              OnLoadTextureSet(std::uint64_t a_arg1, BSTextureSet* a_textureSet) override;                                                       // 08
		virtual void              ClearTextures() override;                                                                                                          // 09
		virtual void              ReceiveValuesFromRootMaterial(bool a_skinned, bool a_rimLighting, bool a_softLighting, bool a_backLighting, bool a_MSN) override;  // 0A
		virtual void              GetTextures(void) override;                                                                                                        // 0B

		// members
		NiPointer<NiSourceTexture> tintTexture;        // A0
		NiPointer<NiSourceTexture> detailTexture;      // A8
		NiPointer<NiSourceTexture> subsurfaceTexture;  // B0

	protected:
		BSLightingShaderMaterialFacegen* ctor()
		{
			using func_t = decltype(&BSLightingShaderMaterialFacegen::ctor);
			REL::Relocation<func_t> func{ REL::ID(100077) };
			return func(this);
		}
		friend class BSLightingShaderMaterialBase;
	};
	static_assert(sizeof(BSLightingShaderMaterialFacegen) == 0xB8);
}
