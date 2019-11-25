#pragma once

#include "RE/BSExtraData.h"
#include "RE/BSTList.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraEnableStateChildren : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraEnableStateChildren;


		enum { kExtraTypeID = ExtraDataType::kEnableStateChildren };


		virtual ~ExtraEnableStateChildren();			// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kEnableStateChildren; }


		// members
		BSSimpleList<UInt32> unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraEnableStateChildren) == 0x20);
}
