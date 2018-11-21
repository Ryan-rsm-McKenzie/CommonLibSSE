#pragma once

#include "skse64_common/Utilities.h"
#include "skse64/GameAPI.h"
#include "skse64/GameFormComponents.h"  // TESFullName,  BGSKeywordForm
#include "skse64/GameTypes.h"  // tArray

#include "RE/TESBoundObject.h"  // TESBoundObject


namespace RE
{
	class Character;
	class EffectSetting;


	class MagicItem :
		public TESBoundObject,
		public TESFullName,
		public BGSKeywordForm
	{
	public:
		struct EffectItem
		{
			float			magnitude;	// 00
			UInt32			area;		// 04
			UInt32			duration;	// 08
			UInt32			pad0C;		// 0C
			EffectSetting*	mgef;		// 10
			float			cost;		// 18
			UInt32			pad1C;		// 1C
			Condition*		conditions;	// 20

			EffectItem()
			{
				magnitude = 0;
				area = 0;
				duration = 0;
				mgef = NULL;
				cost = 0.0;
				pad1C = 0;
				conditions = NULL;
			}

			DEFINE_STATIC_HEAP(Heap_Allocate, Heap_Free);
		};


		virtual UInt32		GetMagicType() const;
		virtual void		SetCastingType(UInt32 a_castingType);
		virtual UInt32		GetCastingType() const;
		virtual void		SetDeliveryType(UInt32 a_deliveryType);
		virtual UInt32		GetDeliveryType() const;
		virtual bool		Unk_57(UInt32 a_arg);
		virtual float		GetCastDuration() const;
		virtual float		GetRange() const;
		virtual bool		Unk_5A(void);
		virtual bool		Unk_5B(void);
		virtual bool		Unk_5C(void);
		virtual bool		Unk_5D(void);
		virtual bool		Unk_5E(void);
		virtual bool		Unk_5F(UInt32 a_arg);
		virtual bool		IsPoison() const;
		virtual bool		Unk_61(void);
		virtual void		Unk_62(UInt32 a_arg0, UInt32 a_arg1);
		virtual float		GetChargeTime() const;
		virtual UInt32		Unk_64(void);
		virtual UInt32		GetActorValueType() const;
		virtual bool		Unk_66(void);
		virtual UInt32		GetDataSigniture() const;
		virtual void		CopyData(MagicItem* a_src);
		virtual void		Unk_69(UInt32 a_arg0, UInt32 a_arg1);
		virtual void		Unk_6A(UInt32 a_arg);
		virtual void*		Unk_6B(void);
		virtual void*		Unk_6C(void);
		virtual UInt32		GetDataSize() const;
		virtual void		Unk_6E(void);

		EffectItem*			GetCostliestEffectItem(int a_arg1, bool a_arg2);
		float				GetEffectiveMagickaCost(Character* a_caster);


		// members
		tArray<EffectItem*> effectItemList;	// 58
		UInt32				hostile;		// 70
		EffectSetting*		effectTemplate;	// 78
		UInt32				unk80;			// 80
		void*				unk88;			// 88
	};

	STATIC_ASSERT(sizeof(MagicItem) == 0x90);
}
