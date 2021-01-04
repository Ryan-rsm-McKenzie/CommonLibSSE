#pragma once

#include "RE/B/BSTSingleton.h"

namespace RE
{
	class TESGlobal;

	class Calendar : public BSTSingletonSDM<Calendar>
	{
	public:
		static constexpr std::uint8_t DAYS_IN_MONTH[] = {
			31,	 // Morning Star
			28,	 // Sun's Dawn
			31,	 // First Seed
			30,	 // Rain's Hand
			31,	 // Second Seed
			30,	 // Midyear
			31,	 // Sun's Height
			31,	 // Last Seed
			30,	 // Hearthfire
			31,	 // Frostfall
			30,	 // Sun's Dusk
			31	 // Evening Star
		};

		struct Days
		{
			enum Day
			{
				kSundas,
				kMorndas,
				kTirdas,
				kMiddas,
				kTurdas,
				kFredas,
				kLoredas,
				kTotal
			};
		};
		using Day = Days::Day;

		struct Months
		{
			enum Month
			{
				kMorningStar,
				kSunsDawn,
				kFirstSeed,
				kRainsHand,
				kSecondSeed,
				kMidyear,
				kSunsHeight,
				kLastSeed,
				kHearthfire,
				kFrostfall,
				kSunsDusk,
				kEveningStar,
				kTotal
			};
		};
		using Month = Months::Month;

		static Calendar* GetSingleton();

		float		  GetCurrentGameTime() const;
		float		  GetDay() const;
		std::string	  GetDayName() const;
		std::uint32_t GetDayOfWeek() const;
		float		  GetDaysPassed() const;
		void		  GetTimeDateString(char* a_dest, std::uint32_t a_max, bool a_showYear) const;
		float		  GetHour() const;
		float		  GetHoursPassed() const;
		std::uint32_t GetMonth() const;
		std::string	  GetMonthName() const;
		std::tm		  GetTime() const;
		float		  GetTimescale() const;
		std::uint32_t GetYear() const;

		// members
		std::uint8_t  pad01;			// 01
		std::uint16_t pad02;			// 02
		std::uint32_t pad04;			// 04
		TESGlobal*	  gameYear;			// 08
		TESGlobal*	  gameMonth;		// 10
		TESGlobal*	  gameDay;			// 18
		TESGlobal*	  gameHour;			// 20
		TESGlobal*	  gameDaysPassed;	// 28
		TESGlobal*	  timeScale;		// 30
		std::uint32_t midnightsPassed;	// 38
		float		  rawDaysPassed;	// 3C
	};
	static_assert(sizeof(Calendar) == 0x40);
}
