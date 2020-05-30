#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraDetachTime : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraDetachTime;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kDetachTime;


		virtual ~ExtraDetachTime();	 // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kDetachTime; }


		// members
		UInt32 time;   // 10
		UInt32 pad14;  // 14
	};
	STATIC_ASSERT(sizeof(ExtraDetachTime) == 0x18);
}
