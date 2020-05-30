#pragma once

#include "RE/BSExtraData.h"
#include "RE/BSPointerHandle.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraOpenCloseActivateRef : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraOpenCloseActivateRef;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kOpenCloseActivateRef;


		virtual ~ExtraOpenCloseActivateRef();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kOpenCloseActivateRef; }


		// members
		ObjectRefHandle activateRef;  // 10
		UInt32			pad14;		  // 14
	};
	STATIC_ASSERT(sizeof(ExtraOpenCloseActivateRef) == 0x18);
}
