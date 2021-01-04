#pragma once

#include "RE/G/GFxValue.h"
#include "RE/H/HUDObject.h"

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
		GFxValue	  stealthMeter;		// 28
		GFxValue	  sneakAnim;		// 40
		GFxValue	  sneakTextHolder;	// 58
		GFxValue	  sneakText;		// 70
		std::uint32_t unk88;			// 88
		std::uint32_t unk8C;			// 8C
		std::uint8_t  unk90;			// 90
		std::uint8_t  unk91;			// 91
		std::uint16_t pad92;			// 92
		std::uint32_t pad94;			// 94
	};
	static_assert(sizeof(StealthMeter) == 0x98);
}
