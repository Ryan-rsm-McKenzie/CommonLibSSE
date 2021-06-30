#pragma once

#include "RE/B/BSIInputDevice.h"

namespace RE
{
	class BSPCGamepadDeviceDelegate;

	class BSPCGamepadDeviceHandler : public BSIInputDevice
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSPCGamepadDeviceHandler;

		~BSPCGamepadDeviceHandler() override;  // 00

		// override (BSIInputDevice)
		void          Initialize() override;                                                  // 01
		void          Process(float a_unk1) override;                                         // 02
		void          Unk_03() override;                                                      // 03
		bool          GetKeyMapping(std::uint32_t a_key, BSFixedString& a_mapping) override;  // 04
		std::uint32_t GetMappingKey(BSFixedString a_mapping) override;                        // 05
		void          Unk_06() override;                                                      // 06
		bool          IsEnabled() const override;                                             // 07 - { return currentPCGamePadDelegate != 0; }
		void          Reset() override;                                                       // 08

		// members
		BSPCGamepadDeviceDelegate* currentPCGamePadDelegate;  // 08
	};
	static_assert(sizeof(BSPCGamepadDeviceHandler) == 0x10);
}
