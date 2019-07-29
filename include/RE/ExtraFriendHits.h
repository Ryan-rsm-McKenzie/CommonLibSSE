#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraFriendHits

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/BSTArray.h"  // BSTArray
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraFriendHits : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraFriendHits;


		enum { kExtraTypeID = ExtraDataType::kFriendHits };


		virtual ~ExtraFriendHits();						// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kFriendHits; }


		// members
		BSTArray<void*> unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraFriendHits) == 0x28);
}
