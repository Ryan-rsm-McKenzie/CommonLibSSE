#pragma once

#include "RE/B/BSShaderProperty.h"

namespace RE
{
	class NiColor;

	class BSEffectShaderProperty : public BSShaderProperty
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSEffectShaderProperty;
		inline static constexpr auto Ni_RTTI = NiRTTI_BSEffectShaderProperty;

		~BSEffectShaderProperty() override;  // 00

		// override (BSShaderProperty)
		const NiRTTI*    GetRTTI() const override;                             // 02
		NiObject*        CreateClone(NiCloningProcess& a_cloning) override;    // 17 - { return 0; }
		void             LoadBinary(NiStream& a_stream) override;              // 18
		void             LinkObject(NiStream& a_stream) override;              // 19 - { NiShadeProperty::LinkObject(a_stream); }
		void             SaveBinary(NiStream& a_stream) override;              // 1B
		void             PostLinkObject(NiStream& a_stream) override;          // 1E - { NiObjectNET::PostLinkObject(a_stream); }
		bool             InitializeGeometry(BSGeometry* a_geometry) override;  // 27 - { return 1; }
		void             Unk_2A(void) override;                                // 2A
		void             Unk_2B(void) override;                                // 2B - { return 0; }
		void             SetMaterialAlpha(float a_alpha) override;             // 31 - { baseColor->alpha = a_alpha }
		float            GetMaterialAlpha() override;                          // 32 - { baseColor->alpha }
		void             Unk_33(void) override;                                // 33
		void             Unk_35(void) override;                                // 35 - { return 1; }
		NiSourceTexture* GetPrimaryTexture() override;                         // 37 - { return unk58 }
		void             Unk_3B(void) override;                                // 3B - { return; }
		void             Unk_3C(void) override;                                // 3C - { return 1; }
		void             Unk_3E(void) override;                                // 3E - { return 1; }

		// members
		NiColor*      unk88;  // 88
		std::uint64_t unk90;  // 90
		std::uint64_t unk98;  // 98
	};
	static_assert(sizeof(BSEffectShaderProperty) == 0xA0);
}
