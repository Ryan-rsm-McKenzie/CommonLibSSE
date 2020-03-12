#pragma once

#include "RE/BSExtraData.h"
#include "RE/BSPointerHandle.h"
#include "RE/BSTList.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraEnableStateChildren : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraEnableStateChildren;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kEnableStateChildren;


		virtual ~ExtraEnableStateChildren();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kEnableStateChildren; }


		// members
		BSSimpleList<ObjectRefHandle> children;	 // 10
	};
	STATIC_ASSERT(sizeof(ExtraEnableStateChildren) == 0x20);
}
