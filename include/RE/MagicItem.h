#pragma once

#include "RE/ActorValues.h"
#include "RE/BGSKeywordForm.h"
#include "RE/BSTArray.h"
#include "RE/BSTSmartPointer.h"
#include "RE/MagicSystem.h"
#include "RE/TESBoundObject.h"
#include "RE/TESFullName.h"


namespace RE
{
	class Actor;
	class Character;
	class EffectSetting;
	class QueuedFile;
	class TESModel;
	class TESObjectWEAP;
	struct Effect;


	class MagicItem :
		public TESBoundObject,	// 00
		public TESFullName,		// 30
		public BGSKeywordForm	// 40
	{
	public:
		inline static const void* RTTI = RTTI_MagicItem;


		class PreloadableVisitor
		{
		public:
			// add
			virtual void	VisitModel(TESModel* a_model) = 0;			// 00
			virtual void	VisitWeapon(TESObjectWEAP* a_weapon) = 0;	// 01
		};
		STATIC_ASSERT(sizeof(PreloadableVisitor) == 0x8);


		virtual ~MagicItem();																	// 00

		// override (TESBoundObject)
		virtual void						InitializeData() override;							// 04 - { TESForm::InitDefaults(); }
		virtual bool						Load(TESFile* a_mod) override;						// 06
		virtual void						InitItemImpl() override;							// 13
		virtual bool						IsMagicItem() const override;						// 29 - { return true; }
		virtual void						Copy(TESForm* a_srcForm) override;					// 2F
		virtual bool						IsAutoCalc() const override;						// 3E - { return (GetData().flags & 1) == 0; }

		// add
		virtual MagicSystem::SpellType		GetSpellType() const = 0;							// 53
		virtual void						SetCastingType(MagicSystem::CastingType a_type);	// 54 - { return; }
		virtual MagicSystem::CastingType	GetCastingType() const = 0;							// 55
		virtual void						SetDeliveryType(MagicSystem::Delivery a_type);		// 56 - { return; }
		virtual MagicSystem::Delivery		GetDeliveryType() const = 0;						// 57
		virtual void						Unk_58(void);										// 58 - { return 1; }
		virtual float						GetCastDuration() const;							// 59 - { return 0.0; }
		virtual float						GetRange() const;									// 5A - { return 0.0; }
		virtual bool						IgnoresResistance();								// 5B - { return false; }
		virtual bool						AreaAffectIgnoresLOS();								// 5C - { return false; }
		virtual bool						IsFoodItem() const;									// 5D - { return false; }
		virtual bool						DisallowsAbsorbReflection();						// 5E - { return false; }
		virtual bool						AllowsDualCastModification();						// 5F - { return false; }
		virtual void						Unk_60(void);										// 60 - { return 0; }
		virtual bool						IsPoison() const;									// 61 - { return GetSpellType() == MagicSystem::SpellType::kPoison; }
		virtual bool						IsHealingItem() const;								// 62 - { return false; }
		virtual void						GetSkillCost(float& a_cost, Actor* a_actor) const;	// 63 - { return; }
		virtual float						GetChargeTime() const;								// 64 - { return 0.0; }
		virtual void						Unk_65(void);										// 65 - { return 0; }
		virtual ActorValue					GetActorValueType() const;							// 66 - { return ActorValue::kNone; } used for Actor::AdvanceSkill()
		virtual void						Unk_67(void);										// 67 - { return 0; } - UsesAllEquipSlotParents()?
		virtual UInt32						GetDataSigniture() const = 0;						// 68
		virtual void						CopyData(MagicItem* a_src) = 0;						// 69
		virtual void						LoadData(TESFile* a_mod, UInt32 a_signature);		// 6A - { return; }
		virtual void						Unk_6B(void);										// 6B - { return; }
		virtual void*						GetData() = 0;										// 6C - actually returns a base data struct that all derived data structs inherit from
		virtual const void*					GetData() const = 0;								// 6D
		virtual UInt32						GetDataSize() const = 0;							// 6E
		virtual void						LoadData(TESFile* a_mod) = 0;						// 6F
		virtual void						ByteSwapData() = 0;									// 70

		float	CalculateMagickaCost(Actor* a_caster) const;
		float	CalculateTotalGoldValue(Actor* a_caster = 0) const;
		Effect*	GetCostliestEffectItem(UInt32 a_arg1 = 5, bool a_arg2 = false);


		// members
		BSTArray<Effect*>			effects;			// 58
		SInt32						hostileCount;		// 70
		UInt32						pad74;				// 74
		EffectSetting*				avEffectSetting;	// 78
		UInt32						preloadCount;		// 80
		UInt32						pad84;				// 84
		BSTSmartPointer<QueuedFile>	preloadedItem;		// 88

	protected:
		float CalculateCost(Actor* a_caster) const;
	};
	STATIC_ASSERT(sizeof(MagicItem) == 0x90);
}
