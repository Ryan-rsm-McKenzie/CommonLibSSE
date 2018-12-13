#pragma once

#include "skse64/GameEvents.h"  // BSTEventSink, MenuOpenCloseEvent, MenuModeChangeEvent, BSTEventSource
#include "skse64/GameFormComponents.h"  // BGSPerkRanks
#include "skse64/GameTypes.h"  // tArray, UnkArray
#include "skse64/NiTypes.h"  // NiTMap

#include "RE/BGSActorCellEvent.h"  // BGSActorCellEvent
#include "RE/BGSActorDeathEvent.h"  // BGSActorDeathEvent
#include "RE/Character.h"  // Character
#include "RE/PositionPlayerEvent.h"  // PositionPlayerEvent
#include "RE/UserEventEnabledEvent.h"  // UserEventEnabledEvent

class BGSLocation;
class BGSPerk;
class BGSTextureSet;
class BSFadeNode;
class ImageSpaceModifierInstanceDOF;
class ObjectListItem;
class TESForm;
class TESRace;
class TESWorldSpace;
class TintMask;


namespace RE
{
	class Actor;
	class InventoryEntryData;
	class TESObjectREFR;


	class PlayerCharacter :
		public Character,							// 000
		public BSTEventSink<MenuOpenCloseEvent>,	// 2B0
		public BSTEventSink<MenuModeChangeEvent>,	// 2B8
		public BSTEventSink<UserEventEnabledEvent>,	// 2C0
		public BSTEventSink<TESTrackedStatsEvent>,	// 2C8
		public BSTEventSource<BGSActorCellEvent>,	// 2D0
		public BSTEventSource<BGSActorDeathEvent>,	// 328
		public BSTEventSource<PositionPlayerEvent>	// 380
	{
	public:
		enum class EventType : UInt32
		{
			kThief = 3,
			kContainer = 5,
			kDeadBody = 6
		};


		struct Data7DC
		{
			float	unk0;	// 0 - init'd to -1
			UInt32	unk4;	// 4
			UInt32	unk8;	// 8 - init'd to 16
		};


		struct DataUnk510 {
			UInt32 a;	// 0
			UInt32 b;	// 4
			UInt32 c;	// 8
			UInt32 pad;	// C
		};


		virtual ~PlayerCharacter();	// 00

		TintMask*				GetOverlayTintMask(TintMask* a_original);
		tArray<TintMask*>*		GetTintList();
		UInt32					GetNumTints(UInt32 a_tintType);
		TintMask*				GetTintMask(UInt32 a_tintType, UInt32 a_index);
		float					GetDamage(InventoryEntryData* a_pForm);
		float					GetArmorValue(InventoryEntryData* a_pForm);

		static PlayerCharacter*	GetSingleton();
		Actor*					GetActorInFavorState();
		TESObjectREFR*			GetGrabbedRef();
		void					PlayPickupEvent(TESForm* a_item, TESForm* a_containerOwner, TESObjectREFR* a_containerRef, EventType a_eventType);
		void					StartActivation();
		bool					TryToPickPocket(Actor* a_target, InventoryEntryData* a_pEntry, UInt32 a_numItems, bool a_unk4);


		// members
		UInt32							unk3D8;					// 3D8
		UInt32							unk3DC;					// 3DC
		UInt32							unk3E0;					// 3E0
		UInt32							unk3E4;					// 3E4
		UInt32							unk3E8;					// 3E8
		UInt32							unk3EC;					// 3EC
		UInt32							unk3F0;					// 3F0
		UInt32							unk3F4;					// 3F4
		void*							unk3F8;					// 3F8
		UInt32							unk400;					// 400
		UInt32							unk404;					// 404
		void*							unk408;					// 408
		UInt32							unk410;					// 410
		UInt32							unk414;					// 414
		UInt32							unk418;					// 418
		UInt32							unk41C;					// 41C
		UInt32							unk420;					// 420
		UInt32							unk424;					// 424
		void*							unk428;					// 428
		UInt32							unk430;					// 430
		UInt32							unk434;					// 434
		void*							unk438;					// 438
		UInt32							unk440;					// 440
		UInt32							unk444;					// 444
		UInt32							unk448;					// 448
		UInt32							unk44C;					// 44C
		UInt32							unk450;					// 450
		UInt32							unk454;					// 454
		UInt32							unk458;					// 458
		UInt32							unk45C;					// 45C
		void*							unk460;					// 460
		UInt64							unk468;					// 468
		ObjectListItem*					unk470;					// 470
		float							unk478;					// 478
		float							unk47C;					// 47C
		float							unk480;					// 480
		float							unk484;					// 484
		float							unk488;					// 488
		float							unk48C;					// 48C
		float							unk490;					// 490
		float							unk494;					// 494
		float							unk498;					// 498
		float							unk49C;					// 49C
		UInt64							unk4A0;					// 4A0
		UInt64							unk4A8;					// 4A8
		BGSPerkRanks					addedPerks;				// 4B0
		tArray<BGSPerk*>				perks;					// 4C8
		tArray<BGSPerk*>				standingStonePerks;		// 4E0
		tArray<UInt32>					unk4F8;					// 4F8
		tArray<DataUnk510>				unk510;					// 510
		UnkArray						unk528;					// 528
		tArray<void*>					unk540;					// 540
		tArray<void*>					unk558;					// 558
		void*							unk570;					// 570
		void*							unk578;					// 578
		tArray<void*>					unk580;					// 580
		UInt32							unk598;					// 598
		UInt32							unk59C;					// 59C
		UInt32							unk5A0;					// 5A0
		UInt32							unk5A4;					// 5A4
		UInt32							unk5A8;					// 5A8
		UInt32							unk5AC;					// 5AC
		void*							unk5B0;					// 5B0
		UInt64							unk5B8;					// 5B8
		void*							unk5C0;					// 5C0
		UInt32							unk5C8;					// 5C8
		UInt32							unk5CC;					// 5CC
		UInt32							unk5D0;					// 5D0
		UInt32							unk5D4;					// 5D4
		UInt32							unk5D8;					// 5D8
		UInt32							unk5DC;					// 5DC
		void*							unk5E0;					// 5E0
		UInt8							unk5E8;					// 5E8
		UInt8							pad5E9[7];				// 5E9
		void*							unk5F0;					// 5F0
		UInt32							unk5F8;					// 5F8
		UInt32							pad5FC;					// 5FC
		UInt64							unk600;					// 600
		NiTMap<UInt64, UInt64>			unk608;					// 608
		TESWorldSpace*					currentWorldSpace;		// 628
		float							unk630;					// 630
		float							unk634;					// 634
		float							unk638;					// 638
		UInt32							unk63C;					// 63C
		UInt64							unk640;					// 640
		UInt64							unk648;					// 648
		float							unk650;					// 650
		float							unk654;					// 654
		float							unk658;					// 658
		float							unk65C;					// 65C
		float							unk660;					// 660
		float							unk664;					// 664
		UInt64							unk668;					// 668
		UInt64							unk670;					// 670
		UInt32							unk678;					// 678
		UInt32							unk67C;					// 67C
		UInt8							unk680;					// 680
		UInt8							unk681;					// 681
		UInt8							unk682;					// 682
		UInt8							pad683;					// 683
		UInt32							unk684;					// 684
		UInt32							unk688;					// 688 - init'd to FFFFFFFF
		UInt8							unk68C;					// 68C
		UInt8							pad68D[3];				// 68D
		UInt32							unk690;					// 690
		UInt32							unk694;					// 694
		UInt8							unk698;					// 698
		UInt8							pad699[3];				// 699
		UInt32							unk69C;					// 69C
		UInt32							unk6A0;					// 6A0
		UInt8							unk6A4;					// 6A4
		UInt8							pad6A5[7];				// 6A5
		UInt64							unk6B0;					// 6B0
		UInt32							unk6B8;					// 6B8
		UInt32							unk6BC;					// 6BC
		UInt64							unk6C0;					// 6C0
		UInt32							unk6C8;					// 6C8
		float							unk6CC;					// 6CC - init'd to -1
		UInt32							unk6D0;					// 6D0
		float							unk6D4;					// 6D4 - init'd to -1
		float							unk6D8;					// 6D8 - FF7FFFFF
		UInt32							unk6DC;					// 6DC - probably pad
		ImageSpaceModifierInstanceDOF*	unk6E0;					// 6E0
		ImageSpaceModifierInstanceDOF*	unk6E8;					// 6E8
		ImageSpaceModifierInstanceDOF*	unk6F0;					// 6F0
		UInt32							unk6F8;					// 6F8 - looks like a pointer along with next in debugger, but it isn't
		UInt32							unk6FC;					// 6FC
		UInt64							unk700[3];				// 700
		UInt64							unk718;					// 718
		UInt32							unk720;					// 720
		UInt32							pad724;					// 724
		UInt64							unk728;					// 728
		UInt8							unk730[0xA0];			// 730 - memset to 0 in ctor
		UInt32							unk7D0;					// 7D0
		UInt32							unk7D4;					// 7D4
		UInt32							unk7D8;					// 7D8
		Data7DC							unk7DC[15];				// 7DC
		UInt32							unk890;					// 890 - init'd to 15
		UInt32							unk894;					// 894 - handle?
		UInt32							unk898;					// 898
		UInt32							unk89C;					// 89C
		UInt64							unk8A0[5];				// 8A0
		UInt32							playerGrabbedHandle;	// 8C8
		float							unk8CC;					// 8CC - related to grabbed item
		UInt32							unk8D0;					// 8D0
		float							unk8D4;					// 8D4 - init'd to -5
		UInt64							unk8D8;					// 8D8
		UInt32							unk8E0;					// 8E0
		UInt32							unk8E4;					// 8E4
		UInt64							unk8E8;					// 8E8
		BSFadeNode*						firstPersonSkeleton;	// 8F0
		float							unk8F8;					// 8F8
		UInt32							pad8FC;					// 8FC
		float							unk900;					// 900
		UInt32							pad904;					// 904
		UInt64							unk908;					// 908
		UInt32							unk910;					// 910
		UInt32							lastRiddenHorseHandle;	// 914
		UInt32							unk918;					// 918
		UInt32							unk91C;					// 91C
		UInt64							unk920;					// 920
		UInt64							unk928;					// 928
		UInt32							unk930;					// 930
		UInt32							unk934;					// 934
		UInt64							unk938;					// 938
		UInt64							unk940;					// 940
		UInt32							unk948;					// 948
		UInt32							unk94C;					// 94C
		UInt32							unk950;					// 950
		UInt32							unk954;					// 954
		UInt32							unk958;					// 958
		UInt32							unk95C;					// 95C
		UInt32							unk960;					// 960
		UInt32							unk964;					// 964
		void*							currentPoison;			// 968
		UInt64							unk970;					// 970 - init'd to GetTickCount() in ctor
		UInt64							unk978;					// 978
		UInt32							unk980;					// 980 - init'd to _time64(NULL) in ctor
		UInt32							unk984;					// 984
		TESWorldSpace*					sameWorldSpace;			// 988
		UInt32							unk990;					// 990
		UInt32							unk994;					// 994
		UInt64							unk998;					// 998
		UInt64							unk9A0;					// 9A0
		UInt64							unk9A8;					// 9A8
		PlayerSkills*					skills;					// 9B0
		UInt32							targetHandle;			// 9B8
		UInt32							unk9BC;					// 9BC
		UInt64							unk9C0;					// 9C0
		BSFadeNode*						fadeNode9C8;			// 9C8
		void*							unk9D0;					// 9D0
		tArray<UInt32>					hostileHandles; 		// 9D8
		UInt64							unk9F0;					// 9F0
		UInt64							unk9F8;					// 9F8
		TESForm*						tempPoison;				// A00
		UInt32							numTeammates;			// A08
		UInt32							unkA0C;					// A0C
		UInt64							unkA10;					// A10
		float							unkA18;					// A18
		UInt32							unkA1C;					// A1C
		UInt8							unkA20[0xA0];			// A20 - memset to 0 in ctor
		UInt32							unkAC0;					// AC0
		UInt32							unkAC4;					// AC4
		BGSLocation*					locationAC8;			// AC8
		float							unkAD0;					// AD0
		UInt32							unkAD4;					// AD4
		UInt32							unkAD8;					// AD8
		UInt32							unkADC;					// ADC
		UInt64							unkAE0;					// AE0
		UInt32							unkAE8;					// AE8
		UInt32							unkAEC;					// AEC
		UInt32							unkAF0;					// AF0
		UInt32							unkAF4;					// AF4
		UInt32							unkAF8;					// AF8
		UInt32							unkAFC;					// AFC
		UInt8							unkB00;					// B00
		UInt8							numPerkPoints;			// B01
		UInt8							unkB02;					// B02
		UInt8							unkB03;					// B03
		UInt32							unkB04;					// B04
		void*							unkB08;					// B08
		tArray<TintMask*>				tintMasks;				// B10
		tArray<TintMask*>*				overlayTintMasks;		// B28
		BGSTextureSet*					texSetB30;				// B30
		TESRace*						race;					// B38
		TESRace*						raceAgain;				// B40 - transformed race maybe for vamps and werewolves?
		UInt32							unkB48;					// B48
		UInt32							unkB4C;					// B4C
		UnkArray						unkB50;					// B50
		UInt64							unkB68[5];				// B68
		UInt64							unkB90;					// B90
		UInt64							unkB98;					// B98
		UInt32							unkBA0;					// BA0
		UInt32							unkBA4;					// BA4
		UInt64							unkBA8;					// BA8
		UInt64							unkBB0[3];				// BB0
		UInt32							unkBC8;					// BC8
		UInt32							unkBCC;					// BCC
		UInt64							unkBD0;					// BD0
		UInt8							unkBD8;					// BD8
		UInt8							unkBD9;					// BD9
		UInt8							unkBDA;					// BDA
		UInt8							unkBDB;					// BDB
		UInt8							unkBDC;					// BDC
		UInt8							unkBDD;					// BDD
		UInt16							padBDE;					// BDE
	};
	STATIC_ASSERT(offsetof(PlayerCharacter, playerGrabbedHandle) == 0x8C8);
	STATIC_ASSERT(sizeof(PlayerCharacter) == 0xBE0);
}
