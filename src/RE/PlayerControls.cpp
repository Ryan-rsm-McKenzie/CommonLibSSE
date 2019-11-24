#include "RE/PlayerControls.h"

#include "skse64/GameInput.h"  // PlayerControls

#include "RE/PlayerInputHandler.h"  // PlayerInputHandler
#include "REL/Relocation.h"


namespace RE
{
	PlayerControls::PlayerControls()
	{
		Ctor();
	}


	PlayerControls* PlayerControls::GetSingleton()
	{
		using func_t = function_type_t<decltype(&PlayerControls::GetSingleton)>;
		func_t* func = unrestricted_cast<func_t*>(&::PlayerControls::GetSingleton);
		return func();
	}


	PlayerControls* PlayerControls::Ctor()
	{
		using func_t = function_type_t<decltype(&PlayerControls::Ctor)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::PlayerControls, ctor, func_t*);
		return func(this);
	}
}
