#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraDetachTime : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraDetachTime;


		enum { kExtraTypeID = ExtraDataType::kDetachTime };


		virtual ~ExtraDetachTime();						// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kDetachTime; }


		// members
		UInt64 unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraDetachTime) == 0x18);
}
