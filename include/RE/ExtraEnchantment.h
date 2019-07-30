#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraEnchantment

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType
#include "RE/FormTypes.h"  // EnchantmentItem


namespace RE
{
	class ExtraEnchantment : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraEnchantment;


		enum { kExtraTypeID = ExtraDataType::kEnchantment };


		ExtraEnchantment();
		ExtraEnchantment(EnchantmentItem* a_objectEffect, UInt16 a_enchantmentAmount);
		virtual ~ExtraEnchantment() = default;											// 00

		// override(BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kEnchantment; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return objectEffect != a_rhs->objectEffect || enchantmentAmount != a_rhs->enchantmentAmount || unk0E != a_rhs->unk0E; }


		// members
		EnchantmentItem*	objectEffect;		// 10
		UInt16				enchantmentAmount;	// 18
		UInt8				unk0E;				// 1A - usually 0
		UInt8				pad1B;				// 1B
		UInt32				pad1C;				// 1C
	};
	STATIC_ASSERT(sizeof(ExtraEnchantment) == 0x20);
}
