#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESObjectWEAP

#include "RE/ActorValues.h"  // ActorValue, ActorValue8
#include "RE/BGSBlockBashData.h"  // BGSBlockBashData
#include "RE/BGSDestructibleObjectForm.h"  // BGSDestructibleObjectForm
#include "RE/BGSEquipType.h"  // BGSEquipType
#include "RE/BGSKeywordForm.h"  // BGSKeywordForm
#include "RE/BGSMessageIcon.h"  // BGSMessageIcon
#include "RE/BGSPickupPutdownSounds.h"  // BGSPickupPutdownSounds
#include "RE/BGSPreloadable.h"  // BGSPreloadable
#include "RE/SoundLevels.h"  // SoundLevel
#include "RE/TESAttackDamageForm.h"  // TESAttackDamageForm
#include "RE/TESBoundObject.h"  // TESBoundObject
#include "RE/TESDescription.h"  // TESDescription
#include "RE/TESEnchantableForm.h"  // TESEnchantableForm
#include "RE/TESFullName.h"  // TESFullName
#include "RE/TESIcon.h"  // TESIcon
#include "RE/TESModelTextureSwap.h"  // TESModelTextureSwap
#include "RE/TESValueForm.h"  // TESValueForm
#include "RE/TESWeightForm.h"  // TESWeightForm


