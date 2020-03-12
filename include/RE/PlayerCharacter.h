#pragma once

#include "RE/BSPointerHandle.h"
#include "RE/BSSoundHandle.h"
#include "RE/BSTArray.h"
#include "RE/BSTEvent.h"
#include "RE/BSTHashMap.h"
#include "RE/BSTList.h"
#include "RE/BSTSmartPointer.h"
#include "RE/BSTTuple.h"
#include "RE/Character.h"
#include "RE/Crime.h"
#include "RE/FormTypes.h"
#include "RE/NiPoint3.h"
#include "RE/NiSmartPointer.h"
#include "RE/NiTMap.h"
#include "RE/PositionPlayerEvent.h"
#include "RE/hkRefPtr.h"


namespace RE
{
	class Actor;
	class BGSInstancedQuestObjective;
	class BGSLocation;
	class bhkMouseSpringAction;
	class BipedAnim;
	class BSFadeNode;
	class BSLight;
	class CombatGroup;
	class ImageSpaceModifierInstanceDOF;
	class InventoryEntryData;
	class MenuModeChangeEvent;
	class MenuOpenCloseEvent;
	class NiAVObject;
	class NiNode;
	class ObjectListItem;
	class TESObjectREFR;
	class TintMask;
	class UserEventEnabledEvent;
	struct BGSActorCellEvent;
	struct BGSActorDeathEvent;
	struct PerkRankData;
	struct PositionPlayerEvent;
	struct TESQuestStageItem;
	struct TESTrackedStatsEvent;


	enum class PLAYER_ACTION : UInt32
	{
		kNone = 0,
		kSwingMeleeWeapon,
		kCastProjectileSpell,
		kShootBow,
		kZKeyObject,
		kJumping,
		kKnockingOverObjects,
		kStandOnTableChair,
		kIronSights,
		kDestroyObject,
		kLockedObject,
		kPickpocket,
		kCastSelfSpell,
		kShout,
		kActorCollision,

		kTotal,
		kInvalidMarker
	};


	struct CrimeGoldStruct
	{
		float violentCur;		 // 00
		float nonViolentCur;	 // 04
		float nonViolentInfamy;	 // 08
		float violentInfamy;	 // 0C
	};
	STATIC_ASSERT(sizeof(CrimeGoldStruct) == 0x10);


	struct StolenItemValueStruct
	{
		SInt32 unwitnessed;	 // 0
		SInt32 witnessed;	 // 4
	};
	STATIC_ASSERT(sizeof(StolenItemValueStruct) == 0x8);


	struct FriendshipFactionsStruct
	{
		UInt16 friendCounts[4];	 // 0
	};
	STATIC_ASSERT(sizeof(FriendshipFactionsStruct) == 0x8);


	class PLAYER_TARGET_LOC
	{
		using ArrivalFunc_t = void(SInt64);


		TESWorldSpace* world;			  // 00
		TESObjectCELL* interior;		  // 08
		NiPoint3	   location;		  // 10
		NiPoint3	   angle;			  // 1C
		ArrivalFunc_t* arrivalFunc;		  // 28
		SInt64		   arrivalFuncData;	  // 30
		RefHandle	   furnitureRef;	  // 38
		RefHandle	   fastTravelMarker;  // 3C
		bool		   resetWeather;	  // 40
		bool		   allowAutoSave;	  // 41
		bool		   isValid;			  // 42
		UInt8		   pad43;			  // 43
		UInt32		   pad44;			  // 44
	};
	STATIC_ASSERT(sizeof(PLAYER_TARGET_LOC) == 0x48);


	struct PlayerActionObject
	{
		float		  timer;   // 0
		RefHandle	  refObj;  // 4
		PLAYER_ACTION next;	   // 8
	};
	STATIC_ASSERT(sizeof(PlayerActionObject) == 0xC);


