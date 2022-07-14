#pragma once

#include "RE/B/BSShaderMaterial.h"
#include "RE/N/NiColor.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class BSTextureSet;
	class NiSourceTexture;
	class NiStream;

	class BSLightingShaderMaterialBase : public BSShaderMaterial
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSLightingShaderMaterialBase;
		inline static constexpr auto VTABLE = VTABLE_BSLightingShaderMaterialBase;

		~BSLightingShaderMaterialBase() override;  // 00

		// override (BSShaderMaterial)
		BSShaderMaterial* Create() override = 0;                            // 01
		void              CopyMembers(BSShaderMaterial* a_other) override;  // 02
		bool              DoIsCopy(BSShaderMaterial* a_other) override;     // 03
		std::uint32_t     ComputeCRC32(void) override;                      // 04
		BSShaderMaterial* GetDefault() override;                            // 05
		Feature           GetFeature() const override;                      // 06 - { return Feature::kDefault; }
		Type              GetType() const override;                         // 07 - { return Type::kLighting; }

		// add
		virtual void OnLoadTextureSet(std::uint64_t a_arg1, BSTextureSet* a_textureSet);                                                       // 08
		virtual void ClearTextures();                                                                                                          // 09
		virtual void ReceiveValuesFromRootMaterial(bool a_skinned, bool a_rimLighting, bool a_softLighting, bool a_backLighting, bool a_MSN);  // 0A
		virtual void GetTextures(void);                                                                                                        // 0B
		virtual void SaveBinary(NiStream& a_stream);                                                                                           // 0C
		virtual void LoadBinary(NiStream& a_stream);                                                                                           // 0D

		static BSLightingShaderMaterialBase* CreateMaterial(Feature a_feature);
		template <class T>
		static T* CreateMaterial();

		void                    CopyBaseMembers(BSLightingShaderMaterialBase* a_other);
		NiPointer<BSTextureSet> GetTextureSet() const;
		void                    SetTextureSet(NiPointer<BSTextureSet> a_textureSet);

		// members
		NiColor                    specularColor;                   // 38
		std::uint32_t              pad44;                           // 44
		NiPointer<NiSourceTexture> diffuseTexture;                  // 48
		std::int32_t               diffuseRenderTargetSourceIndex;  // 50
		std::uint32_t              pad54;                           // 54
		NiPointer<NiSourceTexture> normalTexture;                   // 58
		NiPointer<NiSourceTexture> rimSoftLightingTexture;          // 60
		NiPointer<NiSourceTexture> specularBackLightingTexture;     // 68
		std::int32_t               textureClampMode;                // 70
		std::int32_t               pad74;                           // 70
		NiPointer<BSTextureSet>    textureSet;                      // 78
		float                      materialAlpha;                   // 80
		float                      refractionPower;                 // 84
		float                      specularPower;                   // 88
		float                      specularColorScale;              // 8C
		float                      subSurfaceLightRolloff;          // 90
		float                      rimLightPower;                   // 94
		std::uint64_t              unk98;                           // 98
	};
	static_assert(sizeof(BSLightingShaderMaterialBase) == 0xA0);

	template <class T>
	T* BSLightingShaderMaterialBase::CreateMaterial()
	{
		return static_cast<T*>(CreateMaterial(T::FEATURE));
	}
}
