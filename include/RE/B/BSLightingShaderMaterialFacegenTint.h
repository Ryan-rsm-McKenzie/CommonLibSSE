#pragma once

#include "RE/B/BSLightingShaderMaterialBase.h"
#include "RE/N/NiColor.h"

namespace RE
{
	class BSLightingShaderMaterialFacegenTint : public BSLightingShaderMaterialBase
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSLightingShaderMaterialFacegenTint;
		inline static constexpr auto VTABLE = VTABLE_BSLightingShaderMaterialFacegenTint;
		inline static constexpr auto FEATURE = Feature::kFaceGenRGBTint;

		~BSLightingShaderMaterialFacegenTint() override;  // 00

		// override (BSLightingShaderMaterialBase)
		BSShaderMaterial* Create() override;                                // 01
		void              CopyMembers(BSShaderMaterial* a_other) override;  // 02
		std::uint32_t     ComputeCRC32(void) override;                      // 04
		Feature           GetFeature() const override;                      // 06 - { return Feature::kFaceGenRGBTint; }
		void              SaveBinary(NiStream& a_stream) override;          // 0C
		void              LoadBinary(NiStream& a_stream) override;          // 0D

		// members
		NiColor       tintColor;  // A0
		std::uint32_t padAC;      // AC

	protected:
		BSLightingShaderMaterialFacegenTint* ctor()
		{
			using func_t = decltype(&BSLightingShaderMaterialFacegenTint::ctor);
			REL::Relocation<func_t> func{ REL::ID(100087) };
			return func(this);
		}
		friend class BSLightingShaderMaterialBase;
	};
	static_assert(sizeof(BSLightingShaderMaterialFacegenTint) == 0xB0);
}
