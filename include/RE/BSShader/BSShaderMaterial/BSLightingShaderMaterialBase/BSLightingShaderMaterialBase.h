#pragma once

#include "RE/BSShaderMaterial.h"
#include "RE/NiColor.h"
#include "RE/NiSmartPointer.h"


namespace RE
{
	class BSTextureSet;
	class NiSourceTexture;


	class BSLightingShaderMaterialBase : public BSShaderMaterial
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSLightingShaderMaterialBase;


		virtual ~BSLightingShaderMaterialBase();  // 00

		// override (BSShaderMaterial)
		virtual BSShaderMaterial* Create() override = 0;							// 01
		virtual void			  CopyMembers(BSShaderMaterial* a_other) override;	// 02
		virtual bool			  DoIsCopy(BSShaderMaterial* a_other) override;		// 03
		virtual UInt32			  ComputeCRC32(void) override;						// 04
		virtual BSShaderMaterial* GetDefault() override;							// 05
		virtual Feature			  GetFeature() const override;						// 06 - { return Feature::kDefault; }
		virtual Type			  GetType() const override;							// 07 - { return Type::kLighting; }

		// add
		virtual void OnLoadTextureSet(void);			   // 08
		virtual void ClearTextures(void);				   // 09
		virtual void ReceiveValuesFromRootMaterial(void);  // 0A
		virtual void GetTextures(void);					   // 0B
		virtual void SaveBinary(void);					   // 0C
		virtual void LoadBinary(void);					   // 0D

		static BSLightingShaderMaterialBase* CreateMaterial(Feature a_feature);

		NiPointer<BSTextureSet> GetTextureSet() const;
		void					SetTextureSet(NiPointer<BSTextureSet> a_textureSet);


		// members
		NiColor					   specularColor;					// 38
		UInt32					   pad44;							// 44
		NiPointer<NiSourceTexture> diffuseTexture;					// 48
		SInt32					   diffuseRenderTargetSourceIndex;	// 50
		UInt32					   pad54;							// 54
		NiPointer<NiSourceTexture> normalTexture;					// 58
		NiPointer<NiSourceTexture> rimSoftLightingTexture;			// 60
		NiPointer<NiSourceTexture> specularBackLightingTexture;		// 68
		SInt32					   textureClampMode;				// 70
		SInt32					   pad74;							// 70
		NiPointer<BSTextureSet>	   textureSet;						// 78
		float					   materialAlpha;					// 80
		float					   refractionPower;					// 84
		float					   specularPower;					// 88
		float					   specularColorScale;				// 8C
		float					   subSurfaceLightRolloff;			// 90
		float					   rimLightPower;					// 94
		UInt64					   unk98;							// 98
	};
	STATIC_ASSERT(sizeof(BSLightingShaderMaterialBase) == 0xA0);
}
