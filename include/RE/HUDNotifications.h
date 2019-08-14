#pragma once

#include "skse64/GameRTTI.h"  // RTTI_HUDNotifications

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/BSTArray.h"  // BSTArray
#include "RE/GFxValue.h"  // GFxValue
#include "RE/HUDObject.h"  // HUDObject


namespace RE
{
	class HUDNotifications : public HUDObject
	{
	public:
		inline static const void* RTTI = RTTI_HUDNotifications;


		struct UnkData1
		{
			struct UnkData2
			{
				void*	unk00;	// 00
				UInt64	unk08;	// 08
				void*	unk10;	// 10
				UInt64	unk18;	// 18
			};
			STATIC_ASSERT(sizeof(UnkData2) == 0x20);


			const char*			unk00;	// 00
			UInt64				unk08;	// 08
			const char*			unk10;	// 10
			UInt64				unk18;	// 18
			BSFixedString		unk20;	// 20
			BSTArray<UnkData2>	unk28;	// 28
			UInt64				unk40;	// 40
			UInt64				unk48;	// 48
			UInt64				unk50;	// 50
			UInt64				unk58;	// 58
		};
		STATIC_ASSERT(sizeof(UnkData1) == 0x60);


		virtual ~HUDNotifications();												// 00

		// override (HUDObject)
		virtual void	Update() override;											// 01
		virtual bool	ProcessMessage(UIMessage* a_message) override;				// 02
		virtual void	RegisterHUDComponent(FxDelegateArgs& a_params) override;	// 03
		virtual void	CleanUp() override;											// 04


		// members
		BSTArray<UnkData1>	unk28;					// 28
		GFxValue			questNotificationRoot;	// 40 - "HUDMovieBaseInstance.QuestUpdateBaseInstance"
		GFxValue			objectives;				// 58 - "QuestNotification.ObjectivesA"
		UInt32				unk70;					// 70
		float				levelPoints;			// 74
	};
	STATIC_ASSERT(sizeof(HUDNotifications) == 0x78);
}
