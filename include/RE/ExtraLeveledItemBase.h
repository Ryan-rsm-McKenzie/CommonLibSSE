#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class TESLevItem;


	class ExtraLeveledItemBase : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraLeveledItemBase;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kLeveledItemBase;


		virtual ~ExtraLeveledItemBase();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kLeveledItemBase; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return levItem != a_rhs->levItem; }


		// members
		TESLevItem* levItem;  // 10
	};
	STATIC_ASSERT(sizeof(ExtraLeveledItemBase) == 0x18);
}
