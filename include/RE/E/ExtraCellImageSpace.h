#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/E/ExtraDataTypes.h"

namespace RE
{
	class TESImageSpace;

	class ExtraCellImageSpace : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraCellImageSpace;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kCellImageSpace;

		virtual ~ExtraCellImageSpace();	 // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kCellImageSpace; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return imageSpace != a_rhs->imageSpace; }

		// members
		TESImageSpace* imageSpace;	// 10
	};
	static_assert(sizeof(ExtraCellImageSpace) == 0x18);
}
