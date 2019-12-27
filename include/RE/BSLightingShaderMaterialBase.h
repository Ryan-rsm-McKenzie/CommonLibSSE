#pragma once

#include "RE/BSShaderMaterial.h"
#include "RE/NiSmartPointer.h"


namespace RE
{
	class BSTextureSet;
	class NiTexture;


	class BSLightingShaderMaterialBase : public BSShaderMaterial
	{
	public:
		inline static const void* RTTI = RTTI_BSLightingShaderMaterialBase;


		virtual ~BSLightingShaderMaterialBase();	// 00

		// override (BSShaderMaterial)
		virtual BSShaderMaterial*	Create() override = 0;						// 01
		virtual void				Copy(BSShaderMaterial* a_src) override;		// 02
		virtual bool				DoIsCopy(const BSShaderMaterial* a_src);	// 03
		virtual void				Unk_04(void) override;						// 04
		virtual BSShaderMaterial*	GetDefault() override;						// 05
		virtual Type				GetType() const override;					// 06 - { return Type::kDefault; }
		virtual void				Unk_07(void) override;						// 07 - { return 2; }

		// add
		virtual void				SetTexture(UInt32 index, BSTextureSet* texture, SInt32 unk1);									// 08
		virtual void				ReleaseTextures(void); 																			// 09 - ReleaseRefs
		virtual void				Unk_0A(UInt8 unk1, UInt8 unk2, UInt8 unk3, UInt8 unk4, UInt8 unk5, UInt32 unk6, UInt32 unk7);	// 0A
		virtual void				Unk_0B(void* unk1, UInt32 unk2);																// 0B
		virtual void				Unk_0C(void);																					// 0C
		virtual void				Unk_0D(void);																					// 0D

		static BSLightingShaderMaterialBase* CreateMaterial(Type a_type);

		NiPointer<BSTextureSet>	GetTextureSet() const;
		void					SetTextureSet(BSTextureSet * a_textureSet);


		// members
		UInt64					unk38;				// 38
		UInt64					unk40;				// 40
		NiPointer<NiTexture>	diffuseMap;			// 48
		UInt64					unk50;				// 50
		NiPointer<NiTexture>	normalMap;			// 58
		NiPointer<NiTexture>	heightMap;			// 60
		NiPointer<NiTexture>	specularMap;		// 68
		UInt64					unk70;				// 70
		NiPointer<BSTextureSet>	textureSet;			// 78
		float					alpha;				// 80
		float					unk84;				// 84
		float					glossiness;			// 88
		float					specularStrength;	// 8C
		float					lightingEffect1;	// 90
		float					lightingEffect2;	// 94
		UInt64					unk98;				// 98
	};
	STATIC_ASSERT(sizeof(BSLightingShaderMaterialBase) == 0xA0);
}
