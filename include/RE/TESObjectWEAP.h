#pragma once

#include "skse64/GameFormComponents.h"  // TESFullName, TESModelTextureSwap, TESIcon, TESEnchantableForm, TESValueForm, TESWeightForm, TESAttackDamageForm, BGSDestructibleObjectForm, BGSEquipType, BGSPreloadable, BGSMessageIcon, BGSPickupPutdownSounds, BGSBlockBashData, TESDescription

#include "RE/BGSKeywordForm.h"  // BGSKeywordForm
#include "RE/TESBoundObject.h"  // TESBoundObject


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
		enum { kTypeID = FormType::Weapon };


		struct GameData
		{
			enum class Type : UInt8
			{
				kHandToHandMelee = 0,
				kOneHandSword,
				kOneHandDagger,
				kOneHandAxe,
				kOneHandMace,
				kTwoHandSword,
				kTwoHandAxe,
				kBow,
				kStaff,
				kCrossBow,
				kH2H,
				k1HS,
				k1HD,
				k1HA,
				k1HM,
				k2HS,
				k2HA,
				kBow2,
				kStaff2,
				kCBow
			};


			enum Flags1 : UInt16
			{
				kPlayerOnly = 1 << 0,
				kNPCUseAmmo = 1 << 1,
				kNoJamAfterReload = 1 << 2,
				kMinorCrime = 1 << 4,
				kNotUsedInNormalCombat = 1 << 6,
				kUnknown1 = 1 << 8,
				kLongBursts = 1 << 11,
				kNonHostile = 1 << 12,
				kBoundWeapon = 1 << 13,
			};


			enum Flags2 : UInt8
			{
				kHidebackpack = 1 << 0,
				kAutomatic = 1 << 1,
				kCantDrop = 1 << 3,
				kEmbeddedWeapon = 1 << 5,
				kUnknown2 = 1 << 6,
				kNotPlayable = (UInt8)(1 << 7)
			};


			void*	unk00;			// 00
			float	speed;			// 08
			float	reach;			// 0C
			float	minRange;		// 10 - init'd to 500
			float	maxRange;		// 14 - init'd to 2000
			float	animationMult;	// 18
			float	unk18;			// 1C
			float	stagger;		// 20 - init'd to 1
			UInt32	unk24;			// 24
			UInt32	skill;			// 28 - init'd to FFFFFFFF
			UInt32	resist;			// 2C - init'd to FFFFFFFF
			Flags1	flags1;			// 30
			UInt8	vatsChance;		// 32 - init'd to 5
			UInt8	unk33;			// 33 - init'd to FF
			UInt8	unk34;			// 34
			Type	type;			// 35
			Flags2	flags2;			// 36
			UInt8	unk37;			// 37
		};
		STATIC_ASSERT(sizeof(GameData) == 0x38);


		struct CritData
		{
			float		critMult;		// 00 - init'd to 1
			UInt32		pad04;			// 04
			SpellItem*	critEffect;		// 08
			UInt16		critDamage;		// 10
			UInt8		effectOnDeath;	// 12 - init'd to 1
			UInt8		pad13[5];		// 13
		};
		STATIC_ASSERT(sizeof(CritData) == 0x18);


		float			speed();
		float			reach();
		float			stagger();
		float			minRange();
		float			maxRange();
		GameData::Type	type();
		UInt16			critDamage();
		void			GetNodeName(char* a_dstBuff);


		// members
		GameData				gameData;			// 168
		CritData				critData;			// 1A0
		TESForm*				scopeEffect;		// 1B8
		BGSSoundDescriptorForm*	attackSound;		// 1C0
		BGSSoundDescriptorForm*	attackSound2D;		// 1C8
		BGSSoundDescriptorForm*	attackLoopSound;	// 1D0
		BGSSoundDescriptorForm*	attackFailSound;	// 1D8
		BGSSoundDescriptorForm*	idleSound;			// 1E0
		BGSSoundDescriptorForm*	equipSound;			// 1E8
		BGSSoundDescriptorForm*	unequipSound;		// 1F0
		BGSImpactDataSet*		impactDataSet;		// 1F8
		TESObjectSTAT*			model;				// 200
		TESObjectWEAP*			templateForm;		// 208 - Non-weapon templates don't make sense here and would probably crash anyway so assume it
		BSFixedString			embeddedNode;		// 210
		UInt32					unk218;				// 218
		UInt32					pad21C;				// 21C
	};
	STATIC_ASSERT(sizeof(TESObjectWEAP) == 0x220);
}
