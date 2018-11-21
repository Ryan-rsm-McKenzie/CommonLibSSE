#pragma once

#include "skse64/GameForms.h"  // TESForm
#include "skse64/GameTypes.h"  // tList

class BGSListForm;
class BGSOutfit;


namespace RE
{
	class TESObjectREFR;


	class TESFaction :
		public TESForm,
		public TESFullName,
		public TESReactionForm
	{
	public:
		enum { kTypeID = kFormType_Faction };


		enum FactionFlag : UInt32
		{
			kFactionFlag_HiddenFromNPC		= 1 << 0,
			kFactionFlag_SpecialCombat		= 1 << 1,
			kFactionFlag_PlayerExpelled		= 1 << 2,
			kFactionFlag_Unk00000008		= 1 << 3,
			kFactionFlag_Unk00000010		= 1 << 4,
			kFactionFlag_Unk00000020		= 1 << 5,
			kFactionFlag_TrackCrime			= 1 << 6,
			kFactionFlag_IgnoreMurder		= 1 << 7,
			kFactionFlag_IgnoreAssult		= 1 << 8,
			kFactionFlag_IgnorePickPocket	= 1 << 9,
			kFactionFlag_IngoreStealing		= 1 << 10,
			kFactionFlag_DoReportCrimes		= 1 << 11,
			kFactionFlag_CrimeGoldDefaults	= 1 << 12,
			kFactionFlag_IgnoreTrespass		= 1 << 13,
			kFactionFlag_Vendor				= 1 << 14,
			kFactionFlag_CanBeOwner			= 1 << 15,
			kFactionFlag_IgnoreWerewolf		= 1 << 16
		};


		struct CrimeValues								// CRVA
		{
			TESObjectREFR*	exteriorJailMarker;			// 00 - JAIL
			TESObjectREFR*	followerWaitMarker;			// 08 - WAIT
			TESObjectREFR*	stolenGoodsContainer;		// 10 - STOL
			TESObjectREFR*	playerInventoryContainer;	// 18 - PLCN
			BGSListForm*	sharedCrimeFactionList;		// 20 - CRGR
			BGSOutfit*		jailOutfit;					// 28 - JOUT
			bool			arrest;						// 30
			bool			attackOnSight;				// 31
			UInt16			murder;						// 32
			UInt16			assault;					// 34
			UInt16			trespass;					// 36
			UInt16			pickpocket;					// 38
			float			stealMult;					// 3C
			UInt16			escape;						// 40
			UInt16			werewolf;					// 42
			UInt32			pad44;						// 44
		};


		struct VendorData							// VENV
		{
			UInt16			startHour;				// 00
			UInt16			endHour;				// 02
			UInt32			radius;					// 04
			bool			onlyBuysStolenItems;	// 08
			bool			notSellBuy;				// 09
			UInt8			pad0A[6];				// 0A
			void*			packageLocation;		// 10
			UInt32			unk18;					// 18
			BGSListForm*	buySellList;			// 20
			TESObjectREFR*	merchantContainer;		// 28
			UInt32			unk30;					// 30 - init'd to FFFFFFFF
			UInt32			pad34;					// 34
		};


		struct Rank
		{
			UInt32		titleMasc;	// 0
			UInt32		titleFem;	// 4
			TESTexture	unk8;		// 8
		};


		bool	HiddenFromNPC();
		bool	HasSpecialCombatState();
		bool	TracksCrimes();
		bool	IgnoresMurder();
		bool	IgnoresAssault();
		bool	IgnoresPickpocket();
		bool	IngoresStealing();
		bool	ReportsCrimes();
		bool	UsesCrimeGoldDefaults();
		bool	IgnoresTrespassing();
		bool	IsVendor();
		bool	CanBeOwner();
		bool	IgnoresWerewolf();


		void*			unk50;			// 50
		FactionFlag		factionFlags;	// 58 - DATA
		UInt32			pad5C;			// 5C
		CrimeValues		crimeValues;	// 60 - CRVA
		VendorData		vendorData;		// A8 - VENV
		tList<Rank*>	ranks;			// E0
		UInt32			unkF0;			// F0
		UInt32			unkF4;			// F4
		float			unkF8;			// F8
		float			unkFC;			// FC
	};
	STATIC_ASSERT(sizeof(TESFaction) == 0x100);
	STATIC_ASSERT(offsetof(TESFaction, vendorData) == 0xA8);
}