namespace RE
{
	class TESObjectWEAP :
		public TESBoundObject,				// 000
		public TESFullName,					// 030
		public TESModelTextureSwap,			// 040
		public TESIcon,						// 078
		public TESEnchantableForm,			// 088
		public TESValueForm,				// 0A0
		public TESWeightForm,				// 0B0
		public TESAttackDamageForm,			// 0C0
		public BGSDestructibleObjectForm,	// 0D0
		public BGSEquipType,				// 0E0
		public BGSPreloadable,				// 0F0
		public BGSMessageIcon,				// 0F8
		public BGSPickupPutdownSounds,		// 110
		public BGSBlockBashData,			// 128
		public BGSKeywordForm,				// 140
		public TESDescription				// 158
	{
	public:
		inline static const void* RTTI = RTTI_TESObjectWEAP;


		enum { kTypeID = FormType::Weapon };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kNonPlayable = 1 << 2,
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		struct Data	// DATA
		{
			enum class OnHit : UInt32
			{
				kNoFormulaBehavior,
				kDismemberOnly,
				kExplodeOnly,
				kNoDismemberExplode
			};


			enum class Flag2 : UInt16
			{
				kNone = 0,
				kPlayerOnly = 1 << 0,
				kNPCsUseAmmo = 1 << 1,
				kNoJamAfterReload = 1 << 2,			// unused
				kMinorCrime = 1 << 4,
				kRangeFixed = 1 << 5,
				kNotUsedInNormalCombat = 1 << 6,
				kDontUse3rdPersonISAnim = 1 << 8,	// unused
				kBurstShot = 1 << 9,
				kRumbleAlternate = 1 << 10,
				kLongBursts = 1 << 11,
				kNonHostile = 1 << 12,
				kBoundWeapon = 1 << 13
			};


			enum class AttackAnimation : UInt8
			{
				kAttackLeft = 26,
				kAttackRight = 32,
				kAttack3 = 38,
				kAttack4 = 44,
				kAttack5 = 50,
				kAttack7 = 62,
				kAttack8 = 68,
				kAttackLoop = 74,
				kAttackSpin = 80,
				kAttackSpin2 = 86,
				kPlaceMine = 97,
				kPlaceMine2 = 103,
				kAttackThrow = 109,
				kAttackThrow2 = 115,
				kAttackThrow3 = 121,
				kAttackThrow4 = 127,
				kAttackThrow5 = 133,
				kDefault = 255
			};


			enum class AnimationType : UInt8
			{
				kHandToHandMelee = 0,
				kOneHandSword = 1,
				kOneHandDagger = 2,
				kOneHandAxe = 3,
				kOneHandMace = 4,
				kTwoHandSword = 5,
				kTwoHandAxe = 6,
				kBow = 7,
				kStaff = 8,
				kCrossbow = 9
			};


			enum class Flag : UInt8
			{
				kNone = 0,
				kIgnoresNormalWeaponResistance = 1 << 0,
				kAutomatic = 1 << 1,						// unused
				kHasScope = 1 << 2,							// unused
				kCantDrop = 1 << 3,
				kHideBackpack = 1 << 4,						// unused
				kEmbeddedWeapon = 1 << 5,					// unused
				kDontUseFirstPersonISAnim = 1 << 6,			// unused
				kNonPlayable = 1 << 7
			};


			struct ExtraData
			{
				float	sightFOV;					// 00
				float	unk04;						// 04
				float	rumbleLeftMotorStrength;	// 08
				float	rumbleRightMotorStrength;	// 0C
				float	rumbleDuration;				// 10
				UInt32	unk14;						// 14
				UInt32	numProjectiles;				// 18
			};
			STATIC_ASSERT(sizeof(ExtraData) == 0x1C);


			ExtraData*		extraData;				// 00
			float			speed;					// 08
			float			reach;					// 0C
			float			rangeMin;				// 10
			float			rangeMax;				// 14
			float			animationAttackMult;	// 18
			float			unk1C;					// 1C
			float			stagger;				// 20
			OnHit			onHit;					// 24
			ActorValue		skill;					// 28
			ActorValue		resist;					// 2C
			Flag2			flags2;					// 30
			UInt8			baseVATSToHitChance;	// 32
			AttackAnimation	attackAnimation;		// 33
			ActorValue8		embeddedWeaponAV;		// 34 - unused
			AnimationType	animationType;			// 35
			Flag			flags;					// 36
			UInt8			pad37;					// 37
		};
		STATIC_ASSERT(sizeof(Data) == 0x38);


		struct CriticalData	// CRDT
		{
			enum Flag : UInt8
			{
				kNone = 0,
				kOnDeath = 1 << 0
			};


			float		prcntMult;		// 00
			UInt32		pad04;			// 04
			SpellItem*	effect;			// 08
			UInt16		damage;			// 10
			Flag		flags;			// 12
			UInt8		pad13;			// 13
			UInt32		pad14;			// 14
		};
		STATIC_ASSERT(sizeof(CriticalData) == 0x18);


		virtual ~TESObjectWEAP();											// 00

		// override (TESBoundObject)
		virtual void		InitDefaults() override;						// 04
		virtual void		ReleaseManagedData() override;					// 05
		virtual bool		LoadForm(TESFile* a_mod) override;				// 06
		virtual void		SaveBuffer(BGSSaveFormBuffer* a_buf) override;	// 0E
		virtual void		LoadBuffer(BGSLoadFormBuffer* a_buf) override;	// 0F
		virtual void		InitItem() override;							// 13
		virtual TESFile*	GetFinalSourceFile() override;					// 14
		virtual bool		IsPlayable() override;							// 19 - { return ~((data.flags >> 7) & 1); }
		virtual const char*	GetTypeString() const override;					// 39 - { return g_animationStrings[data.animationType]; }

		float				GetSpeed();
		float				GetReach();
		float				GetStagger();
		float				GetMinRange();
		float				GetMaxRange();
		Data::AnimationType	GetAnimationType();
		UInt16				GetCritDamage();
		void				GetNodeName(char* a_dstBuff);
		bool				IsBound() const;
		bool				IsMelee() const;
		bool				IsRanged() const;
		bool				IsHandToHandMelee() const;
		bool				IsOneHandedSword() const;
		bool				IsOneHandedDagger() const;
		bool				IsOneHandedAxe() const;
		bool				IsOneHandedMace() const;
		bool				IsTwoHandedSword() const;
		bool				IsTwoHandedAxe() const;
		bool				IsBow() const;
		bool				IsStaff() const;
		bool				IsCrossbow() const;


		// members
		Data					data;					// 168 - DNAM
		CriticalData			criticalData;			// 1A0 - CRDT
		TESForm*				scopeEffect;			// 1B8
		BGSSoundDescriptorForm*	attackSound;			// 1C0 - SNAM
		BGSSoundDescriptorForm*	attackSound2D;			// 1C8 - XNAM
		BGSSoundDescriptorForm*	attackLoopSound;		// 1D0 - NAM7
		BGSSoundDescriptorForm*	attackFailSound;		// 1D8 - TNAM
		BGSSoundDescriptorForm*	idleSound;				// 1E0 - UNAM
		BGSSoundDescriptorForm*	equipSound;				// 1E8 - NAM9
		BGSSoundDescriptorForm*	unequipSound;			// 1F0 - NAM8
		BGSImpactDataSet*		impactDataSet;			// 1F8
		TESObjectSTAT*			firstPersonModelObject;	// 200 - WNAM
		TESObjectWEAP*			templateForm;			// 208 - CNAM
		BSFixedString			embeddedNode;			// 210
		SoundLevel				detectionSoundLevel;	// 218 - VNAM
		UInt32					pad21C;					// 21C
	};
	STATIC_ASSERT(sizeof(TESObjectWEAP) == 0x220);
}
