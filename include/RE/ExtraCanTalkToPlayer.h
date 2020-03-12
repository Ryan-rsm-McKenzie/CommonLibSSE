#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


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
		bool   talk;   // 10
		UInt8  pad11;  // 11
		UInt16 pad12;  // 12
		UInt32 pad14;  // 14
	};
	STATIC_ASSERT(sizeof(ExtraCanTalkToPlayer) == 0x18);
}
