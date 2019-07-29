#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraIgnoredBySandbox

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraIgnoredBySandbox : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraIgnoredBySandbox;


		enum { kExtraTypeID = ExtraDataType::kIgnoredBySandbox };


		virtual ~ExtraIgnoredBySandbox();				// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kIgnoredBySandbox; }
	};
	STATIC_ASSERT(sizeof(ExtraIgnoredBySandbox) == 0x10);
}
