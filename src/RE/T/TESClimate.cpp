#include "RE/T/TESClimate.h"

namespace RE
{
	std::tm TESClimate::Timing::Interval::ConvertInterval(std::uint8_t a_time) const
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
		return moonPhaseLength.all(MoonPhaseLength::kMasser);
	}

	bool TESClimate::Timing::IncludesSecunda() const
	{
		return moonPhaseLength.all(MoonPhaseLength::kSecunda);
	}

	std::uint8_t TESClimate::Timing::GetPhaseLength() const
	{
		return (moonPhaseLength & MoonPhaseLength::kPhaseLengthMask).underlying();
	}
}
