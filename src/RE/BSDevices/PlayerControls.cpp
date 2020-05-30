#include "RE/BSDevices/PlayerControls.h"

#include "RE/BSDevices/PlayerInputHandler/HeldStateHandler/ActivateHandler.h"
#include "RE/BSDevices/PlayerInputHandler/PlayerInputHandler.h"


namespace RE
{
	PlayerControls::PlayerControls()
	{
		Ctor();
	}


	PlayerControls* PlayerControls::GetSingleton()
	{
		REL::Offset<PlayerControls**> singleton(Offset::PlayerControls::Singleton);
		return *singleton;
	}


	bool PlayerControls::IsActivateControlsEnabled() const
	{
		return activateHandler ? !activateHandler->disabled : true;
	}


	void PlayerControls::ToggleActivateControls(bool a_enable) const
	{
		if (activateHandler) {
			activateHandler->disabled = !a_enable;
		}
	}


	PlayerControls* PlayerControls::Ctor()
	{
		using func_t = decltype(&PlayerControls::Ctor);
		REL::Offset<func_t> func(Offset::PlayerControls::Ctor);
		return func(this);
	}
}
