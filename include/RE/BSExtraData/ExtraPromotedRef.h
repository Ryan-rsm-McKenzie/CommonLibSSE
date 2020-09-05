#pragma once

#include "RE/BSCore/BSTArray.h"
#include "RE/BSExtraData/BSExtraData.h"
#include "RE/BSExtraData/Enums/ExtraDataTypes.h"
#include "RE/FormComponents/Enums/FormTypes.h"


namespace RE
{
	class ExtraPromotedRef : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraPromotedRef;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kPromotedRef;


		virtual ~ExtraPromotedRef();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kPromotedRef };


		// members
		BSTArray<TESForm*> promotedRefOwners;  // 10
	};
	static_assert(sizeof(ExtraPromotedRef) == 0x28);
}
