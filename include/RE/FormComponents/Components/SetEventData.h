#pragma once

#include "RE/BSCore/BSFixedString.h"
#include "RE/BSCore/BSTArray.h"


namespace RE
{
	struct SetEventData
	{
	public:
		// members
		BSFixedString				  eventName;  // 00
		BSTSmallArray<BSFixedString>* clipNames;  // 08
		bool						  unk10;	  // 10
		std::uint8_t				  pad11;	  // 11
		std::uint16_t				  pad12;	  // 12
		std::uint32_t				  pad14;	  // 14
	};
	static_assert(sizeof(SetEventData) == 0x18);
}
