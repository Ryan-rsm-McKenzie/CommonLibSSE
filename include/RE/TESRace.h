#pragma once

#include "skse64/GameFormComponents.h"
#include "skse64/GameForms.h"

#include "RE/BGSBipedObjectForm.h"  // BGSBipedObjectForm


namespace RE
{
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
		enum { kTypeID = kFormType_Race };


		enum Flag : UInt32
		{
			kFlag_Unk000000000					= 0,
			kFlag_Playable						= 1 << 0,
			kFlag_FaceGenHead					= 1 << 1,
			kFlag_Child							= 1 << 2,
			kFlag_TiltFrontBack					= 1 << 3,
			kFlag_TiltLeftRight					= 1 << 4,
			kFlag_NoShadow						= 1 << 5,
			kFlag_Swims							= 1 << 6,
			kFlag_Flies							= 1 << 7,
			kFlag_Walks							= 1 << 8,
			kFlag_Immobile						= 1 << 9,
			kFlag_NotPushable					= 1 << 10,
			kFlag_NoCombatInWater				= 1 << 11,
			kFlag_NoRotatingToHeadTrack			= 1 << 12,
			kFlag_Unk00002000					= 1 << 13,
			kFlag_Unk00004000					= 1 << 14,
			kFlag_UseHeadTrackAnim				= 1 << 15,
			kFlag_SpellsAlignWithMagicNode		= 1 << 16,
			kFlag_UseWorldRaycasts				= 1 << 17,
			kFlag_AllowRagdollCollision			= 1 << 18,
			kFlag_Unk00080000					= 1 << 19,
			kFlag_CantOpenDoors					= 1 << 20,
			kFlag_AllowPCDialogue				= 1 << 21,
			kFlag_NoKnockdowns					= 1 << 22,
			kFlag_AllowPickpocket				= 1 << 23,
			kFlag_AlwaysUseProxyController		= 1 << 24,
			kFlag_Unk02000000					= 1 << 25,
			kFlag_OverlayHeadParts				= 1 << 26,
			kFlag_OverrideHeadParts				= 1 << 27,
			kFlag_Unk100000000					= 1 << 28,
			kFlag_AllowMultipleMembraneShaders	= 1 << 29,
			kFlag_CanDualWield					= 1 << 30,
			kFlag_AvoidsRoads					= (UInt32)1 << 31,
		};


		enum
		{
			kRace_NumSkillBonuses = 7
		};


		struct Data
		{
			struct SkillBonus
			{
				UInt8 skill;	// 0
				UInt8 bonus;	// 1
			};


			SkillBonus	skillBonus[kRace_NumSkillBonuses];	// 00
			UInt8		pad0E[2];							// 0E
			float		height[2];							// 10
			float		weight[2];							// 18
			Flag		raceFlags;							// 20 - not init'd
			float		health;								// 24
			float		magicka;							// 28
			float		stamina;							// 2C
			float		carryweight;						// 30
			float		mass;								// 34
			float		accelRate;							// 38
			float		deaccelRate;						// 3C
			UInt32		unk40;								// 40 - init'd to 1 - Size
			UInt32		unk44;								// 44 - init'd to FFFFFFFF - Head biped object
			UInt32		unk48;								// 48 - init'd to FFFFFFFF - Hair biped object
			UInt32		unk4C;								// 4C - not init'd
			float		injuredHealthPct;					// 50 - init'd to FFFFFFFF
			float		healthRegen;						// 54
			float		manaRegen;							// 58
			float		staminaRegen;						// 5C
			float		unarmedDamage;						// 60
			float		handReach;							// 64
			UInt32		unk68;								// 68 - init'd to FFFFFFFF - Body biped object
			float		aimAngleTolerance;					// 6C
			float		flightRadius;						// 70 - init'd to 0
			float		angleAcceleration;					// 74
			float		angleTolerance;						// 78
			UInt32		unk7C;								// 7C
			UInt32		unk80;								// 80
			UInt32		unk84;								// 84
			float		mountOffsetX;						// 88
			float		mountOffsetY;						// 8C
			float		unk90;								// 90
			float		unk94;								// 94
			float		unk98;								// 98
			float		unk9C;								// 9C
			float		unkA0;								// A0
			float		unkA4;								// A4
			float		unkA8;								// A8
		};
		STATIC_ASSERT(sizeof(Data) == 0xAC);


		struct CharGenData
		{
			struct TintOption
			{
				UInt32					unk00;			// 00
				TESTexture				texture;		// 08
				BGSColorForm*			defaultColor;	// 18
				tArray<BGSColorForm*>	colors;			// 20
				tArray<float>			alpha;			// 38
				tArray<UInt32>			unk50;			// 50
			};


			UInt32					presetFlags[4][8];	// 00
			UInt32					totalPresets[4];	// 80
			tArray<TintOption*>*	tintData;			// 90
			tArray<BGSTextureSet*>*	textureSet;			// 98
			BGSTextureSet*			defaultTexture;		// A0
			tArray<TESNPC*>*		presets;			// A8
			tArray<BGSColorForm*>*	colors;				// B0
			BGSColorForm*			defaultColor;		// B8
			tArray<BGSHeadPart*>*	headParts;			// C0
		};
		STATIC_ASSERT(sizeof(CharGenData) == 0xC8);


		// members
		TESModel				models[2];					// 098
		Data					data;						// 0E8
		BGSTextureModel			textureModel[2];			// 198
		BGSBehaviorGraphModel	behaviorGraph[2];			// 1E8
		BSFixedString			behaviorPath[2];			// 238
		BSFixedString			behaviorName[2];			// 248
		BGSVoiceType*			voiceTypes[2];				// 258
		BGSBodyPartData*		bodyPartData;				// 268
		TESForm*				decapitateArmor[2];			// 270
		UnkArray				unk280[2];					// 280
		void*					unk2B0[4];					// 2B0
		void*					attackAnimationArrayMap[2];	// 2D0 - AttackAnimationArrayMap
		BSFixedString			editorId;					// 2E0
		BGSMaterialType*		impactMaterial;				// 2E8
		BGSImpactDataSet*		meleeImpact;				// 2F0
		BGSArtObject*			decapitateBloodArt;			// 2F8
		BGSSoundDescriptorForm*	openCorpseSound;			// 300
		BGSSoundDescriptorForm*	closeCorpseSound;			// 308
		BSFixedString			bipedObjectNames[0x20];		// 310
		tArray<BGSEquipSlot*>	slotRestrictions;			// 410
		UInt32					unk428;						// 428
		BGSEquipSlot*			unarmedEquipSlot;			// 430
		TESRace*				morphRace;					// 438
		TESRace*				armorRace;					// 440
		UnkArray				unk448;						// 448
		UnkArray				unk460;						// 460
		UInt8					unk478[0x30];				// 478
		CharGenData*			chargenData[2];				// 4A8
	};
	STATIC_ASSERT(offsetof(TESRace, models) == 0x098);
}
