#pragma once

#include "RE/BaseFormComponent.h"
#include "RE/BSTArray.h"


namespace RE
{
	class BGSVoiceType;
	class TESFaction;
	class TESForm;
	class TESLevItem;
	class TESNPC;


	class TESActorBaseData : public BaseFormComponent	// ACBS
	{
	public:
		inline static const void* RTTI = RTTI_TESActorBaseData;


		enum class Flag : UInt32
		{
			kNone = 0,
			kFemale = 1 << 0,
			kEssential = 1 << 1,
			kIsChargenFacePreset = 1 << 2,
			kRespawn = 1 << 3,
			kAutoCalcStats = 1 << 4,
			kUnique = 1 << 5,
			kDoesntAffectStealthMeter = 1 << 6,
			kPCLevelMult = 1 << 7,
			kUsesTemplate = 1 << 8,
			kProtected = 1 << 11,
			kSummonable = 1 << 14,
			kDoesntBleed = 1 << 16,
			kBleedoutOverride = 1 << 18,
			kOppositeGenderanims = 1 << 19,
			kSimpleActor = 1 << 20,
			kLoopedScript = 1 << 21,	// ?
			kLoopedAudio = 1 << 28,		// ?
			kIsGhost = 1 << 29,
			kInvulnerable = (UInt32)(1 << 31)
		};


		enum class TemplateFlag : UInt16
		{
			kNone = 0,
			kUseTraits = 1 << 0,
			kUseStats = 1 << 1,
			kUseFactions = 1 << 2,
			kUseSpellList = 1 << 3,
			kUseAIData = 1 << 4,
			kUseAIPackages = 1 << 5,
			kUseModelAnimation = 1 << 6,	// ?
			kUseBaseData = 1 << 7,
			kUseInventory = 1 << 8,
			kUseScript = 1 << 9,
			kUseDefPackageList = 1 << 10,
			kUseAttackData = 1 << 11,
			kUseKeywords = 1 << 12,
		};


		struct FactionInfo	// SNAM
		{
			TESFaction*	faction;	// 00
			SInt8		rank;		// 08
			UInt8		pad09;		// 09
			UInt16		pad0A;		// 0A
			UInt32		pad0C;		// 0C
		};
		STATIC_ASSERT(sizeof(FactionInfo) == 0x10);


		virtual ~TESActorBaseData();

		// override (BaseFormComponent)
		virtual void			InitializeDataComponent() override;					// 01
		virtual void			ClearDataComponent() override;						// 02
		virtual void			CopyComponent(BaseFormComponent* a_rhs) override;	// 03

		// add
		virtual void			Unk_04(void);										// 04 - { return; }
		virtual bool			IsGhost();											// 05 - { return (flags >> 29) & 1; }
		virtual bool			IsInvulnerable();									// 06 - { test flags, 80000000h; }
		virtual void			Unk_07(void);										// 07 - { return 1; }
		virtual BGSVoiceType*	GetVoiceType(void);									// 08 - { return voice; }

		bool			IsFemale() const;
		bool			IsPreset() const;
		bool			IsEssential() const;
		bool			Respawns() const;
		bool			HasAutoCalcStats() const;
		bool			IsUnique() const;
		bool			AffectsStealthMeter() const;
		bool			HasPCLevelMult() const;
		bool			UsesTemplate() const;
		bool			Protected() const;
		bool			IsSummonable() const;
		bool			Bleeds() const;
		bool			HasBleedoutOverride() const;
		bool			UsesOppositeGenderAnims() const;
		bool			IsSimpleActor() const;


		// members
		Flag					flags;				// 08
		UInt16					magickaOffset;		// 0C
		UInt16					staminaOffset;		// 0E
		UInt16					level;				// 10
		UInt16					calcMinLevel;		// 12
		UInt16					calcMaxLevel;		// 14
		UInt16					speedMultiplier;	// 16
		UInt16					dispositionBase;	// 18 - unused
		TemplateFlag			templateFlags;		// 1A
		UInt16					healthOffset;		// 1C
		UInt16					bleedoutOverride;	// 1E
		TESLevItem*				deathItem;			// 20 - INAM
		BGSVoiceType*			voice;				// 28 - VTCK
		TESNPC*					npcTemplate;		// 30 - TPLT
		TESForm*				unk38;				// 38
		BSTArray<FactionInfo>	factions;			// 40
	};
	STATIC_ASSERT(sizeof(TESActorBaseData) == 0x58);
}
