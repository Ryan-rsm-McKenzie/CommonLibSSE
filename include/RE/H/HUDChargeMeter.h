#pragma once

#include "RE/H/HUDObject.h"

namespace RE
{
	class HUDChargeMeter : public HUDObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_HUDChargeMeter;
		inline static constexpr auto VTABLE = VTABLE_HUDChargeMeter;

		virtual ~HUDChargeMeter();  // 00

		// override (HUDObject)
		void Update() override;                                        // 01
		bool ProcessMessage(UIMessage* a_message) override;            // 02
		void RegisterHUDComponent(FxDelegateArgs& a_params) override;  // 03

		// members
		float unk28;  // 28 - 100.0
		float unk2C;  // 2C - 100.0
	};
	static_assert(sizeof(HUDChargeMeter) == 0x30);
}
