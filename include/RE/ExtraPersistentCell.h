#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraPersistentCell

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraPersistentCell : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraPersistentCell;


		enum { kExtraTypeID = ExtraDataType::kPersistentCell };


		virtual ~ExtraPersistentCell();					// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kPersistentCell; }


		// members
		UInt64 unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraPersistentCell) == 0x18);
}
