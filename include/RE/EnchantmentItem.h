#pragma once

#include "RE/FormTypes.h"  //FormType
#include "RE/MagicItem.h"  // MagicItem


namespace RE
{
	class EnchantmentItem : public MagicItem
	{
	public:
		enum { kTypeID = FormType::Enchantment };


		struct Data	// DATA
		{
			enum class Flag : UInt32
			{
				kNone = 0,
				kNoAutoCalc = 1 << 0,
				kExtendDurationOnRecast = 1 << 2,
			};


			enum class EnchantmentType : UInt32
			{
				kEnchantment = 6,
				kStaffEnchantment = 12
			};


			UInt32				enchantmentCost;	// 00 - init'd to 0xFFFFFFFF
			Flag				flags;				// 04
			CastType			castType;			// 08
			UInt32				enchantmentAmount;	// 0C - init'd to 0xFFFFFFFF
			TargetType			targetType;			// 10 - init'd to 5
			EnchantmentType		enchantmentType;	// 14 - init'd to kEnchantment
			float				chargeTime;			// 18
			UInt32				pad1C;				// 1C
			EnchantmentItem*	baseEnchantment;	// 20
			BGSListForm*		wornRestrictions;	// 28
		};
		STATIC_ASSERT(sizeof(Data) == 0x30);


		// override (MagicItem)
		virtual Type		GetMagicType() const override;						// 53
		virtual void		SetCastType(CastType a_castingType) override;		// 54
		virtual CastType	GetCastType() const override;						// 55
		virtual void		SetTargetType(TargetType a_deliveryType) override;	// 56
		virtual TargetType	GetTargetType() const override;						// 57
		virtual float		GetChargeTime() const override;						// 64
		virtual UInt32		GetActorValueType() const override;					// 66
		virtual UInt32		GetDataSigniture() const override;					// 68
		virtual void		CopyData(MagicItem* a_src) override;				// 69
		virtual UInt32		GetDataSize() const override;						// 6E


		// members
		Data data;	// 90
	};
	STATIC_ASSERT(sizeof(EnchantmentItem) == 0xC0);
}
