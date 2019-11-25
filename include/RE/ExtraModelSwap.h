#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraModelSwap : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraModelSwap;


		enum { kExtraTypeID = ExtraDataType::kModelSwap };


		virtual ~ExtraModelSwap();						// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kModelSwap; }


		// members
		UInt64	unk10;	// 10
		UInt64	unk18;	// 18
	};
	STATIC_ASSERT(sizeof(ExtraModelSwap) == 0x20);
}
