#pragma once

#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTList.h"
#include "RE/B/BSTextureSet.h"
#include "RE/N/NiColor.h"
#include "RE/N/NiSmartPointer.h"
#include "RE/S/SkyEffectController.h"

namespace RE
{
	class Atmosphere;
	class BGSLightingTemplate;
	class BSMultiBoundNode;
	class Clouds;
	class ImageSpaceModifierInstanceForm;
	class Moon;
	class NiNode;
	class NiTexture;
	class Precipitation;
	class ReferenceEffect;
	class SkySound;
	class Stars;
	class Sun;
	class TESClimate;
	class TESRegion;
	class TESWeather;

	class Sky
	{
	public:
		inline static constexpr auto RTTI = RTTI_Sky;

		enum class Mode
		{
			kNone = 0,
			kInterior,
			kSkyDomeOnly,
			kFull,

			kTotal
		};

		struct SkyStaticRefData
		{
		public:
		};

		virtual ~Sky();	 // 00

		static Sky* GetSingleton();

		// members
		NiPointer<BSMultiBoundNode>			  root;							   // 008
		NiPointer<NiNode>					  moonsRoot;					   // 010
		NiPointer<NiNode>					  auroraRoot;					   // 018
		std::uint64_t						  unk020;						   // 020
		BGSLightingTemplate*				  extLightingOverride;			   // 028
		ObjectRefHandle						  currentRoom;					   // 030
		ObjectRefHandle						  previousRoom;					   // 034
		float								  lightingTransition;			   // 038
		float								  lightingTransitionTimer;		   // 03C
		TESClimate*							  currentClimate;				   // 040
		TESWeather*							  currentWeather;				   // 048
		TESWeather*							  lastWeather;					   // 050
		TESWeather*							  defaultWeather;				   // 058
		TESWeather*							  overrideWeather;				   // 060
		TESRegion*							  region;						   // 068
		Atmosphere*							  atmosphere;					   // 070
		Stars*								  stars;						   // 078
		Sun*								  sun;							   // 080
		Clouds*								  clouds;						   // 088
		Moon*								  masser;						   // 090
		Moon*								  secunda;						   // 098
		Precipitation*						  precip;						   // 0A0
		NiColor								  skyColor[17];					   // 0A8
		std::uint32_t						  unk174;						   // 174
		std::uint64_t						  unk178;						   // 178
		std::uint64_t						  unk180;						   // 180
		std::uint64_t						  unk188;						   // 188
		std::uint64_t						  unk190;						   // 190
		std::uint64_t						  unk198;						   // 198
		std::uint32_t						  unk1A0;						   // 1A0
		std::uint32_t						  unk1A4;						   // 1A4
		float								  unk1A8;						   // 1A8
		float								  unk1AC;						   // 1AC
		float								  currentGameHour;				   // 1B0
		float								  lastWeatherUpdate;			   // 1B4
		float								  currentWeatherPct;			   // 1B8
		stl::enumeration<Mode, std::uint32_t> mode;							   // 1BC
		BSSimpleList<SkySound*>*			  skySoundList;					   // 1C0
		float								  flash;						   // 1C8
		std::uint32_t						  pad1CC;						   // 1CC
		std::time_t							  flashTime;					   // 1D0
		std::uint32_t						  lastMoonPhaseUpdate;			   // 1D8
		std::uint32_t						  flags;						   // 1DC
		ImageSpaceModifierInstanceForm*		  currentWeatherImageSpaceMod;	   // 1E0
		ImageSpaceModifierInstanceForm*		  currentWeatherImageSpaceMod2;	   // 1E8
		ImageSpaceModifierInstanceForm*		  lastWeatherImageSpaceMod;		   // 1F0
		ImageSpaceModifierInstanceForm*		  lastWeatherImageSpaceMod2;	   // 1F8
		NiColor								  directionalAmbientColors[3][2];  // 200
		NiColor								  ambientSpecularTint;			   // 248
		float								  ambientSpecularFresnel;		   // 254
		float								  auroraInStart;				   // 258
		float								  auroraIn;						   // 25C
		float								  auroraOutStart;				   // 260
		float								  auroraOut;					   // 264
		NiPointer<ReferenceEffect>			  currentReferenceEffect;		   // 268
		NiPointer<ReferenceEffect>			  lastReferenceEffect;			   // 270
		SkyEffectController					  effectController;				   // 278
		BSTArray<NiPointer<NiTexture>>		  storedCloudTextures;			   // 280
		BSTArray<NiPointer<NiTexture>>		  storedWorldMapCloudTextures;	   // 298
		BSTArray<SkyStaticRefData>			  skyStaticRefData;				   // 2B0
	};
	static_assert(sizeof(Sky) == 0x2C8);
}
