#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/B/BSSoundHandle.h"
#include "RE/E/ExtraDataTypes.h"

namespace RE
{
	class BGSDialogueBranch;
	class DialogueItem;
	class TESTopic;

	class ExtraSayToTopicInfo : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraSayToTopicInfo;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kSayTopicInfo;

		virtual ~ExtraSayToTopicInfo();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;  // 01 - { return kSayTopicInfo; }

		// members
		TESTopic*          topic;                // 10
		std::uint8_t       unk18;                // 18
		std::uint8_t       pad19;                // 19
		std::uint16_t      pad1A;                // 1A
		float              subtitleSpeechDelay;  // 1C
		BGSDialogueBranch* exclusiveBranch;      // 20
		BSSoundHandle      unk28;                // 28
		std::uint32_t      pad34;                // 34
		DialogueItem*      item;                 // 38
	};
	static_assert(sizeof(ExtraSayToTopicInfo) == 0x40);
}
