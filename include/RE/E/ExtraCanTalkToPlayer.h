#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/E/ExtraDataTypes.h"

namespace RE
{
	class ExtraCanTalkToPlayer : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraCanTalkToPlayer;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kCanTalkToPlayer;

		ExtraCanTalkToPlayer();
		explicit ExtraCanTalkToPlayer(bool a_canTalk);
		virtual ~ExtraCanTalkToPlayer() = default;	// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kCanTalkToPlayer; }

		// members
		bool		  talk;	  // 10
		std::uint8_t  pad11;  // 11
		std::uint16_t pad12;  // 12
		std::uint32_t pad14;  // 14
	};
	static_assert(sizeof(ExtraCanTalkToPlayer) == 0x18);
}
