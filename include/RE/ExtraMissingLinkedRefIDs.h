#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraMissingLinkedRefIDs

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraMissingLinkedRefIDs : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraMissingLinkedRefIDs;


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
