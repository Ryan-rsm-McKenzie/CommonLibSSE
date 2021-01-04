#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/E/ExtraDataTypes.h"

namespace RE
{
	class BGSAcousticSpace;

	class ExtraCellAcousticSpace : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraCellAcousticSpace;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kCellAcousticSpace;

		virtual ~ExtraCellAcousticSpace();	// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kCellAcousticSpace; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return space != a_rhs->space; }

		// members
		BGSAcousticSpace* space;  // 10
	};
	static_assert(sizeof(ExtraCellAcousticSpace) == 0x18);
}
