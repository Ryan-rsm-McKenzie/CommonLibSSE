#pragma once

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraGhost : public BSExtraData
	{
	public:
		enum { kExtraTypeID = ExtraDataType::kGhost };


		virtual ~ExtraGhost();							// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kGhost; }


		// members
		UInt64	unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraGhost) == 0x18);
}
