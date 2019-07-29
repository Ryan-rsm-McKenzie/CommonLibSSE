#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraAlphaCutoff

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraAlphaCutoff : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraAlphaCutoff;


		enum { kExtraTypeID = ExtraDataType::kAlphaCutoff };


		virtual ~ExtraAlphaCutoff();													// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kAlphaCutoff; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return unk10 != a_rhs->unk10; }


		// members
		UInt8	unk10;	// 10
		UInt8	unk11;	// 11
		UInt16	pad12;	// 12
		UInt32	pad14;	// 14
	};
	STATIC_ASSERT(sizeof(ExtraAlphaCutoff) == 0x18);
}
