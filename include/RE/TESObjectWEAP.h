#pragma once

#include "RE/ActorValues.h"
#include "RE/BGSBlockBashData.h"
#include "RE/BGSDestructibleObjectForm.h"
#include "RE/BGSEquipType.h"
#include "RE/BGSKeywordForm.h"
#include "RE/BGSMessageIcon.h"
#include "RE/BGSPickupPutdownSounds.h"
#include "RE/BGSPreloadable.h"
#include "RE/FormTypes.h"
#include "RE/SoundLevels.h"
#include "RE/TESAttackDamageForm.h"
#include "RE/TESBoundObject.h"
#include "RE/TESDescription.h"
#include "RE/TESEnchantableForm.h"
#include "RE/TESFullName.h"
#include "RE/TESIcon.h"
#include "RE/TESModel.h"
#include "RE/TESModelTextureSwap.h"
#include "RE/TESValueForm.h"
#include "RE/TESWeightForm.h"


namespace RE
{
	enum class WEAPONHITBEHAVIOR : UInt32
	{
		kNormal = 0,
		kDismemberOnly = 1,
		kExplodeOnly = 2,
		kNoDismemberOrExplode = 3
	};


	enum class WEAPON_RUMBLE_PATTERN : UInt32
	{
		kConstant = 0,
		kPeriodicSquare = 1,
		kPeriodicTriangle = 2,
		kPeriodicSawtooth = 3
	};


	enum class WEAPON_TYPE : UInt8
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


	class TESObjectWEAP :
		public TESBoundObject,			   // 000
		public TESFullName,				   // 030
		public TESModelTextureSwap,		   // 040
		public TESIcon,					   // 078
		public TESEnchantableForm,		   // 088
		public TESValueForm,			   // 0A0
		public TESWeightForm,			   // 0B0
		public TESAttackDamageForm,		   // 0C0
		public BGSDestructibleObjectForm,  // 0D0
		public BGSEquipType,			   // 0E0
		public BGSPreloadable,			   // 0F0
		public BGSMessageIcon,			   // 0F8
		public BGSPickupPutdownSounds,	   // 110
		public BGSBlockBashData,		   // 128
		public BGSKeywordForm,			   // 140
		public TESDescription			   // 158
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESObjectWEAP;
		inline static constexpr auto FORMTYPE = FormType::Weapon;


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kNonPlayable = 1 << 2,
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		struct RangedData
		{
			float				  sightFOV;						   // 00
			float				  unk04;						   // 04
			float				  firingRumbleLeftMotorStrength;   // 08
			float				  firingRumbleRightMotorStrength;  // 0C
			float				  firingRumbleDuration;			   // 10
			WEAPON_RUMBLE_PATTERN rumblePattern;				   // 14
			SInt8				  numProjectiles;				   // 18
			UInt8				  pad19;						   // 19
			UInt16				  pad1A;						   // 1A
		};
		STATIC_ASSERT(sizeof(RangedData) == 0x1C);


		struct Data	 // DNAM
		{
			enum class Flag2 : UInt16
			{
				kNone = 0,
				kPlayerOnly = 1 << 0,
				kNPCsUseAmmo = 1 << 1,
				kNoJamAfterReload = 1 << 2,	 // unused
				kMinorCrime = 1 << 4,
				kRangeFixed = 1 << 5,
				kNotUsedInNormalCombat = 1 << 6,
				kDontUse3rdPersonISAnim = 1 << 8,  // unused
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


			enum class Flag : UInt8
			{
				kNone = 0,
				kIgnoresNormalWeaponResistance = 1 << 0,
				kAutomatic = 1 << 1,  // unused
				kHasScope = 1 << 2,	  // unused
				kCantDrop = 1 << 3,
				kHideBackpack = 1 << 4,				 // unused
				kEmbeddedWeapon = 1 << 5,			 // unused
				kDontUseFirstPersonISAnim = 1 << 6,	 // unused
				kNonPlayable = 1 << 7
			};


