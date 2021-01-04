#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/E/ExtraDataTypes.h"
#include "RE/T/TESFullName.h"

namespace RE
{
	enum class MARKER_TYPE
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

	class MapMarkerData
	{
	public:
		enum class Flag
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

		constexpr void SetHidden(bool a_value) noexcept { a_value ? flags.set(Flag::kShowAllHidden) : flags.reset(Flag::kShowAllHidden); }
		constexpr void SetVisible(bool a_value) noexcept { a_value ? flags.set(Flag::kVisible) : flags.reset(Flag::kVisible); }

		// members
		TESFullName									locationName;  // 00
		stl::enumeration<Flag, std::uint8_t>		flags;		   // 10
		stl::enumeration<MARKER_TYPE, std::uint8_t> type;		   // 11
		std::uint16_t								pad02;		   // 12
		std::uint32_t								pad04;		   // 14
	};
	static_assert(sizeof(MapMarkerData) == 0x18);

	class ExtraMapMarker : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraMapMarker;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kMapMarker;

		virtual ~ExtraMapMarker();	// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kMapMarker; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02

		// members
		MapMarkerData* mapData;	 // 10
	};
	static_assert(sizeof(ExtraMapMarker) == 0x18);
}
