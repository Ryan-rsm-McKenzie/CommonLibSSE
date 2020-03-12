#pragma once

#include "RE/Color.h"
#include "RE/DecalData.h"
#include "RE/FormTypes.h"
#include "RE/ImpactResults.h"
#include "RE/SoundLevels.h"
#include "RE/TESForm.h"
#include "RE/TESModel.h"


namespace RE
{
	class BGSImpactData :
		public TESForm,	 // 00
		public TESModel	 // 20
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSImpactData;
		inline static constexpr auto FORMTYPE = FormType::Impact;


		enum class ORIENTATION : UInt32
		{
			kSurfaceNormal = 0,
			kProjVector = 1,
			kProjReflect = 2
		};


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		struct IMPACT_DATA_DATA	 // DATA
		{
			enum class Flag : UInt8
			{
				kNone = 0,
				kNoDecalData = 1 << 0
			};


			float		  effectDuration;	// 00
			ORIENTATION	  orient;			// 04
			float		  angleThreshold;	// 08
			float		  placementRadius;	// 0C
			SOUND_LEVEL	  soundLevel;		// 10
			Flag		  flags;			// 14
			ImpactResult8 resultOverride;	// 15
			UInt16		  unk16;			// 16
		};
		STATIC_ASSERT(sizeof(IMPACT_DATA_DATA) == 0x18);


		virtual ~BGSImpactData();  // 00

		// override (TESForm)
		virtual void InitializeData() override;		 // 04
		virtual bool Load(TESFile* a_mod) override;	 // 06
		virtual void InitItemImpl() override;		 // 13


		// members
		IMPACT_DATA_DATA		data;			   // 48 - DATA
		BGSTextureSet*			decalTextureSet;   // 60 - DNAM
		BGSTextureSet*			decalTextureSet2;  // 68 - ENAM
		BGSSoundDescriptorForm* sound1;			   // 70 - SNAM
		BGSSoundDescriptorForm* sound2;			   // 78 - NAM1
		BGSHazard*				hazard;			   // 80 - NAM2
		DecalData				dData;			   // 88 - DODT
		UInt32					padAC;			   // AC
	};
	STATIC_ASSERT(sizeof(BGSImpactData) == 0xB0);
}
