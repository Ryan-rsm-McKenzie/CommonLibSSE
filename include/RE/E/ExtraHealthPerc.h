#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/E/ExtraDataTypes.h"

namespace RE
{
	class ExtraHealthPerc : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraHealthPerc;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kHealthPerc;

		virtual ~ExtraHealthPerc();	 // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kHealthPerc; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return unk10 != a_rhs->unk10; }

		// members
		std::uint32_t unk10;  // 10
		std::uint32_t pad14;  // 14
	};
	static_assert(sizeof(ExtraHealthPerc) == 0x18);
}
