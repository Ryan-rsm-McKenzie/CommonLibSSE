#pragma once

#include "RE/B/BSTSingleton.h"
#include "RE/F/FormTypes.h"
#include "RE/T/TESForm.h"

namespace RE
{
	struct DEFAULT_OBJECTS
	{
		enum DEFAULT_OBJECT
		{
			kWerewolfSpell = 0,
			kSittingAngleLimit = 1,
			kAllowPlayerShout = 2,
			kGold = 3,
			kLockpick = 4,
			kSkeletonKey = 5,
			kPlayerFaction = 6,
			kGuardFaction = 7,
			kDefaultMusic = 8,
			kBattleMusic = 9,
			kDeathMusic = 10,
			kSuccessMusic = 11,
			kLevelUpMusic = 12,
			kDungeonClearedMusic = 13,
			kPlayerVoiceMale = 14,
			kPlayerVoiceMaleChild = 15,
			kPlayerVoiceFemale = 16,
			kPlayerVoiceFemaleChild = 17,
			kEatPackageDefaultFood = 18,
			kLeftHandEquip = 19,
			kRightHandEquip = 20,
			kEitherHandEquip = 21,
			kVoiceEquip = 22,
			kPotionEquip = 23,
			kEveryActorAbility = 24,
			kCommandedActorAbility = 25,
			kDrugWearsOffImageSpace = 26,
			kFootstepSet = 27,
			kLandscapeMaterial = 28,
			kDragonLandZoneMarker = 29,
			kDragonCrashZoneMarker = 30,
			kCombatStyle = 31,
			kDefaultPackList = 32,
			kWaitForDialoguePackage = 33,
			kLocRefTypeBoss = 34,
			kVirtualLocation = 35,
			kPersistAllLocation = 36,
			kInventoryPlayer = 37,
			kPathingTestNPC = 38,
			kFavorCostSmall = 39,
			kFavorCostMedium = 40,
			kFavorCostLarge = 41,
			kFavorGiftsPerDay = 42,
			kActionSwimStateChange = 43,
			kActionLook = 44,
			kActionLeftAttack = 45,
			kActionLeftReady = 46,
			kActionLeftRelease = 47,
			kActionLeftInterrupt = 48,
			kActionRightAttack = 49,
			kActionRightReady = 50,
			kActionRightRelease = 51,
			kActionRightInterrupt = 52,
			kActionDualAttack = 53,
			kActionDualRelease = 54,
			kActionActivate = 55,
			kActionJump = 56,
			kActionFall = 57,
			kActionLand = 58,
			kActionSneak = 59,
			kActionVoice = 60,
			kActionVoiceReady = 61,
			kActionVoiceRelease = 62,
			kActionVoiceInterrupt = 63,
			kActionIdle = 64,
			kActionSprintStart = 65,
			kActionSprintStop = 66,
			kActionDraw = 67,
			kActionSheath = 68,
			kActionLeftPowerAttack = 69,
			kActionRightPowerAttack = 70,
			kActionDualPowerAttack = 71,
			kActionStaggerStart = 72,
			kActionBlockHit = 73,
			kActionBlockAnticipate = 74,
			kActionRecoil = 75,
			kActionLargeRecoil = 76,
			kActionBleedoutStart = 77,
			kActionBleedoutStop = 78,
			kActionIdleStop = 79,
			kActionWardHit = 80,
			kActionForceEquip = 81,
			kActionShieldChange = 82,
			kActionPathStart = 83,
			kActionPathEnd = 84,
			kActionLargeMovementDelta = 85,
			kActionFlyStart = 86,
			kActionFlyStop = 87,
			kActionHoverStart = 88,
			kActionHoverStop = 89,
			kActionBumpedInto = 90,
			kActionSummonedStart = 91,
			kActionTalkingIdle = 92,
			kActionListenIdle = 93,
			kActionDeath = 94,
			kActionDeathWait = 95,
			kActionIdleWarn = 96,
			kActionMoveStart = 97,
			kActionMoveStop = 98,
			kActionTurnRight = 99,
			kActionTurnLeft = 100,
			kActionTurnStop = 101,
			kActionMoveForward = 102,
			kActionMoveBackward = 103,
			kActionMoveLeft = 104,
			kActionMoveRight = 105,
			kActionResetAnimationGraph = 106,
			kActionKnockdown = 107,
			kActionGetUp = 108,
			kActionIdleStopInstant = 109,
			kActionRagdollInstant = 110,
			kActionWaterwalkStart = 111,
			kActionReload = 112,
			kPickupSoundGeneric = 113,
			kPutdownSoundGeneric = 114,
			kPickupSoundWeapon = 115,
			kPutdownSoundWeapon = 116,
			kPickupSoundArmor = 117,
			kPutdownSoundArmor = 118,
			kPickupSoundBook = 119,
			kPutdownSoundBook = 120,
			kPickupSoundIngredient = 121,
			kPutdownSoundIngredient = 122,
			kHarvestSound = 123,
			kHarvestFailedSound = 124,
			kWardBreakSound = 125,
			kWardAbsorbSound = 126,
			kWardDeflectSound = 127,
			kMagicFailSound = 128,
			kShoutFailSound = 129,
			kHeartbeatSoundFast = 130,
			kHeartbeatSoundSlow = 131,
			kImagespaceLowHealth = 132,
			kSoulCapturedSound = 133,
			kNoActivationSound = 134,
			kMapMenuLoopingSound = 135,
			kDialogueVoiceCategory = 136,
			kNonDialogueVoiceCategory = 137,
			kSFXToFadeInDialogueCategory = 138,
			kPauseDuringMenuCategoryFade = 139,
			kPauseDuringMenuCategoryImmediate = 140,
			kPauseDuringLoadingMenuCategory = 141,
			kMusicSoundCategory = 142,
			kStatsMuteCategory = 143,
			kStatsMusic = 144,
			kMasterSoundCategory = 145,
			kTimeSensitiveSoundCategory = 146,
			kDialogueOutputModel3D = 147,
			kDialogueOutputModel2D = 148,
			kPlayersOutputModel1stPerson = 149,
			kPlayersOutputModel3rdPerson = 150,
			kInterfaceOutputModel = 151,
			kReverbType = 152,
			kUnderwaterLoopSound = 153,
			kUnderwaterReverbType = 154,
			kKeywordHorse = 155,
			kKeywordUndead = 156,
			kKeywordNPC = 157,
			kKeywordBeastRace = 158,
			kKeywordDummyObject = 159,
			kKeywordUseGeometryEmitter = 160,
			kKeywordMustStop = 161,
			kKeywordUpdateDuringArchery = 162,
			kKeywordSkipOutfitItems = 163,
			kMaleFaceTextureSetHead = 164,
			kMaleFaceTextureSetMouth = 165,
			kMaleFaceTextureSetEyes = 166,
			kFemaleFaceTextureSetHead = 167,
			kFemaleFaceTextureSetMouth = 168,
			kFemaleFaceTextureSetEyes = 169,
			kImageSpaceModifierforinventorymenu = 170,
			kPackagetemplate = 171,
			kMainMenuCell = 172,
			kDefaultMovementTypeWalk = 173,
			kDefaultMovementTypeRun = 174,
			kDefaultMovementTypeSwim = 175,
			kDefaultMovementTypeFly = 176,
			kDefaultMovementTypeSneak = 177,
			kDefaultMovementTypeSprint = 178,
			kKeywordSpecialFurniture = 179,
			kKeywordFurnitureForces1stPerson = 180,
			kKeywordFurnitureForces3rdPerson = 181,
			kKeywordActivatorFurnitureNoPlayer = 182,
			kTelekinesisGrabSound = 183,
			kTelekinesisThrowSound = 184,
			kWorldMapWeather = 185,
			kHelpManualPC = 186,
			kHelpManualXBox = 187,
			kKeywordTypeAmmo = 188,
			kKeywordTypeArmor = 189,
			kKeywordTypeBook = 190,
			kKeywordTypeIngredient = 191,
			kKeywordTypeKey = 192,
			kKeywordTypeMisc = 193,
			kKeywordTypeSoulGem = 194,
			kKeywordTypeWeapon = 195,
			kKeywordTypePotion = 196,
			kBaseWeaponEnchantment = 197,
			kBaseArmorEnchantment = 198,
			kBasePotion = 199,
			kBasePoison = 200,
			kKeywordDragon = 201,
			kKeywordMovable = 202,
			kArtObjectAbsorbEffect = 203,
			kWeaponMaterialList = 204,
			kArmorMaterialList = 205,
			kKeywordDisallowEnchanting = 206,
			kFavortravelmarkerlocation = 207,
			kKeywordHoldLocation = 208,
			kKeywordCivilWarOwner = 209,
			kKeywordCivilWarNeutral = 210,
			kLocRefTypeCivilWarSoldier = 211,
			kKeywordClearableLocation = 212,
			kLocRefTypeResourceDestructible = 213,
			kFormListHairColorList = 214,
			kComplexSceneObject = 215,
			kKeywordReusableSoulGem = 216,
			kKeywordAnimal = 217,
			kKeywordDaedra = 218,
			kKeywordRobot = 219,
			kKeywordNirnroot = 220,
			kFightersGuildFaction = 221,
			kMagesGuildFaction = 222,
			kThievesGuildFaction = 223,
			kDarkBrotherhoodFaction = 224,
			kJarlFaction = 225,
			kBunnyFaction = 226,
			kPlayerIsVampireVariable = 227,
			kPlayerIsWerewolfVariable = 228,
			kRoadMarker = 229,
			kKeywordScaleActorTo10 = 230,
			kKeywordVampire = 231,
			kKeywordForge = 232,
			kKeywordCookingPot = 233,
			kKeywordSmelter = 234,
			kKeywordTanningRack = 235,
			kHelpBasicLockpickingPC = 236,
			kHelpBasicLockpickingConsole = 237,
			kHelpBasicForging = 238,
			kHelpBasicCooking = 239,
			kHelpBasicSmelting = 240,
			kHelpBasicTanning = 241,
			kHelpBasicObjectCreation = 242,
			kHelpBasicEnchanting = 243,
			kHelpBasicSmithingWeapon = 244,
			kHelpBasicSmithingArmor = 245,
			kHelpBasicAlchemy = 246,
			kHelpBarter = 247,
			kHelpLevelingup = 248,
			kHelpSkillsMenu = 249,
			kHelpMapMenu = 250,
			kHelpJournal = 251,
			kHelpLowHealth = 252,
			kHelpLowMagicka = 253,
			kHelpLowStamina = 254,
			kHelpJail = 255,
			kHelpTeamateFavor = 256,
			kHelpWeaponCharge = 257,
			kHelpFavorites = 258,
			kKinectHelpFormList = 259,
			kHelpFlyingMount = 260,
			kHelpTargetLock = 261,
			kHelpAttackTarget = 262,
			kImagespaceLoadscreen = 263,
			kKeywordWeaponMaterialDaedric = 264,
			kKeywordWeaponMaterialDraugr = 265,
			kKeywordWeaponMaterialDraugrHoned = 266,
			kKeywordWeaponMaterialDwarven = 267,
			kKeywordWeaponMaterialEbony = 268,
			kKeywordWeaponMaterialElven = 269,
			kKeywordWeaponMaterialFalmer = 270,
			kKeywordWeaponMaterialFalmerHoned = 271,
			kKeywordWeaponMaterialGlass = 272,
			kKeywordWeaponMaterialImperial = 273,
			kKeywordWeaponMaterialIron = 274,
			kKeywordWeaponMaterialOrcish = 275,
			kKeywordWeaponMaterialSteel = 276,
			kKeywordWeaponMaterialWood = 277,
			kKeywordWeaponTypeBoundArrow = 278,
			kKeywordArmorMaterialDaedric = 279,
			kKeywordArmorMaterialDragonplate = 280,
			kKeywordArmorMaterialDragonscale = 281,
			kKeywordArmorMaterialDragonbone = 282,
			kKeywordArmorMaterialDwarven = 283,
			kKeywordArmorMaterialEbony = 284,
			kKeywordArmorMaterialElven = 285,
			kKeywordArmorMaterialElvenSplinted = 286,
			kKeywordArmorMaterialFullLeather = 287,
			kKeywordArmorMaterialGlass = 288,
			kKeywordArmorMaterialHide = 289,
			kKeywordArmorMaterialImperial = 290,
			kKeywordArmorMaterialImperialHeavy = 291,
			kKeywordArmorMaterialImperialReinforced = 292,
			kKeywordArmorMaterialIron = 293,
			kKeywordArmorMaterialIronBanded = 294,
			kKeywordArmorMaterialOrcish = 295,
			kKeywordArmorMaterialScaled = 296,
			kKeywordArmorMaterialSteel = 297,
			kKeywordArmorMaterialSteelPlate = 298,
			kKeywordArmorMaterialStormcloak = 299,
			kKeywordArmorMaterialStudded = 300,
			kKeywordGenericCraftableKeyword01 = 301,
			kKeywordGenericCraftableKeyword02 = 302,
			kKeywordGenericCraftableKeyword03 = 303,
			kKeywordGenericCraftableKeyword04 = 304,
			kKeywordGenericCraftableKeyword05 = 305,
			kKeywordGenericCraftableKeyword06 = 306,
			kKeywordGenericCraftableKeyword07 = 307,
			kKeywordGenericCraftableKeyword08 = 308,
			kKeywordGenericCraftableKeyword09 = 309,
			kKeywordGenericCraftableKeyword10 = 310,
			kKeywordJewelry = 311,
			kKeywordCuirass = 312,
			kLocalMapHidePlane = 313,
			kSnowLODMaterial = 314,
			kSnowLODMaterialHD = 315,
			kAshLODMaterial = 316,
			kAshLODMaterialHD = 317,
			kDialogueFollowerQuest = 318,
			kPotentialFollowerFaction = 319,
			kWerewolfAvailablePerks = 320,
			kVampireAvailablePerks = 321,
			kSurvivalModeToggle = 322,
			kSurvivalModeEnabled = 323,
			kSurvivalModeShowOption = 324,
			kSurvivalTemperature = 325,
			kSurvivalColdPenalty = 326,
			kSurvivalHungerPenalty = 327,
			kSurvivalSleepPenalty = 328,
			kSurvivalKeywordCold = 329,
			kSurvivalKeywordWarm = 330,
			kSurvivalKeywordArmorHands = 331,
			kSurvivalKeywordClothingHands = 332,
			kSurvivalKeywordArmorFeet = 333,
			kSurvivalKeywordClothingFeet = 334,
			kSurvivalKeywordArmorBody = 335,
			kSurvivalKeywordClothingBody = 336,
			kSurvivalKeywordArmorHead = 337,
			kSurvivalKeywordClothingHead = 338,
			kWerewolfRace = 339,
			kVampireRace = 340,
			kVampireSpells = 341,
			kDragonMountNoLandList = 342,
			kPlayerCanMountDragonHereList = 343,
			kFlyingMountAllowedSpells = 344,
			kFlyingMountDisallowedSpells = 345,
			kKeywordMount = 346,
			kVerletCape = 347,
			kFurnitureTestNPC = 348,
			kKeywordConditionalExplosion = 349,
			kVampireFeedNoCrimeFaction = 350,
			kSkyrimWorldspace = 351,
			kKeywordArmorMaterialLightBonemold = 352,
			kKeywordArmorMaterialLightChitin = 353,
			kKeywordArmorMaterialLightNordic = 354,
			kKeywordArmorMaterialLightStalhrim = 355,
			kFlyingMountFlyFastWorldspaces = 356,
			kKeywordArmorMaterialHeavyBonemold = 357,
			kKeywordArmorMaterialHeavyChitin = 358,
			kKeywordArmorMaterialHeavyNordic = 359,
			kKeywordArmorMaterialHeavyStalhrim = 360,
			kKeywordWeaponMaterialNordic = 361,
			kKeywordWeaponMaterialStalhrim = 362,
			kModsHelpFormList = 363,

