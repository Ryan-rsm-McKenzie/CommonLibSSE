#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraGIDBuffer : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraGIDBuffer;


		enum { kExtraTypeID = ExtraDataType::kGIDBuffer };


		virtual ~ExtraGIDBuffer();						// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kGIDBuffer; }


		// members
		SInt8* buffer;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraGIDBuffer) == 0x18);
}
