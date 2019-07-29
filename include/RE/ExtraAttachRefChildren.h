#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraAttachRefChildren

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/BSTList.h"  // BSSimpleList
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraAttachRefChildren : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraAttachRefChildren;


		enum { kExtraTypeID = ExtraDataType::kAttachRefChildren };


		virtual ~ExtraAttachRefChildren();				// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kAttachRefChildren; }


		// members
		BSSimpleList<UInt32> unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraAttachRefChildren) == 0x20);
}
