#pragma once

#include "skse64/GameRTTI.h"  // RTTI_PlayerCharacter

#include "RE/BGSActorCellEvent.h"  // BGSActorCellEvent
#include "RE/BGSActorDeathEvent.h"  // BGSActorDeathEvent
#include "RE/BGSPerkRankArray.h"  // BGSPerkRankArray
#include "RE/BSTArray.h"  // BSTArray
#include "RE/BSTEvent.h"  // BSTEventSink, BSTEventSource
#include "RE/BSTHashMap.h"  // BSTHashMap
#include "RE/Character.h"  // Character
#include "RE/FormTypes.h"  // FormType, TESForm, TESRace, TESWorldSpace, BGSPerk, BGSTextureSet
#include "RE/NiTMap.h"  // NiTMap
#include "RE/PositionPlayerEvent.h"  // PositionPlayerEvent
#include "RE/UserEventEnabledEvent.h"  // UserEventEnabledEvent



namespace RE
{
	class Actor;
	class BGSLocation;
	class BSFadeNode;
	class ImageSpaceModifierInstanceDOF;
	class InventoryEntryData;
	class MenuOpenCloseEvent;
	class ObjectListItem;
	class TESObjectREFR;
	class TintMask;
	struct ModeChangeEvent;


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
		inline static const void* RTTI = RTTI_PlayerCharacter;


		enum { kTypeID = FormType::ActorCharacter };


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


		struct DataUnk510
		{
			UInt32 a;	// 0
			UInt32 b;	// 4
			UInt32 c;	// 8
			UInt32 pad;	// C
		};


		virtual ~PlayerCharacter();				// 000

		// add
		virtual void			Unk_12A(void);	// 12A
		virtual void			Unk_12B(void);	// 12B
		virtual void			Unk_12C(void);	// 12C
		virtual void			Unk_12D(void);	// 12D
		virtual void			Unk_12E(void);	// 12E - { return 0; }

		static PlayerCharacter*	GetSingleton();
		static UInt32			GetPickpocketChance(float a_playerSkill, float a_targetSkill, UInt32 a_totalValue, float a_itemWeight, Actor* a_player, Actor* a_target, bool a_isDetected, TESForm* a_item);

		TintMask*				GetOverlayTintMask(TintMask* a_original);
		BSTArray<TintMask*>&	GetTintList();
		UInt32					GetNumTints(UInt32 a_tintType);
		TintMask*				GetTintMask(UInt32 a_tintType, UInt32 a_index);
		float					GetDamage(InventoryEntryData* a_form);
		float					GetArmorValue(InventoryEntryData* a_form);
		Actor*					GetActorInFavorState();
		TESObjectREFR*			GetGrabbedRef();
		void					PlayPickupEvent(TESForm* a_item, TESForm* a_containerOwner, TESObjectREFR* a_containerRef, EventType a_eventType);
		void					StartActivation();
		bool					TryToPickPocket(Actor* a_target, InventoryEntryData* a_entry, UInt32 a_numItems, bool a_arg4 = true);
		void					SetCollision(bool a_enable);


