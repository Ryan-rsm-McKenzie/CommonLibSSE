#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraActivateRef

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraActivateRef : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraActivateRef;


		enum { kExtraTypeID = ExtraDataType::kActivateRef };


		virtual ~ExtraActivateRef();													// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kActivateRef; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02


		// members
		UInt64	unk10;	// 10
		UInt64	unk18;	// 18
		UInt64	unk20;	// 20
	};
	STATIC_ASSERT(sizeof(ExtraActivateRef) == 0x28);
}
