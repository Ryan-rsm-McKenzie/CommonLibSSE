#pragma once

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


	class TESFaction :
		public TESForm,			// 000
		public TESFullName,		// 020
		public TESReactionForm	// 030
	{
	public:
		inline static const void* RTTI = RTTI_TESFaction;


		enum { kTypeID = FormType::Faction };


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


		struct CrimeValues	// CRVA
		{
			bool	arrest;				// 00
			bool	attackOnSight;		// 01
			SInt16	murder;				// 02
			SInt16	assault;			// 04
			SInt16	trespass;			// 06
			SInt16	pickpocket;			// 08
			UInt16	unk0A;				// 0A
			float	stealMultiplier;	// 0C
			SInt16	escape;				// 10
			SInt16	werewolf;			// 12
		};
		STATIC_ASSERT(sizeof(CrimeValues) == 0x14);


		struct VendorValues	// VENV
		{
			UInt16	startHour;				// 00
			UInt16	endHour;				// 02
			UInt16	radius;					// 04
			UInt16	unk06;					// 06
			bool	onlyBuysStolenItems;	// 08
			bool	notSellBuy;				// 09
			UInt16	unk0A;					// 0A
		};
		STATIC_ASSERT(sizeof(VendorValues) == 0xC);


		struct Rank
		{
			BSFixedString	maleTitle;		// 00 - MNAM
			BSFixedString	femaleTitle;	// 08 - FNAM
			TESTexture		insignia;		// 10 - INAM - unused
		};
		STATIC_ASSERT(sizeof(Rank) == 0x20);


		virtual ~TESFaction();											// 00

		// override (TESForm)
		virtual void	InitializeData() override;						// 04
		virtual void	ClearData() override;							// 05
		virtual bool	Load(TESFile* a_mod) override;					// 06
		virtual void	SaveGame(BGSSaveFormBuffer* a_buf) override;	// 0E
		virtual void	LoadGame(BGSLoadFormBuffer* a_buf) override;	// 0F
		virtual void	Revert(void* a_arg1) override;					// 12
		virtual void	InitItemImpl() override;						// 13

		bool	CanBeOwner() const;
		bool	CanPayCrimeGold() const;
		SInt32	GetCrimeGold() const;
		SInt32	GetCrimeGoldNonViolent() const;
		SInt32	GetCrimeGoldViolent() const;
		SInt32	GetInfamy() const;
		SInt32	GetInfamyNonViolent() const;
		SInt32	GetInfamyViolent() const;
		SInt32	GetStolenItemValueCrime() const;
		SInt32	GetStolenItemValueNoCrime() const;
		bool	HasSpecialCombatState() const;
		bool	HasStealMultiplier() const;
		bool	HiddenFromNPC() const;
		bool	IgnoresAssault() const;
		bool	IgnoresMurder() const;
		bool	IgnoresPickpocket() const;
		bool	IgnoresStealing() const;
		bool	IgnoresTrespass() const;
		bool	IgnoresWerewolf() const;
		bool	IsFactionInCrimeGroup(const TESFaction* a_other) const;
		bool	IsPlayerEnemy() const;
		bool	IsPlayerExpelled() const;
		bool	IsVendor() const;
		void	ModCrimeGold(SInt32 a_amount, bool a_violent);
		void	PlayerPayCrimeGold(bool a_removeStolenItems = true, bool a_goToJail = true);
		bool	ReportsCrimesAgainstMembers() const;
		void	SendPlayerToJail(bool a_removeInventory = true, bool a_realJail = true);
		void	SetCrimeGold(SInt32 a_gold);
		void	SetCrimeGoldViolent(SInt32 a_gold);
		bool	TracksCrimes() const;
		bool	UsesCrimeGoldDefaults() const;


		// members
		BSTHashMap<TESForm*, SInt32>*	crimeMap;					// 050
		Flag							flags;						// 058 - DATA
		UInt32							pad05C;						// 05C
		TESObjectREFR*					exteriorJailMarker;			// 060 - JAIL
		TESObjectREFR*					followerWaitMarker;			// 068 - WAIT
		TESObjectREFR*					stolenGoodsContainer;		// 070 - STOL
		TESObjectREFR*					playerInventoryContainer;	// 078 - PLCN
		BGSListForm*					sharedCrimeFactionList;		// 080 - CRGR
		BGSOutfit*						jailOutfit;					// 088 - JOUT
		CrimeValues						crimeValues;				// 090 - CRVA
		UInt32							pad0A4;						// 0A4
		VendorValues					vendorValues;				// 0A8 - VENV
		UInt32							pad0B4;						// 0B4
		PackageLocation*				location;					// 0B8 - PLVD
		TESCondition*					conditions;					// 0C0
		BGSListForm*					vendorBuySellList;			// 0C8 - VEND
		TESObjectREFR*					merchantContainer;			// 0D0 - VENC
		UInt32							unk0D8;						// 0D8
		UInt32							pad0DC;						// 0DC
		BSSimpleList<Rank*>				ranks;						// 0E0
		UInt32							unk0F0;						// 0F0
		UInt32							unk0F4;						// 0F4
		UInt32							unk0F8;						// 0F8
		float							playerIsEnemyTimeStamp;		// 0FC - current game time in hours
	};
	STATIC_ASSERT(sizeof(TESFaction) == 0x100);
}
