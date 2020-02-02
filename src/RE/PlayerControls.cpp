#include "RE/PlayerControls.h"

#include "RE/ActivateHandler.h"
#include "RE/Offsets.h"
#include "RE/PlayerInputHandler.h"
#include "REL/Relocation.h"


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
