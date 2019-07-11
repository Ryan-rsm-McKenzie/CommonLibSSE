#pragma once

#include "skse64/GameRTTI.h"  // RTTI_EnchantmentItem

#include "RE/FormTypes.h"  //FormType
#include "RE/MagicItem.h"  // MagicItem


namespace RE
{
	class EnchantmentItem : public MagicItem
	{
	public:
		inline static const void* RTTI = RTTI_EnchantmentItem;


		enum { kTypeID = FormType::Enchantment };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		struct Data	// ENIT
		{
			enum class Flag : UInt32
			{
				kNone = 0,
				kNoAutoCalc = 1 << 0,
				kExtendDurationOnRecast = 1 << 2
			};


			UInt32				enchantmentCost;	// 00
			Flag				flags;				// 04
			CastType			castType;			// 08
			UInt32				enchantmentAmount;	// 0C
			TargetType			targetType;			// 10
			MagicType			enchantType;		// 14
			float				chargeTime;			// 18
			UInt32				pad1C;				// 1C
			EnchantmentItem*	baseEnchantment;	// 20
			BGSListForm*		wornRestrictions;	// 28
		};
		STATIC_ASSERT(sizeof(Data) == 0x30);


		virtual ~EnchantmentItem();												// 00

		// override (MagicItem)
		virtual void		InitDefaults() override;							// 04
		virtual void		ReleaseManagedData() override;						// 05
		virtual void		InitItem() override;								// 13
		virtual MagicType	GetMagicType() const override;						// 53 - { return data.enchantmentType; }
		virtual void		SetCastType(CastType a_castType) override;			// 54 - { data.castType = a_castType; }
		virtual CastType	GetCastType() const override;						// 55 - { return data.castType; }
		virtual void		SetTargetType(TargetType a_targetType) override;	// 56 - { if (Unk_58()) { data.targetType = a_targetType; } }
		virtual TargetType	GetTargetType() const override;						// 57 - { return data.targetType; }
		virtual float		GetChargeTime() const override;						// 64
		virtual ActorValue	GetActorValueType() const override;					// 66 - { return ActorValue::kEnchanting; }
		virtual UInt32		GetDataSigniture() const override;					// 68 - { return 'ENIT'; }
		virtual void		CopyData(MagicItem* a_src) override;				// 69
		virtual void*		GetData() override;									// 6C - { return &data; }
		virtual void*		GetData2() override;								// 6D - { return &data; }
		virtual UInt32		GetDataSize() const override;						// 6E - { return 0x30; }
		virtual void		LoadData(TESFile* a_mod) override;					// 6F
		virtual void		ByteSwapData() override;							// 70


		// members
		Data data;	// 90 - ENIT
	};
	STATIC_ASSERT(sizeof(EnchantmentItem) == 0xC0);
}
