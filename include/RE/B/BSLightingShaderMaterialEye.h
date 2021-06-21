#pragma once

#include "RE/B/BSLightingShaderMaterialBase.h"
#include "RE/N/NiPoint3.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class NiSourceTexture;

	class BSLightingShaderMaterialEye : public BSLightingShaderMaterialBase
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSLightingShaderMaterialEye;
		inline static constexpr auto VTABLE = VTABLE_BSLightingShaderMaterialEye;
		inline static constexpr auto FEATURE = Feature::kEye;

		virtual ~BSLightingShaderMaterialEye();  // 00

		// override (BSLightingShaderMaterialBase)
		virtual BSShaderMaterial* Create() override;                                                                                                                 // 01
		virtual void              CopyMembers(BSShaderMaterial* a_other) override;                                                                                   // 02
		virtual std::uint32_t     ComputeCRC32(void) override;                                                                                                       // 04
		virtual Feature           GetFeature() const override;                                                                                                       // 06 - { return Feature::kEye; }
		virtual void              OnLoadTextureSet(std::uint64_t a_arg1, BSTextureSet* a_textureSet) override;                                                       // 08
		virtual void              ClearTextures() override;                                                                                                          // 09
		virtual void              ReceiveValuesFromRootMaterial(bool a_skinned, bool a_rimLighting, bool a_softLighting, bool a_backLighting, bool a_MSN) override;  // 0A
		virtual void              GetTextures(void) override;                                                                                                        // 0B
		virtual void              SaveBinary(NiStream& a_stream) override;                                                                                           // 0C
		virtual void              LoadBinary(NiStream& a_stream) override;                                                                                           // 0D

		// members
		NiPointer<NiSourceTexture> envTexture;      // A0
		NiPointer<NiSourceTexture> envMaskTexture;  // A8
		float                      envMapScale;     // B0
		NiPoint3                   eyeCenter[2];    // B4
		std::uint32_t              padC8;           // CC

	protected:
		BSLightingShaderMaterialEye* ctor()
		{
			using func_t = decltype(&BSLightingShaderMaterialEye::ctor);
			REL::Relocation<func_t> func{ REL::ID(100033) };
			return func(this);
		}
		friend class BSLightingShaderMaterialBase;
	};
	static_assert(sizeof(BSLightingShaderMaterialEye) == 0xD0);
}
