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


	struct ACTOR_BASE_DATA
	{
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
			kInvulnerable = (UInt32)1 << 31
		};


		enum class TEMPLATE_USE_FLAG : UInt16
		{
			kNone = 0,
			kTraits = 1 << 0,
			kStats = 1 << 1,
			kFactions = 1 << 2,
			kSpells = 1 << 3,
			kAIData = 1 << 4,
			kAIPackages = 1 << 5,
			kUnused = 1 << 6,
			kBaseData = 1 << 7,
			kInventory = 1 << 8,
			kScript = 1 << 9,
			kAIDefPackList = 1 << 10,
			kAttackData = 1 << 11,
			kKeywords = 1 << 12
		};


		// members
		Flag				actorBaseFlags;		// 00
		SInt16				magickaOffset;		// 04
		SInt16				staminaOffset;		// 06
		UInt16				level;				// 08
		UInt16				calcLevelMin;		// 0A
		UInt16				calcLevelMax;		// 0C
		UInt16				speedMult;			// 0E
		UInt16				baseDisposition;	// 10 - unused
		TEMPLATE_USE_FLAG	templateUseFlags;	// 12
		SInt16				healthOffset;		// 14
		SInt16				bleedoutOverride;	// 16
	};
	STATIC_ASSERT(sizeof(ACTOR_BASE_DATA) == 0x18);


	struct FACTION_RANK	// SNAM
	{
		TESFaction*	faction;	// 00
		SInt8		rank;		// 08
		UInt8		pad09;		// 09
		UInt16		pad0A;		// 0A
		UInt32		pad0C;		// 0C
	};
	STATIC_ASSERT(sizeof(FACTION_RANK) == 0x10);


	class TESActorBaseData : public BaseFormComponent	// ACBS
	{
	public:
		inline static const void* RTTI = RTTI_TESActorBaseData;


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

		bool	IsFemale() const;
		bool	IsPreset() const;
		bool	IsEssential() const;
		bool	Respawns() const;
		bool	HasAutoCalcStats() const;
		bool	IsUnique() const;
		bool	AffectsStealthMeter() const;
		bool	HasPCLevelMult() const;
		bool	UsesTemplate() const;
		bool	Protected() const;
		bool	IsSummonable() const;
		bool	Bleeds() const;
		bool	HasBleedoutOverride() const;
		bool	UsesOppositeGenderAnims() const;
		bool	IsSimpleActor() const;


		// members
		ACTOR_BASE_DATA			actorData;			// 08
		TESLevItem*				deathItem;			// 20 - INAM
		BGSVoiceType*			voiceType;			// 28 - VTCK
		TESForm*				baseTemplateForm;	// 30 - TPLT
		TESForm**				templateForms;		// 38
		BSTArray<FACTION_RANK>	factions;			// 40
	};
	STATIC_ASSERT(sizeof(TESActorBaseData) == 0x58);
}
