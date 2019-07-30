#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraLockList

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraLockList : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraLockList;


		enum { kExtraTypeID = ExtraDataType::kLockList };


		virtual ~ExtraLockList();														// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { reutrn kLockList; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return unk10 != a_rhs->unk10; }


		// members
		UInt64 unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraLockList) == 0x18);
}
