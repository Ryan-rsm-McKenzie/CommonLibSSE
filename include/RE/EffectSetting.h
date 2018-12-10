#pragma once

#include "skse64/GameFormComponents.h"  // TESFullName, BGSMenuDisplayObject

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/BGSKeywordForm.h"  // BGSKeywordForm
#include "RE/BSTArray.h"  // BSTArray
#include "RE/BSTList.h"  // BSSimpleList
#include "RE/TESForm.h"  // TESForm

#include "Utility.h"  // MAKE_BITWISE_OPERATORS

class BGSArtObject;
class BGSExplosion;
class BGSImpactDataSet;
class BGSPerk;
class BGSProjectile;
class BGSDualCastData;
class SpellItem;
class TESImageSpaceModifier;
class TESSound;


namespace RE
{
	class TESEffectShader;
	class TESObjectLIGH;


	class EffectSetting :
		public TESForm,
		public TESFullName,
		public BGSMenuDisplayObject,
		public BGSKeywordForm
	{
	public:
		enum { kTypeID = FormType::EffectSetting };


		struct Data	// DATA
		{
			enum class Flag : UInt32
			{
				kHostile = (1 << 0),		// 00000001
				kRecover = (1 << 1),		// 00000002
				kDetrimental = (1 << 2),	// 00000004
				kUnk08 = (1 << 3),			// 00000008
				kNoHitEvent = (1 << 4),		// 00000010
				kUnk20 = (1 << 5),			// 00000020
				kUnk40 = (1 << 6),			// 00000040
				kUnk80 = (1 << 7),			// 00000080
				kDispelKeywords = (1 << 8),	// 00000100
				kNoDuration = (1 << 9),		// 00000200
				kNoMagnitude = (1 << 10),	// 00000400
				kNoArea = (1 << 11),		// 00000800
				kFXPersist = (1 << 12),		// 00001000
				kUnk2000 = (1 << 13),		// 00002000
				kGloryVisuals = (1 << 14),	// 00004000
				kHideInUI = (1 << 15),		// 00008000
				kUnk10000 = (1 << 16),		// 00010000
				kNoRecast = (1 << 17),		// 00020000
				kUnk40000 = (1 << 18),		// 00040000
				kUnk80000 = (1 << 19),		// 00080000
				kUnk100000 = (1 << 20),		// 00100000
				kMagnitude = (1 << 21),		// 00200000
				kDuration = (1 << 22),		// 00400000
				kUnk800000 = (1 << 23),		// 00800000
				kUnk1000000 = (1 << 24),	// 01000000
				kUnk2000000 = (1 << 25),	// 02000000
				kPainless = (1 << 26),		// 04000000
				kNoHitEffect = (1 << 27),	// 08000000
				kNoDeathDispel = (1 << 28)	// 10000000
			};

			MAKE_BITWISE_OPERATORS(Flag);


			enum class MagicSkill : UInt32
			{
				kOneHanded = 0x6,
				kTwoHanded = 0x7,
				kArchery = 0x8,
				kBlock = 0x9,
				kSmithing = 0xA,
				kHeavyArmor = 0xB,
				kLightArmor = 0xC,
				kPickPocket = 0xD,
				kLockPicking = 0xE,
				kSneak = 0xF,
				kAlchemy = 0x10,
				kSpeech = 0x11,
				kAlteration = 0x12,
				kConjuration = 0x13,
				kDestruction = 0x14,
				kIllusion = 0x15,
				kRestoration = 0x16,
				kEnchanting = 0x17
			};

			MAKE_BITWISE_OPERATORS(MagicSkill);


			enum class ResistValue : UInt32
			{

			};

			MAKE_BITWISE_OPERATORS(ResistValue);


			enum class Archetype : UInt32
			{
				kValueMod = 0,
				kScript,
				kDispel,
				kCureDisease,
				kAbsorb,
				kDualValueMod,
				kCalm,
				kDemoralize,
				kFrenzy,
				kDisarm,
				kCommandSummoned,
				kInvisibility,
				kLight,
				kLock = 15,
				kOpen,
				kBoundWeapon,
				kSummonCreature,
				kDetectLife,
				kTelekinesis,
				kParalysis,
				kReanimate,
				kSoulTrap,
				kTurnUndead,
				kGuide,
				kWerewolfFeed,
				kCureParalysis,
				kCureAddiction,
				kCurePoison,
				kConcussion,
				kValueAndParts,
				kAccumulateMagnitude,
				kStagger,
				kPeakValueMod,
				kCloak,
				kWerewolf,
				kSlowTime,
				kRally,
				kEnhanceWeapon,
				kSpawnHazard,
				kEtherealize,
				kBanish,
				kDisguise = 44,
				kGrabActor,
				kVampireLord
			};

			MAKE_BITWISE_OPERATORS(Archetype);


			enum class CastingType : UInt32
			{
				kConstantEffect = 0,
				kFireAndForget,
				kConcentration
			};

			MAKE_BITWISE_OPERATORS(CastingType);


			enum class DeliveryType : UInt32
			{
				kSelf = 0,
				kContact,
				kAimed,
				kTargetActor,
				kTargetLocation
			};

			MAKE_BITWISE_OPERATORS(DeliveryType);


			enum class Volume : UInt32
			{
				kLoud = 0,
				kNormal,
				kSilent,
				kVeryLoud
			};

			MAKE_BITWISE_OPERATORS(Volume);


			enum ActorValue : UInt32
			{
				kAggression = 0,
				kConfidence,
				kEnergy,
				kMorality,
				kMood,
				kAssistance,
				kOnehanded,
				kTwohanded,
				kMarksman,
				kBlock,
				kSmithing,
				kHeavyArmor,
				kLightArmor,
				kPickpocket,
				kLockpicking,
				kSneak,
				kAlchemy,
				kSpeechcraft,
				kAlteration,
				kConjuration,
				kDestruction,
				kIllusion,
				kRestoration,
				kEnchanting,
				kHealth,
				kMagicka,
				kStamina,
				kHealrate,
				kMagickaRate,
				kStaminaRate,
				kSpeedMult,
				kInventoryWeight,
				kCarryWeight,
				kCritChance,
				kMeleeDamage,
				kUnarmedDamage,
				kMass,
				kVoicePoints,
				kVoiceRate,
				kDamageResist,
				kPoisonResist,
				kFireResist,
				kElectricResist,
				kFrostResist,
				kMagicResist,
				kDiseaseResist,
				kPerceptionCondition,
				kEnduranceCondition,
				kLeftAttackCondition,
				kRightAttackCondition,
				kLeftMobilityCondition,
				kRightMobilityCondition,
				kBrainCondition,
				kParalysis,
				kInvisibility,
				kNightEye,
				kDetectLifeRange,
				kWaterBreathing,
				kWaterWalking,
				kIgnoreCrippledLimbs,
				kFame,
				kInfamy,
				kJumpingBonus,
				kWardPower,
				kRightItemCharge,
				kArmorPerks,
				kShieldPerks,
				kWardDeflection,
				kVariable01,
				kVariable02,
				kVariable03,
				kVariable04,
				kVariable05,
				kVariable06,
				kVariable07,
				kVariable08,
				kVariable09,
				kVariable10,
				kBowSpeedBonus,
				kFavorActive,
				kFavorSperDay,
				kFavorSperDaytimer,
				kLeftItemCharge,
				kAbsorbChance,
				kBlindness,
				kWeaponSpeedMult,
				kShoutRecoveryMult,
				kBowStaggerBonus,
				kTelekinesis,
				kFavorPointsBonus,
				kLastBribedIntimidated,
				kLastFlattered,
				kMovementNoiseMult,
				kBypassVendorStolenCheck,
				kBypassVendorKeywordCheck,
				kWaitingForPlayer,
				kOnehandedMod,
				kTwohandedMod,
				kMarksmanMod,
				kBlockMod,
				kSmithingMod,
				kHeavyArmorMod,
				kLightArmorMod,
				kPickpocketMod,
				kLockpickingMod,
				kSneakMod,
				kAlchemyMod,
				kSpeechcraftMod,
				kAlterationMod,
				kConjurationMod,
				kDestructionMod,
				kIllusionMod,
				kRestorationMod,
				kEnchantingMod,
				kOnehandedSkillAdvance,
				kTwohandedSkillAdvance,
				kMarksmanSkillAdvance,
				kBlockSkillAdvance,
				kSmithingSkillAdvance,
				kHeavyArmorSkillAdvance,
				kLightArmorSkillAdvance,
				kPickpocketSkillAdvance,
				kLockpickingSkillAdvance,
				kSneakSkillAdvance,
				kAlchemySkillAdvance,
				kSpeechcraftSkillAdvance,
				kAlterationSkillAdvance,
				kConjurationSkillAdvance,
				kDestructionSkillAdvance,
				kIllusionSkillAdvance,
				kRestorationSkillAdvance,
				kEnchantingSkillAdvance,
				kLeftWeaponSpeedMult,
				kDragonSouls,
				kCombatHealthRegenMult,
				kOnehandedPowerMod,
				kTwohandedPowerMod,
				kMarksmanPowerMod,
				kBlockPowerMod,
				kSmithingPowerMod,
				kHeavyarmorPowerMod,
				kLightarmorPowerMod,
				kPickpocketPowerMod,
				kLockpickingPowerMod,
				kSneakPowerMod,
				kAlchemyPowerMod,
				kSpeechcraftPowerMod,
				kAlterationPowerMod,
				kConjurationPowerMod,
				kDestructionPowerMod,
				kIllusionPowerMod,
				kRestorationPowerMod,
				kEnchantingPowerMod,
				kDragonrend,
				kAttackDamageMult,
				kHealRateMult,
				kMagickaRateMult,
				kStaminaRateMult,
				kWerewolfPerks,
				kVampirePerks,
				kGrabActorOffset,
				kGrabbed,
				kDeprecated05,
				kReflectDamage
			};

			MAKE_BITWISE_OPERATORS(ActorValue);


			struct SpellMaking
			{
				UInt32	area;			// 0 - init'd to 0
				float	castingTime;	// 4 - init'd to 0
			};
			STATIC_ASSERT(sizeof(SpellMaking) == 0x8);


			struct DualCasting
			{
				BGSDualCastData*	art;	// 00 - init'd to 0
				float				scale;	// 08 - init'd to 1
				UInt32				pad0C;	// 0C
			};
			STATIC_ASSERT(sizeof(DualCasting) == 0x10);


			struct ScriptEffectAI
			{
				float	score;		// 0 - init'd to 0
				float	delayTime;	// 4 - init'd to 0
			};
			STATIC_ASSERT(sizeof(ScriptEffectAI) == 0x8);


			Flag					flags;					// 00 - init'd to 0
			float					baseCost;				// 04 - init'd to 0
			TESForm*				primaryObject;			// 08 - init'd to 0 - unused
			MagicSkill				magicSkill;				// 10 - init'd to FFFFFFFF
			ResistValue				resistValue;			// 14 - init'd to FFFFFFFF
			UInt16					counterEffectCount;		// 18 - init'd to 0
			UInt8					pad1A[6];				// 1A
			TESObjectLIGH*			castingLight;			// 20 - init'd to 0
			float					taperWeight;			// 28 - init'd to 0
			TESEffectShader*		hitShader;				// 30 - init'd to 0
			TESEffectShader*		enchantShader;			// 38 - init'd to 0
			UInt32					minimumSkillLevel;		// 40 - init'd to 0
			SpellMaking				spellMaking;			// 44
			float					taperCurve;				// 4C - init'd to 0
			float					taperDuration;			// 50 - init'd to 0
			float					secondAVWeight;			// 54 - init'd to 0 float - Always 0
			Archetype				archetype;				// 58 - init'd to 0
			ActorValue				primaryActorValue;		// 5C - init'd to FFFFFFFF
			BGSProjectile*			projectile;				// 60 - init'd to 0
			BGSExplosion*			explosion;				// 68 - init'd to 0
			CastingType				castingType;			// 70 - init'd to 3
			DeliveryType			deliveryType;			// 74 - init'd to 5
			ActorValue				secondaryActorValue;	// 78 - init'd to FFFFFFFF
			BGSArtObject*			castingArt;				// 80 - init'd to 0
			BGSArtObject*			hitEffectArt;			// 88 - init'd to 0
			BGSImpactDataSet*		impactDataSet;			// 90 - init'd to 0
			float					skillUsageMult;			// 98 - init'd to 0
			DualCasting				dualCasting;			// A0
			BGSArtObject*			enchantArt;				// B0 - init'd to 0
			void*					unkB8;					// B8 - init'd to 0
			void*					unkC0;					// C0 - init'd to 0
			SpellItem*				equipAbility;			// C8 - init'd to 0
			TESImageSpaceModifier*	imageSpaceMod;			// D0 - init'd to 0
			BGSPerk*				perkToApply;			// D8 - init'd to 0
			Volume					volume;					// E0 - init'd to 1
			ScriptEffectAI			scriptEffectAI;			// E4
		};
		STATIC_ASSERT(sizeof(Data) == 0xF0);


		struct SoundInfo	// SNDD
		{
			enum class Type : UInt32
			{
				kDrawSheathe = 0,
				kCharge,
				kReady,
				kRelease,
				kCastLoop,
				kOnHit,
				kTotalTypes
			};

			MAKE_BITWISE_OPERATORS(Type);


			Type		type;	// 00
			UInt32		pad04;	// 04
			TESSound*	sound;	// 08
		};
		STATIC_ASSERT(sizeof(SoundInfo) == 0x10);


		// override (TESForm)
		virtual bool		LoadForm(TESFile* a_mod) override;					// 06
		virtual void		InitItem() override;								// 13
		virtual void		CopyFrom(TESForm* a_srcForm) override;				// 2F
		virtual const char*	GetTypeString() const override;						// 39

		// override (BGSKeywordForm)
		virtual bool		HasKeyword(BGSKeyword* a_keyword) const override;	// 04

		Data::MagicSkill	GetMagickSkill();
		UInt32				GetMinimumSkillLevel();
		bool				HasArchetype(Data::Archetype a_type);


		// members
		void*							unk058;					// 058
		void*							unk060;					// 060
		Data							data;					// 068
		BSSimpleList<EffectSetting*>	counterEffects;			// 158
		BSTArray<SoundInfo>				sounds;					// 168
		BSFixedString					magicItemDescription;	// 180 - DNAM
		UInt32							unk188;					// 188
		UInt32							unk18C;					// 18C
		Condition*						conditions;				// 190
	};
	STATIC_ASSERT(sizeof(EffectSetting) == 0x198);
}
