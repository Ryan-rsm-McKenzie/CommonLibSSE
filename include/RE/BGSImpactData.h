#pragma once

#include "RE/Color.h"
#include "RE/FormTypes.h"
#include "RE/SoundLevels.h"
#include "RE/TESForm.h"
#include "RE/TESModel.h"


namespace RE
{
	struct DECAL_DATA_DATA
	{
		enum class Flag : UInt8
		{
			kNone = 0,
			kParallax = 1 << 0,
			kAlpha_Blending = 1 << 1,
			kAlpha_Testing = 1 << 2,
			kNoSubtextures = 1 << 3
		};


		float	decalMinWidth;	// 00
		float	decalMaxWidth;	// 04
		float	decalMinHeight;	// 08
		float	decalMaxHeight;	// 0C
		float	depth;			// 10
		float	shininess;		// 14
		float	parallaxScale;	// 18
		SInt8	parallaxPasses;	// 1C
		Flag	flags;			// 1D
		UInt16	pad1E;			// 1E
		Color	color;			// 20
	};
	STATIC_ASSERT(sizeof(DECAL_DATA_DATA) == 0x24);


	struct DecalData	// DODT
	{
		DECAL_DATA_DATA data;	// 00
	};
	STATIC_ASSERT(sizeof(DecalData) == 0x24);


	class BGSImpactData :
		public TESForm,	// 00
		public TESModel	// 20
	{
	public:
		inline static const void* RTTI = RTTI_BGSImpactData;


		enum { kTypeID = FormType::Impact };


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


		struct IMPACT_DATA_DATA	// DATA
		{
			enum class Flag : UInt8
			{
				kNone = 0,
				kNoDecalData = 1 << 0
			};


			enum class ImpactResult : UInt8
			{
				kDefault = 0,
				kDestroy = 1,
				kBounce = 2,
				kImpale = 3,
				kStick = 4
			};


			float			effectDuration;		// 00
			ORIENTATION		orient;				// 04
			float			angleThreshold;		// 08
			float			placementRadius;	// 0C
			SOUND_LEVEL		soundLevel;			// 10
			Flag			flags;				// 14
			ImpactResult	resultOverride;		// 18
			UInt16			unk16;				// 1C
		};
		STATIC_ASSERT(sizeof(IMPACT_DATA_DATA) == 0x18);


		virtual ~BGSImpactData();						// 00

		// override (TESForm)
		virtual void	InitializeData() override;		// 04
		virtual bool	Load(TESFile* a_mod) override;	// 06
		virtual void	InitItemImpl() override;		// 13


		// members
		IMPACT_DATA_DATA		data;				// 48 - DATA
		BGSTextureSet*			decalTextureSet;	// 60 - DNAM
		BGSTextureSet*			decalTextureSet2;	// 68 - ENAM
		BGSSoundDescriptorForm*	sound1;				// 70 - SNAM
		BGSSoundDescriptorForm*	sound2;				// 78 - NAM1
		BGSHazard*				hazard;				// 80 - NAM2
		DecalData				dData;				// 88 - DODT
		UInt32					padAC;				// AC
	};
	STATIC_ASSERT(sizeof(BGSImpactData) == 0xB0);
}
