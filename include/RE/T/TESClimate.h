#pragma once

#include "RE/B/BSTList.h"
#include "RE/F/FormTypes.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESModel.h"
#include "RE/T/TESTexture.h"
#include "RE/W/WeatherType.h"

namespace RE
{
	class TESClimate : public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESClimate;
		inline static constexpr auto FORMTYPE = FormType::Climate;

		struct SkyObjects
		{
			enum SkyObject
			{
				kSun,
				kSunGlare,

				kTotal
			};
		};
		using SkyObject = SkyObjects::SkyObject;

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};

		struct Timing
		{
		public:
			enum class MoonPhaseLength
			{
				kPhaseLengthMask = 0x3F,

				kNone = 0,
				kMasser = 1 << 6,
				kSecunda = 1 << 7
			};

			struct Interval
			{
			public:
				std::tm ConvertInterval(std::uint8_t a_time) const;
				std::tm GetBeginTime() const;
				std::tm GetEndTime() const;

				// members
				std::uint8_t begin;	 // 0
				std::uint8_t end;	 // 1
			};
			static_assert(sizeof(Interval) == 0x2);

			bool		 IncludesMasser() const;
			bool		 IncludesSecunda() const;
			std::uint8_t GetPhaseLength() const;

			// members
			Interval										sunrise;		  // 0
			Interval										sunset;			  // 2
			std::uint8_t									volatility;		  // 4
			stl::enumeration<MoonPhaseLength, std::uint8_t> moonPhaseLength;  // 5
			std::uint8_t									unk6;			  // 6
			std::uint8_t									unk7;			  // 7
		};
		static_assert(sizeof(Timing) == 0x8);

		virtual ~TESClimate();	// 00

		// override (TESForm)
		virtual void InitializeData() override;		 // 04
		virtual bool Load(TESFile* a_mod) override;	 // 06

		// members
		TESModel				   nightSky;						// 20
		BSSimpleList<WeatherType*> weatherList;						// 48 - WLST
		TESTexture				   skyObjects[SkyObjects::kTotal];	// 58 - FNAM - GNAM
		Timing					   timing;							// 78 - TNAM
	};
	static_assert(sizeof(TESClimate) == 0x80);
}
