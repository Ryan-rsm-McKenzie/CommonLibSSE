#pragma once

#include "RE/A/ActorValues.h"
#include "RE/B/BGSKeywordForm.h"
#include "RE/B/BGSMenuDisplayObject.h"
#include "RE/B/BSFixedString.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTList.h"
#include "RE/E/EffectArchetypes.h"
#include "RE/F/FormTypes.h"
#include "RE/M/MagicSystem.h"
#include "RE/S/SoundLevels.h"
#include "RE/T/TESCondition.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"

namespace RE
{
	class EffectSetting :
		public TESForm,				  // 000
		public TESFullName,			  // 020
		public BGSMenuDisplayObject,  // 030
		public BGSKeywordForm		  // 040
	{
	public:
		inline static constexpr auto RTTI = RTTI_EffectSetting;

		using Archetype = EffectArchetypes::ArchetypeID;
		using FilterValidation_t = bool(EffectSetting*, void*);
		inline static constexpr auto FORMTYPE = FormType::MagicEffect;

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};

		struct EffectSettingData  // DATA
		{
		public:
			enum class Flag
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

			// members
			stl::enumeration<Flag, std::uint32_t> flags;				  // 00
			float								  baseCost;				  // 04
			TESForm*							  associatedForm;		  // 08
			ActorValue							  associatedSkill;		  // 10
			ActorValue							  resistVariable;		  // 14
			std::int16_t						  numCounterEffects;	  // 18
			std::uint16_t						  pad1A;				  // 1A
			std::uint32_t						  pad1C;				  // 1C
			TESObjectLIGH*						  light;				  // 20
			float								  taperWeight;			  // 28
			std::uint32_t						  pad2C;				  // 2C
			TESEffectShader*					  effectShader;			  // 30
			TESEffectShader*					  enchantShader;		  // 38
			std::int32_t						  minimumSkill;			  // 40
			std::int32_t						  spellmakingArea;		  // 44
			float								  spellmakingChargeTime;  // 48
			float								  taperCurve;			  // 4C
			float								  taperDuration;		  // 50
			float								  secondAVWeight;		  // 54
			Archetype							  archetype;			  // 58
			ActorValue							  primaryAV;			  // 5C
			BGSProjectile*						  projectileBase;		  // 60
			BGSExplosion*						  explosion;			  // 68
			MagicSystem::CastingType			  castingType;			  // 70
			MagicSystem::Delivery				  delivery;				  // 74
			ActorValue							  secondaryAV;			  // 78
			BGSArtObject*						  castingArt;			  // 80
			BGSArtObject*						  hitEffectArt;			  // 88
			BGSImpactDataSet*					  impactDataSet;		  // 90
			float								  skillUsageMult;		  // 98
			std::uint32_t						  pad9C;				  // 9C
			BGSDualCastData*					  dualCastData;			  // A0
			float								  dualCastScale;		  // A8
			std::uint32_t						  padAC;				  // AC
			BGSArtObject*						  enchantEffectArt;		  // B0
			BGSReferenceEffect*					  hitVisuals;			  // B8
			BGSReferenceEffect*					  enchantVisuals;		  // C0
			SpellItem*							  equipAbility;			  // C8
			TESImageSpaceModifier*				  imageSpaceMod;		  // D0
			BGSPerk*							  perk;					  // D8
			SOUND_LEVEL							  castingSoundLevel;	  // E0
			float								  aiScore;				  // E4
			float								  aiDelayTimer;			  // E8
			std::uint32_t						  padEC;				  // EC
		};
		static_assert(sizeof(EffectSettingData) == 0xF0);

		struct SoundPair  // SNDD
		{
		public:
			// members
			MagicSystem::SoundID	id;		// 00
			std::uint32_t			pad04;	// 04
			BGSSoundDescriptorForm* sound;	// 08
		};
		static_assert(sizeof(SoundPair) == 0x10);

		virtual ~EffectSetting();  // 00

		// override (TESForm)
		virtual void		ClearData() override;				 // 05
		virtual bool		Load(TESFile* a_mod) override;		 // 06
		virtual void		InitItemImpl() override;			 // 13
		virtual void		Copy(TESForm* a_srcForm) override;	 // 2F
		virtual const char* GetObjectTypeName() const override;	 // 39

		// override (BGSKeywordForm)
		virtual bool HasKeyword(const BGSKeyword* a_keyword) const override;  // 04

		[[nodiscard]] constexpr Archetype	 GetArchetype() const noexcept { return data.archetype; }
		[[nodiscard]] constexpr ActorValue	 GetMagickSkill() const noexcept { return data.associatedSkill; }
		[[nodiscard]] constexpr std::int32_t GetMinimumSkillLevel() const noexcept { return data.minimumSkill; }
		[[nodiscard]] constexpr bool		 HasArchetype(Archetype a_type) const noexcept { return data.archetype == a_type; }

		// members
		FilterValidation_t*			 filterValidationFunction;	 // 058
		void*						 filterValidationItem;		 // 060
		EffectSettingData			 data;						 // 068 - DATA
		BSSimpleList<EffectSetting*> counterEffects;			 // 158 - ESCE
		BSTArray<SoundPair>			 effectSounds;				 // 168 - SNDD
		BSFixedString				 magicItemDescription;		 // 180 - DNAM
		std::int32_t				 effectLoadedCount;			 // 188
		std::int32_t				 associatedItemLoadedCount;	 // 18C
		TESCondition				 conditions;				 // 190
	};
	static_assert(sizeof(EffectSetting) == 0x198);
}