			kTotal = 364
		};
	};
	using DEFAULT_OBJECT = DEFAULT_OBJECTS::DEFAULT_OBJECT;

	enum class DEFAULT_OBJECT_TYPE
	{
		kMisc = 0,
		kFaceGen = 1,
		kMovement = 2,
		kActions = 3,
		kItems = 4,
		kSounds = 5,
		kKeywords = 6
	};

	struct DEFAULT_OBJECT_DATA
	{
	public:
		// members
		const char*											 name;		   // 00
		stl::enumeration<FormType, std::uint8_t>			 type;		   // 08
		std::uint8_t										 pad09;		   // 09
		std::uint16_t										 pad0A;		   // 0A
		char												 uniqueID[4];  // 0C
		stl::enumeration<DEFAULT_OBJECT_TYPE, std::uint32_t> doType;	   // 10
		std::uint32_t										 pad14;		   // 14
	};
	static_assert(sizeof(DEFAULT_OBJECT_DATA) == 0x18);

	class BGSDefaultObjectManager :
		public TESForm,										  // 000
		public BSTSingletonImplicit<BGSDefaultObjectManager>  // 020
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSDefaultObjectManager;

		using DefaultObject = DEFAULT_OBJECT;
		inline static constexpr auto FORMTYPE = FormType::DefaultObject;

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
			};
		};

		virtual ~BGSDefaultObjectManager();	 // 00

		// override (TESForm)
		virtual bool Load(TESFile* a_mod) override;	 // 06
		virtual void InitItemImpl() override;		 // 13

		[[nodiscard]] static BGSDefaultObjectManager* GetSingleton()
		{
			using func_t = decltype(&BGSDefaultObjectManager::GetSingleton);
			REL::Relocation<func_t> func{ REL::ID(10878) };
			return func();
		}

		[[nodiscard]] TESForm* GetObject(DefaultObject a_object) const noexcept { return GetObject(to_underlying(a_object)); }

		template <class T>
		[[nodiscard]] T* GetObject(DefaultObject a_object) const noexcept
		{
			return GetObject<T>(to_underlying(a_object));
		}

		[[nodiscard]] TESForm* GetObject(std::size_t a_idx) const noexcept
		{
			assert(a_idx < to_underlying(DefaultObject::kTotal));
			return objectInit[a_idx] ? objects[a_idx] : nullptr;
		}

		template <class T>
		[[nodiscard]] T* GetObject(std::size_t a_idx) const noexcept
		{
			const auto obj = GetObject(a_idx);
			return obj ? obj->As<T>() : nullptr;
		}

		// members
		TESForm*	  objects[DEFAULT_OBJECTS::kTotal];		// 020 - DNAM
		bool		  objectInit[DEFAULT_OBJECTS::kTotal];	// B80
		std::uint32_t padCEC;								// CEC
	};
	static_assert(sizeof(BGSDefaultObjectManager) == 0xCF0);
}