			RangedData*		  rangedData;			// 00
			float			  speed;				// 08
			float			  reach;				// 0C
			float			  minRange;				// 10
			float			  maxRange;				// 14
			float			  animationAttackMult;	// 18
			float			  unk1C;				// 1C
			float			  staggerValue;			// 20
			WEAPONHITBEHAVIOR hitBehavior;			// 24
			ActorValue		  skill;				// 28
			ActorValue		  resistance;			// 2C
			Flag2			  flags2;				// 30
			UInt8			  baseVATSToHitChance;	// 32
			AttackAnimation	  attackAnimation;		// 33
			ActorValue8		  embeddedWeaponAV;		// 34 - unused
			WEAPON_TYPE		  animationType;		// 35
			Flag			  flags;				// 36
			UInt8			  unk37;				// 37
		};
		STATIC_ASSERT(sizeof(Data) == 0x38);


		struct CriticalData	 // CRDT
		{
			enum Flag : UInt8
			{
				kNone = 0,
				kOnDeath = 1 << 0
			};


			float	   prcntMult;  // 00
			UInt32	   pad04;	   // 04
			SpellItem* effect;	   // 08
			UInt16	   damage;	   // 10
			Flag	   flags;	   // 12
			UInt8	   pad13;	   // 13
			UInt32	   pad14;	   // 14
		};
		STATIC_ASSERT(sizeof(CriticalData) == 0x18);


		struct Unk1B8
		{
			TESModel		 unk00;	 // 00
			TESEffectShader* unk28;	 // 28
		};
		STATIC_ASSERT(sizeof(Unk1B8) == 0x30);


		virtual ~TESObjectWEAP();  // 00

		// override (TESBoundObject)
		virtual void		InitializeData() override;					  // 04
		virtual void		ClearData() override;						  // 05
		virtual bool		Load(TESFile* a_mod) override;				  // 06
		virtual void		SaveGame(BGSSaveFormBuffer* a_buf) override;  // 0E
		virtual void		LoadGame(BGSLoadFormBuffer* a_buf) override;  // 0F
		virtual void		InitItemImpl() override;					  // 13
		virtual TESFile*	GetDescriptionOwnerFile() const override;	  // 14
		virtual bool		GetPlayable() const override;				  // 19 - { return ~((data.flags >> 7) & 1); }
		virtual const char* GetObjectTypeName() const override;			  // 39 - { return g_animationStrings[data.animationType]; }

		// override (BGSKeywordForm)
		virtual BGSKeyword* GetDefaultKeyword() const override;	 // 05

		float		GetSpeed() const;
		float		GetReach() const;
		float		GetStagger() const;
		float		GetMinRange() const;
		float		GetMaxRange() const;
		UInt16		GetCritDamage() const;
		void		GetNodeName(char* a_dstBuff) const;
		WEAPON_TYPE GetWeaponType() const;
		bool		IsBound() const;
		bool		IsMelee() const;
		bool		IsRanged() const;
		bool		IsHandToHandMelee() const;
		bool		IsOneHandedSword() const;
		bool		IsOneHandedDagger() const;
		bool		IsOneHandedAxe() const;
		bool		IsOneHandedMace() const;
		bool		IsTwoHandedSword() const;
		bool		IsTwoHandedAxe() const;
		bool		IsBow() const;
		bool		IsStaff() const;
		bool		IsCrossbow() const;


		// members
		Data					weaponData;				 // 168 - DNAM
		CriticalData			criticalData;			 // 1A0 - CRDT
		Unk1B8*					unk1B8;					 // 1B8
		BGSSoundDescriptorForm* attackSound;			 // 1C0 - SNAM
		BGSSoundDescriptorForm* attackSound2D;			 // 1C8 - XNAM
		BGSSoundDescriptorForm* attackLoopSound;		 // 1D0 - NAM7
		BGSSoundDescriptorForm* attackFailSound;		 // 1D8 - TNAM
		BGSSoundDescriptorForm* idleSound;				 // 1E0 - UNAM
		BGSSoundDescriptorForm* equipSound;				 // 1E8 - NAM9
		BGSSoundDescriptorForm* unequipSound;			 // 1F0 - NAM8
		BGSImpactDataSet*		impactDataSet;			 // 1F8
		TESObjectSTAT*			firstPersonModelObject;	 // 200 - WNAM
		TESObjectWEAP*			templateWeapon;			 // 208 - CNAM
		BSFixedString			embeddedNode;			 // 210
		SOUND_LEVEL				soundLevel;				 // 218 - VNAM
		UInt32					pad21C;					 // 21C
	};
	STATIC_ASSERT(sizeof(TESObjectWEAP) == 0x220);
}
