#pragma once

#include "RE/B/BSShaderProperty.h"
#include "RE/B/BSTArray.h"
#include "RE/N/NiColor.h"

namespace RE
{
	class BSLightingShaderProperty : public BSShaderProperty
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSLightingShaderProperty;
		inline static constexpr auto Ni_RTTI = NiRTTI_BSLightingShaderProperty;

		struct Data
		{
			std::uint64_t unk00;  // 00
			std::uint64_t unk08;  // 08
		};
		static_assert(sizeof(Data) == 0x10);

		virtual ~BSLightingShaderProperty();  // 00

		// override (BSShaderProperty)
		virtual const NiRTTI*    GetRTTI() const override;                             // 02
		virtual NiObject*        CreateClone(NiCloningProcess& a_cloning) override;    // 17
		virtual void             LoadBinary(NiStream& a_stream) override;              // 18
		virtual void             LinkObject(NiStream& a_stream) override;              // 19
		virtual bool             RegisterStreamables(NiStream& a_stream) override;     // 1A
		virtual void             SaveBinary(NiStream& a_stream) override;              // 1B
		virtual bool             IsEqual(NiObject* a_object) override;                 // 1C - { return false; }
		virtual void             PostLinkObject(NiStream& a_stream) override;          // 1E
		virtual bool             InitializeGeometry(BSGeometry* a_geometry) override;  // 27
		virtual bool             InitializeShader(BSGeometry* a_geometry) override;    // 28
		virtual void             Unk_2A(void) override;                                // 2A
		virtual void             Unk_2B(void) override;                                // 2B
		virtual void             Unk_2C(void) override;                                // 2C
		virtual void             Unk_2D(void) override;                                // 2D
		virtual void             Unk_2F(void) override;                                // 2F
		virtual bool             DoIsCopy(BSShaderProperty* a_other) override;         // 30
		virtual void             SetMaterialAlpha(float a_alpha) override;             // 31
		virtual float            GetMaterialAlpha() override;                          // 32
		virtual void             Unk_33(void) override;                                // 33
		virtual void             Unk_34(void) override;                                // 34
		virtual void             Unk_35(void) override;                                // 35 - { return 11; }
		virtual NiSourceTexture* GetPrimaryTexture() override;                         // 37 - { return diffuseTexture }
		virtual bool             AcceptsEffectData() const override;                   // 39 - { return !(flags & kRefraction) && !(flags & kTempRefraction); }
		virtual void             Unk_3B(void) override;                                // 3B
		virtual void             Unk_3D(void) override;                                // 3D
		virtual void             Unk_3E(void) override;                                // 3E - { return 2; }

		void CopyMembers(BSLightingShaderProperty* a_other);

		// members
		Data            unk088[3];          // 088
		Data            unk0B8;             // 0B8
		Data            unk0C8;             // 0C8
		Data            unk0D8;             // 0D8
		std::uint64_t   unk0E8;             // 0E8
		NiColor*        emissiveColor;      // 0F0
		float           emissiveMult;       // 0F8
		float           darknessValue;      // 0FC - unused
		float           specularLODFade;    // 100
		float           envmapLODFade;      // 104
		std::uint32_t   unk108;             // 108
		NiColorA        projectedUVParams;  // 10C
		NiColorA        projectedUVColor;   // 11C
		std::int32_t    unk12C;             // 12C
		std::uint32_t   unk130;             // 130
		std::uint32_t   unk134;             // 134
		BSTArray<void*> unk138;             // 138
		std::uint64_t   unk150;             // 150
		std::uint8_t    unk158;             // 158
		std::uint8_t    pad159;             // 159
		std::uint16_t   pad15A;             // 15A
		std::uint32_t   pad15C;             // 15C
	};
	static_assert(sizeof(BSLightingShaderProperty) == 0x160);
}
