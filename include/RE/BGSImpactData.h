#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSImpactData

#include "RE/Color.h"  // Color
#include "RE/FormTypes.h"  // FormType
#include "RE/SoundLevels.h"  // SoundLevel
#include "RE/TESForm.h"  // TESModel
#include "RE/TESModel.h"  // TESModel


namespace RE
{
	class BGSImpactData :
		public TESForm,	// 00
		public TESModel	// 20
	{
	public:
		inline static const void* RTTI = RTTI_BGSImpactData;


		enum { kTypeID = FormType::Impact };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		struct Data	// DATA
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


			struct Effect
			{
				float	duration;		// 0
				float	orientation;	// 4
			};
			STATIC_ASSERT(sizeof(Effect) == 0x8);


			Effect			effect;				// 00
			float			angleThreshold;		// 08
			float			placementRadius;	// 0C
			SoundLevel		soundLevel;			// 10
			Flag			flags;				// 14
			ImpactResult	impactResult;		// 18
			UInt16			unk16;				// 1c
		};
		STATIC_ASSERT(sizeof(Data) == 0x18);


		struct DecalData	// DODT
		{
			enum class Flag : UInt8
			{
				kNone = 0,
				kParallax = 1 << 0,
				kAlpha_Blending = 1 << 1,
				kAlpha_Testing = 1 << 2,
				kNoSubtextures = 1 << 3
			};


			float		minWidth;		// 00
			float		maxWidth;		// 04
			float		minHeight;		// 08
			float		maxHeight;		// 0C
			float		depth;			// 10
			float		shininess;		// 14
			float		parallaxScale;	// 18
			UInt8		parallaxPasses;	// 1C
			Flag		flags;			// 1D
			UInt16		unk1E;			// 1E
			Color		color;			// 20
		};
		STATIC_ASSERT(sizeof(DecalData) == 0x24);


		virtual ~BGSImpactData();							// 00

		// override (TESForm)
		virtual void	InitDefaults() override;			// 04
		virtual bool	LoadForm(TESFile* a_mod) override;	// 06
		virtual void	InitItem() override;				// 13


		// members
		Data					data;					// 48 - DATA
		BGSTextureSet*			primaryTextureSet;		// 60 - DNAM
		BGSTextureSet*			secondaryTextureSet;	// 68 - ENAM
		BGSSoundDescriptorForm*	sound1;					// 70 - SNAM
		BGSSoundDescriptorForm*	sound2;					// 78 - NAM1
		BGSHazard*				hazard;					// 80 - NAM2
		DecalData				decalData;				// 88 - DODT
		UInt32					padAC;					// AC
	};
	STATIC_ASSERT(sizeof(BGSImpactData) == 0xB0);
}
