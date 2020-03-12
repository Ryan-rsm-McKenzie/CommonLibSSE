#pragma once

#include "RE/GFxValue.h"
#include "RE/HUDObject.h"


namespace RE
{
	class StealthMeter : public HUDObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_StealthMeter;


		virtual ~StealthMeter();  // 00

		// override (HUDObject)
		virtual void Update() override;										   // 01
		virtual bool ProcessMessage(UIMessage* a_message) override;			   // 02
		virtual void RegisterHUDComponent(FxDelegateArgs& a_params) override;  // 03


		// members
		GFxValue stealthMeter;	   // 28
		GFxValue sneakAnim;		   // 40
		GFxValue sneakTextHolder;  // 58
		GFxValue sneakText;		   // 70
		UInt32	 unk88;			   // 88
		UInt32	 unk8C;			   // 8C
		UInt8	 unk90;			   // 90
		UInt8	 unk91;			   // 91
		UInt16	 pad92;			   // 92
		UInt32	 pad94;			   // 94
	};
	STATIC_ASSERT(sizeof(StealthMeter) == 0x98);
}
