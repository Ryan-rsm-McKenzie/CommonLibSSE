#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraCanTalkToPlayer

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraCanTalkToPlayer : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraCanTalkToPlayer;


		enum { kExtraTypeID = ExtraDataType::kCanTalkToPlayer };


		virtual ~ExtraCanTalkToPlayer();				// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kCanTalkToPlayer; }


		// members
		UInt64 unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraCanTalkToPlayer) == 0x18);
}
