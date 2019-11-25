#pragma once

#include "RE/BSExtraData.h"
#include "RE/BSTList.h"
#include "RE/ExtraDataTypes.h"


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
