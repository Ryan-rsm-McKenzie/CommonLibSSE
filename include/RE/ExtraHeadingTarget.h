#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraHeadingTarget

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraHeadingTarget : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraHeadingTarget;


		enum { kExtraTypeID = ExtraDataType::kHeadingTarget };


		virtual ~ExtraHeadingTarget();					// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kHeadingTarget; }


		// members
		UInt64 unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraHeadingTarget) == 0x18);
}
