#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraHasNoRumors

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraHasNoRumors : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraHasNoRumors;


		enum { kExtraTypeID = ExtraDataType::kHasNoRumors };


		virtual ~ExtraHasNoRumors();					// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kHasNoRumors; }


		// members
		UInt64 unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraHasNoRumors) == 0x18);
}
