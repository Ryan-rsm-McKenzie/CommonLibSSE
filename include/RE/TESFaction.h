#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESFaction

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/BSTList.h"  // BSSimpleList
#include "RE/FormTypes.h"  // FormType, TESObjectREFR, BGSListForm, BGSOutfit
#include "RE/TESForm.h"  // TESForm
#include "RE/TESFullName.h"  // TESFullName
#include "RE/TESReactionForm.h"  // TESReactionForm
#include "RE/TESTexture.h"  // TESTexture


namespace RE
{
	class Condition;
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
			UInt16	murder;				// 02
			UInt16	assault;			// 04
			UInt16	trespass;			// 06
			UInt16	pickpocket;			// 08
			UInt16	unk0A;				// 0A
			float	stealMultiplier;	// 0C
			UInt16	escape;				// 10
			UInt16	werewolf;			// 12
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
		virtual bool	LoadForm(TESFile* a_mod) override;				// 06
		virtual void	SaveBuffer(BGSSaveFormBuffer* a_buf) override;	// 0E
		virtual void	LoadBuffer(BGSLoadFormBuffer* a_buf) override;	// 0F
		virtual void	InitItem() override;							// 13

		bool			HiddenFromNPC();
		bool			HasSpecialCombatState();
		bool			TracksCrimes();
		bool			IgnoresMurder();
		bool			IgnoresAssault();
		bool			IgnoresStealing();
		bool			IgnoresTrespass();
		bool			ReportsCrimesAgainstMembers();
		bool			UsesCrimeGoldDefaults();
		bool			IgnoresPickpocket();
		bool			IsVendor();
		bool			CanBeOwner();
		bool			IgnoresWerewolf();


		// members
		void*				unk050;						// 050
		Flag				flags;						// 058 - DATA
		UInt32				pad05C;						// 05C
		TESObjectREFR*		exteriorJailMarker;			// 060 - JAIL
		TESObjectREFR*		followerWaitMarker;			// 068 - WAIT
		TESObjectREFR*		stolenGoodsContainer;		// 070 - STOL
		TESObjectREFR*		playerInventoryContainer;	// 078 - PLCN
		BGSListForm*		sharedCrimeFactionList;		// 080 - CRGR
		BGSOutfit*			jailOutfit;					// 088 - JOUT
		CrimeValues			crimeValues;				// 090 - CRVA
		UInt32				pad0A4;						// 0A4
		VendorValues		vendorValues;				// 0A8 - VENV
		UInt32				pad0B4;						// 0B4
		PackageLocation*	location;					// 0B8 - PLVD
		Condition*			conditions;					// 0C0
		BGSListForm*		vendorBuySellList;			// 0C8 - VEND
		TESObjectREFR*		merchantContainer;			// 0D0 - VENC
		UInt32				unk0D8;						// 0D8
		UInt32				pad0DC;						// 0DC
		BSSimpleList<Rank*>	ranks;						// 0E0
		UInt32				unk0F0;						// 0F0
		UInt32				unk0F4;						// 0F4
		UInt32				unk0F8;						// 0F8
		UInt32				unk0FC;						// 0FC
	};
	STATIC_ASSERT(sizeof(TESFaction) == 0x100);
}
