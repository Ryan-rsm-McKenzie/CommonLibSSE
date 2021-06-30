#pragma once

#include "RE/B/BSShaderProperty.h"
#include "RE/B/BSTArray.h"

namespace RE
{
	class NiColor;

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

		~BSLightingShaderProperty() override;  // 00

		// override (BSShaderProperty)
		const NiRTTI* GetRTTI() const override;                           // 02
		NiObject*     CreateClone(NiCloningProcess& a_cloning) override;  // 17
		void          LoadBinary(NiStream& a_stream) override;            // 18
		void          LinkObject(NiStream& a_stream) override;            // 19
		bool          RegisterStreamables(NiStream& a_stream) override;   // 1A
		void          SaveBinary(NiStream& a_stream) override;            // 1B
		bool          IsEqual(NiObject* a_object) override;               // 1C - { return false; }
		void          PostLinkObject(NiStream& a_stream) override;        // 1E
		void          Unk_27(void) override;                              // 27
		void          Unk_28(void) override;                              // 28
		void          Unk_2A(void) override;                              // 2A
		void          Unk_2B(void) override;                              // 2B
		void          Unk_2C(void) override;                              // 2C
		void          Unk_2D(void) override;                              // 2D
		void          Unk_2F(void) override;                              // 2F
		void          Unk_30(void) override;                              // 30
		void          Unk_31(void) override;                              // 31
		void          Unk_32(void) override;                              // 32
		void          Unk_33(void) override;                              // 33
		void          Unk_34(void) override;                              // 34
		void          Unk_35(void) override;                              // 35 - { return 11; }
		void          Unk_37(void) override;                              // 37
		bool          AcceptsEffectData() const override;                 // 39 - { return !(flags & kRefraction) && !(flags & kTempRefraction); }
		void          Unk_3B(void) override;                              // 3B
		void          Unk_3D(void) override;                              // 3D
		void          Unk_3E(void) override;                              // 3E - { return 2; }

		// members
		Data            unk088[3];      // 088
		Data            unk0B8;         // 0B8
		Data            unk0C8;         // 0C8
		Data            unk0D8;         // 0D8
		std::uint64_t   unk0E8;         // 0E8
		NiColor*        emissiveColor;  // 0F0
		float           emissiveMult;   // 0F8
		std::uint32_t   unk0FC;         // 0FC
		std::uint64_t   unk100;         // 100
		std::uint64_t   unk108;         // 108
		std::uint64_t   unk110;         // 110
		std::uint64_t   unk118;         // 118
		std::uint64_t   unk120;         // 120
		std::uint64_t   unk128;         // 128
		std::uint64_t   unk130;         // 130
		BSTArray<void*> unk138;         // 138
		std::uint64_t   unk150;         // 150
		std::uint64_t   unk158;         // 158
	};
	static_assert(sizeof(BSLightingShaderProperty) == 0x160);
}
