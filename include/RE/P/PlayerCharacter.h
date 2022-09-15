#pragma once

#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSSoundHandle.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSTHashMap.h"
#include "RE/B/BSTList.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/B/BSTTuple.h"
#include "RE/C/Character.h"
#include "RE/C/Crime.h"
#include "RE/F/FormTypes.h"
#include "RE/H/hkRefPtr.h"
#include "RE/N/NiPoint3.h"
#include "RE/N/NiSmartPointer.h"
#include "RE/N/NiTMap.h"
#include "RE/P/PositionPlayerEvent.h"

namespace RE
{
	enum class AQUIRE_TYPE;

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
	class TESObject;
	class TESObjectREFR;
	class TintMask;
	class UserEventEnabledEvent;
	struct BGSActorCellEvent;
	struct BGSActorDeathEvent;
	struct PerkRankData;
	struct PositionPlayerEvent;
	struct TESQuestStageItem;
	struct TESTrackedStatsEvent;

	enum class PLAYER_ACTION
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
	public:
		// members
		float violentCur;        // 00
		float nonViolentCur;     // 04
		float nonViolentInfamy;  // 08
		float violentInfamy;     // 0C
	};
	static_assert(sizeof(CrimeGoldStruct) == 0x10);

	struct StolenItemValueStruct
	{
	public:
		// members
		std::int32_t unwitnessed;  // 0
		std::int32_t witnessed;    // 4
	};
	static_assert(sizeof(StolenItemValueStruct) == 0x8);

	struct FriendshipFactionsStruct
	{
	public:
		// members
		std::uint16_t friendCounts[4];  // 0
	};
	static_assert(sizeof(FriendshipFactionsStruct) == 0x8);

	class PLAYER_TARGET_LOC
	{
	public:
		using ArrivalFunc_t = void(std::int64_t);

		// members
		TESWorldSpace* world;             // 00
		TESObjectCELL* interior;          // 08
		NiPoint3       location;          // 10
		NiPoint3       angle;             // 1C
		ArrivalFunc_t* arrivalFunc;       // 28
		std::int64_t   arrivalFuncData;   // 30
		RefHandle      furnitureRef;      // 38
		RefHandle      fastTravelMarker;  // 3C
		bool           resetWeather;      // 40
		bool           allowAutoSave;     // 41
		bool           isValid;           // 42
		std::uint8_t   pad43;             // 43
		std::uint32_t  pad44;             // 44
	};
	static_assert(sizeof(PLAYER_TARGET_LOC) == 0x48);

	struct PlayerActionObject
	{
	public:
		// members
		float                                          timer;   // 0
		RefHandle                                      refObj;  // 4
		stl::enumeration<PLAYER_ACTION, std::uint32_t> next;    // 8
	};
	static_assert(sizeof(PlayerActionObject) == 0xC);

	class PlayerCharacter :
		public Character,                            // 000
		public BSTEventSource<BGSActorCellEvent>,    // 2D0
		public BSTEventSource<BGSActorDeathEvent>,   // 328
		public BSTEventSource<PositionPlayerEvent>,  // 380
		public BSTEventSink<MenuOpenCloseEvent>,     // 2B0
		public BSTEventSink<MenuModeChangeEvent>,    // 2B8
		public BSTEventSink<UserEventEnabledEvent>,  // 2C0
		public BSTEventSink<TESTrackedStatsEvent>    // 2C8
	{
	public:
		inline static constexpr auto RTTI = RTTI_PlayerCharacter;
		inline static constexpr auto FORMTYPE = FormType::ActorCharacter;

		enum class EventType
		{
			kThief = 3,
			kContainer = 5,
			kDeadBody = 6
		};

		enum class GrabbingType
		{
			kNone = 0,
			kNormal,
			kTelekinesis,
		};

		enum class ByCharGenFlag
		{
			kNone = 0,
			kHandsBound = 1 << 2
		};

		enum class FlagBD9
		{
			kNone = 0,
			kIsSleeping = 1 << 2,
			kGreetingPlayer = 1 << 6
		};

		enum class FlagBDB
		{
			kNone = 0,
			kIsInCombat = 1 << 5
		};

		enum class FlagBDC
		{
			kNone = 0,
			kHealthTutorialShown = 1 << 3,
			kMagickaTutorialShown = 1 << 4,
			kStaminaTutorialShown = 1 << 5,
			kGoToJailQueued = 1 << 6
		};

		enum class FlagBDD
		{
			kNone = 0,
			kSprinting = 1 << 0,
			kDragonRideTargetLocked = 1 << 2,
			kEverModded = 1 << 3,
			kServingJailTime = 1 << 4
		};

		struct Data928
		{
		public:
			// members
			BSTArray<UnkValue> unk00;  // 00
			BSTArray<UnkValue> unk18;  // 18
			std::uint64_t      unk30;  // 30
			std::uint64_t      unk38;  // 38
			std::uint64_t      unk40;  // 40
		};
		static_assert(sizeof(Data928) == 0x48);

		struct PlayerSkills
		{
		public:
			struct Data
			{
			public:
				struct Skills
				{
					enum Skill : std::uint32_t
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
				public:
					// members
					float level;           // 0
					float xp;              // 4
					float levelThreshold;  // 8
				};
				static_assert(sizeof(SkillData) == 0xC);

				// members
				float         xp;                              // 000
				float         levelThreshold;                  // 004
				SkillData     skills[Skill::kTotal];           // 008
				std::uint32_t legendaryLevels[Skill::kTotal];  // 0E0
			};
			static_assert(sizeof(Data) == 0x128);

			void AdvanceLevel(bool a_addThreshold);

			// members
			Data* data;  // 0
		};
		static_assert(sizeof(PlayerSkills) == 0x8);

		~PlayerCharacter() override;  // 000

		// add
		virtual void          Unk_12A(void);                                                   // 12A
		virtual std::uint32_t GetViolentCrimeGoldValue(const TESFaction* a_faction) const;     // 12B
		virtual std::uint32_t GetNonViolentCrimeGoldValue(const TESFaction* a_faction) const;  // 12C
		virtual void          ClearAllCrimeGold(TESFaction* a_faction);                        // 12D
		virtual void          Unk_12E(void);                                                   // 12E - { return 0; }

		static PlayerCharacter* GetSingleton();

		void                     ActivatePickRef();
		void                     AddPlayerAddItemEvent(TESObject* a_object, TESForm* a_owner, TESObjectREFR* a_container, AQUIRE_TYPE a_type);
		void                     AddSkillExperience(ActorValue a_skill, float a_experience);
		bool                     AttemptPickpocket(TESObjectREFR* a_containerRef, InventoryEntryData* a_entry, std::int32_t a_number, bool a_fromContainer = true);
		bool                     CenterOnCell(const char* a_cellName);
		bool                     CenterOnCell(RE::TESObjectCELL* a_cell);
		NiPointer<Actor>         GetActorDoingPlayerCommand() const;
		float                    GetArmorValue(InventoryEntryData* a_form);
		float                    GetDamage(InventoryEntryData* a_form);
		NiPointer<TESObjectREFR> GetGrabbedRef();
		std::uint32_t            GetNumTints(std::uint32_t a_tintType);
		TintMask*                GetOverlayTintMask(TintMask* a_original);
		BSTArray<TintMask*>&     GetTintList();
		TintMask*                GetTintMask(std::uint32_t a_tintType, std::uint32_t a_index);
		bool                     HasActorDoingCommand() const;
		bool                     IsGrabbing() const;
		void                     PlayPickupEvent(TESForm* a_item, TESForm* a_containerOwner, TESObjectREFR* a_containerRef, EventType a_eventType);
		void                     StartGrabObject();

		// members
		std::uint32_t                                           unk3D8;                                       // 3D8
		std::uint32_t                                           unk3DC;                                       // 3DC
		BSTHashMap<const TESFaction*, CrimeGoldStruct>          crimeGoldMap;                                 // 3E0
		BSTHashMap<const TESFaction*, StolenItemValueStruct>    stolenItemValueMap;                           // 410
		ObjectRefHandle                                         commandWaitMarker;                            // 440
		std::uint32_t                                           unk444;                                       // 444
		BSTHashMap<const TESFaction*, FriendshipFactionsStruct> factionOwnerFriendsMap;                       // 448
		NiPoint3                                                lastKnownGoodPosition;                        // 478
		NiPoint3                                                bulletAutoAim;                                // 484
		NiPoint3                                                cachedVelocity;                               // 490
		float                                                   unk49C;                                       // 49C
		std::uint64_t                                           unk4A0;                                       // 4A0
		std::uint64_t                                           unk4A8;                                       // 4A8
		BSTArray<PerkRankData*>                                 addedPerks;                                   // 4B0
		BSTArray<BGSPerk*>                                      perks;                                        // 4C8
		BSTArray<BGSPerk*>                                      standingStonePerks;                           // 4E0
		BSTArray<ObjectRefHandle>                               currentMapMarkers;                            // 4F8
		BSTArray<BSTTuple<NiPoint3, AITimeStamp>>               velocityArray;                                // 510
		BSTArray<ProjectileHandle>                              runesCast;                                    // 528
		BSTArray<void*>                                         imageSpaceModifierAnims1;                     // 540
		BSTArray<void*>                                         imageSpaceModifierAnims2;                     // 558
		BSSimpleList<TESQuestStageItem*>                        questLog;                                     // 570
		BSTArray<BGSInstancedQuestObjective>                    objectives;                                   // 580
		BSTHashMap<UnkKey, UnkValue>                            unk598;                                       // 598
		BSTHashMap<UnkKey, UnkValue>                            currentSayOnceInfosMap;                       // 5C8
		BSSimpleList<ObjectRefHandle>                           droppedRefList;                               // 5F8
		NiTMap<std::uint32_t, std::uint8_t>                     randomDoorSpaceMap;                           // 608
		TESWorldSpace*                                          cachedWorldSpace;                             // 628
		NiPoint3                                                exteriorPosition;                             // 630
		std::uint32_t                                           unk63C;                                       // 63C
		PLAYER_TARGET_LOC                                       queuedTargetLoc;                              // 640
		BSSoundHandle                                           unk688;                                       // 688
		BSSoundHandle                                           magicFailureSound;                            // 694
		BSSoundHandle                                           unk6A0;                                       // 6A0
		std::uint32_t                                           pad6AC;                                       // 6AC
		DialoguePackage*                                        closestConversation;                          // 6B0
		std::uint32_t                                           unk6B8;                                       // 6B8
		std::uint32_t                                           unk6BC;                                       // 6BC
		DialoguePackage*                                        aiConversationRunning;                        // 6C0
		std::int32_t                                            numberofStealWarnings;                        // 6C8
		float                                                   stealWarningTimer;                            // 6CC
		std::int32_t                                            numberofPickpocketWarnings;                   // 6D0
		float                                                   pickPocketWarningTimer;                       // 6D4
		AITimeStamp                                             warnToLeaveTimeStamp;                         // 6D8
		std::uint32_t                                           pad6DC;                                       // 6DC
		ImageSpaceModifierInstanceDOF*                          ironsightsDOFInstance;                        // 6E0
		ImageSpaceModifierInstanceDOF*                          vatsDOFInstance;                              // 6E8
		ImageSpaceModifierInstanceDOF*                          dynamicDOFInstance;                           // 6F0
		float                                                   dynamicDOFFocusTime;                          // 6F8
		bool                                                    dynamicDOFFocused;                            // 6FC
		std::uint8_t                                            unk6FD;                                       // 6FD
		std::uint16_t                                           unk6FE;                                       // 6FE
		NiPoint3                                                dynamicDOFLastAngle;                          // 700
		NiPoint3                                                dynamicDOFLastPosition;                       // 70C
		TESFaction*                                             currentPrisonFaction;                         // 718
		std::int32_t                                            jailSentence;                                 // 720
		std::uint32_t                                           pad724;                                       // 724
		void*                                                   unk728;                                       // 728 - smart ptr
		std::uint8_t                                            unk730[0xA0];                                 // 730
		std::int32_t                                            vampireFeedDetection;                         // 7D0
		std::uint32_t                                           mapMarkerIterator;                            // 7D4
		RefHandle                                               forceActivateRef;                             // 7D8
		PlayerActionObject                                      playerActionObjects[15];                      // 7DC
		PLAYER_ACTION                                           mostRecentAction;                             // 890
		ActorHandle                                             actorDoingPlayerCommand;                      // 894
		BSTSmallArray<hkRefPtr<bhkMouseSpringAction>, 4>        grabSpring;                                   // 898
		ObjectRefHandle                                         grabbedObject;                                // 8C8
		float                                                   grabObjectWeight;                             // 8CC
		float                                                   grabDistance;                                 // 8D0
		float                                                   unk8D4;                                       // 8D4
		std::uint64_t                                           unk8D8;                                       // 8D8
		std::uint32_t                                           unk8E0;                                       // 8E0
		std::uint32_t                                           sleepSeconds;                                 // 8E4
		BSTSmartPointer<BipedAnim>                              largeBiped;                                   // 8E8
		NiPointer<NiNode>                                       firstPerson3D;                                // 8F0
		float                                                   eyeHeight;                                    // 8F8
		float                                                   greetTimer;                                   // 8FC
		float                                                   encumberedTimer;                              // 900
		float                                                   powerAttackTimer;                             // 904
		std::int32_t                                            hoursToSleep;                                 // 908
		std::int32_t                                            amountStolenSold;                             // 90C
		std::uint32_t                                           valueStolen;                                  // 910
		ActorHandle                                             lastRiddenMount;                              // 914
		ActorHandle                                             lightTarget;                                  // 918
		float                                                   sortActorDistanceTimer;                       // 91C
		float                                                   sitHeadingDelta;                              // 920
		std::uint32_t                                           unk924;                                       // 924
		Data928*                                                unk928;                                       // 928
		std::uint32_t                                           skillTrainingsThisLevel;                      // 930
		std::uint32_t                                           unk934;                                       // 934
		TESClass*                                               defaultClass;                                 // 938
		std::uint64_t                                           unk940;                                       // 940
		std::uint32_t                                           crimeCounts[PackageNS::CRIME_TYPES::kTotal];  // 948
		std::uint32_t                                           unk964;                                       // 964
		AlchemyItem*                                            pendingPoison;                                // 968
		std::int64_t                                            lastPlayingTimeUpdate;                        // 970
		std::int64_t                                            totalPlayingTime;                             // 978
		std::int32_t                                            characterSeed;                                // 980
		std::uint32_t                                           unk984;                                       // 984
		TESForm*                                                lastKnownGoodLocation;                        // 988
		std::uint32_t                                           unk990;                                       // 990
		std::uint32_t                                           unk994;                                       // 994
		NiPointer<BSLight>                                      firstPersonLight;                             // 998
		NiPointer<BSLight>                                      thirdPersonLight;                             // 9A0
		float                                                   dropAngleMod;                                 // 9A8
		float                                                   lastDropAngleMod;                             // 9AC
		PlayerSkills*                                           skills;                                       // 9B0
		ActorHandle                                             autoAimActor;                                 // 9B8
		RefHandle                                               unk9BC;                                       // 9BC
		std::uint64_t                                           unk9C0;                                       // 9C0
		NiPointer<NiAVObject>                                   targeted3D;                                   // 9C8
		CombatGroup*                                            combatGroup;                                  // 9D0
		BSTArray<ActorHandle>                                   actorsToDisplayOnTheHUDArray;                 // 9D8
		std::uint64_t                                           unk9F0;                                       // 9F0
		TESBoundObject*                                         lastOneHandItems[2];                          // 9F8
		std::uint32_t                                           teammateCount;                                // A08
		float                                                   combatTimer;                                  // A0C
		float                                                   yieldTimer;                                   // A10
		float                                                   chaseTimer;                                   // A14
		float                                                   drawSheatheSafetyTimer;                       // A18
		std::uint32_t                                           unkA1C;                                       // A1C
		std::uint8_t                                            unkA20[0xA0];                                 // A20
		std::uint32_t                                           unkAC0;                                       // AC0
		std::uint32_t                                           unkAC4;                                       // AC4
		BGSLocation*                                            currentLocation;                              // AC8
		AITimeStamp                                             cachedVelocityTimeStamp;                      // AD0
		float                                                   telekinesisDistance;                          // AD4
		float                                                   commandTimer;                                 // AD8
		std::uint32_t                                           unkADC;                                       // ADC
		TESImageSpaceModifier*                                  unkAE0;                                       // AE0
		std::int32_t                                            unkAE8;                                       // AE8
		std::uint32_t                                           unkAEC;                                       // AEC
		std::uint32_t                                           unkAF0;                                       // AF0
		stl::enumeration<GrabbingType, std::uint32_t>           grabType;                                     // AF4
		std::int32_t                                            difficulty;                                   // AF8
		std::uint32_t                                           unkAFC;                                       // AFC
		std::int8_t                                             murder;                                       // B00
		std::int8_t                                             perkCount;                                    // B01
		stl::enumeration<ByCharGenFlag, std::uint8_t>           byCharGenFlag;                                // B02
		std::uint8_t                                            padB03;                                       // B03
		std::uint32_t                                           unkB04;                                       // B04
		Crime*                                                  resistArrestCrime;                            // B08
		BSTArray<TintMask*>                                     tintMasks;                                    // B10
		BSTArray<TintMask*>*                                    overlayTintMasks;                             // B28
		BGSTextureSet*                                          complexion;                                   // B30
		TESRace*                                                charGenRace;                                  // B38
		TESRace*                                                race2;                                        // B40
		std::int32_t                                            unkB48;                                       // B48
		std::uint32_t                                           padB4C;                                       // B4C
		BSTArray<std::uint64_t>                                 unkB50;                                       // B50
		std::uint64_t                                           unkB68;                                       // B68
		std::uint64_t                                           unkB70;                                       // B70
		std::uint64_t                                           unkB78;                                       // B78
		std::uint64_t                                           unkB80;                                       // B80
		std::int32_t                                            unkB88;                                       // B88
		std::uint32_t                                           padB8C;                                       // B8C
		std::uint64_t                                           unkB90;                                       // B90
		std::uint64_t                                           unkB98;                                       // B98
		BSTSmallArray<void*, 4>                                 unkBA0;                                       // BA0
		std::uint64_t                                           unkBD0;                                       // BD0
		std::uint8_t                                            unkBD8;                                       // BD8
		stl::enumeration<FlagBD9, std::uint8_t>                 unkBD9;                                       // BD9
		std::uint8_t                                            unkBDA;                                       // BDA
		stl::enumeration<FlagBDB, std::uint8_t>                 unkBDB;                                       // BDB
		stl::enumeration<FlagBDC, std::uint8_t>                 unkBDC;                                       // BDC
		stl::enumeration<FlagBDD, std::uint8_t>                 unkBDD;                                       // BDD
		std::uint16_t                                           padBDE;                                       // BDE

	private:
		bool CenterOnCell_Impl(const char* a_cellName, RE::TESObjectCELL* a_cell);
	};
	static_assert(sizeof(PlayerCharacter) == 0xBE8);
}
