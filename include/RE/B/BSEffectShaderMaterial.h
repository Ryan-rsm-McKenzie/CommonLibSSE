#pragma once

#include "RE/B/BSShaderMaterial.h"
#include "RE/N/NiColor.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class NiSourceTexture;

	class BSEffectShaderMaterial : public BSShaderMaterial
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSEffectShaderMaterial;

		~BSEffectShaderMaterial() override;  // 00

		// override (BSShaderMaterial)
		BSShaderMaterial* Create() override = 0;                            // 01
		void              CopyMembers(BSShaderMaterial* a_other) override;  // 02
		bool              DoIsCopy(BSShaderMaterial* a_other) override;     // 03
		std::uint32_t     ComputeCRC32(void) override;                      // 04
		BSShaderMaterial* GetDefault() override;                            // 05
		Type              GetType() const override;                         // 07 - { return Type::kEffect; }

		// members
		float                      falloffStartAngle;     // 38
		float                      falloffStopAngle;      // 3C
		float                      falloffStartOpacity;   // 40
		float                      falloffStopOpacity;    // 44
		NiColorA                   baseColor;             // 48
		NiPointer<NiSourceTexture> sourceTexture;         // 58
		NiPointer<NiSourceTexture> greyscaleTexture;      // 60
		float                      softFalloffDepth;      // 68
		float                      baseColorScale;        // 6C
		BSFixedString              sourceTexturePath;     // 70
		BSFixedString              greyscaleTexturePath;  // 78
		std::uint8_t               effectClampMode;       // 80
		std::uint8_t               unk81;                 // 81
	};
	static_assert(sizeof(BSEffectShaderMaterial) == 0x88);
}
