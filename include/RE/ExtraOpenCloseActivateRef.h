#pragma once

#include "RE/BSExtraData.h"
#include "RE/BSPointerHandle.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraOpenCloseActivateRef : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraOpenCloseActivateRef;


		enum { kExtraTypeID = ExtraDataType::kOpenCloseActivateRef };


		virtual ~ExtraOpenCloseActivateRef();			// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kOpenCloseActivateRef; }


		// members
		ObjectRefHandle	activateRef;	// 10
		UInt32			pad14;			// 14
	};
	STATIC_ASSERT(sizeof(ExtraOpenCloseActivateRef) == 0x18);
}
