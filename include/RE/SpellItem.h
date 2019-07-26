#pragma once

#include "skse64/GameRTTI.h"  // RTTI_SpellItem

#include "RE/BGSEquipType.h"  // BGSEquipType
#include "RE/BGSMenuDisplayObject.h"  // BGSMenuDisplayObject
#include "RE/FormTypes.h"  // FormType, BGSPerk
#include "RE/MagicItem.h"  // MagicItem
#include "RE/TESDescription.h"  // TESDescription


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
			enum class Flag : UInt32
			{
				kNone = 0,
				kManualCostCalc = 1 << 0,
				kPCStartSpell = 1 << 17,
				kAreaEffectIgnoresLOS = 1 << 19,
				kIgnoreResistance = 1 << 20,
				kNoAbsorbReflect = 1 << 21,
				kNoDualCastModification = 1 << 23
			};


			UInt32		baseCost;		// 00
			Flag		flags;			// 04
			MagicType	type;			// 08
			float		chargeTime;		// 0C
			CastType	castType;		// 10
			TargetType	targetType;		// 14
			float		castDuration;	// 18
			float		range;			// 1C
			BGSPerk*	halfCostPerk;	// 20
		};
		STATIC_ASSERT(sizeof(Data) == 0x28);


		virtual ~SpellItem();															// 00

		// override (MagicItem)
		virtual void		InitDefaults() override;									// 04
		virtual void		ReleaseManagedData() override;								// 05
		virtual void		InitItem() override;										// 13
		virtual MagicType	GetMagicType() const override;								// 53 - { return data.type; }
		virtual void		SetCastType(CastType a_castType) override;					// 54 - { data.castType = a_castType; }
		virtual CastType	GetCastType() const override;								// 55 - { return data.castType; }
		virtual void		SetTargetType(TargetType a_targetType) override;			// 56 - { if (Unk_58()) { data.targetType = a_targetType; } }
		virtual TargetType	GetTargetType() const override;								// 57 - { return data.targetType; }
		virtual float		GetCastDuration() const override;							// 59 - { return (GetCastType() == CastType::kConcentration) ? data.castDuration : 0.0; }
		virtual float		GetRange() const override;									// 5A - { return data.range; }
		virtual bool		IgnoresResistance() override;								// 5B - { return (GetData()->flags >> 20) & 1; }
		virtual bool		AreaAffectIgnoresLOS() override;							// 5C - { return (GetData()->flags >> 19) & 1; }
		virtual bool		DisallowsAbsorbReflection() override;						// 5E - { return (GetData()->flags >> 21) & 1; }
		virtual bool		AllowsDualCastModification() override;						// 5F - { return (GetData()->flags >> 23) & 1; }
		virtual void		Unk_60(void) override;										// 60
		virtual void		GetSkillCost(float& a_cost, Actor* a_actor) const override;	// 63
		virtual float		GetChargeTime() const override;								// 64
		virtual ActorValue	GetActorValueType() const override;							// 66
		virtual void		Unk_67(void) override;										// 67 - { BGSEquipSlot* equipSlot = BGSEquipType::GetEquipSlot(); return equipSlot && equipSlot->flags & 1; } - UsesAllEquipSlotParents()?
		virtual UInt32		GetDataSigniture() const override;							// 68 - { return 'SPIT'; }
		virtual void		CopyData(MagicItem* a_src) override;						// 69
		virtual void		LoadData(TESFile* a_mod, UInt32 a_signature) override;		// 6A
		virtual void		Unk_6B(void) override;										// 6B
		virtual void*		GetData() override;											// 6C - { return &data; }
		virtual void*		GetData2() override;										// 6D - { return &data; }
		virtual UInt32		GetDataSize() const override;								// 6E - { return 0x28; }
		virtual void		LoadData(TESFile* a_mod) override;							// 6F
		virtual void		ByteSwapData() override;									// 70

		UInt32				GetMagickaCost();


		// members
		Data data;	// C0 - SPIT
	};
	STATIC_ASSERT(sizeof(SpellItem) == 0xE8);
}
