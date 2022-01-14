#pragma once

#include "RE/B/BSTArray.h"
#include "RE/F/FormTypes.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESTexture.h"

namespace RE
{
	union SETTING_VALUE
	{
		float         f;
		std::uint32_t i;
	};
	static_assert(sizeof(SETTING_VALUE) == 0x4);

	class BGSShaderParticleGeometryData : public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSShaderParticleGeometryData;
		inline static constexpr auto VTABLE = VTABLE_BGSShaderParticleGeometryData;
		inline static constexpr auto FORMTYPE = FormType::ShaderParticleGeometryData;

		enum class DataID
		{
			kGravityVelocity = 0,
			kRotationVelocity,
			kParticleSizeX,
			kParticleSizeY,
			kCenterOffsetMin,
			kCenterOffsetMax,
			kStartRotationRange,
			kNumSubtexturesX,
			kNumSubtexturesY,
			kParticleType,
			kBoxSize,
			kParticleDensity,

			kTotal
		};

		enum class ParticleType
		{
			kRain = 0,
			kSnow = 1
		};

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};

		~BGSShaderParticleGeometryData() override;  // 00

		// override (TESForm)
		void InitializeData() override;      // 04
		void ClearData() override;           // 05
		bool Load(TESFile* a_mod) override;  // 06
		void InitItemImpl() override;        // 13

		BSTArray<SETTING_VALUE> data;             // 20 - DATA - size == DataID::kTotal
		TESTexture              particleTexture;  // 38 - ICON
	};
	static_assert(sizeof(BGSShaderParticleGeometryData) == 0x48);
}
