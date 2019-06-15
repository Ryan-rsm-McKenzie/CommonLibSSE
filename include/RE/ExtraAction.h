#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraAction

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraAction : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraAction;


		enum { kExtraTypeID = ExtraDataType::kAction };


		virtual ~ExtraAction();															// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kAction; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return unk10 != a_rhs->unk10; }


		// members
		UInt64	unk10;	// 10
		UInt64	unk18;	// 18
	};
	STATIC_ASSERT(sizeof(ExtraAction) == 0x20);
}
