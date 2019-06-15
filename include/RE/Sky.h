#pragma once

#include "skse64/GameRTTI.h"  // RTTI_Sky

#include "RE/BSTArray.h"  // BSTArray
#include "RE/BSTextureSet.h"  // NiSourceTexture
#include "RE/SkyEffectController.h"  // SkyEffectController


namespace RE
{
	class Atmosphere;
	class BSMultiBoundNode;
	class Clouds;
	class Moon;
	class NiNode;
	class Precipitation;
	class Stars;
	class Sun;
	class TESClimate;
	class TESRegion;
	class TESWeather;


	class Sky
	{
	public:
		inline static const void* RTTI = RTTI_Sky;


		virtual ~Sky();	// 00

		static Sky* GetSingleton();


		// members
		BSMultiBoundNode*			unkBSMultiBoundNode;	// 008
		NiNode*						unkNode;				// 010
		UInt64						unk018;					// 018
		UInt64						unk020;					// 020
		UInt64						unk028;					// 028
		UInt64						unk030;					// 030
		UInt64						unk038;					// 038
		TESClimate*					climate;				// 040
		TESWeather*					currentWeather;			// 048 - current weather active or being transitioned to
		TESWeather*					outgoingWeather;		// 050 - previous weather during transition
		TESWeather*					nextWeather;			// 058 - next weather in queue, transition hasn't begun yet
		UInt64						unk060;					// 060
		TESRegion*					region;					// 068
		Atmosphere*					atmosphere;				// 070
		Stars*						stars;					// 078
		Sun*						sun;					// 080
		Clouds*						clouds;					// 088
		Moon*						masser;					// 090
		Moon*						secunda;				// 098
		Precipitation*				precipitation;			// 0A0
		float						unk0A8[61];				// 0A8
		UInt32						unk19C;					// 19C
		UInt32						unk1A0;					// 1A0
		UInt32						unk1A4;					// 1A4
		float						unk1A8;					// 1A8
		float						unk1AC;					// 1AC
		float						timeOfDay;				// 1B0 - time of day as float 0.0~24.0
		float						unk1B4;					// 1B4
		float						transition;				// 1B8 - weather transition amount 0.0 -> 1.0
		UInt32						skyMode;				// 1BC
		void*						unk1C0;					// 1C0
		UInt32						unk1C8;					// 1C8
		UInt32						unk1CC;					// 1CC
		UInt32						unk1D0;					// 1D0
		float						unk1D4;					// 1D4
		UInt32						unk1D8;					// 1D8
		UInt32						unk1DC;					// 1DC
		UInt64						unk1E0;					// 1E0
		UInt64						unk1E8;					// 1E8
		UInt64						unk1F0;					// 1F0
		float						unk1F8[32];				// 1F8
		SkyEffectController			skyEffectController;	// 278
		BSTArray<void*>				unk280;					// 280
		BSTArray<NiSourceTexture>	textures;				// 298
		BSTArray<void*>				unk2B0;					// 2B0
	};
	STATIC_ASSERT(offsetof(Sky, unkBSMultiBoundNode) == 0x008);
	STATIC_ASSERT(offsetof(Sky, currentWeather) == 0x048);
	STATIC_ASSERT(offsetof(Sky, transition) == 0x1B8);
	STATIC_ASSERT(sizeof(Sky) == 0x2C8);
}
