#pragma once

#include "RE/FormTypes.h"
#include "RE/TESForm.h"


namespace RE
{
	struct ENCOUNTER_ZONE_DATA	// DATA
	{
		enum class Flag : UInt8
		{
			kNone = 0,
			kNeverResets = 1 << 0,
			kMatchPCBelowMinimumLevel = 1 << 1,
			kDisableCombatBoundary = 1 << 2
		};


		TESFaction*	 zoneOwner;	 // 00
		BGSLocation* location;	 // 08
		SInt8		 ownerRank;	 // 10
		SInt8		 minLevel;	 // 11
		Flag		 flags;		 // 12
		SInt8		 maxLevel;	 // 13
		UInt32		 pad14;		 // 14
	};
	STATIC_ASSERT(sizeof(ENCOUNTER_ZONE_DATA) == 0x18);


	struct ENCOUNTER_ZONE_GAME_DATA
	{
		UInt32 detachTime;	// 00
		UInt32 attachTime;	// 04
		UInt32 resetTime;	// 08
		UInt16 zoneLevel;	// 0C
		UInt16 pad0D;		// 0D
	};
	STATIC_ASSERT(sizeof(ENCOUNTER_ZONE_GAME_DATA) == 0x10);


	class BGSEncounterZone : public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSEncounterZone;
		inline static constexpr auto FORMTYPE = FormType::EncounterZone;


		struct ChangeFlags
		{
			enum ChangeFlag : UInt32
			{
				kZoneFlags = 1 << 1,
				kGameData = (UInt32)1 << 31
			};
		};


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~BGSEncounterZone();  // 00

		// override (TESForm)
		virtual void InitializeData() override;					   // 04
		virtual bool Load(TESFile* a_mod) override;				   // 06
		virtual void SaveGame(BGSSaveFormBuffer* a_buf) override;  // 0E
		virtual void LoadGame(BGSLoadFormBuffer* a_buf) override;  // 0F
		virtual void Revert(BGSLoadFormBuffer* a_buf) override;	   // 12
		virtual void InitItemImpl() override;					   // 13


		// members
		ENCOUNTER_ZONE_DATA		 data;		// 20 - DATA
		ENCOUNTER_ZONE_GAME_DATA gameData;	// 38
	};
	STATIC_ASSERT(sizeof(BGSEncounterZone) == 0x48);
}
