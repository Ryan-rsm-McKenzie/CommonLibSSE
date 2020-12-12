#pragma once

#include "RE/BSCore/BSPointerHandle.h"
#include "RE/BSCore/BSTList.h"
#include "RE/BSExtraData/BSExtraData.h"
#include "RE/BSExtraData/Enums/ExtraDataTypes.h"


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
	static_assert(sizeof(ExtraAttachRefChildren) == 0x20);
}
