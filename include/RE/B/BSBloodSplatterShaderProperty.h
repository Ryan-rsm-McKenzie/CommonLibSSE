#pragma once

#include "RE/B/BSShaderProperty.h"
#include "RE/B/BSTArray.h"
#include "RE/N/NiColor.h"
#include "RE/N/NiPoint3.h"

namespace RE
{
	class NiSourceTexture;

	class BSBloodSplatterShaderProperty : public BSShaderProperty
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSBloodSplatterShaderProperty;
		inline static constexpr auto Ni_RTTI = NiRTTI_BSBloodSplatterShaderProperty;

		enum : std::uint32_t
		{
			kBloodColor = 0,
			kBloodAlpha,
			kFlareColor,

			kTotal
		};

		~BSBloodSplatterShaderProperty() override;  // 00

		// override (BSShaderProperty)
		const NiRTTI*    GetRTTI() const override;                           // 02
		NiObject*        CreateClone(NiCloningProcess& a_cloning) override;  // 17
		void             Unk_2A(void) override;                              // 2A
		void             Unk_33(void) override;                              // 33
		void             Unk_35(void) override;                              // 35 - { return 12 }
		NiSourceTexture* GetPrimaryTexture() override;                       // 37 - { return bloodColorTexture; }

		// members
		NiPointer<NiSourceTexture> bloodTextures[kTotal];  // 088
		std::int32_t               textureClampMode;       // 0A0
		float*                     alphaSource;            // 0A8
	};
	static_assert(sizeof(BSBloodSplatterShaderProperty) == 0xB0);
}
