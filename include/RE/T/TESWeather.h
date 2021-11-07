#pragma once

#include "RE/B/BGSDirectionalAmbientLightingColors.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTList.h"
#include "RE/C/Color.h"
#include "RE/F/FormTypes.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESModel.h"
#include "RE/T/TESTexture1024.h"

namespace RE
{
	class BGSVolumetricLighting;

	class TESWeather : public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESWeather;
		inline static constexpr auto VTABLE = VTABLE_TESWeather;
		inline static constexpr auto FORMTYPE = FormType::Weather;

		enum
		{
			kTotalLayers = 32
		};

		enum class SoundType
		{
			kDefault = 0,
			kPrecip = 1,
			kWind = 2,
			kThunder = 3
		};

		enum class WeatherDataFlag
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
			enum ColorTime : std::uint32_t
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
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};

		struct Data  // DATA
		{
		public:
			struct Color3
			{
			public:
				// members
				std::int8_t red;    // 0
				std::int8_t green;  // 1
				std::int8_t blue;   // 2
			};
			static_assert(sizeof(Color3) == 0x3);

			// members
			std::int8_t                                     windSpeed;                    // 00
			std::int8_t                                     unk01;                        // 01
			std::int8_t                                     unk02;                        // 02
			std::int8_t                                     transDelta;                   // 03
			std::int8_t                                     sunGlare;                     // 04
			std::int8_t                                     sunDamage;                    // 05
			std::int8_t                                     precipitationBeginFadeIn;     // 06
			std::int8_t                                     precipitationEndFadeOut;      // 07
			std::int8_t                                     thunderLightningBeginFadeIn;  // 08
			std::int8_t                                     thunderLightningEndFadeOut;   // 09
			std::int8_t                                     thunderLightningFrequency;    // 0A
			stl::enumeration<WeatherDataFlag, std::uint8_t> flags;                        // 0B
			Color3                                          lightningColor;               // 0C
			std::int8_t                                     visualEffectBegin;            // 0F
			std::int8_t                                     visualEffectEnd;              // 10
			std::int8_t                                     windDirection;                // 11
			std::int8_t                                     windDirectionRange;           // 12
			std::int8_t                                     unk13;                        // 13
		};
		static_assert(sizeof(Data) == 0x14);

		struct FogData  // FNAM
		{
		public:
			// members
			float dayNear;     // 00
			float dayFar;      // 04
			float nightNear;   // 08
			float nightFar;    // 0C
			float dayPower;    // 10
			float nightPower;  // 14
			float dayMax;      // 18
			float nightMax;    // 1C
		};
		static_assert(sizeof(FogData) == 0x20);

		struct WeatherSound  // SNAM
		{
		public:
			// members
			FormID                                     soundFormID;  // 00
			stl::enumeration<SoundType, std::uint32_t> type;         // 04
		};
		static_assert(sizeof(WeatherSound) == 0x8);

		struct WeatherSoundList : public BSSimpleList<WeatherSound*>
		{};

		~TESWeather() override;  // 00

		// override (TESForm)
		void InitializeData() override;      // 04
		void ClearData() override;           // 05
		bool Load(TESFile* a_mod) override;  // 06
		void InitItemImpl() override;        // 13

		// members
		TESTexture1024                      cloudTextures[kTotalLayers];                          // 020 - 00TX - L0TX
		std::int8_t                         cloudLayerSpeedY[kTotalLayers];                       // 220 - RNAM
		std::int8_t                         cloudLayerSpeedX[kTotalLayers];                       // 240 - QNAM
		Color                               cloudColorData[kTotalLayers][ColorTime::kTotal];      // 260 - PNAM
		float                               cloudAlpha[kTotalLayers][ColorTime::kTotal];          // 460 - JNAM
		std::uint32_t                       cloudLayerDisabledBits;                               // 660 - NAM1 - bitfield
		Data                                data;                                                 // 664 - DATA
		FogData                             fogData;                                              // 678 - FNAM
		Color                               colorData[ColorTypes::kTotal][ColorTime::kTotal];     // 698 - NAM0
		WeatherSoundList                    sounds;                                               // 7A8
		BSTArray<TESObjectSTAT*>            skyStatics;                                           // 7B8
		std::uint32_t                       numCloudLayers;                                       // 7D0 - LNAM
		std::uint32_t                       pad7D4;                                               // 7D4
		TESImageSpace*                      imageSpaces[ColorTime::kTotal];                       // 7D8 - IMSP
		BGSDirectionalAmbientLightingColors directionalAmbientLightingColors[ColorTime::kTotal];  // 7F8
		TESModel                            aurora;                                               // 878
		BGSLensFlare*                       sunGlareLensFlare;                                    // 8A0
		BGSVolumetricLighting*              volumetricLighting[ColorTime::kTotal];                // 8A8 - HNAM
		BGSShaderParticleGeometryData*      precipitationData;                                    // 8C8 - MNAM
		BGSReferenceEffect*                 referenceEffect;                                      // 8D0 - NNAM
	};
	static_assert(sizeof(TESWeather) == 0x8D8);
}
