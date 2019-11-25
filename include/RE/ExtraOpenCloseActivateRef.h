#pragma once

#include "RE/BSExtraData.h"
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
		UInt64 unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraOpenCloseActivateRef) == 0x18);
}
