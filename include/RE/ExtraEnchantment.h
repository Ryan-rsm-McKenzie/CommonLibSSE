#pragma once

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/FormTypes.h"  // EnchantmentItem


namespace RE
{
	class ExtraEnchantment : public BSExtraData
	{
	public:
		enum { kExtraTypeID = ExtraDataType::kEnchantment };


		virtual ~ExtraEnchantment();													// 00

		// override(BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kEnchantment; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02


		// members
		EnchantmentItem*	objectEffect;		// 10
		UInt16				enchantmentAmount;	// 18
		UInt8				unk0E;				// 1A - usually 0
		UInt8				pad1B;				// 1B
		UInt32				pad1C;				// 1C
	};
	STATIC_ASSERT(sizeof(ExtraEnchantment) == 0x20);
}
