#pragma once

#include "RE/BSTArray.h"
#include "RE/FormTypes.h"
#include "RE/TESForm.h"
#include "RE/TESTexture.h"


namespace RE
{
	union SETTING_VALUE
	{
		float  f;
		UInt32 i;
	};
	STATIC_ASSERT(sizeof(SETTING_VALUE) == 0x4);


	class BGSShaderParticleGeometryData : public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSShaderParticleGeometryData;
		inline static constexpr auto FORMTYPE = FormType::ShaderParticleGeometryData;


		enum class DataID : UInt32
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


		enum class ParticleType : UInt32
		{
			kRain = 0,
			kSnow = 1
		};


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~BGSShaderParticleGeometryData();  // 00

		// override (TESForm)
		virtual void InitializeData() override;		 // 04
		virtual void ClearData() override;			 // 05
		virtual bool Load(TESFile* a_mod) override;	 // 06
		virtual void InitItemImpl() override;		 // 13


		BSTArray<SETTING_VALUE> data;			  // 20 - DATA - size == DataID::kTotal
		TESTexture				particleTexture;  // 38 - ICON
	};
	STATIC_ASSERT(sizeof(BGSShaderParticleGeometryData) == 0x48);
}
