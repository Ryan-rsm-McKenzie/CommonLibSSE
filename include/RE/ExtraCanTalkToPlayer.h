#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


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
