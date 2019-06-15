#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESClimate

#include <ctime>  // tm

#include "RE/BSTList.h"  // BSSimpleList
#include "RE/FormTypes.h"  // FormType
#include "RE/TESForm.h"  // TESForm
#include "RE/TESModel.h"  // TESModel
#include "RE/TESTexture.h"  // TESTexture
#include "RE/WeatherType.h"  // WeatherType


namespace RE
{
	class TESClimate : public TESForm
	{
	public:
		inline static const void* RTTI = RTTI_TESClimate;


		enum { kTypeID = FormType::Climate };


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
				std::tm	ConvertInterval(UInt8 a_time) const;
				std::tm	GetBeginTime() const;
				std::tm	GetEndTime() const;


				UInt8	begin;	// 0
				UInt8	end;	// 1
			};
			STATIC_ASSERT(sizeof(Interval) == 0x2);


			bool	IncludesMasser() const;
			bool	IncludesSecunda() const;
			UInt8	GetPhaseLength() const;


			Interval		sunrise;			// 0
			Interval		sunset;				// 2
			UInt8			volatility;			// 4
			MoonPhaseLength	moonPhaseLength;	// 5
			UInt8			unk6;				// 6
			UInt8			unk7;				// 7
		};
		STATIC_ASSERT(sizeof(Timing) == 0x8);


		virtual ~TESClimate();								// 00

		// override (TESForm)
		virtual void	InitDefaults() override;			// 04
		virtual bool	LoadForm(TESFile* a_mod) override;	// 06


		// members
		TESModel					model;				// 20
		BSSimpleList<WeatherType*>	weatherTypes;		// 48 - WLST
		TESTexture					sunTexture;			// 58 - FNAM
		TESTexture					sunGlareTexture;	// 68 - GNAM
		Timing						timing;				// 78 - TNAM
	};
	STATIC_ASSERT(sizeof(TESClimate) == 0x80);
}
