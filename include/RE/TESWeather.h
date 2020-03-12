#pragma once

#include "RE/BGSDirectionalAmbientLightingColors.h"
#include "RE/BSTArray.h"
#include "RE/BSTList.h"
#include "RE/Color.h"
#include "RE/FormTypes.h"
#include "RE/TESForm.h"
#include "RE/TESModel.h"
#include "RE/TESTexture1024.h"


namespace RE
{
	class BGSVolumetricLighting;


	class TESWeather : public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESWeather;
		inline static constexpr auto FORMTYPE = FormType::Weather;


		enum
		{
			kTotalLayers = 32
		};


		enum class SoundType : UInt32
		{
			kDefault = 0,
			kPrecip = 1,
			kWind = 2,
			kThunder = 3
		};


		enum class WeatherDataFlag : UInt8
		{
			kNone = 0,
			kPleasant = 1 << 0,
			kCloudy = 1 << 1,
			kRainy = 1 << 2,
			kSnow = 1 << 3,
			kPermAurora = 1 << 4,
			kAuroraFollowsSun = 1 << 5
		};


		struct ColorTimes
		{
			enum ColorTime : UInt32
			{
				kSunrise = 0,
				kDay,
				kSunset,
				kNight,

				kTotal
			};
		};
		using ColorTime = ColorTimes::ColorTime;


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


		struct Data	 // DATA
		{
			struct Color3
			{
				SInt8 red;	  // 0
				SInt8 green;  // 1
				SInt8 blue;	  // 2
			};
			STATIC_ASSERT(sizeof(Color3) == 0x3);


			SInt8			windSpeed;					  // 00
			SInt8			unk01;						  // 01
			SInt8			unk02;						  // 02
			SInt8			transDelta;					  // 03
			SInt8			sunGlare;					  // 04
			SInt8			sunDamage;					  // 05
			SInt8			precipitationBeginFadeIn;	  // 06
			SInt8			precipitationEndFadeOut;	  // 07
			SInt8			thunderLightningBeginFadeIn;  // 08
			SInt8			thunderLightningEndFadeOut;	  // 09
			SInt8			thunderLightningFrequency;	  // 0A
			WeatherDataFlag flags;						  // 0B
			Color3			lightningColor;				  // 0C
			SInt8			visualEffectBegin;			  // 0F
			SInt8			visualEffectEnd;			  // 10
			SInt8			windDirection;				  // 11
			SInt8			windDirectionRange;			  // 12
			SInt8			unk13;						  // 13
		};
		STATIC_ASSERT(sizeof(Data) == 0x14);


		struct FogData	// FNAM
		{
			float dayNear;	   // 00
			float dayFar;	   // 04
			float nightNear;   // 08
			float nightFar;	   // 0C
			float dayPower;	   // 10
			float nightPower;  // 14
			float dayMax;	   // 18
			float nightMax;	   // 1C
		};
		STATIC_ASSERT(sizeof(FogData) == 0x20);


		struct WeatherSound	 // SNAM
		{
			FormID	  soundFormID;	// 00
			SoundType type;			// 04
		};
		STATIC_ASSERT(sizeof(WeatherSound) == 0x8);


		struct WeatherSoundList : public BSSimpleList<WeatherSound*>
		{};


		virtual ~TESWeather();	// 00

		// override (TESForm)
		virtual void InitializeData() override;		 // 04
		virtual void ClearData() override;			 // 05
		virtual bool Load(TESFile* a_mod) override;	 // 06
		virtual void InitItemImpl() override;		 // 13


		// members
		TESTexture1024						cloudTextures[kTotalLayers];						  // 020 - 00TX - L0TX
		SInt8								cloudLayerSpeedY[kTotalLayers];						  // 220 - RNAM
		SInt8								cloudLayerSpeedX[kTotalLayers];						  // 240 - QNAM
		Color								cloudColorData[kTotalLayers][ColorTime::kTotal];	  // 260 - PNAM
		float								cloudAlpha[kTotalLayers][ColorTime::kTotal];		  // 460 - JNAM
		UInt32								cloudLayerDisabledBits;								  // 660 - NAM1 - bitfield
		Data								data;												  // 664 - DATA
		FogData								fogData;											  // 678 - FNAM
		Color								colorData[ColorTypes::kTotal][ColorTime::kTotal];	  // 698 - NAM0
		WeatherSoundList					sounds;												  // 7A8
		BSTArray<TESObjectSTAT*>			skyStatics;											  // 7B8
		UInt32								numCloudLayers;										  // 7D0 - LNAM
		UInt32								pad7D4;												  // 7D4
		TESImageSpace*						imageSpaces[ColorTime::kTotal];						  // 7D8 - IMSP
		BGSDirectionalAmbientLightingColors directionalAmbientLightingColors[ColorTime::kTotal];  // 7F8
		TESModel							aurora;												  // 878
		BGSLensFlare*						sunGlareLensFlare;									  // 8A0
		BGSVolumetricLighting*				volumetricLighting[ColorTime::kTotal];				  // 8A8 - HNAM
		BGSShaderParticleGeometryData*		precipitationData;									  // 8C8 - MNAM
		BGSReferenceEffect*					referenceEffect;									  // 8D0 - NNAM
	};
	STATIC_ASSERT(sizeof(TESWeather) == 0x8D8);
}
