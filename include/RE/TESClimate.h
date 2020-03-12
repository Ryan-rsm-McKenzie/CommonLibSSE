#pragma once

#include <ctime>

#include "RE/BSTList.h"
#include "RE/FormTypes.h"
#include "RE/TESForm.h"
#include "RE/TESModel.h"
#include "RE/TESTexture.h"
#include "RE/WeatherType.h"


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
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		struct Timing
		{
			enum class MoonPhaseLength : UInt8
			{
				kPhaseLengthMask = 0x3F,

				kNone = 0,
				kMasser = 1 << 6,
				kSecunda = 1 << 7
			};


			struct Interval
			{
				std::tm ConvertInterval(UInt8 a_time) const;
				std::tm GetBeginTime() const;
				std::tm GetEndTime() const;


				UInt8 begin;  // 0
				UInt8 end;	  // 1
			};
			STATIC_ASSERT(sizeof(Interval) == 0x2);


			bool  IncludesMasser() const;
			bool  IncludesSecunda() const;
			UInt8 GetPhaseLength() const;


			Interval		sunrise;		  // 0
			Interval		sunset;			  // 2
			UInt8			volatility;		  // 4
			MoonPhaseLength moonPhaseLength;  // 5
			UInt8			unk6;			  // 6
			UInt8			unk7;			  // 7
		};
		STATIC_ASSERT(sizeof(Timing) == 0x8);


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
	STATIC_ASSERT(sizeof(TESClimate) == 0x80);
}
