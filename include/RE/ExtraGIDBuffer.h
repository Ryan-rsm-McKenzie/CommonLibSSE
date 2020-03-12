#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraGIDBuffer : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraGIDBuffer;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kGIDBuffer;


		virtual ~ExtraGIDBuffer();	// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kGIDBuffer; }


		// members
		SInt8* buffer;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraGIDBuffer) == 0x18);
}
