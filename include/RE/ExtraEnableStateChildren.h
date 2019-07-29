#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraEnableStateChildren

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/BSTList.h"  // BSSimpleList
#include "RE/ExtraDataTypes.h"  // ExtraDataType


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
