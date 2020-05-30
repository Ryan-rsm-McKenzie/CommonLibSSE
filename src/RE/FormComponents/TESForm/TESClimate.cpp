#include "RE/TESClimate.h"


namespace RE
{
	std::tm TESClimate::Timing::Interval::ConvertInterval(UInt8 a_time) const
	{
		std::tm result;
		result.tm_sec = 0;
		result.tm_min = (a_time * 10) % 60;
		result.tm_hour = (a_time * 10) / 60;
		result.tm_mday = 0;
		result.tm_mon = 0;
		result.tm_year = 0;
		result.tm_wday = 0;
		result.tm_yday = 0;
		result.tm_isdst = 0;
		return result;
	}


	std::tm TESClimate::Timing::Interval::GetBeginTime() const
	{
		return ConvertInterval(begin);
	}


	std::tm TESClimate::Timing::Interval::GetEndTime() const
	{
		return ConvertInterval(end);
	}


	bool TESClimate::Timing::IncludesMasser() const
	{
		return (moonPhaseLength & MoonPhaseLength::kMasser) != MoonPhaseLength::kNone;
	}


	bool TESClimate::Timing::IncludesSecunda() const
	{
		return (moonPhaseLength & MoonPhaseLength::kSecunda) != MoonPhaseLength::kNone;
	}


	UInt8 TESClimate::Timing::GetPhaseLength() const
	{
		return static_cast<UInt8>(moonPhaseLength & MoonPhaseLength::kPhaseLengthMask);
	}
}
