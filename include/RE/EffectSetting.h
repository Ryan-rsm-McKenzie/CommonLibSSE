#pragma once

#include "skse64/GameRTTI.h"  // RTTI_EffectSetting

#include "RE/ActorValues.h"  // ActorValue
#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/BGSKeywordForm.h"  // BGSKeywordForm
#include "RE/BGSMenuDisplayObject.h"  // BGSMenuDisplayObject
#include "RE/BSTArray.h"  // BSTArray
#include "RE/BSTList.h"  // BSSimpleList
#include "RE/Condition.h"  // Condition
#include "RE/FormTypes.h"  // FormType, TESObjectLIGH, TESEffectShader, BGSImpactDataSet, BGSProjectile, SpellItem, BGSSoundDescriptorForm, BGSArtObject, BGSExplosion, BGSPerk, BGSDualCastData, TESImageSpaceModifier
#include "RE/TESForm.h"  // TESForm
#include "RE/TESFullName.h"  // TESFullName


namespace RE
{
	class EffectSetting :
		public TESForm,					// 000
		public TESFullName,				// 020
		public BGSMenuDisplayObject,	// 030
		public BGSKeywordForm			// 040
	{
	public:
		inline static const void* RTTI = RTTI_EffectSetting;


		enum { kTypeID = FormType::MagicEffect };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		struct Data	// DATA
		{
			enum class Flag : UInt32
			{
				kNone = 0,
				kHostile = 1 << 0,
				kRecover = 1 << 1,
				kDetrimental = 1 << 2,
				kSnapToNavMesh = 1 << 3,
				kNoHitEvent = 1 << 4,
				kDispelWithKeywords = 1 << 8,
				kNoDuration = 1 << 9,
				kNoMagnitude = 1 << 10,
				kNoArea = 1 << 11,
				kFXPersist = 1 << 12,
				kGoryVisuals = 1 << 14,
				kHideInUI = 1 << 15,
				kNoRecast = 1 << 17,
				kPowerAffectsMagnitude = 1 << 21,
				kPowerAffectsDuration = 1 << 22,
				kPainless = 1 << 26,
				kNoHitEffect = 1 << 27,
				kNoDeathDispel = 1 << 28
			};


			enum class Archetype : UInt32
			{
				kValueModifier = 0,
				kScript = 1,
				kDispel = 2,
				kCureDisease = 3,
				kAbsorb = 4,
				kDualValueModifier = 5,
				kCalm = 6,
				kDemoralize = 7,
				kFrenzy = 8,
				kDisarm = 9,
				kCommandSummoned = 10,
				kInvisibility = 11,
				kLight = 12,
				kUnknown13 = 13,
				kUnknown14 = 14,
				kLock = 15,
				kOpen = 16,
				kBoundWeapon = 17,
				kSummonCreature = 18,
				kDetectLife = 19,
				kTelekinesis = 20,
				kParalysis = 21,
				kReanimate = 22,
				kSoulTrap = 23,
				kTurnUndead = 24,
				kGuide = 25,
				kWerewolfFeed = 26,
				kCureParalysis = 27,
				kCureAddiction = 28,
				kCurePoison = 29,
				kConcussion = 30,
				kValueAndParts = 31,
				kAccumulateMagnitude = 32,
				kStagger = 33,
				kPeakValueModifier = 34,
				kCloak = 35,
				kWerewolf = 36,
				kSlowTime = 37,
				kRally = 38,
				kEnhanceWeapon = 39,
				kSpawnHazard = 40,
				kEtherealize = 41,
				kBanish = 42,
				kSpawnScriptedRef = 43,
				kDisguise = 44,
				kGrabActor = 45,
				kVampireLord = 46
			};


			enum class CastingType : UInt32
			{
				kConstantEffect = 0,
				kFireAndForget = 1,
				kConcentration = 2,
				kScroll = 3
			};


			enum class DeliveryType : UInt32
			{
				kSelf = 0,
				kTouch = 1,
				kAimed = 2,
				kTargetActor = 3,
				kTargetLocation = 4
			};


			enum class Volume : UInt32
			{
				kLoud = 0,
				kNormal = 1,
				kSilent = 2,
				kVeryLoud = 3
			};



			struct SpellMaking
			{
				UInt32	area;			// 0
				float	castingTime;	// 4
			};
			STATIC_ASSERT(sizeof(SpellMaking) == 0x8);


			struct DualCasting
			{
				BGSDualCastData*	art;	// 00
				float				scale;	// 08
				UInt32				pad0C;	// 0C
			};
			STATIC_ASSERT(sizeof(DualCasting) == 0x10);


			struct ScriptEffectAI
			{
				float	score;		// 0
				float	delayTime;	// 4
			};
			STATIC_ASSERT(sizeof(ScriptEffectAI) == 0x8);


			Flag					flags;					// 00
			float					baseCost;				// 04
			TESForm*				associatedItem;			// 08
			ActorValue				magicSkill;				// 10
			ActorValue				resistValue;			// 14
			UInt16					counterEffectCount;		// 18
			UInt16					pad1A;					// 1A
			UInt32					pad1C;					// 1C
			TESObjectLIGH*			castingLight;			// 20
			float					taperWeight;			// 28
			UInt32					pad2C;					// 2C
			TESEffectShader*		hitShader;				// 30
			TESEffectShader*		enchantShader;			// 38
			UInt32					minimumSkillLevel;		// 40
			SpellMaking				spellMaking;			// 44
			float					taperCurve;				// 4C
			float					taperDuration;			// 50
			float					secondAVWeight;			// 54
			Archetype				archetype;				// 58
			ActorValue				primaryActorValue;		// 5C
			BGSProjectile*			projectile;				// 60
			BGSExplosion*			explosion;				// 68
			CastingType				castingType;			// 70
			DeliveryType			deliveryType;			// 74
			ActorValue				secondaryActorValue;	// 78
			BGSArtObject*			castingArt;				// 80
			BGSArtObject*			hitEffectArt;			// 88
			BGSImpactDataSet*		impactData;				// 90
			float					skillUsageMult;			// 98
			UInt32					pad9C;					// 9C
			DualCasting				dualCasting;			// A0
			BGSArtObject*			enchantArt;				// B0
			TESForm*				unkB8;					// B8
			TESForm*				unkC0;					// C0
			SpellItem*				equipAbility;			// C8
			TESImageSpaceModifier*	imageSpaceModifier;		// D0
			BGSPerk*				perkToApply;			// D8
			Volume					castingSoundLevel;		// E0
			ScriptEffectAI			scriptEffectAI;			// E4
			UInt32					padEC;					// EC
		};
		STATIC_ASSERT(sizeof(Data) == 0xF0);


		struct SoundInfo	// SNDD
		{
			enum class Type : UInt32
			{
				kSheatheDraw = 0,
				kCharge = 1,
				kReady = 2,
				kRelease = 3,
				kConcentrationCastLoop = 4,
				kOnHit = 5
			};


			Type					type;	// 00
			UInt32					pad04;	// 04
			BGSSoundDescriptorForm*	sound;	// 08
		};
		STATIC_ASSERT(sizeof(SoundInfo) == 0x10);


		virtual ~EffectSetting();												// 00

		// override (TESForm)
		virtual bool		LoadForm(TESFile* a_mod) override;					// 06
		virtual void		InitItem() override;								// 13
		virtual void		CopyFrom(TESForm* a_srcForm) override;				// 2F
		virtual const char*	GetTypeString() const override;						// 39

		// override (BGSKeywordForm)
		virtual bool		HasKeyword(BGSKeyword* a_keyword) const override;	// 04

		ActorValue			GetMagickSkill();
		UInt32				GetMinimumSkillLevel();
		bool				HasArchetype(Data::Archetype a_type);


		// members
		void*							unk058;					// 058
		void*							unk060;					// 060
		Data							data;					// 068 - DATA
		BSSimpleList<EffectSetting*>	counterEffects;			// 158 - ESCE
		BSTArray<SoundInfo>				sounds;					// 168 - SNDD
		BSFixedString					magicItemDescription;	// 180 - DNAM
		UInt32							unk188;					// 188
		UInt32							unk18C;					// 18C
		Condition						conditions;				// 190
	};
	STATIC_ASSERT(sizeof(EffectSetting) == 0x198);
}
