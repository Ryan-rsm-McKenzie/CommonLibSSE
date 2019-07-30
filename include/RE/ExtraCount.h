#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraCount

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraCount : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraCount;


		enum { kExtraTypeID = ExtraDataType::kCount };


		ExtraCount();
		ExtraCount(SInt32 a_count);
		virtual ~ExtraCount() = default;												// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kCount; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return return count != a_rhs->count; }


		// members
		SInt32	count;	// 10
		SInt32	pad14;	// 14
	};
	STATIC_ASSERT(sizeof(ExtraCount) == 0x18);
}
