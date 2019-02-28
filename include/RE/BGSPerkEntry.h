#pragma once

#include "RE/FormTypes.h"  // BGSPerk


namespace RE
{
	class BGSEntryPointFunctionData;
	class TESFile;


	class BGSPerkEntry
	{
	public:
		enum class EntryPointType : UInt8
		{
			kCalculateWeaponDamage,
			kCalculateMyCriticalHitChance,
			kCalculateMyCriticalHitDamage,
			kCalculateMineExplodeChance,
			kAdjustLimbDamage,
			kAdjustBookSkillPoints,
			kModifyRecoveredHealth,
			kGetShouldAttack,
			kModifyBuyPrices,
			kAddLeveledListOnDeath,
			kGetMaxCarryWeight,
			kModifyAddictionChance,
			kModifyAddictionDuration,
			kModifyPositiveChemDuration,
			kActivate,
			kIgnoreRunningDuringDetection,
			kIgnoreBrokenLock,
			kModifyEnemyCriticalHitChance,
			kModifySneakAttackMult,
			kModifyMaxPlaceableMines,
			kModifyBowZoom,
			kModifyRecoverArrowChance,
			kModifySkillUse,
			kModifyTelekinesisDistance,
			kModifyTelekinesisDamageMult,
			kModifyTelekinesisDamage,
			kModBashingDamage,
			kModPowerAttackStamina,
			kModPowerAttackDamage,
			kModSpellMagnitude,
			kModSpellDuration,
			kModSecondaryValueWeight,
			kModArmorWeight,
			kModIncomingStagger,
			kModTargetStagger,
			kModAttackDamage,
			kModIncomingDamage,
			kModTargetDamageResistance,
			kModSpellCost,
			kModPercentBlocked,
			kModShieldDeflectArrowChance,
			kModIncomingSpellMagnitude,
			kModIncomingSpellDuration,
			kModPlayerIntimidation,
			kModPlayerReputation,
			kModFavorPoints,
			kModBribeAmount,
			kModDetectionLight,
			kModDetectionMovement,
			kModSoulGemRecharge,
			kSetSweepAttack,
			kApplyCombatHitSpell,
			kApplyBashingSpell,
			kApplyReanimateSpell,
			kSetBooleanGraphVariable,
			kModSpellCastingSoundEvent,
			kModifyPickpocketChance,
			kModifyDetectionSneakSkill,
			kModifyFallingDamage,
			kModifyLockpickSweetSpot,
			kModifySellPrices,
			kCanPickpocketEquippedItem,
			kModifyLockpicklevelAllowed,
			kSetLockpickStartingArc,
			kSetProgressionPicking,
			kMakeLockpicksUnbreakable,
			kModifyAlchemyEffectiveness,
			kApplyWeaponSwingSpell,
			kModifyCommandedActorLimit,
			kApplySneakingSpell,
			kModifyPlayerMagicSlowdown,
			kModifyWardMagickaAbsorptionPct,
			kModifyInitialIngredientEffectsLearned,
			kPurifyAlchemyIngredients,
			kFilterActivation,
			kCanDualcastspell,
			kModifyTemperingHealth,
			kModifyEnchantmentPower,
			kModifySoulPctCapturedToWeapon,
			kModSoulGemEnchanting,
			kModAppliedEnchantmentsAllowed,
			kSetActivateLabel,
			kModShoutOK,
			kModPoisonDoseCount,
			kShouldApplyPlacedItem,
			kModifyArmorRating,
			kModifyLockpickingCrimeChance,
			kModifyIngredientsHarvested,
			kModifySpellRangeTargetLoc,
			kModifyPotionsCreated,
			kModifyLockpickingkeyRewardChance,
			kAllowMountActor,

			kTotal
		};


		virtual bool						EvaluateConditions(UInt32 a_numArgs, void* a_args);	// 00 - { return false; }
		virtual EntryPointType				GetType() const;									// 01 - { return 0; }
		virtual BGSEntryPointFunctionData*	GetFunctionData() const;							// 02 - { return 0; }

		virtual ~BGSPerkEntry();																// 03

		virtual UInt32						GetNumConditions() const = 0;						// 04
		virtual void						ReleaseRefs();										// 05 - { return; }
		virtual void						Unk_06(void);										// 06 - { return; }
		virtual bool						LoadPerk(TESFile* a_mod);							// 07 - { return true; }
		virtual void						SetPerk(BGSPerk* a_perk);							// 08 - { return; }
		virtual void						Unk_09(void);										// 09 - { return 0xFFFF; }
		virtual void						Unk_0A(void);										// 0A - pure
		virtual void						Unk_0B(void);										// 0B - pure


		// members
		UInt8	rank;		// 08
		UInt8	priority;	// 09
		UInt16	type;		// 0A
		UInt32	pad0C;		// 0C
	};
	STATIC_ASSERT(sizeof(BGSPerkEntry) == 0x10);
}
