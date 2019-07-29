#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraActivateLoopSound

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraActivateLoopSound : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraActivateLoopSound;


		enum { kExtraTypeID = ExtraDataType::kActivateLoopSound };


		virtual ~ExtraActivateLoopSound();				// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kActivateLoopSound; }


		// members
		UInt64	unk10;	// 10
		UInt64	unk18;	// 18
	};
	STATIC_ASSERT(sizeof(ExtraActivateLoopSound) == 0x20);
}
