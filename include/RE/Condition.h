#pragma once

#include "RE/FormTypes.h"
#include "RE/TESMemoryManager.h"  // TES_HEAP_REDEFINE_NEW


namespace RE
{
	class Condition
	{
	public:
		enum class OpCode : UInt8
		{
			kEqualTo,				// ==
			kNotEqualTo,			// !=
			kGreaterThan,			// >
			kGreaterThanOrEqualTo,	// >=
			kLessThan,				// <
			kLessThanOrEqualTo,		// <=
		};


		enum class ReferenceType : UInt8
		{
			kSubject = 0,
			kTarget,
			kReference,
			kCombatTarget,
			kLinkedReference,
			kQuestAlias,
			kPackageData,
			kEventData,
			kPlayer
		};


		// Betheseda keeps these in a giant lookup table
		// using func_t = bool(TESObjectREFR* a_perkOwnerOrTarget, void* a_param1, void* a_param2, float& a_result);
		enum class FunctionID : UInt16
		{
			kGetWantBlocking = 0,
			kGetDistance = 1,
			kGetLocked = 5,
			kGetPos = 6,
			kGetAngle = 8,
			kGetStartingPos = 10,
			kGetStartingAngle = 11,
			kGetSecondsPassed = 12,
			kGetActorValue = 14,
			kGetCurrentTime = 18,
			kGetScale = 24,
			kIsMoving = 25,
			kIsTurning = 26,
			kGetLineOfSight = 27,
			kGetInSameCell = 32,
			kGetDisabled = 35,
			kMenuMode = 36,
			kGetDisease = 39,
			kGetClothingValue = 41,
			kSameFaction = 42,
			kSameRace = 43,
			kSameSex = 44,
			kGetDetected = 45,
			kGetDead = 46,
			kGetItemCount = 47,
			kGetGold = 48,
			kGetSleeping = 49,
			kGetTalkedToPC = 50,
			kGetScriptVariable = 53,
			kGetQuestRunning = 56,
			kGetStage = 58,
			kGetStageDone = 59,
			kGetFactionRankDifference = 60,
			kGetAlarmed = 61,
			kIsRaining = 62,
			kGetAttacked = 63,
			kGetIsCreature = 64,
			kGetLockLevel = 65,
			kGetShouldAttack = 66,
			kGetInCell = 67,
			kGetIsClass = 68,
			kGetIsRace = 69,
			kGetIsSex = 70,
			kGetInFaction = 71,
			kGetIsID = 72,
			kGetFactionRank = 73,
			kGetGlobalValue = 74,
			kIsSnowing = 75,
			kGetRandomPercent = 77,
			kGetQuestVariable = 79,
			kGetLevel = 80,
			kIsRotating = 81,
			kGetDeadCount = 84,
			kGetIsAlerted = 91,
			kGetPlayerControlsDisabled = 98,
			kGetHeadingAngle = 99,
			kIsWeaponMagicOut = 101,
			kIsTorchOut = 102,
			kIsShieldOut = 103,
			kIsFacingUp = 106,
			kGetKnockedState = 107,
			kGetWeaponAnimType = 108,
			kIsWeaponSkillType = 109,
			kGetCurrentAIPackage = 110,
			kIsWaiting = 111,
			kIsIdlePlaying = 112,
			kIsIntimidatebyPlayer = 116,
			kIsPlayerInRegion = 117,
			kGetActorAggroRadiusViolated = 118,
			kGetCrime = 122,
			kIsGreetingPlayer = 123,
			kIsGuard = 125,
			kHasBeenEaten = 127,
			kGetStaminaPercentage = 128,
			kGetPCIsClass = 129,
			kGetPCIsRace = 130,
			kGetPCIsSex = 131,
			kGetPCInFaction = 132,
			kSameFactionAsPC = 133,
			kSameRaceAsPC = 134,
			kSameSexAsPC = 135,
			kGetIsReference = 136,
			kIsTalking = 141,
			kGetWalkSpeed = 142,
			kGetCurrentAIProcedure = 143,
			kGetTrespassWarningLevel = 144,
			kIsTrespassing = 145,
			kIsInMyOwnedCell = 146,
			kGetWindSpeed = 147,
			kGetCurrentWeatherPercent = 148,
			kGetIsCurrentWeather = 149,
			kIsContinuingPackagePCNear = 150,
			kGetIsCrimeFaction = 152,
			kCanHaveFlames = 153,
			kHasFlames = 154,
			kGetOpenState = 157,
			kGetSitting = 159,
			kGetIsCurrentPackage = 161,
			kIsCurrentFurnitureRef = 162,
			kIsCurrentFurnitureObj = 163,
			kGetDayOfWeek = 170,
			kGetTalkedToPCParam = 172,
			kIsPCSleeping = 175,
			kIsPCAMurderer = 176,
			kHasSameEditorLocAsRef = 180,
			kHasSameEditorLocAsRefAlias = 181,
			kGetEquipped = 182,
			kIsSwimming = 185,
			kGetAmountSoldStolen = 190,
			kGetIgnoreCrime = 192,
			kGetPCExpelled = 193,
			kGetPCFactionMurder = 195,
			kGetPCEnemyofFaction = 197,
			kGetPCFactionAttack = 199,
			kGetDestroyed = 203,
			kHasMagicEffect = 214,
			kGetDefaultOpen = 215,
			kGetAnimAction = 219,
			kIsSpellTarget = 223,
			kGetVATSMode = 224,
			kGetPersuasionNumber = 225,
			kGetVampireFeed = 226,
			kGetCannibal = 227,
			kGetIsClassDefault = 228,
			kGetClassDefaultMatch = 229,
			kGetInCellParam = 230,
			kGetVatsTargetHeight = 235,
			kGetIsGhost = 237,
			kGetUnconscious = 242,
			kGetRestrained = 244,
			kGetIsUsedItem = 246,
			kGetIsUsedItemType = 247,
			kIsScenePlaying = 248,
			kIsInDialogueWithPlayer = 249,
			kGetLocationCleared = 250,
			kGetIsPlayableRace = 254,
			kGetOffersServicesNow = 255,
			kHasAssociationType = 258,
			kHasFamilyRelationship = 259,
			kHasParentRelationship = 261,
			kIsWarningAbout = 262,
			kIsWeaponOut = 263,
			kHasSpell = 264,
			kIsTimePassing = 265,
			kIsPleasant = 266,
			kIsCloudy = 267,
			kIsSmallBump = 274,
			kGetBaseActorValue = 277,
			kIsOwner = 278,
			kIsCellOwner = 280,
			kIsHorseStolen = 282,
			kIsLeftUp = 285,
			kIsSneaking = 286,
			kIsRunning = 287,
			kGetFriendHit = 288,
			kIsInCombat = 289,
			kIsInInterior = 300,
			kIsWaterObject = 304,
			kGetPlayerAction = 305,
			kIsActorUsingATorch = 306,
			kIsXBox = 309,
			kGetInWorldspace = 310,
			kGetPCMiscStat = 312,
			kGetPairedAnimation = 313,
			kIsActorAVictim = 314,
			kGetTotalPersuasionNumber = 315,
			kGetIdleDoneOnce = 318,
			kGetNoRumors = 320,
			kGetCombatState = 323,
			kGetWithinPackageLocation = 325,
			kIsRidingMount = 327,
			kIsFleeing = 329,
			kIsInDangerousWater = 332,
			kGetIgnoreFriendlyHits = 338,
			kIsPlayersLastRiddenMount = 339,
			kIsActor = 353,
			kIsEssential = 354,
			kIsPlayerMovingIntoNewSpace = 358,
			kGetInCurrentLoc = 359,
			kGetInCurrentLocAlias = 360,
			kGetTimeDead = 361,
			kHasLinkedRef = 362,
			kIsChild = 365,
			kGetStolenItemValueNoCrime = 366,
			kGetLastPlayerAction = 367,
			kIsPlayerActionActive = 368,
			kIsTalkingActivatorActor = 370,
			kIsInList = 372,
			kGetStolenItemValue = 373,
			kGetCrimeGoldViolent = 375,
			kGetCrimeGoldNonviolent = 376,
			kHasShout = 378,
			kGetHasNote = 381,
			kGetHitLocation = 390,
			kIsPC1stPerson = 391,
			kGetCauseofDeath = 396,
			kIsLimbGone = 397,
			kIsWeaponInList = 398,
			kIsBribedbyPlayer = 402,
			kGetRelationshipRank = 403,
			kGetVATSValue = 407,
			kIsKiller = 408,
			kIsKillerObject = 409,
			kGetFactionCombatReaction = 410,
			kExists = 414,
			kGetGroupMemberCount = 415,
			kGetGroupTargetCount = 416,
			kGetIsVoiceType = 426,
			kGetPlantedExplosive = 427,
			kIsScenePackageRunning = 429,
			kGetHealthPercentage = 430,
			kGetIsObjectType = 432,
			kGetDialogueEmotion = 434,
			kGetDialogueEmotionValue = 435,
			kGetIsCreatureType = 437,
			kGetInCurrentLocFormList = 444,
			kGetInZone = 445,
			kGetVelocity = 446,
			kGetGraphVariableFloat = 447,
			kHasPerk = 448,
			kGetFactionRelation = 449,
			kIsLastIdlePlayed = 450,
			kGetPlayerTeammate = 453,
			kGetPlayerTeammateCount = 454,
			kGetActorCrimePlayerEnemy = 458,
			kGetCrimeGold = 459,
			kIsPlayerGrabbedRef = 463,
			kGetKeywordItemCount = 465,
			kGetDestructionStage = 470,
			kGetIsAlignment = 473,
			kIsProtected = 476,
			kGetThreatRatio = 477,
			kGetIsUsedItemEquipType = 479,
			kIsCarryable = 487,
			kGetConcussed = 488,
			kGetMapMarkerVisible = 491,
			kPlayerKnows = 493,
			kGetPermanentActorValue = 494,
			kGetKillingBlowLimb = 495,
			kCanPayCrimeGold = 497,
			kGetDaysInJail = 499,
			kEPAlchemyGetMakingPoison = 500,
			kEPAlchemyEffectHasKeyword = 501,
			kGetAllowWorldInteractions = 503,
			kGetLastHitCritical = 508,
			kIsCombatTarget = 513,
			kGetVATSRightAreaFree = 515,
			kGetVATSLeftAreaFree = 516,
			kGetVATSBackAreaFree = 517,
			kGetVATSFrontAreaFree = 518,
			kGetLockIsBroken = 519,
			kIsPS3 = 520,
			kIsWin32 = 521,
			kGetVATSRightTargetVisible = 522,
			kGetVATSLeftTargetVisible = 523,
			kGetVATSBackTargetVisible = 524,
			kGetVATSFrontTargetVisible = 525,
			kIsInCriticalStage = 528,
			kGetXPForNextLevel = 530,
			kGetInfamy = 533,
			kGetInfamyViolent = 534,
			kGetInfamyNonViolent = 535,
			kGetQuestCompleted = 543,
			kIsGoreDisabled = 547,
			kIsSceneActionComplete = 550,
			kGetSpellUsageNum = 552,
			kGetActorsInHigh = 554,
			kHasLoaded3D = 555,
			kHasKeyword = 560,
			kHasRefType = 561,
			kLocationHasKeyword = 562,
			kLocationHasRefType = 563,
			kGetIsEditorLocation = 565,
			kGetIsAliasRef = 566,
			kGetIsEditorLocAlias = 567,
			kIsSprinting = 568,
			kIsBlocking = 569,
			kHasEquippedSpell = 570,
			kGetCurrentCastingType = 571,
			kGetCurrentDeliveryType = 572,
			kGetAttackState = 574,
			kGetEventData = 576,
			kIsCloserToAThanB = 577,
			kGetEquippedShout = 579,
			kIsBleedingOut = 580,
			kGetRelativeAngle = 584,
			kGetMovementDirection = 589,
			kIsInScene = 590,
			kGetRefTypeDeadCount = 591,
			kGetRefTypeAliveCount = 592,
			kGetIsFlying = 594,
			kIsCurrentSpell = 595,
			kSpellHasKeyword = 596,
			kGetEquippedItemType = 597,
			kGetLocationAliasCleared = 598,
			kGetLocAliasRefTypeDeadCount = 600,
			kGetLocAliasRefTypeAliveCount = 601,
			kIsWardState = 602,
			kIsInSameCurrentLocAsRef = 603,
			kIsInSameCurrentLocAsRefAlias = 604,
			kLocAliasIsLocation = 605,
			kGetKeywordDataForLocation = 606,
			kGetKeywordDataForAlias = 608,
			kLocAliasHasKeyword = 610,
			kIsNullPackageData = 611,
			kGetNumericPackageData = 612,
			kIsFurnitureAnimType = 613,
			kIsFurnitureEntryType = 614,
			kGetHighestRelationshipRank = 615,
			kGetLowestRelationshipRank = 616,
			kHasAssociationTypeAny = 617,
			kHasFamilyRelationshipAny = 618,
			kGetPathingTargetOffset = 619,
			kGetPathingTargetAngleOffset = 620,
			kGetPathingTargetSpeed = 621,
			kGetPathingTargetSpeedAngle = 622,
			kGetMovementSpeed = 623,
			kGetInContainer = 624,
			kIsLocationLoaded = 625,
			kIsLocAliasLoaded = 626,
			kIsDualCasting = 627,
			kGetVMQuestVariable = 629,
			kGetVMScriptVariable = 630,
			kIsEnteringInteractionQuick = 631,
			kIsCasting = 632,
			kGetFlyingState = 633,
			kIsInFavorState = 635,
			kHasTwoHandedWeaponEquipped = 636,
			kIsExitingInstant = 637,
			kIsInFriendStateWithPlayer = 638,
			kGetWithinDistance = 639,
			kGetActorValuePercent = 640,
			kIsUnique = 641,
			kGetLastBumpDirection = 642,
			kIsInFurnitureState = 644,
			kGetIsInjured = 645,
			kGetIsCrashLandRequest = 646,
			kGetIsHastyLandRequest = 647,
			kIsLinkedTo = 650,
			kGetKeywordDataForCurrentLocation = 651,
			kGetInSharedCrimeFaction = 652,
			kGetBribeSuccess = 654,
			kGetIntimidateSuccess = 655,
			kGetArrestedState = 656,
			kGetArrestingActor = 657,
			kEPTemperingItemIsEnchanted = 659,
			kEPTemperingItemHasKeyword = 660,
			kGetReplacedItemType = 664,
			kIsAttacking = 672,
			kIsPowerAttacking = 673,
			kIsLastHostileActor = 674,
			kGetGraphVariableInt = 675,
			kGetCurrentShoutVariation = 676,
			kShouldAttackKill = 678,
			kGetActivatorHeight = 680,
			kEPMagic_IsAdvanceSkill = 681,
			kWornHasKeyword = 682,
			kGetPathingCurrentSpeed = 683,
			kGetPathingCurrentSpeedAngle = 684,
			kEPModSkillUsage_AdvanceObjectHasKeyword = 691,
			kEPModSkillUsage_IsAdvanceAction = 692,
			kEPMagic_SpellHasKeyword = 693,
			kGetNoBleedoutRecovery = 694,
			kEPMagic_SpellHasSkill = 696,
			kIsAttackType = 697,
			kIsAllowedToFly = 698,
			kHasMagicEffectKeyword = 699,
			kIsCommandedActor = 700,
			kIsStaggered = 701,
			kIsRecoiling = 702,
			kIsExitingInteractionQuick = 703,
			kIsPathing = 704,
			kGetShouldHelp = 705,
			kHasBoundWeaponEquipped = 706,
			kGetCombatTargetHasKeyword = 707,
			kGetCombatGroupMemberCount = 709,
			kIsIgnoringCombat = 710,
			kGetLightLevel = 711,
			kSpellHasCastingPerk = 713,
			kIsBeingRidden = 714,
			kIsUndead = 715,
			kGetRealHoursPassed = 716,
			kIsUnlockedDoor = 718,
			kIsHostileToActor = 719,
			kGetTargetHeight = 720,
			kIsPoison = 721,
			kWornApparelHasKeywordCount = 722,
			kGetItemHealthPercent = 723,
			kEffectWasDualCast = 724,
			kGetKnockedStateEnum = 725,
			kDoesNotExist = 726,
			kIsOnFlyingMount = 730,
			kCanFlyHere = 731,
			kIsFlyingMountPatrolQueud = 732,
			kIsFlyingMountFastTravelling = 733,
			kIsOverEncumbered = 734,
			kGetActorWarmth = 735,

