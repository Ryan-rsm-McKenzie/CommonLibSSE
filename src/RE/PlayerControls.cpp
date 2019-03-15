#include "RE/PlayerControls.h"

#include "skse64/GameInput.h"  // PlayerControls


namespace RE
{
	PlayerControls::PlayerControls()
	{
		ctor_internal();
	}


	PlayerControls* PlayerControls::GetSingleton()
	{
		using func_t = function_type_t<decltype(&PlayerControls::GetSingleton)>;
		func_t* func = function_cast<func_t*>(&::PlayerControls::GetSingleton);
		return func();
	}


	PlayerControls* PlayerControls::ctor_Hook()
	{
		using func_t = function_type_t<decltype(&PlayerControls::ctor_Hook)>;
		func_t* func = function_cast<func_t*>(&::PlayerControls::ctor_Hook);
		return func(this);
	}


	PlayerControls* PlayerControls::ctor_internal()
	{
		using func_t = function_type_t<decltype(&PlayerControls::ctor_internal)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::PlayerControls, ctor, func_t*);
		return func(this);
	}
}
