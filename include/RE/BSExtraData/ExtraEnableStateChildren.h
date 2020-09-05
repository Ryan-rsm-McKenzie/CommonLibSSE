#pragma once

#include "RE/BSCore/BSPointerHandle.h"
#include "RE/BSCore/BSTList.h"
#include "RE/BSExtraData/BSExtraData.h"
#include "RE/BSExtraData/Enums/ExtraDataTypes.h"


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
	static_assert(sizeof(ExtraEnableStateChildren) == 0x20);
}