		// members
		UInt32								unk3D8;					// 3D8
		UInt32								unk3DC;					// 3DC
		BSTHashMap<UnkKey, UnkValue>		unk3E0;					// 3E0
		BSTHashMap<UnkKey, UnkValue>		unk410;					// 410
		UInt32								unk440;					// 440
		UInt32								unk444;					// 444
		BSTHashMap<UnkKey, UnkValue>		unk448;					// 448
		float								unk478;					// 478
		float								unk47C;					// 47C
		float								unk480;					// 480
		float								unk484;					// 484
		float								unk488;					// 488
		float								unk48C;					// 48C
		float								unk490;					// 490
		float								unk494;					// 494
		float								unk498;					// 498
		float								unk49C;					// 49C
		UInt64								unk4A0;					// 4A0
		UInt64								unk4A8;					// 4A8
		BSTArray<BGSPerkRankArray::Entry*>	addedPerks;				// 4B0
		BSTArray<BGSPerk*>					perks;					// 4C8
		BSTArray<BGSPerk*>					standingStonePerks;		// 4E0
		BSTArray<UInt32>					unk4F8;					// 4F8
		BSTArray<DataUnk510>				unk510;					// 510
		BSTArray<UInt64>					unk528;					// 528
		BSTArray<void*>						unk540;					// 540
		BSTArray<void*>						unk558;					// 558
		void*								unk570;					// 570
		void*								unk578;					// 578
		BSTArray<void*>						unk580;					// 580
		BSTHashMap<UnkKey, UnkValue>		unk598;					// 598
		BSTHashMap<UnkKey, UnkValue>		unk5C8;					// 5C8
		UInt32								unk5F8;					// 5F8
		UInt32								pad5FC;					// 5FC
		UInt64								unk600;					// 600
		NiTMap<UInt32, UInt8>				unk608;					// 608
		TESWorldSpace*						currentWorldSpace;		// 628
		float								unk630;					// 630
		float								unk634;					// 634
		float								unk638;					// 638
		UInt32								unk63C;					// 63C
		UInt64								unk640;					// 640
		UInt64								unk648;					// 648
		float								unk650;					// 650
		float								unk654;					// 654
		float								unk658;					// 658
		float								unk65C;					// 65C
		float								unk660;					// 660
		float								unk664;					// 664
		UInt64								unk668;					// 668
		UInt64								unk670;					// 670
		UInt32								unk678;					// 678
		UInt32								unk67C;					// 67C
		UInt8								unk680;					// 680
		UInt8								unk681;					// 681
		UInt8								unk682;					// 682
		UInt8								pad683;					// 683
		UInt32								unk684;					// 684
		UInt32								unk688;					// 688 - init'd to FFFFFFFF
		UInt8								unk68C;					// 68C
		UInt8								pad68D[3];				// 68D
		UInt32								unk690;					// 690
		UInt32								unk694;					// 694
		UInt8								unk698;					// 698
		UInt8								pad699[3];				// 699
		UInt32								unk69C;					// 69C
		UInt32								unk6A0;					// 6A0
		UInt8								unk6A4;					// 6A4
		UInt8								pad6A5[7];				// 6A5
		UInt64								unk6B0;					// 6B0
		UInt32								unk6B8;					// 6B8
		UInt32								unk6BC;					// 6BC
		UInt64								unk6C0;					// 6C0
		UInt32								unk6C8;					// 6C8
		float								unk6CC;					// 6CC - init'd to -1
		UInt32								unk6D0;					// 6D0
		float								unk6D4;					// 6D4 - init'd to -1
		float								unk6D8;					// 6D8 - FF7FFFFF
		UInt32								unk6DC;					// 6DC - probably pad
		ImageSpaceModifierInstanceDOF*		unk6E0;					// 6E0
		ImageSpaceModifierInstanceDOF*		unk6E8;					// 6E8
		ImageSpaceModifierInstanceDOF*		unk6F0;					// 6F0
		UInt32								unk6F8;					// 6F8 - looks like a pointer along with next in debugger, but it isn't
		UInt32								unk6FC;					// 6FC
		UInt64								unk700[3];				// 700
		UInt64								unk718;					// 718
		UInt32								unk720;					// 720
		UInt32								pad724;					// 724
		UInt64								unk728;					// 728
		UInt8								unk730[0xA0];			// 730 - memset to 0 in ctor
		UInt32								unk7D0;					// 7D0
		UInt32								unk7D4;					// 7D4
		UInt32								unk7D8;					// 7D8
		Data7DC								unk7DC[15];				// 7DC
		UInt32								unk890;					// 890 - init'd to 15
		UInt32								unk894;					// 894 - handle?
		UInt32								unk898;					// 898
		UInt32								unk89C;					// 89C
		UInt64								unk8A0[5];				// 8A0
		UInt32								playerGrabbedHandle;	// 8C8
		float								unk8CC;					// 8CC - related to grabbed item
		UInt32								unk8D0;					// 8D0
		float								unk8D4;					// 8D4 - init'd to -5
		UInt64								unk8D8;					// 8D8
		UInt32								unk8E0;					// 8E0
		UInt32								unk8E4;					// 8E4
		Biped*								largeBiped;				// 8E8
		BSFadeNode*							firstPersonSkeleton;	// 8F0
		float								unk8F8;					// 8F8
		UInt32								pad8FC;					// 8FC
		float								unk900;					// 900
		UInt32								pad904;					// 904
		UInt64								unk908;					// 908
		UInt32								unk910;					// 910
		UInt32								lastRiddenHorseHandle;	// 914
		UInt32								unk918;					// 918
		UInt32								unk91C;					// 91C
		UInt64								unk920;					// 920
		UInt64								unk928;					// 928
		UInt32								unk930;					// 930
		UInt32								unk934;					// 934
		UInt64								unk938;					// 938
		UInt64								unk940;					// 940
		UInt32								unk948;					// 948
		UInt32								unk94C;					// 94C
		UInt32								unk950;					// 950
		UInt32								unk954;					// 954
		UInt32								unk958;					// 958
		UInt32								unk95C;					// 95C
		UInt32								unk960;					// 960
		UInt32								unk964;					// 964
		AlchemyItem*						currentPoison;			// 968
		UInt64								unk970;					// 970 - init'd to GetTickCount() in ctor
		UInt64								unk978;					// 978
		UInt32								unk980;					// 980 - init'd to _time64(NULL) in ctor
		UInt32								unk984;					// 984
		TESObjectCELL*						currentCell;			// 988
		UInt32								unk990;					// 990
		UInt32								unk994;					// 994
		UInt64								unk998;					// 998
		UInt64								unk9A0;					// 9A0
		UInt64								unk9A8;					// 9A8
		PlayerSkills*						skills;					// 9B0
		UInt32								targetHandle;			// 9B8
		UInt32								unk9BC;					// 9BC
		UInt64								unk9C0;					// 9C0
		BSFadeNode*							unk9C8;					// 9C8
		void*								unk9D0;					// 9D0
		BSTArray<UInt32>					hostileHandles; 		// 9D8
		UInt64								unk9F0;					// 9F0
		UInt64								unk9F8;					// 9F8
		AlchemyItem*						tempPoison;				// A00
		UInt32								numTeammates;			// A08
		UInt32								unkA0C;					// A0C
		UInt64								unkA10;					// A10
		float								animTimeout;			// A18
		UInt32								unkA1C;					// A1C
		UInt8								unkA20[0xA0];			// A20 - memset to 0 in ctor
		UInt32								unkAC0;					// AC0
		UInt32								unkAC4;					// AC4
		BGSLocation*						currentLocation;		// AC8
		float								unkAD0;					// AD0
		UInt32								unkAD4;					// AD4
		UInt32								unkAD8;					// AD8
		UInt32								unkADC;					// ADC
		UInt64								unkAE0;					// AE0
		UInt32								unkAE8;					// AE8
		UInt32								unkAEC;					// AEC
		UInt32								unkAF0;					// AF0
		UInt32								unkAF4;					// AF4
		UInt32								unkAF8;					// AF8
		UInt32								unkAFC;					// AFC
		UInt8								unkB00;					// B00
		UInt8								numPerkPoints;			// B01
		UInt8								unkB02;					// B02
		UInt8								unkB03;					// B03
		UInt32								unkB04;					// B04
		void*								unkB08;					// B08
		BSTArray<TintMask*>					tintMasks;				// B10
		BSTArray<TintMask*>*				overlayTintMasks;		// B28
		BGSTextureSet*						texSetB30;				// B30
		TESRace*							baseRace;				// B38 - untransformed race
		TESRace*							race2;					// B40
		UInt32								unkB48;					// B48
		UInt32								unkB4C;					// B4C
		BSTArray<UInt64>					unkB50;					// B50
		UInt64								unkB68;					// B68
		UInt64								unkB70;					// B70
		UInt64								unkB78;					// B78
		UInt64								unkB80;					// B80
		UInt64								unkB88;					// B88
		UInt64								unkB90;					// B90
		UInt64								unkB98;					// B98
		UInt32								unkBA0;					// BA0
		UInt32								unkBA4;					// BA4
		UInt64								unkBA8;					// BA8
		UInt64								unkBB0;					// BB0
		UInt64								unkBB8;					// BB8
		UInt64								unkBC0;					// BC0
		UInt32								unkBC8;					// BC8
		UInt32								unkBCC;					// BCC
		UInt64								unkBD0;					// BD0
		UInt8								unkBD8;					// BD8
		UInt8								unkBD9;					// BD9
		UInt8								unkBDA;					// BDA
		UInt8								unkBDB;					// BDB
		UInt8								unkBDC;					// BDC
		UInt8								unkBDD;					// BDD
		UInt16								padBDE;					// BDE
	};
	STATIC_ASSERT(offsetof(PlayerCharacter, playerGrabbedHandle) == 0x8C8);
	STATIC_ASSERT(sizeof(PlayerCharacter) == 0xBE0);
}
