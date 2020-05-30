#pragma once

#include "RE/AITimeStamp.h"
#include "RE/BSFixedString.h"
#include "RE/BSTHashMap.h"
#include "RE/BSTList.h"
#include "RE/FormTypes.h"
#include "RE/TESForm.h"
#include "RE/TESFullName.h"
#include "RE/TESReactionForm.h"
#include "RE/TESTexture.h"


namespace RE
{
	class TESCondition;
	class PackageLocation;

	struct FACTION_DATA
	{
		enum Flag : UInt32
		{
			kNone = 0,
			kHiddenFromNPC = 1 << 0,
			kSpecialCombat = 1 << 1,
			kPlayerIsExpelled = 1 << 2,
			kPlayerIsEnemy = 1 << 3,
			kTrackCrime = 1 << 6,
			kIgnoresCrimes_Murder = 1 << 7,
			kIgnoresCrimes_Assult = 1 << 8,
			kIgnoresCrimes_Stealing = 1 << 9,
			kIngoresCrimes_Trespass = 1 << 10,
			kDoNotReportCrimesAgainstMembers = 1 << 11,
			kCrimeGold_UseDefaults = 1 << 12,
			kIgnoresCrimes_Pickpocket = 1 << 13,
			kVendor = 1 << 14,
			kCanBeOwner = 1 << 15,
			kIgnoresCrimes_Werewolf = 1 << 16
		};


		Flag flags;	 // 0
	};
	STATIC_ASSERT(sizeof(FACTION_DATA) == 0x4);


	struct FACTION_CRIME_DATA_VALUES  // CRVA
	{
		bool   arrest;				 // 00
		bool   attackOnSight;		 // 01
		UInt16 murderCrimeGold;		 // 02
		UInt16 assaultCrimeGold;	 // 04
		UInt16 trespassCrimeGold;	 // 06
		UInt16 pickpocketCrimeGold;	 // 08
		UInt16 pad0A;				 // 0A
		float  stealCrimeGoldMult;	 // 0C
		UInt16 escapeCrimeGold;		 // 10
		UInt16 werewolfCrimeGold;	 // 12
	};
	STATIC_ASSERT(sizeof(FACTION_CRIME_DATA_VALUES) == 0x14);


	struct FACTION_CRIME_DATA
	{
		TESObjectREFR*			  factionJailMarker;				// 00 - JAIL
		TESObjectREFR*			  factionWaitMarker;				// 08 - WAIT
		TESObjectREFR*			  factionStolenContainer;			// 10 - STOL
		TESObjectREFR*			  factionPlayerInventoryContainer;	// 18 - PLCN
		BGSListForm*			  crimeGroup;						// 20 - CRGR
		BGSOutfit*				  jailOutfit;						// 28 - JOUT
		FACTION_CRIME_DATA_VALUES crimevalues;						// 30 - CRVA
		UInt32					  pad44;							// 44
	};
	STATIC_ASSERT(sizeof(FACTION_CRIME_DATA) == 0x48);


	struct FACTION_VENDOR_DATA_VALUES  // VENV
	{
		UInt16 startHour;		// 0
		UInt16 endHour;			// 2
		UInt32 locationRadius;	// 4
		bool   buysStolen;		// 8
		bool   notBuySell;		// 9
		bool   buysNonStolen;	// A
		UInt8  padB;			// B
	};
	STATIC_ASSERT(sizeof(FACTION_VENDOR_DATA_VALUES) == 0xC);


	struct FACTION_VENDOR_DATA	// VENV
	{
		FACTION_VENDOR_DATA_VALUES vendorValues;	   // 00
		UInt32					   pad0C;			   // 0C
		PackageLocation*		   vendorLocation;	   // 10 - PLVD
		TESCondition*			   vendorConditions;   // 18
		BGSListForm*			   vendorSellBuyList;  // 20 - VEND
		TESObjectREFR*			   merchantContainer;  // 28 - VENC
		UInt32					   lastDayReset;	   // 30
		UInt32					   pad34;			   // 34
	};
	STATIC_ASSERT(sizeof(FACTION_VENDOR_DATA) == 0x38);


