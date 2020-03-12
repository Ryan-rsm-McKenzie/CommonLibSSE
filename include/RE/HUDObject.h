#pragma once

#include "RE/GFxValue.h"
#include "RE/GPtr.h"
#include "RE/MemoryManager.h"


namespace RE
{
	class FxDelegateArgs;
	class GFxMovieView;
	class UIMessage;


	class HUDObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_HUDObject;


		struct HudComponents
		{
			enum HudComponent : UInt32
			{
				kThis = 0,
				kHudElements,
				kQuestUpdateBaseInstance,
				kEnemyHealthMeter,
				kStealthMeterInstance,
				kSneakAnimInstance,
				kBracketsInstance,
				kRolloverNameInstance,
				kSneakTextHolder,
				kSneakTextInstance
			};
		};
		using HudComponent = HudComponents::HudComponent;


		HUDObject(GFxMovieView* a_view);
		virtual ~HUDObject();  // 00

		// add
		virtual void Update() = 0;									  // 01
		virtual bool ProcessMessage(UIMessage* a_message);			  // 02 - { return false; }
		virtual void RegisterHUDComponent(FxDelegateArgs& a_params);  // 03 - { root = a_params[0]; }
		virtual void CleanUp();										  // 04 - { return; }

		TES_HEAP_REDEFINE_NEW();


		// members
		GPtr<GFxMovieView> view;  // 08
		GFxValue		   root;  // 10 - kDisplayObject - "_level0.HUDMovieBaseInstance"
	};
	STATIC_ASSERT(sizeof(HUDObject) == 0x28);
}
