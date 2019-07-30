#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraMapMarker

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType
#include "RE/TESFullName.h"  // TESFullName


namespace RE
{
	class ExtraMapMarker : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraMapMarker;


		enum { kExtraTypeID = ExtraDataType::kMapMarker };


		struct MapMarker
		{
			enum class Flag : UInt8
			{
				kNone = 0,
				kVisible = 1 << 0,
				kCanTravelTo = 1 << 1,
				kShowAllHidden = 1 << 2,
				kUnk3 = 1 << 3,
				kUnk4 = 1 << 4,
				kUnk5 = 1 << 5,
				kUnk6 = 1 << 6,
				kUnk7 = 1 << 7
			};


			enum class Type : UInt8
			{
				kNone = 0,
				kCity = 1,
				kTown = 2,
				kSettlement = 3,
				kCave = 4,
				kCamp = 5,
				kFort = 6,
				kNordicRuins = 7,
				kDwemerRuin = 8,
				kShipwreck = 9,
				kGrove = 10,
				kLandmark = 11,
				kDragonLair = 12,
				kFarm = 13,
				kWoodMill = 14,
				kMine = 15,
				kImperialCamp = 16,
				kStormcloakCamp = 17,
				kDoomstone = 18,
				kWheatMill = 19,
				kSmelter = 20,
				kStable = 21,
				kImperialTower = 22,
				kClearing = 23,
				kPass = 24,
				kAlter = 25,
				kRock = 26,
				kLighthouse = 27,
				kOrcStronghold = 28,
				kGiantCamp = 29,
				kShack = 30,
				kNordicTower = 31,
				kNordicDwelling = 32,
				kDocks = 33,
				kShrine = 34,
				kRiftenCastle = 35,
				kRiftenCapitol = 36,
				kWindhelmCastle = 37,
				kWindhelmCapitol = 38,
				kWhiterunCastle = 39,
				kWhiterunCapitol = 40,
				kSolitudeCastle = 41,
				kSolitudeCapitol = 42,
				kMarkarthCastle = 43,
				kMarkarthCapitol = 44,
				kWinterholdCastle = 45,
				kWinterholdCapitol = 46,
				kMorthalCastle = 47,
				kMorthalCapitol = 48,
				kFalkreathCastle = 49,
				kFalkreathCapitol = 50,
				kDawnstarCastle = 51,
				kDawnstarCapitol = 52,
				kDLC02_TempleOfMiraak = 53,
				kDLC02_RavenRock = 54,
				kDLC02_BeastStone = 55,
				kDLC02_TelMithryn = 56,
				kDLC02_ToSkyrim = 57,
				kDLC02_ToSolstheim = 58
			};


			void Enable(bool a_enabled);


			// members
			TESFullName	name;	// 00
			Flag		flags;	// 10
			Type		type;	// 11
			UInt16		pad02;	// 12
			UInt32		pad04;	// 14
		};
		STATIC_ASSERT(sizeof(MapMarker) == 0x18);


		virtual ~ExtraMapMarker();														// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kMapMarker; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02


		// members
		MapMarker* mapMarker;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraMapMarker) == 0x18);
}
