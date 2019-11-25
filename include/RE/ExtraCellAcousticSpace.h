#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraCellAcousticSpace : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraCellAcousticSpace;


		enum { kExtraTypeID = ExtraDataType::kCellAcousticSpace };


		virtual ~ExtraCellAcousticSpace();												// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kCellAcousticSpace; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return unk10 != a_rhs->unk10; }


		// members
		UInt64 unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraCellAcousticSpace) == 0x18);
}
