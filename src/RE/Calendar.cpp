#include "RE/Calendar.h"

#include "RE/GameSettingCollection.h"
#include "RE/Offsets.h"
#include "RE/Setting.h"
#include "RE/TESGlobal.h"
#include "REL/Relocation.h"


namespace RE
{
	Calendar* Calendar::GetSingleton()
	{
		REL::Offset<Calendar**> singleton(Offset::Calendar::Singleton);
		return *singleton;
	}


	float Calendar::GetCurrentGameTime() const
	{
		return gameDaysPassed ? gameDaysPassed->value : 1.0;
	}


	float Calendar::GetDay() const
	{
		return gameDay ? gameDay->value : 17.0;
	}


	std::string	Calendar::GetDayName() const
	{
		auto gmst = RE::GameSettingCollection::GetSingleton();
		Setting* setting = 0;

		switch (GetDayOfWeek()) {
		case Day::kSundas:
			setting = gmst->GetSetting("sDaySunday");
			break;
		case Day::kMorndas:
			setting = gmst->GetSetting("sDayMonday");
			break;
		case Day::kTirdas:
			setting = gmst->GetSetting("sDayTuesday");
			break;
		case Day::kMiddas:
			setting = gmst->GetSetting("sDayWednesday");
			break;
		case Day::kTurdas:
			setting = gmst->GetSetting("sDayThursday");
			break;
		case Day::kFredas:
			setting = gmst->GetSetting("sDayFriday");
			break;
		case Day::kLoredas:
			setting = gmst->GetSetting("sDaySaturday");
			break;
		default:
			setting = 0;
			break;
		}

		return setting ? setting->GetString() : "Bad Day";
	}


	UInt32 Calendar::GetDayOfWeek() const
	{
		return static_cast<UInt32>(GetDaysPassed()) % 7;
	}


	float Calendar::GetDaysPassed() const
	{
		return gameDaysPassed ? gameDaysPassed->value : 1.0;
	}


	float Calendar::GetHour() const
	{
		return gameHour ? gameHour->value : 12.0;
	}


	float Calendar::GetHoursPassed() const
	{
		return GetDaysPassed() * 24.0;
	}


	UInt32 Calendar::GetMonth() const
	{
		return gameMonth ? gameMonth->value : 7;
	}


	std::string	Calendar::GetMonthName() const
	{
		auto gmst = RE::GameSettingCollection::GetSingleton();
		Setting* setting = 0;

		switch (GetMonth()) {
		case Month::kMorningStar:
			setting = gmst->GetSetting("sMonthJanuary");
			break;
		case Month::kSunsDawn:
			setting = gmst->GetSetting("sMonthFebruary");
			break;
		case Month::kFirstSeed:
			setting = gmst->GetSetting("sMonthMarch");
			break;
		case Month::kRainsHand:
			setting = gmst->GetSetting("sMonthApril");
			break;
		case Month::kSecondSeed:
			setting = gmst->GetSetting("sMonthMay");
			break;
		case Month::kMidyear:
			setting = gmst->GetSetting("sMonthJune");
			break;
		case Month::kSunsHeight:
			setting = gmst->GetSetting("sMonthJuly");
			break;
		case Month::kLastSeed:
			setting = gmst->GetSetting("sMonthAugust");
			break;
		case Month::kHearthfire:
			setting = gmst->GetSetting("sMonthSeptember");
			break;
		case Month::kFrostfall:
			setting = gmst->GetSetting("sMonthOctober");
			break;
		case Month::kSunsDusk:
			setting = gmst->GetSetting("sMonthNovember");
			break;
		case Month::kEveningStar:
			setting = gmst->GetSetting("sMonthDecember");
			break;
		default:
			setting = 0;
			break;
		}

		return setting ? setting->GetString() : "Bad Month";
	}


	std::tm Calendar::GetTime() const
	{
		std::tm time;

		time.tm_sec = 0;
		time.tm_min = 0;
		time.tm_hour = GetHour();
		time.tm_mday = GetDay();
		time.tm_mon = GetMonth();
		time.tm_year = GetYear();
		time.tm_wday = GetDayOfWeek();

		time.tm_yday = time.tm_mday;
		for (int i = 0; i < time.tm_mon - 1; ++i) {
			time.tm_yday += DAYS_IN_MONTH[i];
		}

		time.tm_isdst = 0;

		return time;
	}


	float Calendar::GetTimescale() const
	{
		return timeScale->value;
	}


	UInt32 Calendar::GetYear() const
	{
		return gameYear ? gameYear->value : 77;
	}
}