			// SKSE
			kGetSKSEVersion = 1024,
			kGetSKSEVersionMinor = 1025,
			kGetSKSEVersionBeta = 1026,
			kGetSKSERelease = 1027,
			kClearInvalidRegistrations = 1028
		};


		struct Solution
		{
			constexpr Solution(TESObjectREFR* a_perkOwner, TESObjectREFR* a_target) :
				perkOwner(a_perkOwner),
				target(a_target),
				unk10(0),
				unk18(0),
				unk20(0),
				unk28(0)
			{}


			TESObjectREFR*	perkOwner;	// 00
			TESObjectREFR*	target;		// 08
			void*			unk10;		// 10
			void*			unk18;		// 18
			void*			unk20;		// 20
			void*			unk28;		// 28
		};
		STATIC_ASSERT(sizeof(Solution) == 0x30);


		struct ComparisonFlags
		{
			ComparisonFlags();
			~ComparisonFlags() = default;


			bool	isOR : 1;			// 0 - false == AND, true == OR
			bool	usesAliases : 1;	// 1
			bool	global : 1;			// 2
			bool	usePackData : 1;	// 3
			bool	swapTarget : 1;		// 4
			OpCode	opCode : 3;			// 5
		};
		STATIC_ASSERT(sizeof(ComparisonFlags) == 0x1);


		struct Node	// CTDA
		{
			Node();
			~Node() = default;

			TES_HEAP_REDEFINE_NEW();

			bool Run(Solution& a_solution);


			// members
			Node*			next;				// 00
			float			comparisonValue;	// 08
			UInt32			unk0C;				// 0C
			RefHandle		handle;				// 10 - kReference
			SInt32			unk14;				// 14
			FunctionID		functionID;			// 18
			UInt8			unk1A;				// 1A
			UInt8			unk1B;				// 1B
			UInt32			pad1C;				// 1C
			void*			param1;				// 20
			void*			param2;				// 28
			ComparisonFlags	comparisonFlags;	// 30
			ReferenceType	referenceType;		// 31
			UInt16			pad32;				// 32
			UInt32			pad34;				// 34
		};
		STATIC_ASSERT(sizeof(Node) == 0x38);


		Condition();
		~Condition();

		TES_HEAP_REDEFINE_NEW();

		explicit operator bool() const;
		bool Run(TESObjectREFR* a_perkOwner, TESObjectREFR* a_target);	// Perk fragments will short circuit


		// members
		Node* head;	// 0
	};
	STATIC_ASSERT(sizeof(Condition) == 0x8);
}
