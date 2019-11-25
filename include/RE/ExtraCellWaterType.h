#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraCellWaterType : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraCellWaterType;


		enum { kExtraTypeID = ExtraDataType::kCellWaterType };


		virtual ~ExtraCellWaterType();													// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kCellWaterType; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return unk10 != a_rhs->unk10; }


		// members
		UInt64 unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraCellWaterType) == 0x18);
}
