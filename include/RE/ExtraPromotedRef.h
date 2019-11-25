#pragma once

#include "RE/BSExtraData.h"
#include "RE/BSTArray.h"
#include "RE/ExtraDataTypes.h"
#include "RE/FormTypes.h"


namespace RE
{
	class ExtraPromotedRef : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraPromotedRef;


		enum { kExtraTypeID = ExtraDataType::kPromotedRef };


		virtual ~ExtraPromotedRef();					// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kPromotedRef };


		// members
		BSTArray<TESForm*> promotedRefs;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraPromotedRef) == 0x28);
}