	struct RANK_DATA
	{
		BSFixedString maleRankTitle;	// 00 - MNAM
		BSFixedString femaleRankTitle;	// 08 - FNAM
		TESTexture	  textureInsignia;	// 10 - INAM - unused
	};
	STATIC_ASSERT(sizeof(RANK_DATA) == 0x20);


	class TESFaction :
		public TESForm,			// 000
		public TESFullName,		// 020
		public TESReactionForm	// 030
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESFaction;
		inline static constexpr auto FORMTYPE = FormType::Faction;


		struct ChangeFlags
		{
			enum ChangeFlag : UInt32
			{
				kFactionFlags = 1 << 1,
				kFactionReactions = 1 << 2,
				kFactionCrimeCounts = (UInt32)1 << 31
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


		virtual ~TESFaction();	// 00

		// override (TESForm)
		virtual void InitializeData() override;					   // 04
		virtual void ClearData() override;						   // 05
		virtual bool Load(TESFile* a_mod) override;				   // 06
		virtual void SaveGame(BGSSaveFormBuffer* a_buf) override;  // 0E
		virtual void LoadGame(BGSLoadFormBuffer* a_buf) override;  // 0F
		virtual void Revert(BGSLoadFormBuffer* a_buf) override;	   // 12
		virtual void InitItemImpl() override;					   // 13

		bool   CanBeOwner() const;
		bool   CanPayCrimeGold() const;
		SInt32 GetCrimeGold() const;
		SInt32 GetCrimeGoldNonViolent() const;
		SInt32 GetCrimeGoldViolent() const;
		SInt32 GetInfamy() const;
		SInt32 GetInfamyNonViolent() const;
		SInt32 GetInfamyViolent() const;
		SInt32 GetStolenItemValueCrime() const;
		SInt32 GetStolenItemValueNoCrime() const;
		bool   HasSpecialCombatState() const;
		bool   HasStealMultiplier() const;
		bool   HiddenFromNPC() const;
		bool   IgnoresAssault() const;
		bool   IgnoresMurder() const;
		bool   IgnoresPickpocket() const;
		bool   IgnoresStealing() const;
		bool   IgnoresTrespass() const;
		bool   IgnoresWerewolf() const;
		bool   IsFactionInCrimeGroup(const TESFaction* a_other) const;
		bool   IsPlayerEnemy() const;
		bool   IsPlayerExpelled() const;
		bool   IsVendor() const;
		void   ModCrimeGold(SInt32 a_amount, bool a_violent);
		void   PlayerPayCrimeGold(bool a_removeStolenItems = true, bool a_goToJail = true);
		bool   ReportsCrimesAgainstMembers() const;
		void   SendPlayerToJail(bool a_removeInventory = true, bool a_realJail = true);
		void   SetCrimeGold(SInt32 a_gold);
		void   SetCrimeGoldViolent(SInt32 a_gold);
		bool   TracksCrimes() const;
		bool   UsesCrimeGoldDefaults() const;


		// members
		BSTHashMap<const TESNPC*, UInt32>* crimeGoldMap;		   // 050
		FACTION_DATA					   data;				   // 058 - DATA
		UInt32							   pad05C;				   // 05C
		FACTION_CRIME_DATA				   crimeData;			   // 060
		FACTION_VENDOR_DATA				   vendorData;			   // 0A8
		BSSimpleList<RANK_DATA*>		   rankData;			   // 0E0
		SInt32							   majorCrime;			   // 0F0
		SInt32							   minorCrime;			   // 0F4
		AITimeStamp						   resistArrestTimeStamp;  // 0F8
		float							   pcEnemyFlagTimeStamp;   // 0FC - current game time in hours
	};
	STATIC_ASSERT(sizeof(TESFaction) == 0x100);
}
