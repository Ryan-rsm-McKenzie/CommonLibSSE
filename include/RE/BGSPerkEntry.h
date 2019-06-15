#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSPerkEntry

#include "RE/FormTypes.h"  // BGSPerk


namespace RE
{
	class BGSEntryPointFunctionData;
	class TESFile;


	class BGSPerkEntry
	{
	public:
		inline static const void* RTTI = RTTI_BGSPerkEntry;


		enum class EntryPoint : UInt8
		{
			kCalculateWeaponDamage = 0,
			kCalculateMyCriticalHitChance = 1,
			kCalculateMyCriticalHitDamage = 2,
			kCalculateMineExplodeChance = 3,
			kAdjustLimbDamage = 4,
			kAdjustBookSkillPoints = 5,
			kModRecoveredHealth = 6,
			kGetShouldAttack = 7,
			kModBuyPrices = 8,
			kAddLeveledListOnDeath = 9,
			kGetMaxCarryWeight = 10,
			kModAddictionChance = 11,
			kModAddictionDuration = 12,
			kModPositiveChemDuration = 13,
			kActivate = 14,
			kIgnoreRunningDuringDetection = 15,
			kIgnoreBrokenLock = 16,
			kModEnemyCriticalHitChance = 17,
			kModSneakAttackMult = 18,
			kModMaxPlaceableMines = 19,
			kModBowZoom = 20,
			kModRecoverArrowChance = 21,
			kModSkillUse = 22,
			kModTelekinesisDistance = 23,
			kModTelekinesisDamageMult = 24,
			kModTelekinesisDamage = 25,
			kModBashingDamage = 26,
			kModPowerAttackStamina = 27,
			kModPowerAttackDamage = 28,
			kModSpellMagnitude = 29,
			kModSpellDuration = 30,
			kModSecondaryValueWeight = 31,
			kModArmorWeight = 32,
			kModIncomingStagger = 33,
			kModTargetStagger = 34,
			kModAttackDamage = 35,
			kModIncomingDamage = 36,
			kModTargetDamageResistance = 37,
			kModSpellCost = 38,
			kModPercentBlocked = 39,
			kModShieldDeflectArrowChance = 40,
			kModIncomingSpellMagnitude = 41,
			kModIncomingSpellDuration = 42,
			kModPlayerIntimidation = 43,
			kModPlayerReputation = 44,
			kModFavorPoints = 45,
			kModBribeAmount = 46,
			kModDetectionLight = 47,
			kModDetectionMovement = 48,
			kModSoulGemRecharge = 49,
			kSetSweepAttack = 50,
			kApplyCombatHitSpell = 51,
			kApplyBashingSpell = 52,
			kApplyReanimateSpell = 53,
			kSetBooleanGraphVariable = 54,
			kModSpellCastingSoundEvent = 55,
			kModPickpocketChance = 56,
			kModDetectionSneakSkill = 57,
			kModFallingDamage = 58,
			kModLockpickSweetSpot = 59,
			kModSellPrices = 60,
			kCanPickpocketEquippedItem = 61,
			kModLockpickLevelAllowed = 62,
			kSetLockpickStartingArc = 63,
			kSetProgressionPicking = 64,
			kMakeLockpicksUnbreakable = 65,
			kModAlchemyEffectiveness = 66,
			kApplyWeaponSwingSpell = 67,
			kModCommandedActorLimit = 68,
			kApplySneakingSpell = 69,
			kModPlayerMagicSlowdown = 70,
			kModWardMagickaAbsorptionPct = 71,
			kModInitialIngredientEffectsLearned = 72,
			kPurifyAlchemyIngredients = 73,
			kFilterActivation = 74,
			kCanDualCastSpell = 75,
			kModTemperingHealth = 76,
			kModEnchantmentPower = 77,
			kModSoulPctCapturedToWeapon = 78,
			kModSoulGemEnchanting = 79,
			kModNumberAppliedEnchantmentsAllowed = 80,
			kSetActivateLabel = 81,
			kModShoutOK = 82,
			kModPoisonDoseCount = 83,
			kShouldApplyPlacedItem = 84,
			kModArmorRating = 85,
			kModLockpickingCrimeChance = 86,
			kModIngredientsHarvested = 87,
			kModSpellRange_TargetLoc = 88,
			kModPotionsCreated = 89,
			kModLockpickingKeyRewardChance = 90,
			kAllowMountActor = 91,

			kTotal
		};


		enum class Type
		{
			kQuestStage = 0,
			kAbility = 1,
			kEntryPoint = 2
		};


		struct Header	// PRKE
		{
			UInt8	rank;		// 0
			UInt8	priority;	// 1
			UInt16	unk2;		// 2
			UInt32	unk4;		// 4
		};
		STATIC_ASSERT(sizeof(Header) == 0x8);


		virtual bool						EvaluateConditions(UInt32 a_numArgs, void* a_args);	// 00 - { return false; }
		virtual EntryPoint					GetEntryPoint() const;								// 01 - { return 0; }
		virtual BGSEntryPointFunctionData*	GetFunctionData() const;							// 02 - { return 0; }

		virtual ~BGSPerkEntry();																// 03

		virtual Type						GetType() const = 0;								// 04
		virtual void						ReleaseRefs();										// 05 - { return; }
		virtual void						ResolveForms(TESFile* a_mod);						// 06 - { return; }
		virtual bool						LoadPerk(TESFile* a_mod);							// 07 - { return true; }
		virtual void						SetPerk(BGSPerk* a_perk);							// 08 - { return; }
		virtual void						Unk_09(void);										// 09 - { return 0xFFFF; }
		virtual void						Unk_0A(void) = 0;									// 0A
		virtual void						Unk_0B(void) = 0;									// 0B

		UInt8								GetRank() const;
		UInt8								GetPriority() const;


		// members
		Header header;	// 08 - PRKE
	};
	STATIC_ASSERT(sizeof(BGSPerkEntry) == 0x10);
}
