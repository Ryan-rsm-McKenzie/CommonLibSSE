#pragma once

#include "skse64/GameFormComponents.h"  // TESFullName, BGSMenuDisplayObject, BGSKeywordForm
#include "skse64/GameForms.h"  // TESForm
#include "skse64/GameTypes.h"  // tList, tArray, BSFixedString

class BGSArtObject;
class BGSExplosion;
class BGSImpactDataSet;
class BGSPerk;
class BGSProjectile;
class BGSDualCastData;
class SpellItem;
class TESEffectShader;
class TESImageSpaceModifier;
class TESSound;


namespace RE
{
	class TESObjectLIGH;


	class EffectSetting :
		public TESForm,
		public TESFullName,
		public BGSMenuDisplayObject,
		public BGSKeywordForm
	{
	public:
		enum { kTypeID = kFormType_EffectSetting };


		struct Properties
		{
			enum EffectType : UInt32
			{
				kEffectType_Hostile			= (1 << 0),		// 00000001
				kEffectType_Recover			= (1 << 1),		// 00000002
				kEffectType_Detrimental		= (1 << 2),		// 00000004
				kEffectType_Unk08			= (1 << 3),		// 00000008
				kEffectType_NoHitEvent		= (1 << 4),		// 00000010
				kEffectType_Unk20			= (1 << 5),		// 00000020
				kEffectType_Unk40			= (1 << 6),		// 00000040
				kEffectType_Unk80			= (1 << 7),		// 00000080
				kEffectType_DispelKeywords	= (1 << 8),		// 00000100
				kEffectType_NoDuration		= (1 << 9),		// 00000200
				kEffectType_NoMagnitude		= (1 << 10),	// 00000400
				kEffectType_NoArea			= (1 << 11),	// 00000800
				kEffectType_FXPersist		= (1 << 12),	// 00001000
				kEffectType_Unk2000			= (1 << 13),	// 00002000
				kEffectType_GloryVisuals	= (1 << 14),	// 00004000
				kEffectType_HideInUI		= (1 << 15),	// 00008000
				kEffectType_Unk10000		= (1 << 16),	// 00010000
				kEffectType_NoRecast		= (1 << 17),	// 00020000
				kEffectType_Unk40000		= (1 << 18),	// 00040000
				kEffectType_Unk80000		= (1 << 19),	// 00080000
				kEffectType_Unk100000		= (1 << 20),	// 00100000
				kEffectType_Magnitude		= (1 << 21),	// 00200000
				kEffectType_Duration		= (1 << 22),	// 00400000
				kEffectType_Unk800000		= (1 << 23),	// 00800000
				kEffectType_Unk1000000		= (1 << 24),	// 01000000
				kEffectType_Unk2000000		= (1 << 25),	// 02000000
				kEffectType_Painless		= (1 << 26),	// 04000000
				kEffectType_NoHitEffect		= (1 << 27),	// 08000000
				kEffectType_NoDeathDispel	= (1 << 28)		// 10000000
			};


			enum Archetype
			{
				kArchetype_ValueMod = 0,
				kArchetype_Script,
				kArchetype_Dispel,
				kArchetype_CureDisease,
				kArchetype_Absorb,
				kArchetype_DualValueMod,
				kArchetype_Calm,
				kArchetype_Demoralize,
				kArchetype_Frenzy,
				kArchetype_Disarm,
				kArchetype_CommandSummoned,
				kArchetype_Invisibility,
				kArchetype_Light,
				kArchetype_Lock = 15,
				kArchetype_Open,
				kArchetype_BoundWeapon,
				kArchetype_SummonCreature,
				kArchetype_DetectLife,
				kArchetype_Telekinesis,
				kArchetype_Paralysis,
				kArchetype_Reanimate,
				kArchetype_SoulTrap,
				kArchetype_TurnUndead,
				kArchetype_Guide,
				kArchetype_WerewolfFeed,
				kArchetype_CureParalysis,
				kArchetype_CureAddiction,
				kArchetype_CurePoison,
				kArchetype_Concussion,
				kArchetype_ValueAndParts,
				kArchetype_AccumulateMagnitude,
				kArchetype_Stagger,
				kArchetype_PeakValueMod,
				kArchetype_Cloak,
				kArchetype_Werewolf,
				kArchetype_SlowTime,
				kArchetype_Rally,
				kArchetype_EnhanceWeapon,
				kArchetype_SpawnHazard,
				kArchetype_Etherealize,
				kArchetype_Banish,
				kArchetype_Disguise = 44,
				kArchetype_GrabActor,
				kArchetype_VampireLord
			};


			enum CastingType
			{
				kCastingType_ConstantEffect = 0,
				kCastingType_FireAndForget,
				kCastingType_Concentration
			};


			enum DeliveryType
			{
				kDeliveryType_Self = 0,
				kDeliveryType_Contact,
				kDeliveryType_Aimed,
				kDeliveryType_TargetActor,
				kDeliveryType_TargetLocation
			};


			enum Volume
			{
				kVolume_Loud = 0,
				kVolume_Normal,
				kVolume_Silent,
				kVolume_VeryLoud
			};


			enum ActorValue
			{
				kActorValue_Aggression = 0,
				kActorValue_Confidence,
				kActorValue_Energy,
				kActorValue_Morality,
				kActorValue_Mood,
				kActorValue_Assistance,
				kActorValue_Onehanded,
				kActorValue_Twohanded,
				kActorValue_Marksman,
				kActorValue_Block,
				kActorValue_Smithing,
				kActorValue_HeavyArmor,
				kActorValue_LightArmor,
				kActorValue_Pickpocket,
				kActorValue_Lockpicking,
				kActorValue_Sneak,
				kActorValue_Alchemy,
				kActorValue_Speechcraft,
				kActorValue_Alteration,
				kActorValue_Conjuration,
				kActorValue_Destruction,
				kActorValue_Illusion,
				kActorValue_Restoration,
				kActorValue_Enchanting,
				kActorValue_Health,
				kActorValue_Magicka,
				kActorValue_Stamina,
				kActorValue_Healrate,
				kActorValue_MagickaRate,
				kActorValue_StaminaRate,
				kActorValue_SpeedMult,
				kActorValue_InventoryWeight,
				kActorValue_CarryWeight,
				kActorValue_CritChance,
				kActorValue_MeleeDamage,
				kActorValue_UnarmedDamage,
				kActorValue_Mass,
				kActorValue_VoicePoints,
				kActorValue_VoiceRate,
				kActorValue_DamageResist,
				kActorValue_PoisonResist,
				kActorValue_FireResist,
				kActorValue_ElectricResist,
				kActorValue_FrostResist,
				kActorValue_MagicResist,
				kActorValue_DiseaseResist,
				kActorValue_PerceptionCondition,
				kActorValue_EnduranceCondition,
				kActorValue_LeftAttackCondition,
				kActorValue_RightAttackCondition,
				kActorValue_LeftMobilityCondition,
				kActorValue_RightMobilityCondition,
				kActorValue_BrainCondition,
				kActorValue_Paralysis,
				kActorValue_Invisibility,
				kActorValue_NightEye,
				kActorValue_DetectLifeRange,
				kActorValue_WaterBreathing,
				kActorValue_WaterWalking,
				kActorValue_IgnoreCrippledLimbs,
				kActorValue_Fame,
				kActorValue_Infamy,
				kActorValue_JumpingBonus,
				kActorValue_WardPower,
				kActorValue_RightItemCharge,
				kActorValue_ArmorPerks,
				kActorValue_ShieldPerks,
				kActorValue_WardDeflection,
				kActorValue_Variable01,
				kActorValue_Variable02,
				kActorValue_Variable03,
				kActorValue_Variable04,
				kActorValue_Variable05,
				kActorValue_Variable06,
				kActorValue_Variable07,
				kActorValue_Variable08,
				kActorValue_Variable09,
				kActorValue_Variable10,
				kActorValue_BowSpeedBonus,
				kActorValue_FavorActive,
				kActorValue_FavorSperDay,
				kActorValue_FavorSperDaytimer,
				kActorValue_LeftItemCharge,
				kActorValue_AbsorbChance,
				kActorValue_Blindness,
				kActorValue_WeaponSpeedMult,
				kActorValue_ShoutRecoveryMult,
				kActorValue_BowStaggerBonus,
				kActorValue_Telekinesis,
				kActorValue_FavorPointsBonus,
				kActorValue_LastBribedIntimidated,
				kActorValue_LastFlattered,
				kActorValue_MovementNoiseMult,
				kActorValue_BypassVendorStolenCheck,
				kActorValue_BypassVendorKeywordCheck,
				kActorValue_WaitingForPlayer,
				kActorValue_OnehandedMod,
				kActorValue_TwohandedMod,
				kActorValue_MarksmanMod,
				kActorValue_BlockMod,
				kActorValue_SmithingMod,
				kActorValue_HeavyArmorMod,
				kActorValue_LightArmorMod,
				kActorValue_PickpocketMod,
				kActorValue_LockpickingMod,
				kActorValue_SneakMod,
				kActorValue_AlchemyMod,
				kActorValue_SpeechcraftMod,
				kActorValue_AlterationMod,
				kActorValue_ConjurationMod,
				kActorValue_DestructionMod,
				kActorValue_IllusionMod,
				kActorValue_RestorationMod,
				kActorValue_EnchantingMod,
				kActorValue_OnehandedSkillAdvance,
				kActorValue_TwohandedSkillAdvance,
				kActorValue_MarksmanSkillAdvance,
				kActorValue_BlockSkillAdvance,
				kActorValue_SmithingSkillAdvance,
				kActorValue_HeavyArmorSkillAdvance,
				kActorValue_LightArmorSkillAdvance,
				kActorValue_PickpocketSkillAdvance,
				kActorValue_LockpickingSkillAdvance,
				kActorValue_SneakSkillAdvance,
				kActorValue_AlchemySkillAdvance,
				kActorValue_SpeechcraftSkillAdvance,
				kActorValue_AlterationSkillAdvance,
				kActorValue_ConjurationSkillAdvance,
				kActorValue_DestructionSkillAdvance,
				kActorValue_IllusionSkillAdvance,
				kActorValue_RestorationSkillAdvance,
				kActorValue_EnchantingSkillAdvance,
				kActorValue_LeftWeaponSpeedMult,
				kActorValue_DragonSouls,
				kActorValue_CombatHealthRegenMult,
				kActorValue_OnehandedPowerMod,
				kActorValue_TwohandedPowerMod,
				kActorValue_MarksmanPowerMod,
				kActorValue_BlockPowerMod,
				kActorValue_SmithingPowerMod,
				kActorValue_HeavyarmorPowerMod,
				kActorValue_LightarmorPowerMod,
				kActorValue_PickpocketPowerMod,
				kActorValue_LockpickingPowerMod,
				kActorValue_SneakPowerMod,
				kActorValue_AlchemyPowerMod,
				kActorValue_SpeechcraftPowerMod,
				kActorValue_AlterationPowerMod,
				kActorValue_ConjurationPowerMod,
				kActorValue_DestructionPowerMod,
				kActorValue_IllusionPowerMod,
				kActorValue_RestorationPowerMod,
				kActorValue_EnchantingPowerMod,
				kActorValue_Dragonrend,
				kActorValue_AttackDamageMult,
				kActorValue_HealRateMult,
				kActorValue_MagickaRateMult,
				kActorValue_StaminaRateMult,
				kActorValue_WerewolfPerks,
				kActorValue_VampirePerks,
				kActorValue_GrabActorOffset,
				kActorValue_Grabbed,
				kActorValue_Deprecated05,
				kActorValue_ReflectDamage
			};


			EffectType				effectTypes;			// 00 - init'd to 0
			float					baseCost;				// 04 - init'd to 0
			TESForm*				primaryObject;			// 08 - init'd to 0
			UInt32					school;					// 10 - init'd to FFFFFFFF
			UInt32					resistance;				// 14 - init'd to FFFFFFFF
			UInt16					unk18;					// 18 - init'd to 0
			UInt8					pad1A[6];				// 1A
			TESObjectLIGH*			light;					// 20 - init'd to 0
			float					taperWeight;			// 28 - init'd to 0
			TESEffectShader*		hitShader;				// 30 - init'd to 0
			TESEffectShader*		enchantShader;			// 38 - init'd to 0
			UInt32					level;					// 40 - init'd to 0
			UInt32					area;					// 44 - init'd to 0
			float					castingTime;			// 48 - init'd to 0
			float					taperCurve;				// 4C - init'd to 0
			float					taperDuration;			// 50 - init'd to 0
			float					secondAVWeight;			// 54 - init'd to 0 float - Always 0
			Archetype				archetype;				// 58 - init'd to 0
			ActorValue				primaryActorValue;		// 5C - init'd to FFFFFFFF
			BGSProjectile*			projectile;				// 60 - init'd to 0
			BGSExplosion*			explosion;				// 68 - init'd to 0
			CastingType				castingType;			// 70 - init'd to 3 cast type?
			DeliveryType			deliveryType;			// 74 - init'd to 5 cast type?
			ActorValue				secondaryActorValue;	// 78 - init'd to FFFFFFFF
			BGSArtObject*			castingArt;				// 80 - init'd to 0
			BGSArtObject*			hitEffectArt;			// 88 - init'd to 0
			BGSImpactDataSet*		impactDataSet;			// 90 - init'd to 0
			float					skillUsageMult;			// 98 - init'd to 0
			BGSDualCastData*		dualCastData;			// A0 - init'd to 0
			float					dualCastingScale;		// A8 - init'd to 1
			BGSArtObject*			enchantArt;				// B0 - init'd to 0
			void*					unkB8;					// B8 - init'd to 0
			void*					unkC0;					// C0 - init'd to 0
			SpellItem*				equipAbility;			// C8 - init'd to 0
			TESImageSpaceModifier*	imageSpaceMod;			// D0 - init'd to 0
			BGSPerk*				perk;					// D8 - init'd to 0
			Volume					volume;					// E0 - init'd to 1
			float					aiScore;				// E4 - init'd to 0
			float					delayTime;				// E8 - init'd to 0
		};


		struct SoundInfo
		{
			enum
			{
				kSound_DrawSheathe = 0,
				kSound_Charge,
				kSound_Ready,
				kSound_Release,
				kSound_CastLoop,
				kSound_OnHit,
				kNumSounds
			};

			UInt32		index;
			TESSound*	sound;
		};


		UInt32	GetSchool();
		UInt32	GetLevel();
		bool	HasArchetype(Properties::Archetype a_type);


		void*					unk058;			// 58
		void*					unk060;			// 60
		Properties				properties;		// 68
		tList<EffectSetting>	counterEffects;	// 158
		tArray<SoundInfo>		sounds;			// 168
		BSFixedString			description;	// 180
		UInt32					unk188;			// 188
		UInt32					unk18C;			// 18C
		void*					conditions;		// 190 - linked list
	};
}