	class PlayerCharacter :
		public Character,							 // 000
		public BSTEventSource<BGSActorCellEvent>,	 // 2D0
		public BSTEventSource<BGSActorDeathEvent>,	 // 328
		public BSTEventSource<PositionPlayerEvent>,	 // 380
		public BSTEventSink<MenuOpenCloseEvent>,	 // 2B0
		public BSTEventSink<MenuModeChangeEvent>,	 // 2B8
		public BSTEventSink<UserEventEnabledEvent>,	 // 2C0
		public BSTEventSink<TESTrackedStatsEvent>	 // 2C8
	{
	public:
		inline static constexpr auto RTTI = RTTI_PlayerCharacter;
		inline static constexpr auto FORMTYPE = FormType::ActorCharacter;


		enum class EventType : UInt32
		{
			kThief = 3,
			kContainer = 5,
			kDeadBody = 6
		};


		enum class GrabbingType : UInt32
		{
			kNone = 0,
			kNormal,
			kTelekinesis,
		};


		enum class ByCharGenFlag : UInt8
		{
			kNone = 0,
			kHandsBound = 1 << 2
		};


		enum class FlagBD9 : UInt8
		{
			kNone = 0,
			kIsSleeping = 1 << 2,
			kGreetingPlayer = 1 << 6
		};


		enum class FlagBDB : UInt8
		{
			kNone = 0,
			kIsInCombat = 1 << 5
		};


		enum class FlagBDC : UInt8
		{
			kNone = 0,
			kHealthTutorialShown = 1 << 3,
			kMagickaTutorialShown = 1 << 4,
			kStaminaTutorialShown = 1 << 5,
			kGoToJailQueued = 1 << 6
		};


		struct Data928
		{
			BSTArray<UnkValue> unk00;  // 00
			BSTArray<UnkValue> unk18;  // 18
			UInt64			   unk30;  // 30
			UInt64			   unk38;  // 38
			UInt64			   unk40;  // 40
		};
		STATIC_ASSERT(sizeof(Data928) == 0x48);


		struct PlayerSkills
		{
			struct Data
			{
				struct Skills
				{
					enum Skill : UInt32
					{
						kOneHanded = 0,
						kTwoHanded = 1,
						kArchery = 2,
						kBlock = 3,
						kSmithing = 4,
						kHeavyArmor = 5,
						kLightArmor = 6,
						kPickpocket = 7,
						kLockpicking = 8,
						kSneak = 9,
						kAlchemy = 10,
						kSpeech = 11,
						kAlteration = 12,
						kConjuration = 13,
						kDestruction = 14,
						kIllusion = 15,
						kRestoration = 16,
						kEnchanting = 17,
						kTotal
					};
				};
				using Skill = Skills::Skill;


				struct SkillData
				{
					float level;		   // 0
					float xp;			   // 4
					float levelThreshold;  // 8
				};
				STATIC_ASSERT(sizeof(SkillData) == 0xC);


				float	  xp;							   // 000
				float	  levelThreshold;				   // 004
				SkillData skills[Skill::kTotal];		   // 008
				UInt32	  legendaryLevels[Skill::kTotal];  // 0E0
			};
			STATIC_ASSERT(sizeof(Data) == 0x128);


			void AdvanceLevel(bool a_addThreshold);


			// members
			Data* data;	 // 0
		};
		STATIC_ASSERT(sizeof(PlayerSkills) == 0x8);


		virtual ~PlayerCharacter();	 // 000

		// add
		virtual void   Unk_12A(void);													// 12A
		virtual UInt32 GetViolentCrimeGoldValue(const TESFaction* a_faction) const;		// 12B
		virtual UInt32 GetNonViolentCrimeGoldValue(const TESFaction* a_faction) const;	// 12C
		virtual void   ClearAllCrimeGold(TESFaction* a_faction);						// 12D
		virtual void   Unk_12E(void);													// 12E - { return 0; }

		static PlayerCharacter* GetSingleton();
		static UInt32			GetPickpocketChance(float a_playerSkill, float a_targetSkill, UInt32 a_totalValue, float a_itemWeight, Actor* a_player, Actor* a_target, bool a_isDetected, TESForm* a_item);

		void					 ActivatePickRef();
		bool					 AttemptPickpocket(TESObjectREFR* a_target, InventoryEntryData* a_entry, SInt32 a_numItems, bool a_useMult = true);
		NiPointer<Actor>		 GetActorDoingPlayerCommand() const;
		float					 GetArmorValue(InventoryEntryData* a_form);
		float					 GetDamage(InventoryEntryData* a_form);
		NiPointer<TESObjectREFR> GetGrabbedRef();
		UInt32					 GetNumTints(UInt32 a_tintType);
		TintMask*				 GetOverlayTintMask(TintMask* a_original);
		BSTArray<TintMask*>&	 GetTintList();
		TintMask*				 GetTintMask(UInt32 a_tintType, UInt32 a_index);
		void					 PlayPickupEvent(TESForm* a_item, TESForm* a_containerOwner, TESObjectREFR* a_containerRef, EventType a_eventType);
		void					 StartGrabObject();


		// members
		UInt32													unk3D8;										  // 3D8
		UInt32													unk3DC;										  // 3DC
		BSTHashMap<const TESFaction*, CrimeGoldStruct>			crimeGoldMap;								  // 3E0
		BSTHashMap<const TESFaction*, StolenItemValueStruct>	stolenItemValueMap;							  // 410
		ObjectRefHandle											commandWaitMarker;							  // 440
		UInt32													unk444;										  // 444
		BSTHashMap<const TESFaction*, FriendshipFactionsStruct> factionOwnerFriendsMap;						  // 448
		NiPoint3												lastKnownGoodPosition;						  // 478
		NiPoint3												bulletAutoAim;								  // 484
		NiPoint3												cachedVelocity;								  // 490
		float													unk49C;										  // 49C
		UInt64													unk4A0;										  // 4A0
		UInt64													unk4A8;										  // 4A8
		BSTArray<PerkRankData*>									addedPerks;									  // 4B0
		BSTArray<BGSPerk*>										perks;										  // 4C8
		BSTArray<BGSPerk*>										standingStonePerks;							  // 4E0
		BSTArray<ObjectRefHandle>								currentMapMarkers;							  // 4F8
		BSTArray<BSTTuple<NiPoint3, AITimeStamp>>				velocityArray;								  // 510
		BSTArray<ProjectileHandle>								runesCast;									  // 528
		BSTArray<void*>											imageSpaceModifierAnims1;					  // 540
		BSTArray<void*>											imageSpaceModifierAnims2;					  // 558
		BSSimpleList<TESQuestStageItem*>						questLog;									  // 570
		BSTArray<BGSInstancedQuestObjective*>					objectives;									  // 580
		BSTHashMap<UnkKey, UnkValue>							unk598;										  // 598
		BSTHashMap<UnkKey, UnkValue>							currentSayOnceInfosMap;						  // 5C8
		BSSimpleList<ObjectRefHandle>							droppedRefList;								  // 600
		NiTMap<UInt32, UInt8>									randomDoorSpaceMap;							  // 608
		TESWorldSpace*											cachedWorldSpace;							  // 628
		NiPoint3												exteriorPosition;							  // 630
		UInt32													unk63C;										  // 63C
		PLAYER_TARGET_LOC										queuedTargetLoc;							  // 640
		BSSoundHandle											unk688;										  // 688
		BSSoundHandle											magicFailureSound;							  // 694
		BSSoundHandle											unk6A0;										  // 6A0
		UInt32													pad6AC;										  // 6AC
		DialoguePackage*										closestConversation;						  // 6B0
		UInt32													unk6B8;										  // 6B8
		UInt32													unk6BC;										  // 6BC
		DialoguePackage*										aiConversationRunning;						  // 6C0
		SInt32													numberofStealWarnings;						  // 6C8
		float													stealWarningTimer;							  // 6CC
		SInt32													numberofPickpocketWarnings;					  // 6D0
		float													pickPocketWarningTimer;						  // 6D4
		AITimeStamp												warnToLeaveTimeStamp;						  // 6D8
		UInt32													pad6DC;										  // 6DC
		ImageSpaceModifierInstanceDOF*							ironsightsDOFInstance;						  // 6E0
		ImageSpaceModifierInstanceDOF*							vatsDOFInstance;							  // 6E8
		ImageSpaceModifierInstanceDOF*							dynamicDOFInstance;							  // 6F0
		float													dynamicDOFFocusTime;						  // 6F8
		bool													dynamicDOFFocused;							  // 6FC
		UInt8													unk6FD;										  // 6FD
		UInt16													unk6FE;										  // 6FE
		NiPoint3												dynamicDOFLastAngle;						  // 700
		NiPoint3												dynamicDOFLastPosition;						  // 70C
		TESFaction*												currentPrisonFaction;						  // 718
		SInt32													jailSentence;								  // 720
		UInt32													pad724;										  // 724
		void*													unk728;										  // 728 - smart ptr
		UInt8													unk730[0xA0];								  // 730
		SInt32													vampireFeedDetection;						  // 7D0
		UInt32													mapMarkerIterator;							  // 7D4
		RefHandle												forceActivateRef;							  // 7D8
		PlayerActionObject										playerActionObjects[15];					  // 7DC
		PLAYER_ACTION											mostRecentAction;							  // 890
		ActorHandle												actorDoingPlayerCommand;					  // 894
		BSTSmallArray<hkRefPtr<bhkMouseSpringAction>, 4>		grabSpring;									  // 898
		ObjectRefHandle											grabbedObject;								  // 8C8
		float													grabObjectWeight;							  // 8CC
		float													grabDistance;								  // 8D0
		float													unk8D4;										  // 8D4
		UInt64													unk8D8;										  // 8D8
		UInt32													unk8E0;										  // 8E0
		UInt32													sleepSeconds;								  // 8E4
		BSTSmartPointer<BipedAnim>								largeBiped;									  // 8E8
		NiPointer<NiNode>										firstPerson3D;								  // 8F0
		float													eyeHeight;									  // 8F8
		float													greetTimer;									  // 8FC
		float													encumberedTimer;							  // 900
		float													powerAttackTimer;							  // 904
		SInt32													hoursToSleep;								  // 908
		SInt32													amountStolenSold;							  // 90C
		UInt32													valueStolen;								  // 910
		ActorHandle												lastRiddenMount;							  // 914
		ActorHandle												lightTarget;								  // 918
		float													sortActorDistanceTimer;						  // 91C
		float													sitHeadingDelta;							  // 920
		UInt32													unk924;										  // 924
		Data928*												unk928;										  // 928
		UInt32													skillTrainingsThisLevel;					  // 930
		UInt32													unk934;										  // 934
		TESClass*												defaultClass;								  // 938
		UInt64													unk940;										  // 940
		UInt32													crimeCounts[PackageNS::CRIME_TYPES::kTotal];  // 948
		UInt32													unk964;										  // 964
		AlchemyItem*											pendingPoison;								  // 968
		SInt64													lastPlayingTimeUpdate;						  // 970
		SInt64													totalPlayingTime;							  // 978
		SInt32													characterSeed;								  // 980
		UInt32													unk984;										  // 984
		TESForm*												lastKnownGoodLocation;						  // 988
		UInt32													unk990;										  // 990
		UInt32													unk994;										  // 994
		NiPointer<BSLight>										firstPersonLight;							  // 998
		NiPointer<BSLight>										thirdPersonLight;							  // 9A0
		float													dropAngleMod;								  // 9A8
		float													lastDropAngleMod;							  // 9AC
		PlayerSkills*											skills;										  // 9B0
		ActorHandle												autoAimActor;								  // 9B8
		RefHandle												unk9BC;										  // 9BC
		UInt64													unk9C0;										  // 9C0
		NiPointer<NiAVObject>									targeted3D;									  // 9C8
		CombatGroup*											combatGroup;								  // 9D0
		BSTArray<ActorHandle>									actorsToDisplayOnTheHUDArray;				  // 9D8
		UInt64													unk9F0;										  // 9F0
		TESBoundObject*											lastOneHandItems[2];						  // 9F8
		UInt32													teammateCount;								  // A08
		float													combatTimer;								  // A0C
		float													yieldTimer;									  // A10
		float													chaseTimer;									  // A14
		float													drawSheatheSafetyTimer;						  // A18
		UInt32													unkA1C;										  // A1C
		UInt8													unkA20[0xA0];								  // A20
		UInt32													unkAC0;										  // AC0
		UInt32													unkAC4;										  // AC4
		BGSLocation*											currentLocation;							  // AC8
		AITimeStamp												cachedVelocityTimeStamp;					  // AD0
		float													telekinesisDistance;						  // AD4
		float													commandTimer;								  // AD8
		UInt32													unkADC;										  // ADC
		TESImageSpaceModifier*									unkAE0;										  // AE0
		SInt32													unkAE8;										  // AE8
		UInt32													unkAEC;										  // AEC
		UInt32													unkAF0;										  // AF0
		GrabbingType											grabType;									  // AF4
		SInt32													difficulty;									  // AF8
		UInt32													unkAFC;										  // AFC
		SInt8													murder;										  // B00
		SInt8													perkCount;									  // B01
		ByCharGenFlag											byCharGenFlag;								  // B02
		UInt8													padB03;										  // B03
		UInt32													unkB04;										  // B04
		Crime*													resistArrestCrime;							  // B08
		BSTArray<TintMask*>										tintMasks;									  // B10
		BSTArray<TintMask*>*									overlayTintMasks;							  // B28
		BGSTextureSet*											complexion;									  // B30
		TESRace*												charGenRace;								  // B38
		TESRace*												race2;										  // B40
		SInt32													unkB48;										  // B48
		UInt32													padB4C;										  // B4C
		BSTArray<UInt64>										unkB50;										  // B50
		UInt64													unkB68;										  // B68
		UInt64													unkB70;										  // B70
		UInt64													unkB78;										  // B78
		UInt64													unkB80;										  // B80
		SInt32													unkB88;										  // B88
		UInt32													padB8C;										  // B8C
		UInt64													unkB90;										  // B90
		UInt64													unkB98;										  // B98
		BSTSmallArray<void*, 4>									unkBA0;										  // BA0
		UInt64													unkBD0;										  // BD0
		UInt8													unkBD8;										  // BD8
		FlagBD9													unkBD9;										  // BD9
		UInt8													unkBDA;										  // BDA
		FlagBDB													unkBDB;										  // BDB
		FlagBDC													unkBDC;										  // BDC
		UInt8													unkBDD;										  // BDD
		UInt16													padBDE;										  // BDE
	};
	STATIC_ASSERT(sizeof(PlayerCharacter) == 0xBE0);
}
