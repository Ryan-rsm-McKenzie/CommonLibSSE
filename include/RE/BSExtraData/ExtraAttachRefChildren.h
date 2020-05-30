#pragma once

#include "RE/BSExtraData.h"
#include "RE/BSPointerHandle.h"
#include "RE/BSTList.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraAttachRefChildren : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraAttachRefChildren;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kAttachRefChildren;


		virtual ~ExtraAttachRefChildren();	// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kAttachRefChildren; }


		// members
		BSSimpleList<ObjectRefHandle> children;	 // 10
	};
	STATIC_ASSERT(sizeof(ExtraAttachRefChildren) == 0x20);
}
