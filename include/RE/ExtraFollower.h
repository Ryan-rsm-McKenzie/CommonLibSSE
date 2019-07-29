#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraFollower

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/BSTArray.h"  // BSTArray
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraFollower : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraFollower;


		enum { kExtraTypeID = ExtraDataType::kFollower };


		virtual ~ExtraFollower();						// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kFollower; }


		// members
		BSTArray<void*> unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraFollower) == 0x28);
}
