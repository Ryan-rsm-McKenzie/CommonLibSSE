#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSTArray.h"
#include "RE/G/GFxValue.h"
#include "RE/H/HUDObject.h"

namespace RE
{
	class HUDNotifications : public HUDObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_HUDNotifications;

		struct UnkData1
		{
			struct UnkData2
			{
				void*		  unk00;  // 00
				std::uint64_t unk08;  // 08
				void*		  unk10;  // 10
				std::uint64_t unk18;  // 18
			};
			static_assert(sizeof(UnkData2) == 0x20);

			const char*		   unk00;  // 00
			std::uint64_t	   unk08;  // 08
			const char*		   unk10;  // 10
			std::uint64_t	   unk18;  // 18
			BSFixedString	   unk20;  // 20
			BSTArray<UnkData2> unk28;  // 28
			std::uint64_t	   unk40;  // 40
			std::uint64_t	   unk48;  // 48
			std::uint64_t	   unk50;  // 50
			std::uint64_t	   unk58;  // 58
		};
		static_assert(sizeof(UnkData1) == 0x60);

		virtual ~HUDNotifications();  // 00

		// override (HUDObject)
		virtual void Update() override;										   // 01
		virtual bool ProcessMessage(UIMessage* a_message) override;			   // 02
		virtual void RegisterHUDComponent(FxDelegateArgs& a_params) override;  // 03
		virtual void CleanUp() override;									   // 04

		// members
		BSTArray<UnkData1> unk28;				   // 28
		GFxValue		   questNotificationRoot;  // 40 - "HUDMovieBaseInstance.QuestUpdateBaseInstance"
		GFxValue		   objectives;			   // 58 - "QuestNotification.ObjectivesA"
		std::uint32_t	   unk70;				   // 70
		float			   levelPoints;			   // 74
	};
	static_assert(sizeof(HUDNotifications) == 0x78);
}
