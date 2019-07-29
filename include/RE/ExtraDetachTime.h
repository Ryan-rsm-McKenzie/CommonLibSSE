#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraDetachTime

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraDetachTime : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraDetachTime;


		enum { kExtraTypeID = ExtraDataType::kDetachTime };


		virtual ~ExtraDetachTime();						// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kDetachTime; }


		// members
		UInt64 unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraDetachTime) == 0x18);
}
