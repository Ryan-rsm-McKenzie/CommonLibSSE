#pragma once

#include "RE/BGSKeywordForm.h"  // BGSKeywordForm
#include "RE/BSTArray.h"  // BSTArray
#include "RE/TESBoundObject.h"  // TESBoundObject
#include "RE/TESFullName.h"  // TESFullName

#include "Utility.h"  // MAKE_BITWISE_OPERATORS


namespace RE
{
	class Character;
	class EffectSetting;
	struct EffectItem;


	class MagicItem :
		public TESBoundObject,
		public TESFullName,
		public BGSKeywordForm
	{
	public:
		enum class Type : UInt32
		{
			kSpell = 0,
			kDisease,
			kPower,
			kLesserPower,
			kAbility,
			kPoison,
			kEnchantment,
			kArchemy,
			kIngredient,
			kUnk09,
			kUnk10,
			kVoicePower,
			kStaffEnchantment,
			kScroll
		};

		MAKE_BITWISE_OPERATORS(Type);


		enum class CastType : UInt32
		{
			kConstant = 0,
			kFireAndForget,
			kConcentration
		};

		MAKE_BITWISE_OPERATORS(CastType);


		enum class TargetType : UInt32
		{
			kSelf = 0,
			kContact,
			kAimed,
			kTargetActor,
			kTargetLocation,
		};

		MAKE_BITWISE_OPERATORS(TargetType);


		class PreloadableVisitor
		{
		public:
			virtual ~PreloadableVisitor();
			virtual void Visit(void) = 0;
		};


		// override (TESBoundObject)
		virtual bool		IsMagicItem() const;						// 29

		// add
		virtual Type		GetMagicType() const = 0;					// 53
		virtual void		SetCastType(CastType a_castingType);		// 54 - { return; }
		virtual CastType	GetCastType() const = 0;					// 55
		virtual void		SetTargetType(TargetType a_deliveryType);	// 56 - { return; }
		virtual TargetType	GetTargetType() const = 0;					// 57
		virtual void		Unk_58(void);								// 58
		virtual float		GetCastDuration() const;					// 59 - { return 0.0f; }
		virtual float		GetRange() const;							// 5A - { return 0.0f; }
		virtual void		Unk_5B(void);								// 5B
		virtual void		Unk_5C(void);								// 5C
		virtual void		Unk_5D(void);								// 5D
		virtual void		Unk_5E(void);								// 5E
		virtual void		Unk_5F(void);								// 5F
		virtual void		Unk_60(void);								// 60
		virtual bool		IsPoison() const;							// 61 - { return GetMagicType() == kPoison } offensive or defensive ?
		virtual void		Unk_62(void);								// 62
		virtual void		Unk_63(void);								// 63
		virtual float		GetChargeTime() const;						// 64 - { return 0.0f; }
		virtual void		Unk_65(void);								// 65
		virtual UInt32		GetActorValueType() const;					// 66 - { return -1; } used for Actor::AdvanceSkill()
		virtual void		Unk_67(void);								// 67
		virtual UInt32		GetDataSigniture() const = 0;				// 68
		virtual void		CopyData(MagicItem* a_src) = 0;				// 69
		virtual void		Unk_6A(void);								// 6A
		virtual void		Unk_6B(void);								// 6B
		virtual void		Unk_6C(void);								// 6C
		virtual void		Unk_6D(void);								// 6D
		virtual UInt32		GetDataSize() const = 0;					// 6E
		virtual void		Unk_6F(void);								// 6F

		EffectItem*			GetCostliestEffectItem(int a_arg1, bool a_arg2);
		float				GetEffectiveMagickaCost(Character* a_caster);


		// members
		BSTArray<EffectItem*>	effects;		// 58
		UInt32					hostile;		// 70
		EffectSetting*			effectTemplate;	// 78
		UInt32					unk80;			// 80
		void*					unk88;			// 88
	};
	STATIC_ASSERT(sizeof(MagicItem) == 0x90);
}
