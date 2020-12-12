#pragma once

#include "RE/BSCore/BSTArray.h"
#include "RE/BSExtraData/BSExtraData.h"
#include "RE/BSExtraData/Enums/ExtraDataTypes.h"
#include "RE/FormComponents/Components/AITimeStamp.h"


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
	static_assert(sizeof(ExtraFriendHits) == 0x28);
}
