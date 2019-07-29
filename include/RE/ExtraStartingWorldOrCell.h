#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraStartingWorldOrCell

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraStartingWorldOrCell : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraStartingWorldOrCell;


		enum { kExtraTypeID = ExtraDataType::kStartingWorldOrCell };


		virtual ~ExtraStartingWorldOrCell();			// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kStartingWorldOrCell; }


		// members
		UInt64 unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraStartingWorldOrCell) == 0x18);
}
