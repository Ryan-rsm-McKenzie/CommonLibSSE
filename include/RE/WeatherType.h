#pragma once


namespace RE
{
	class TESGlobal;
	class TESWeather;


	struct WeatherType
	{
		TESWeather*	weather;	// 00
		UInt32		chance;		// 08
		UInt32		unk0C;		// 0C
		TESGlobal*	global;		// 10
	};
	STATIC_ASSERT(sizeof(WeatherType) == 0x18);
}
