#pragma once

#include "RE/B/BSIInputDevice.h"

namespace RE
{
	class BSPCGamepadDeviceDelegate;

	class BSPCGamepadDeviceHandler : public BSIInputDevice
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSPCGamepadDeviceHandler;

		virtual ~BSPCGamepadDeviceHandler();  // 00

		// override (BSIInputDevice)
		virtual void		  Initialize() override;												  // 01
		virtual void		  Process(float a_unk1) override;										  // 02
		virtual void		  Unk_03() override;													  // 03
		virtual bool		  GetKeyMapping(std::uint32_t a_key, BSFixedString& a_mapping) override;  // 04
		virtual std::uint32_t GetMappingKey(BSFixedString a_mapping) override;						  // 05
		virtual void		  Unk_06() override;													  // 06
		virtual bool		  IsEnabled() const override;											  // 07 - { return currentPCGamePadDelegate != 0; }
		virtual void		  Reset() override;														  // 08

		// members
		BSPCGamepadDeviceDelegate* currentPCGamePadDelegate;  // 08
	};
	static_assert(sizeof(BSPCGamepadDeviceHandler) == 0x10);
}
