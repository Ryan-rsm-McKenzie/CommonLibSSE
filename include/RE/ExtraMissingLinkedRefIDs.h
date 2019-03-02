#pragma once

#include "RE/BSExtraData.h"  // BSExtraData


namespace RE
{
	class ExtraMissingLinkedRefIDs : public BSExtraData
	{
	public:
		enum { kExtraTypeID = ExtraDataType::kMissingLinkedRefIDs };


		virtual ~ExtraMissingLinkedRefIDs();			// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kMissingLinkedRefIDs; }


		// members
		UInt64	unk10;	// 10
		UInt64	unk18;	// 18
		UInt64	unk20;	// 20
	};
	STATIC_ASSERT(sizeof(ExtraMissingLinkedRefIDs) == 0x28);
}
