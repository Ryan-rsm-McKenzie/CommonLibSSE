#pragma once

#include "RE/ActorValues.h"  // ActorValue
#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/BGSKeywordForm.h"  // BGSKeywordForm
#include "RE/BGSMenuDisplayObject.h"  // BGSMenuDisplayObject
#include "RE/BSTArray.h"  // BSTArray
#include "RE/BSTList.h"  // BSSimpleList
#include "RE/TESForm.h"  // TESForm
#include "RE/TESFullName.h"  // TESFullName

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
				kHostile = 1 << 0,
				kRecover = 1 << 1,
				kDetrimental = 1 << 2,
				kSnapToNavMesh = 1 << 3,
				kNoHitEvent = 1 << 4,
				kDispelKeywords = 1 << 8,
				kNoDuration = 1 << 9,
				kNoMagnitude = 1 << 10,
				kNoArea = 1 << 11,
				kFXPersist = 1 << 12,
				kGloryVisuals = 1 << 14,
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


			enum class CastingType : UInt32
			{
				kConstantEffect = 0,
				kFireAndForget,
				kConcentration,
				kScroll
			};


			enum class DeliveryType : UInt32
			{
				kSelf = 0,
				kTouch,
				kAimed,
				kTargetActor,
				kTargetLocation
			};


			enum class Volume : UInt32
			{
				kLoud = 0,
				kNormal,
				kSilent,
				kVeryLoud
			};



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
			ActorValue				magicSkill;				// 10 - init'd to FFFFFFFF
			ActorValue				resistValue;			// 14 - init'd to FFFFFFFF
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
				kSheatheDraw = 0,
				kCharge,
				kReady,
				kRelease,
				kConcentrationCastLoop,
				kOnHit,

				kTotalTypes
			};


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

		ActorValue			GetMagickSkill();
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
