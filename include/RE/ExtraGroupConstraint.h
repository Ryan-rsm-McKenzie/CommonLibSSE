#pragma once

#include "RE/BSExtraData.h"
#include "RE/BSFixedString.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraGroupConstraint : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraGroupConstraint;


		enum { kExtraTypeID = ExtraDataType::kGroupConstraint };


		virtual ~ExtraGroupConstraint();				// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kGroupConstraint; }


		// members
		UInt64			unk10;	// 10
		BSFixedString	unk18;	// 18
		BSFixedString	unk20;	// 20
		UInt64			unk28;	// 28
		UInt64			unk30;	// 30
		UInt64			unk38;	// 38
		UInt64			unk40;	// 40
	};
	STATIC_ASSERT(sizeof(ExtraGroupConstraint) == 0x48);
}
