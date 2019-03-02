#pragma once

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/BSTArray.h"  // BSTArray
#include "RE/ExtraDataTypes.h"  // ExtraDataType
#include "RE/FormTypes.h"  // TESForm


namespace RE
{
	class ExtraPromotedRef : public BSExtraData
	{
	public:
		enum { kExtraTypeID = ExtraDataType::kPromotedRef };


		virtual ~ExtraPromotedRef();					// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kPromotedRef };


		// members
		BSTArray<TESForm*> promotedRefs;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraPromotedRef) == 0x28);
}
