#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/E/ExtraDataTypes.h"

namespace RE
{
	class ExtraFromAlias : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraFromAlias;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kFromAlias;

		virtual ~ExtraFromAlias();	// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kFromAlias; }

		// members
		TESQuest*	  quest;	// 10
		std::uint32_t aliasID;	// 18
		std::uint32_t pad1C;	// 1C
	};
	static_assert(sizeof(ExtraFromAlias) == 0x20);
}
