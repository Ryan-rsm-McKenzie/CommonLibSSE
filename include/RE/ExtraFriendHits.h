#pragma once

#include "RE/AITimeStamp.h"
#include "RE/BSExtraData.h"
#include "RE/BSTArray.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraFriendHits : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraFriendHits;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kFriendHits;


		virtual ~ExtraFriendHits();	 // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kFriendHits; }


		// members
		BSTArray<AITimeStamp> hits;	 // 10
	};
	STATIC_ASSERT(sizeof(ExtraFriendHits) == 0x28);
}
