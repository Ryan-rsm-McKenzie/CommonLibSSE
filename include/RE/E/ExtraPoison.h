#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/E/ExtraDataTypes.h"

namespace RE
{
	class AlchemyItem;

	class ExtraPoison : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraPoison;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kPoison;

		ExtraPoison();
		ExtraPoison(AlchemyItem* a_poison, std::int32_t a_count);
		virtual ~ExtraPoison() = default;  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kPoison; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return poison != a_rhs->poison || count != a_rhs->count; }

		// members
		AlchemyItem*  poison;  // 10
		std::uint32_t count;   // 18
		std::uint32_t pad1C;   // 1C
	};
	static_assert(sizeof(ExtraPoison) == 0x20);
}
