#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/E/ExtraDataTypes.h"

namespace RE
{
	class BGSPrimitive;

	class ExtraPrimitive : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraPrimitive;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kPrimitive;

		virtual ~ExtraPrimitive();	// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kPrimitive; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return primitive != a_rhs->primitive; }

		// members
		BGSPrimitive* primitive;  // 10
	};
	static_assert(sizeof(ExtraPrimitive) == 0x18);
}
