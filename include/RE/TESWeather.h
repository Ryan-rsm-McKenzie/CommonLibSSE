#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESWeather

#include "RE/BSTArray.h"  // BSTArray
#include "RE/BSTList.h"  // BSSimpleList
#include "RE/Color.h"  // Color
#include "RE/DirectionalAmbientLightingColor.h"  // DirectionalAmbientLightingColor
#include "RE/FormTypes.h"  // FormType, TESObjectSTAT
#include "RE/TESForm.h"  // TESForm
#include "RE/TESModel.h"  // TESModel
#include "RE/TESTexture1024.h"  // TESTexture1024


namespace RE
{
	class BGSVolumetricLighting;


	class TESWeather : public TESForm
	{
	public:
		inline static const void* RTTI = RTTI_TESWeather;


		enum { kTypeID = FormType::Weather };


		enum { kTotalLayers = 32 };


		struct TimePeriods
		{
			enum
			{
				kSunrise = 0,
				kDay,
				kSunset,
				kNight,

				kTotal
			};
		};


		struct ColorTypes
		{
			enum
			{
				kSkyUpper = 0,
				kFogNear,
				kUnknown,
				kAmbient,
				kSunlight,
				kSun,
				kStars,
				kSkyLower,
				kHorizon,
				kEffectLighting,
				kCloudLODDiffuse,
				kCloudLODAmbient,
				kFogFar,
				kSkyStatics,
				kWaterMultiplier,
				kSunGlare,
				kMoonGlare,

				kTotal
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


		struct CloudSpeed
		{
			UInt8	ySpeed[kTotalLayers];	// 00 - RNAM
			UInt8	xSpeed[kTotalLayers];	// 20 - QNAM
		};
		STATIC_ASSERT(sizeof(CloudSpeed) == 0x40);


		struct ColorLayer
		{
			Color time[TimePeriods::kTotal];	// 00
		};
		STATIC_ASSERT(sizeof(ColorLayer) == 0x10);


		struct AlphaLayer
		{
			float time[TimePeriods::kTotal];	// 00
		};
		STATIC_ASSERT(sizeof(AlphaLayer) == 0x10);


		struct Data	// DATA
		{
			enum class Flag : UInt8
			{
				kNone = 0,
				kWeather_Pleasant = 1 << 0,
				kWeather_Cloudy = 1 << 1,
				kWeather_Rainy = 1 << 2,
				kWeather_Snowy = 1 << 3,
				kSkyStatic_AlwaysVisible = 1 << 4,
				kSkyStatic_FollowsSunPosition = 1 << 5
			};


			struct Color3
			{
				UInt8	red;	// 0
				UInt8	green;	// 1
				UInt8	blue;	// 2
			};
			STATIC_ASSERT(sizeof(Color3) == 0x3);


			UInt8	windSpeed;						// 00
			UInt8	unk01;							// 01
			UInt8	unk02;							// 02
			UInt8	transDelta;						// 03
			UInt8	sunGlare;						// 04
			UInt8	sunDamage;						// 05
			UInt8	precipitationBeginFadeIn;		// 06
			UInt8	precipitationEndFadeOut;		// 07
			UInt8	thunderLightningBeginFadeIn;	// 08
			UInt8	thunderLightningEndFadeOut;		// 09
			UInt8	thunderLightningFrequency;		// 0A
			Flag	flags;							// 0B
			Color3	lightningColor;					// 0C
			UInt8	visualEffectBegin;				// 0F
			UInt8	visualEffectEnd;				// 10
			UInt8	windDirection;					// 11
			UInt8	windDirectionRange;				// 12
			UInt8	unk13;							// 13
		};
		STATIC_ASSERT(sizeof(Data) == 0x14);


		struct FogDistance	// FNAM
		{
			float	dayNear;	// 00
			float	dayFar;		// 04
			float	nightNear;	// 08
			float	nightFar;	// 0C
			float	dayPower;	// 10
			float	nightPower;	// 14
			float	dayMax;		// 18
			float	nightMax;	// 1C
		};
		STATIC_ASSERT(sizeof(FogDistance) == 0x20);


		struct Sound	// SNAM
		{
			enum class Type : UInt32
			{
				kDefault = 0,
				kPrecipitation = 1,
				kWind = 2,
				kThunder = 3
			};


			UInt32	soundFormID;	// 00
			Type	type;			// 04
		};
		STATIC_ASSERT(sizeof(Sound) == 0x8);


		virtual ~TESWeather();								// 00

		// override (TESForm)
		virtual void	InitDefaults() override;			// 04
		virtual void	ReleaseManagedData() override;		// 05
		virtual bool	LoadForm(TESFile* a_mod) override;	// 06
		virtual void	InitItem() override;				// 13


		// members
		TESTexture1024					cloudTextureLayers[kTotalLayers];						// 020 - 00TX - L0TX
		CloudSpeed						cloudSpeed;												// 220
		ColorLayer						cloudColors[kTotalLayers];								// 260 - PNAM
		AlphaLayer						cloudAlphas[kTotalLayers];								// 460 - JNAM
		UInt32							disabledCloudLayers;									// 660 - NAM1 - bitfield
		Data							data;													// 664 - DATA
		FogDistance						fogDistance;											// 678 - FNAM
		ColorLayer						weatherColors[ColorTypes::kTotal];						// 698 - NAM0
		BSSimpleList<Sound*>			sounds;													// 7A8
		BSTArray<TESObjectSTAT*>		skyStatics;												// 7B8
		UInt32							unk7D0;													// 7D0 - LNAM
		UInt32							unk7D4;													// 7D4
		TESImageSpace*					imageSpaces[TimePeriods::kTotal];						// 7D8 - IMSP
		DirectionalAmbientLightingColor	directionalAmbientLightingColors[TimePeriods::kTotal];	// 7F8
		TESModel						aurora;													// 878
		UInt64							unk8A0;													// 8A0
		BGSVolumetricLighting*			volumetricLighting[TimePeriods::kTotal];				// 8A8 - HNAM
		BGSShaderParticleGeometryData*	precipitationType;										// 8C8 - MNAM
		BGSReferenceEffect*				visualEffect;											// 8D0 - NNAM
	};
	STATIC_ASSERT(sizeof(TESWeather) == 0x8D8);
}
