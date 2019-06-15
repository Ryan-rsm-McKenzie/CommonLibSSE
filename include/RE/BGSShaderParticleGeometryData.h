#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSShaderParticleGeometryData

#include "RE/BSTArray.h"  // BSTArray
#include "RE/FormTypes.h"  // FormType
#include "RE/TESForm.h"  // TESForm
#include "RE/TESTexture.h"  // TESTexture


namespace RE
{
	class BGSShaderParticleGeometryData : public TESForm
	{
	public:
		inline static const void* RTTI = RTTI_BGSShaderParticleGeometryData;


		enum { kTypeID = FormType::ShaderParticleGeometryData };


		struct Entries
		{
			enum Entry : UInt32
			{
				kGravityVelocity = 0,
				kRotationVelocity,
				kParticleSizeX,
				kParticleSizeY,
				kCenterOffsetMin,
				kCenterOffsetMax,
				kInitialRotationRange,
				kNumSubtexturesX,
				kNumSubtexturesY,
				kType,
				kBoxSize,
				kParticleDensity,

				kTotal
			};
		};


		struct Types
		{
			enum Type : UInt32
			{
				kRain = 0,
				kSnow = 1
			};
		};


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		union Entry
		{
			float	f;
			UInt32	i;
		};
		STATIC_ASSERT(sizeof(Entry) == 0x4);


		virtual ~BGSShaderParticleGeometryData();			// 00

		// override (TESForm)
		virtual void	InitDefaults() override;			// 04
		virtual void	ReleaseManagedData() override;		// 05
		virtual bool	LoadForm(TESFile* a_mod) override;	// 06
		virtual void	InitItem() override;				// 13


		BSTArray<Entry>	data;				// 20 - DATA - size == Entries::kTotal
		TESTexture		particleTexture;	// 38 - ICON
	};
	STATIC_ASSERT(sizeof(BGSShaderParticleGeometryData) == 0x48);
}
