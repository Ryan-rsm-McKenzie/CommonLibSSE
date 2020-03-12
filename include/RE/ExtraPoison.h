#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class AlchemyItem;


	class ExtraPoison : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraPoison;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kPoison;


		ExtraPoison();
		ExtraPoison(AlchemyItem* a_poison, SInt32 a_count);
		virtual ~ExtraPoison() = default;  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kPoison; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return poison != a_rhs->poison || count != a_rhs->count; }


		// members
		AlchemyItem* poison;  // 10
		UInt32		 count;	  // 18
		UInt32		 pad1C;	  // 1C
	};
	STATIC_ASSERT(sizeof(ExtraPoison) == 0x20);
}
