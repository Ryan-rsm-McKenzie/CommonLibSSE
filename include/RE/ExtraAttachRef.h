#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraAttachRef

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraAttachRef : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraAttachRef;


		enum { kExtraTypeID = ExtraDataType::kAttachRef };


		virtual ~ExtraAttachRef();														// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kAttachRef; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return unk10 != a_rhs->unk10; }


		// members
		UInt32	unk10;	// 10
		UInt32	pad14;	// 14
	};
	STATIC_ASSERT(sizeof(ExtraAttachRef) == 0x18);
}
