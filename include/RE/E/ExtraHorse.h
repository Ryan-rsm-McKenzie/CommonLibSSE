#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/B/BSPointerHandle.h"
#include "RE/E/ExtraDataTypes.h"

namespace RE
{
	class ExtraHorse : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraHorse;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kHorse;

		virtual ~ExtraHorse();	// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kHorse; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return horseRef != a_rhs->horseRef; }

		// members
		ObjectRefHandle horseRef;  // 10
		std::uint32_t	pad14;	   // 14
	};
	static_assert(sizeof(ExtraHorse) == 0x18);
}
