#pragma once

#include "RE/B/BSString.h"
#include "RE/I/IUIMessageData.h"

namespace RE
{
	class HUDData : public IUIMessageData
	{
	public:
		inline static constexpr auto RTTI = RTTI_HUDData;

		enum class Type
		{
			kUnk0 = 0,
			kNotification = 1,
			kActivate = 2,
			kActivateNoLabel = 3,
			kCenter = 4,
			kSubtitle = 5,
			kSetBlinking = 11,
			kSetFadeOut = 12,
			kSetPct = 13,
			kQuestStarted = 14,
			kQuestComplete = 15,
			kQuestFailed = 16,
			kObjectiveStarted = 17,
			kObjectiveComplete = 18,
			kObjectiveFailed = 19,
			kSkillIncrease = 20,
			kWordOfPower1 = 21,
			kWordOfPower2 = 22,
			kCrosshairHide = 23,
			kCrosshairSneak = 24,
		};

		enum class Discovery
		{
			kCity = 1,
			kTown = 2,
			kDungeon4 = 4,
			kDungeon7 = 7,
			kDungeon8 = 8,
			kDungeon12 = 12,
			kDungeon15 = 15
		};

		~HUDData() override;  // 00

		// members
		stl::enumeration<Type, std::uint32_t>      type;          // 10
		std::uint32_t                              pad14;         // 14
		BSString                                   text;          // 18
		ObjectRefHandle                            crossHairRef;  // 28
		std::uint32_t                              pad2C;         // 2C
		void*                                      unk30;         // 30
		std::uint64_t                              unk38;         // 38
		std::uint8_t                               unk40;         // 40
		std::uint8_t                               pad41;         // 41
		std::uint16_t                              pad42;         // 42
		stl::enumeration<Discovery, std::uint32_t> discovery;     // 44
	};
	static_assert(sizeof(HUDData) == 0x48);
}
