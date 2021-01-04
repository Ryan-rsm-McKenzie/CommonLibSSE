#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/B/BSTList.h"
#include "RE/E/ExtraDataTypes.h"

namespace RE
{
	class TESObjectREFR;

	class ExtraLitWaterRefs : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraLitWaterRefs;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kLitWaterRefs;

		virtual ~ExtraLitWaterRefs();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kLitWaterRefs; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return refs != a_rhs->refs; }

		// members
		BSSimpleList<TESObjectREFR*> refs;	// 10
	};
	static_assert(sizeof(ExtraLitWaterRefs) == 0x20);
}
