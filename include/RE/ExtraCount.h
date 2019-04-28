#pragma once

#include "RE/BSExtraData.h"  // BSExtraData


namespace RE
{
	class ExtraCount : public BSExtraData
	{
	public:
		enum { kExtraTypeID = ExtraDataType::kCount };


		ExtraCount();
		ExtraCount(SInt32 a_count);
		virtual ~ExtraCount();															// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kCount; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return return count != a_rhs->count; }


		// members
		SInt32	count;	// 10
		SInt32	pad14;	// 14
	};
	STATIC_ASSERT(sizeof(ExtraCount) == 0x18);
}
