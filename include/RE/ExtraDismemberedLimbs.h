#pragma once

#include "RE/BSExtraData.h"
#include "RE/BSTArray.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraDismemberedLimbs : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraDismemberedLimbs;


		enum { kExtraTypeID = ExtraDataType::kDismemberedLimbs };


		virtual ~ExtraDismemberedLimbs();				// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kDismemberedLimbs; }


		// members
		UInt64			unk10;	// 10
		UInt64			unk18;	// 18
		BSTArray<void*>	unk20;	// 20
		UInt64			unk38;	// 38
	};
	STATIC_ASSERT(sizeof(ExtraDismemberedLimbs) == 0x40);
}
