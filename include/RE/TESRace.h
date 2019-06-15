#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESRace

#include "RE/ActorValues.h"  // ActorValue8
#include "RE/BGSAttackDataForm.h"  // BGSAttackDataForm
#include "RE/BGSBehaviorGraphModel.h"  // BGSBehaviorGraphModel
#include "RE/BGSBipedObjectForm.h"  // BGSBipedObjectForm
#include "RE/BGSKeywordForm.h"  // BGSKeywordForm
#include "RE/BGSSkinForm.h"  // BGSSkinForm
#include "RE/BGSTextureModel.h"  // BGSTextureModel
#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/BSTArray.h"  // BSTArray
#include "RE/FileHash.h"  // FileHash
#include "RE/FormTypes.h"  // FormType, BGSVoiceType, BGSSoundDescriptorForm, BGSColorForm
#include "RE/TESDescription.h"  // TESDescription
#include "RE/TESForm.h"  // TESForm
#include "RE/TESFullName.h"  // TESFullName
#include "RE/TESModel.h"  // TESModel
#include "RE/TESSpellList.h"  // TESSpellList
#include "RE/TESTexture.h"  // TESTexture


namespace RE
{
	class AttackAnimationArrayMap;


	class TESRace :
		public TESForm,				// 000
		public TESFullName,			// 020
		public TESDescription,		// 030
		public TESSpellList,		// 040
		public BGSSkinForm,			// 050
		public BGSBipedObjectForm,	// 060
		public BGSKeywordForm,		// 070
		public BGSAttackDataForm	// 088
	{
	public:
		inline static const void* RTTI = RTTI_TESRace;


		enum { kTypeID = FormType::Race };


		enum
		{
			kNumBipedObjectNames = 32
		};


		enum class EquipmentFlag : UInt32
		{
			kNone = 0,
			kHandToHandMelee = 1 << 0,
			kOneHandSword = 1 << 1,
			kOneHandDagger = 1 << 2,
			kOneHandAxe = 1 << 3,
			kOneHandMace = 1 << 4,
			kTwoHandSword = 1 << 5,
			kTwoHandAxe = 1 << 6,
			kBow = 1 << 7,
			kStaff = 1 << 8,
			kSpell = 1 << 9,
			kShield = 1 << 10,
			kTorch = 1 << 11,
			kCrossbow = 1 << 12
		};


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12,
				kCritter = 1 << 19	// ?
			};
		};


		struct MovementTypes
		{
			enum
			{
				kWalk = 0,
				kRun,
				kSwim,
				kFly,
				kSneak,
				kSprint,
				kTotal
			};
		};


		struct Sexes
		{
			enum
			{
				kMale = 0,
				kFemale,
				kTotal
			};
		};


		struct Data
		{
			enum
			{
				kNumSkillBoosts = 7
			};


			enum class Flag : UInt32
			{
				kNone = 0,
				kPlayable = 1 << 0,
				kFaceGenHead = 1 << 1,
				kChild = 1 << 2,
				kTiltFrontBack = 1 << 3,
				kTiltLeftRight = 1 << 4,
				kNoShadow = 1 << 5,
				kSwims = 1 << 6,
				kFlies = 1 << 7,
				kWalks = 1 << 8,
				kImmobile = 1 << 9,
				kNotPushable = 1 << 10,
				kNoCombatInWater = 1 << 11,
				kNoRotatingToHeadTrack = 1 << 12,
				kDontShowBloodSpray = 1 << 13,
				kDontShowBloodDecal = 1 << 14,
				kUseHeadTrackAnims = 1 << 15,
				kSpellsAlignWithMagicNode = 1 << 16,
				kUseWorldRaycastsForFootIK = 1 << 17,
				kAllowRagdollCollision = 1 << 18,
				kRegenHPInCombat = 1 << 19,
				kCantOpenDoors = 1 << 20,
				kAllowPCDialogue = 1 << 21,
				kNoKnockdowns = 1 << 22,
				kAllowPickpocket = 1 << 23,
				kAlwaysUseProxyController = 1 << 24,
				kDontShowWeaponBlood = 1 << 25,
				kOverlayHeadPartList = 1 << 26,
				kOverrideHeadPartList = 1 << 27,
				kCanPickupItems = 1 << 28,
				kAllowMultipleMembraneShaders = 1 << 29,
				kCanDualWield = 1 << 30,
				kAvoidsRoads = (UInt32)1 << 31,
			};


			enum class Size : UInt32
			{
				kSmall = 0,
				kMedium = 1,
				kLarge = 2,
				kExtraLarge = 3
			};


			enum class Flag2 : UInt32
			{
				kNone = 0,
				kUseAdvancedAvoidance = 1 << 0,
				kNonHostile = 1 << 1,
				kAllowMountedCombat = 1 << 4
			};


			struct SkillBoost
			{
				ActorValue8	skill;	// 0
				UInt8		bonus;	// 1
			};
			STATIC_ASSERT(sizeof(SkillBoost) == 0x2);


			struct MountData
			{
				float	offsetX;	// 00
				float	offsetY;	// 04
				float	unk08;		// 08
				float	unk0C;		// 0C
				float	unk19;		// 10
				float	unk14;		// 14
				float	unk18;		// 18
				float	unk1C;		// 1C
				float	unk20;		// 20
			};
			STATIC_ASSERT(sizeof(MountData) == 0x24);


			SkillBoost	skillBoosts[kNumSkillBoosts];	// 00
			UInt16		unk0E;							// 0E
			float		maleHeight;						// 10
			float		femaleHeight;					// 14
			float		maleWeight;						// 18
			float		femaleWeight;					// 1C
			Flag		flags;							// 20
			float		startingHealth;					// 24
			float		startingMagicka;				// 28
			float		startingStamina;				// 2C
			float		baseCarryWeight;				// 30
			float		baseMass;						// 34
			float		accelerationRate;				// 38
			float		decelerationRate;				// 3C
			Size		size;							// 40
			BipedObject	headBipedObject;				// 44
			BipedObject	hairBipedObject;				// 48
			float		injuredHealthPct;				// 4C
			BipedObject	shieldBipedObject;				// 50
			float		healthRegen;					// 54
			float		magickaRegen;					// 58
			float		staminaRegen;					// 5C
			float		unarmedDamage;					// 60
			float		unarmedReach;					// 64
			BipedObject	bodyBipedObject;				// 68
			float		aimAngleTolerance;				// 6C
			float		flightRadius;					// 70
			float		angularAccelerationRate;		// 74
			float		anuglarTolerance;				// 78
			Flag2		flags2;							// 7C
			MountData	mountData;						// 88
		};
		STATIC_ASSERT(sizeof(Data) == 0xA4);


		struct FaceGen
		{
			float	mainClamp;	// 0 - PNAM
			float	faceClamp;	// 4 - UNAM
		};
		STATIC_ASSERT(sizeof(FaceGen) == 0x8);


		struct HeadData
		{
			enum
			{
				kNose = 0,
				kBrows,
				kEyes,
				kLips,

				kNumVariants
			};


			struct Morph
			{
				UInt32	morphFlags;	// 00
				UInt32	unk04;		// 04
				UInt32	unk08;		// 08
				UInt32	unk0C;		// 0C
				UInt32	unk10;		// 10
				UInt32	unk14;		// 14
				UInt32	unk18;		// 18
				UInt32	unk1C;		// 1C
			};
			STATIC_ASSERT(sizeof(Morph) == 0x20);


			struct TintAsset
			{
				struct TintLayer
				{
					enum class SkinTone : UInt8
					{
						kNone = 0,
						kLipColor = 1,
						kCheekColor = 2,
						kEyeliner = 3,
						kEyeSocketUpper = 4,
						kEyeSocketLower = 5,
						kSkinTone = 6,
						kPaint = 7,
						kLaughLines = 8,
						kCheekColorLower = 9,
						kNose = 10,
						kChin = 11,
						kNeck = 12,
						kForehead = 13,
						kDirt = 14,
					};


					UInt16			index;			// 00 - TINI
					SkinTone		skinTone;		// 02 - TINP
					UInt8			pad03;			// 03
					UInt32			pad04;			// 04
					TESTexture		file;			// 08 - TINT
					BGSColorForm*	presetDefault;	// 18 - TIND
				};
				STATIC_ASSERT(sizeof(TintLayer) == 0x20);


				struct Presets
				{
					BSTArray<BGSColorForm*>	colors;			// 00 - TINC
					BSTArray<float>			defaultValues;	// 18 - TINV
					BSTArray<UInt16>		indices;		// 30 - TIRS
				};
				STATIC_ASSERT(sizeof(Presets) == 0x48);


				TintLayer	texture;	// 00
				Presets		presets;	// 20
			};
			STATIC_ASSERT(sizeof(TintAsset) == 0x68);


			Morph						availableMorphs[kNumVariants];	// 00
			UInt32						numFlagsSet[kNumVariants];		// 80
			BSTArray<TintAsset*>*		tintMasks;						// 90
			BSTArray<BGSTextureSet*>*	faceDetailsTextureSetList;		// 98 - FTSM / FTSF
			BGSTextureSet*				defaultFaceTexture;				// A0 - DFTM / DFTF
			BSTArray<TESNPC*>*			racePresets;					// A8 - RPRM / RPRF
			BSTArray<BGSColorForm*>*	availableHairColors;			// B0 - AHCM / AHCF
			BGSColorForm*				defaultHairColor;				// B8
			BSTArray<BGSHeadPart*>*		headParts;						// C0 - HEAD
		};
		STATIC_ASSERT(sizeof(HeadData) == 0xC8);


		struct BodyData
		{
			enum
			{
				kBodyTexture,
				kNumParts
			};


			BGSTextureModel	parts[Sexes::kTotal][kNumParts];	// 00
		};
		STATIC_ASSERT(sizeof(BodyData) == 0x50);


		struct UnkData
		{
			FileHash**	unkHashes;			// 00
			UInt32		Unk1_NumUnkHashes;	// 08
			UInt32		Unk1_Unk0C;			// 0C - TESModel::unk24
			UInt32		Unk2_NumUnkHashes;	// 10
			UInt32		Unk2_Unk14;			// 14 - TESModel::unk24
		};
		STATIC_ASSERT(sizeof(UnkData) == 0x18);


		virtual ~TESRace();										// 00

		// override (TESForm)
		virtual bool		LoadForm(TESFile* a_mod) override;	// 06
		virtual void		InitItem() override;				// 13
		virtual bool		IsPlayable() override;				// 19
		virtual const char*	GetName();							// 32
		virtual bool		SetName(const char* a_str);			// 33

		bool				AllowsPickpocket() const;


		// members
		TESModel					skeletalModels[Sexes::kTotal];					// 098 - ANAM
		Data						data;											// 0E8
		FaceGen						faceGen;										// 18C
		UInt32						unk194;											// 194 - TESModel::unk24
		BodyData					bodyData;										// 198
		BGSBehaviorGraphModel		behaviourGraphs[Sexes::kTotal];					// 1E8
		BSFixedString				behaviorPaths[Sexes::kTotal];					// 238
		BSFixedString				behaviorNames[Sexes::kTotal];					// 248
		BGSVoiceType*				voiceTypes[Sexes::kTotal];						// 258 - VTCK
		BGSBodyPartData*			bodyPartData;									// 268 - GNAM
		TESObjectARMO*				decapitateArmors[Sexes::kTotal];				// 270 - DNAM
		UnkData						unk280;											// 280
		UnkData						unk298;											// 298
		UInt64						unk2B0;											// 2B0
		UInt64						unk2B8;											// 2B8
		UInt64						unk2C0;											// 2C0
		UInt64						unk2C8;											// 2C8
		AttackAnimationArrayMap*	attackAnimationArrayMap[Sexes::kTotal];			// 2D0
		BSFixedString				editorID;										// 2E0 - EDID
		BGSMaterialType*			materialType;									// 2E8 - NAM4
		BGSImpactDataSet*			impactDataSet;									// 2F0 - NAM5
		BGSArtObject*				decapitationFX;									// 2F8 - NAM7
		BGSSoundDescriptorForm*		openLootSound;									// 300 - ONAM
		BGSSoundDescriptorForm*		closeLootSound;									// 308 - LNAM
		BSFixedString				bipedObjectNames[kNumBipedObjectNames];			// 310 - NAME
		BSTArray<BGSEquipSlot*>		equipSlots;										// 410 - QNAM
		EquipmentFlag				equipmentFlags;									// 428 - VNAM - bits 13+ are always set
		UInt32						unk42C;											// 42C - TESModel::unk24
		BGSEquipSlot*				unarmedEquipSlot;								// 430 - UNES
		TESRace*					morphRace;										// 438 - NAM8
		TESRace*					armorRace;										// 440 - RNAM
		UnkData						unk448;											// 448
		BSTArray<BSFixedString>		phenomeTargetNames;								// 460 - PHTN
		BGSMovementType*			baseMovementDefaults[MovementTypes::kTotal];	// 478 - WKMV / RNMV / WMMV / FLMV / SNMV / SPMV
		HeadData*					headData[Sexes::kTotal];						// 4A8
	};
	STATIC_ASSERT(sizeof(TESRace) == 0x4B8);
}
