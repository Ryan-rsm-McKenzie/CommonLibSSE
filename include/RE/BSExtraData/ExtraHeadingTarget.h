#pragma once

#include "RE/BSExtraData.h"
#include "RE/BSPointerHandle.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraHeadingTarget : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraHeadingTarget;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kHeadingTarget;


		virtual ~ExtraHeadingTarget();	// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kHeadingTarget; }


		// members
		ObjectRefHandle target;	 // 10
		UInt32			pad14;	 // 14
	};
	STATIC_ASSERT(sizeof(ExtraHeadingTarget) == 0x18);
}
