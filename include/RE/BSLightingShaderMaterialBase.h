#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSLightingShaderMaterialBase

#include "RE/BSShaderMaterial.h"  // BSShaderMaterial
#include "RE/NiSmartPointer.h"  // NiPointer


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
		virtual BSShaderMaterial*	Create() override = 0;					// 01
		virtual void				Copy(BSShaderMaterial* a_src) override;	// 02
		virtual void				Unk_03(void) override;					// 03
		virtual void				Unk_04(void) override;					// 04
		virtual void				Unk_05(void) override;					// 05
		virtual Type				GetType() const override;				// 06 - { return Type::kDefault; }
		virtual void				Unk_07(void) override;					// 07 - { return 2; }

		// add
		virtual void				Unk_08(void);							// 08
		virtual void				Unk_09(void);							// 09
		virtual void				Unk_0A(void);							// 0A
		virtual void				Unk_0B(void);							// 0B
		virtual void				Unk_0C(void);							// 0C
		virtual void				Unk_0D(void);							// 0D


		// members
		UInt64					unk38;				// 38
		UInt64					unk40;				// 40
		NiPointer<NiTexture>	unk48;				// 48
		UInt64					unk50;				// 50
		NiPointer<NiTexture>	unk58;				// 58
		NiPointer<NiTexture>	unk60;				// 60
		NiPointer<NiTexture>	unk68;				// 68
		UInt64					unk70;				// 70
		NiPointer<BSTextureSet>	unk78;				// 78
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
