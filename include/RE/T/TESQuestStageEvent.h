#pragma once

namespace RE
{
	struct TESQuestStageEvent
	{
	public:
		// members
		void*         finishedCallback;  // 00
		FormID        formID;            // 08
		std::uint16_t stage;             // 0C
		std::uint8_t  unk0E;             // 0E
		std::uint8_t  pad0F;             // 0F
	};
	static_assert(sizeof(TESQuestStageEvent) == 0x10);
}
