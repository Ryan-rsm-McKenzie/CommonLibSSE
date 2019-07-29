#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraSound

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraSound : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraSound;


		enum { kExtraTypeID = ExtraDataType::kSound };


		virtual ~ExtraSound();							// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kSound; }


		// members
		UInt64	unk10;	// 10
		UInt64	unk18;	// 18
	};
	STATIC_ASSERT(sizeof(ExtraSound) == 0x20);
}
