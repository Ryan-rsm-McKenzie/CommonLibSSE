#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSString.h"
#include "RE/B/BSTArray.h"
#include "RE/G/GFxValue.h"
#include "RE/H/HUDObject.h"

namespace RE
{
	class TESQuest;
	class TESWordOfPower;

	class HUDNotifications : public HUDObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_HUDNotifications;

		struct Notification
		{
		public:
			// members
			BSString                text;              // 00
			BSString                status;            // 10
			BSFixedString           sound;             // 20
			BSTArray<BSFixedString> objectives;        // 28
			std::uint32_t           type{ 0 };         // 40
			std::uint32_t           pad44{ 0 };        // 44
			TESQuest*               quest{ nullptr };  // 48
			TESWordOfPower*         word{ nullptr };   // 50
			std::uint32_t           time{ 0 };         // 58 - gameTime + iObjectivesWaitTime
			std::uint32_t           pad5C{ 0 };        // 5C
		};
		static_assert(sizeof(Notification) == 0x60);

		~HUDNotifications() override;  // 00

		// override (HUDObject)
		void Update() override;                                        // 01
		bool ProcessMessage(UIMessage* a_message) override;            // 02
		void RegisterHUDComponent(FxDelegateArgs& a_params) override;  // 03
		void CleanUp() override;                                       // 04

		// members
		BSTArray<Notification> queue;        // 28
		GFxValue               root;         // 40 - "HUDMovieBaseInstance.QuestUpdateBaseInstance"
		GFxValue               objectives;   // 58 - "QuestNotification.ObjectivesA"
		std::uint32_t          time;         // 70 - last meter update time
		float                  levelPoints;  // 74 - cached meter progress
	};
	static_assert(sizeof(HUDNotifications) == 0x78);
}
