#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"
#include "RE/FormTypes.h"


namespace RE
{
	class ExtraEnchantment : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraEnchantment;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kEnchantment;


		ExtraEnchantment();
		ExtraEnchantment(EnchantmentItem* a_enchantment, UInt16 a_charge, bool a_removeOnUnequip = false);
		virtual ~ExtraEnchantment() = default;	// 00

		// override(BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kEnchantment; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return enchantment != a_rhs->enchantment || charge != a_rhs->charge || removeOnUnequip != a_rhs->removeOnUnequip; }


		// members
		EnchantmentItem* enchantment;	   // 10
		UInt16			 charge;		   // 18
		bool			 removeOnUnequip;  // 1A
		UInt8			 pad1B;			   // 1B
		UInt32			 pad1C;			   // 1C
	};
	STATIC_ASSERT(sizeof(ExtraEnchantment) == 0x20);
}
