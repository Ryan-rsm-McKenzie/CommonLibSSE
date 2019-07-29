#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraCreatureMovementSound

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraCreatureMovementSound : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraCreatureMovementSound;


		enum { kExtraTypeID = ExtraDataType::kCreatureMovementSound };


		virtual ~ExtraCreatureMovementSound();			// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kCreatureMovementSound; }


		// members
		UInt64	unk10;	// 10
		UInt64	unk18;	// 18
	};
	STATIC_ASSERT(sizeof(ExtraCreatureMovementSound) == 0x20);
}
