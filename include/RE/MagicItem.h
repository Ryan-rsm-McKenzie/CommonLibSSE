#pragma once

#include "skse64/GameRTTI.h"  // RTTI_MagicItem

#include "RE/ActorValues.h"  // ActorValue
#include "RE/BGSKeywordForm.h"  // BGSKeywordForm
#include "RE/BSTArray.h"  // BSTArray
#include "RE/TESBoundObject.h"  // TESBoundObject
#include "RE/TESFullName.h"  // TESFullName


namespace RE
{
	class Actor;
	class Character;
	class EffectSetting;
	struct Effect;


	class MagicItem :
		public TESBoundObject,	// 00
		public TESFullName,		// 30
		public BGSKeywordForm	// 40
	{
	public:
		inline static const void* RTTI = RTTI_MagicItem;


		enum class MagicType : UInt32
		{
			kSpell = 0,
			kDisease = 1,
			kPower = 2,
			kLesserPower = 3,
			kAbility = 4,
			kPoison = 5,
			kEnchantment = 6,
			kAlchemy = 7,
			kIngredient = 8,
			kUnknown9 = 9,
			kAddiction = 10,
			kVoice = 11,
			kStaffEnchantment = 12,
			kScroll = 13
		};


		enum class CastType : UInt32
		{
			kConstantEffect = 0,
			kFireAndForget = 1,
			kConcentration = 2,
			kScroll = 3
		};


		enum class TargetType : UInt32
		{
			kSelf = 0,
			kTouch = 1,
			kAimed = 2,
			kTargetActor = 3,
			kTargetLocation = 4
		};


		class PreloadableVisitor
		{
		public:
			// add
			virtual void	Unk_00(void) = 0;	// 00
			virtual void	Unk_01(void) = 0;	// 01
		};
		STATIC_ASSERT(sizeof(PreloadableVisitor) == 0x8);


		virtual ~MagicItem();													// 00

		// override (TESBoundObject)
		virtual void		InitDefaults() override;							// 04 - { TESForm::InitDefaults(); }
		virtual bool		LoadForm(TESFile* a_mod) override;					// 06
		virtual void		InitItem() override;								// 13
		virtual bool		IsMagicItem() const override;						// 29 - { return true; }
		virtual void		CopyFrom(TESForm* a_srcForm) override;				// 2F
		virtual bool		IsAutoCalc() const override;						// 3E - { return (GetData().unk4 & 1) == 0; }

		// add
		virtual MagicType	GetMagicType() const = 0;							// 53
		virtual void		SetCastType(CastType a_castType);					// 54 - { return; }
		virtual CastType	GetCastType() const = 0;							// 55
		virtual void		SetTargetType(TargetType a_targetType);				// 56 - { return; }
		virtual TargetType	GetTargetType() const = 0;							// 57
		virtual void		Unk_58(void);										// 58 - { return 1; }
		virtual float		GetCastDuration() const;							// 59 - { return 0.0; }
		virtual float		GetRange() const;									// 5A - { return 0.0; }
		virtual bool		IgnoresResistance();								// 5B - { return false; }
		virtual bool		AreaAffectIgnoresLOS();								// 5C - { return false; }
		virtual bool		IsFoodItem() const;									// 5D - { return false; }
		virtual bool		DisallowsAbsorbReflection();						// 5E - { return false; }
		virtual bool		AllowsDualCastModification();						// 5F - { return false; }
		virtual void		Unk_60(void);										// 60 - { return 0; }
		virtual bool		IsPoison() const;									// 61 - { return GetMagicType() == MagicType::kPoison; }
		virtual bool		IsHealingItem() const;								// 62 - { return false; }
		virtual void		GetSkillCost(float& a_cost, Actor* a_actor) const;	// 63 - { return; }
		virtual float		GetChargeTime() const;								// 64 - { return 0.0; }
		virtual void		Unk_65(void);										// 65 - { return 0; }
		virtual ActorValue	GetActorValueType() const;							// 66 - { return ActorValue::kNone; } used for Actor::AdvanceSkill()
		virtual void		Unk_67(void);										// 67 - { return 0; } - UsesAllEquipSlotParents()?
		virtual UInt32		GetDataSigniture() const = 0;						// 68
		virtual void		CopyData(MagicItem* a_src) = 0;						// 69
		virtual void		LoadData(TESFile* a_mod, UInt32 a_signature);		// 6A - { return; }
		virtual void		Unk_6B(void);										// 6B - { return; }
		virtual void*		GetData() = 0;										// 6C - actually returns a base data struct that all derived data structs inherit from
		virtual void*		GetData2() = 0;										// 6D
		virtual UInt32		GetDataSize() const = 0;							// 6E
		virtual void		LoadData(TESFile* a_mod) = 0;						// 6F
		virtual void		ByteSwapData() = 0;									// 70

		Effect*	GetCostliestEffectItem(UInt32 a_arg1 = 5, bool a_arg2 = false);
		float	GetEffectiveMagickaCost(Character* a_caster);
		float	CalculateTotalGoldValue(Actor* a_caster = 0) const;


		// members
		BSTArray<Effect*>	effects;		// 58
		UInt32				hostile;		// 70
		UInt32				pad74;			// 74
		EffectSetting*		effectTemplate;	// 78
		UInt32				unk80;			// 80
		UInt32				unk84;			// 84
		void*				unk88;			// 88
	};
	STATIC_ASSERT(sizeof(MagicItem) == 0x90);
}
