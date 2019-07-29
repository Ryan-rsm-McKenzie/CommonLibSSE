#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraHealthPerc

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraHealthPerc : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraHealthPerc;


		enum { kExtraTypeID = ExtraDataType::kHealthPerc };


		virtual ~ExtraHealthPerc();														// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kHealthPerc; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return unk10 != a_rhs->unk10; }


		// members
		UInt32	unk10;	// 10
		UInt32	pad14;	// 14
	};
	STATIC_ASSERT(sizeof(ExtraHealthPerc) == 0x18);
}
