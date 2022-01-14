#include "RE/S/Sky.h"

#include "RE/T/TESWeather.h"

namespace RE
{
	Sky* Sky::GetSingleton()
	{
		using func_t = decltype(&Sky::GetSingleton);
		REL::Relocation<func_t> func{ Offset::Sky::GetSingleton };
		return func();
	}

	bool Sky::GetIsSnowing()
	{
		return currentWeather && currentWeather->data.flags.all(TESWeather::WeatherDataFlag::kSnow);
	}
}
