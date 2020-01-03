#pragma once

#include "RE/BGSEquipType.h"
#include "RE/BGSMenuDisplayObject.h"
#include "RE/FormTypes.h"
#include "RE/MagicItem.h"
#include "RE/TESDescription.h"


namespace RE
{
	class SpellItem :
		public MagicItem,				// 00
		public BGSEquipType,			// 90
		public BGSMenuDisplayObject,	// A0
		public TESDescription			// B0
	{
	public:
		inline static const void* RTTI = RTTI_SpellItem;


		enum { kTypeID = FormType::Spell };


		enum class SpellFlag : UInt32
		{
			kNone = 0,
			kCostOverride = 1 << 0,
			kFoodItem = 1 << 1,
			kExtendDuration = 1 << 3,
			kPCStartSpell = 1 << 17,
			kInstantCast = 1 << 18,
			kIgnoreLOSCheck = 1 << 19,
			kIgnoreResistance = 1 << 20,
			kNoAbsorb = 1 << 21,
			kNoDualCastMods = 1 << 23
		};


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		struct Data	// SPIT
		{
			SInt32						costOverride;	// 00
			SpellFlag					flags;			// 04
			MagicSystem::SpellType		spellType;		// 08
			float						chargeTime;		// 0C
			MagicSystem::CastingType	castingType;	// 10
			MagicSystem::Delivery		delivery;		// 14
			float						castDuration;	// 18
			float						range;			// 1C
			BGSPerk*					castingPerk;	// 20
		};
		STATIC_ASSERT(sizeof(Data) == 0x28);


		virtual ~SpellItem();																			// 00

		// override (MagicItem)
		virtual void						InitializeData() override;									// 04
		virtual void						ClearData() override;										// 05
		virtual void						InitItemImpl() override;									// 13
		virtual MagicSystem::SpellType		GetSpellType() const override;								// 53 - { return data.spellType; }
		virtual void						SetCastingType(MagicSystem::CastingType a_type) override;	// 54 - { data.castingType = a_type; }
		virtual MagicSystem::CastingType	GetCastingType() const override;							// 55 - { return data.castingType; }
		virtual void						SetDeliveryType(MagicSystem::Delivery a_type) override;		// 56 - { if (Unk_58()) { data.delivery = a_type; } }
		virtual MagicSystem::Delivery		GetDeliveryType() const override;							// 57 - { return data.delivery; }
		virtual float						GetCastDuration() const override;							// 59 - { return (GetCastingType() == MagicSystem::CastingType::kConcentration) ? data.castDuration : 0.0; }
		virtual float						GetRange() const override;									// 5A - { return data.range; }
		virtual bool						IgnoresResistance() override;								// 5B - { return (GetData()->flags >> 20) & 1; }
		virtual bool						AreaAffectIgnoresLOS() override;							// 5C - { return (GetData()->flags >> 19) & 1; }
		virtual bool						DisallowsAbsorbReflection() override;						// 5E - { return (GetData()->flags >> 21) & 1; }
		virtual bool						AllowsDualCastModification() override;						// 5F - { return (GetData()->flags >> 23) & 1; }
		virtual void						Unk_60(void) override;										// 60
		virtual void						GetSkillCost(float& a_cost, Actor* a_actor) const override;	// 63
		virtual float						GetChargeTime() const override;								// 64
		virtual ActorValue					GetActorValueType() const override;							// 66
		virtual void						Unk_67(void) override;										// 67 - { BGSEquipSlot* equipSlot = BGSEquipType::GetEquipSlot(); return equipSlot && equipSlot->flags & 1; } - UsesAllEquipSlotParents()?
		virtual UInt32						GetDataSigniture() const override;							// 68 - { return 'SPIT'; }
		virtual void						CopyData(MagicItem* a_src) override;						// 69
		virtual void						LoadData(TESFile* a_mod, UInt32 a_signature) override;		// 6A
		virtual void						Unk_6B(void) override;										// 6B
		virtual void*						GetData() override;											// 6C - { return &data; }
		virtual const void*					GetData() const override;									// 6D - { return &data; }
		virtual UInt32						GetDataSize() const override;								// 6E - { return 0x28; }
		virtual void						LoadData(TESFile* a_mod) override;							// 6F
		virtual void						ByteSwapData() override;									// 70


		// members
		Data data;	// C0 - SPIT
	};
	STATIC_ASSERT(sizeof(SpellItem) == 0xE8);
}
