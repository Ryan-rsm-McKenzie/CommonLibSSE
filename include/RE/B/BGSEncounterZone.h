#pragma once

#include "RE/F/FormTypes.h"
#include "RE/T/TESForm.h"

namespace RE
{
	struct ENCOUNTER_ZONE_DATA  // DATA
	{
	public:
		enum class Flag
		{
			kNone = 0,
			kNeverResets = 1 << 0,
			kMatchPCBelowMinimumLevel = 1 << 1,
			kDisableCombatBoundary = 1 << 2
		};

		// members
		TESFaction*                          zoneOwner;  // 00
		BGSLocation*                         location;   // 08
		std::int8_t                          ownerRank;  // 10
		std::int8_t                          minLevel;   // 11
		stl::enumeration<Flag, std::uint8_t> flags;      // 12
		std::int8_t                          maxLevel;   // 13
		std::uint32_t                        pad14;      // 14
	};
	static_assert(sizeof(ENCOUNTER_ZONE_DATA) == 0x18);

	struct ENCOUNTER_ZONE_GAME_DATA
	{
	public:
		// members
		std::uint32_t detachTime;  // 00
		std::uint32_t attachTime;  // 04
		std::uint32_t resetTime;   // 08
		std::uint16_t zoneLevel;   // 0C
		std::uint16_t pad0D;       // 0D
	};
	static_assert(sizeof(ENCOUNTER_ZONE_GAME_DATA) == 0x10);

	class BGSEncounterZone : public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSEncounterZone;
		inline static constexpr auto VTABLE = VTABLE_BGSEncounterZone;
		inline static constexpr auto FORMTYPE = FormType::EncounterZone;

		struct ChangeFlags
		{
			enum ChangeFlag : std::uint32_t
			{
				kZoneFlags = 1 << 1,
				kGameData = (std::uint32_t)1 << 31
			};
		};

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};

		~BGSEncounterZone() override;  // 00

		// override (TESForm)
		void InitializeData() override;                    // 04
		bool Load(TESFile* a_mod) override;                // 06
		void SaveGame(BGSSaveFormBuffer* a_buf) override;  // 0E
		void LoadGame(BGSLoadFormBuffer* a_buf) override;  // 0F
		void Revert(BGSLoadFormBuffer* a_buf) override;    // 12
		void InitItemImpl() override;                      // 13

		// members
		ENCOUNTER_ZONE_DATA      data;      // 20 - DATA
		ENCOUNTER_ZONE_GAME_DATA gameData;  // 38
	};
	static_assert(sizeof(BGSEncounterZone) == 0x48);
}
