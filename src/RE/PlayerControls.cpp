#include "RE/PlayerControls.h"

#include "skse64/GameInput.h"  // PlayerControls


namespace RE
{
	PlayerControls::PlayerControls()
	{
		Ctor_Internal();
	}


	PlayerControls* PlayerControls::GetSingleton()
	{
		using func_t = function_type_t<decltype(&PlayerControls::GetSingleton)>;
		func_t* func = unrestricted_cast<func_t*>(&::PlayerControls::GetSingleton);
		return func();
	}


	PlayerControls* PlayerControls::Ctor_Internal()
	{
		using func_t = function_type_t<decltype(&PlayerControls::Ctor_Internal)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::PlayerControls, ctor, func_t*);
		return func(this);
	}
}
