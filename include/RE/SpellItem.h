#pragma once

#include "skse64/GameFormComponents.h"  // BGSEquipType, TESDescription

#include "RE/MagicItem.h"  // MagicItem
#include "RE/BGSMenuDisplayObject.h"  // BGSMenuDisplayObject


namespace RE
{
	class SpellItem :
		public MagicItem,				// 00
		public BGSEquipType,			// 90
		public BGSMenuDisplayObject,	// A0
		public TESDescription			// B0
	{
	public:
		enum { kTypeID = FormType::Spell };


		struct Data	// SPIT
		{
			enum class Flag : UInt32
			{
				kManualCostCalc = (1 << 0),				// 00000000
				kPCStartSpell = (1 << 17),				// 00020000
				kAreaEffectIgnoresLOS = (1 << 19),		// 00080000
				kIgnoreResistance = (1 << 20),			// 00100000
				kNoAbsorbReflect = (1 << 21),			// 00200000
				kNoDualCastModification = (1 << 23)		// 00800000
			};


			UInt32		baseCost;		// 00 - init'd to 0xFFFFFFFF
			Flag		flags;			// 04
			Type		type;			// 08
			float		chargeTime;		// 0C
			CastType	castType;		// 10 - init'd to 3
			TargetType	targetType;		// 14 - init'd to 5
			float		castDuration;	// 18
			float		range;			// 1C
			BGSPerk*	halfCostPerk;	// 20
		};
		STATIC_ASSERT(sizeof(Data) == 0x28);


		// override (MagicItem)
		virtual Type		GetMagicType() const override;			// 53 - { return this->data.type; }
		virtual CastType	GetCastType() const override;			// 55 - { return this->data.castType; }
		virtual TargetType	GetTargetType() const override;			// 57 - { return this->data.targetType; }
		virtual float		GetCastDuration() const override;		// 59 - { return (GetCastringType() = kConcentration) ? duration : 0.0f; }
		virtual float		GetRange() const override;				// 5A - { return data.range; }
		virtual float		GetChargeTime() const override;			// 64
		virtual UInt32		GetActorValueType() const override;		// 66
		virtual UInt32		GetDataSigniture() const override;		// 68 - { return 'SPIT'; }
		virtual void		CopyData(MagicItem* a_src) override;	// 69 - { if (this->formType == src->formType) data = src->data; }
		virtual UInt32		GetDataSize() const override;			// 6E - { return sizeof(Data); }

		UInt32				GetMagickaCost();


		// members
		Data data;	// C0
	};
	STATIC_ASSERT(sizeof(SpellItem) == 0xE8);
}
