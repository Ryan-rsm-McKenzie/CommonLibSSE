#include "RE/PlayerCamera.h"

#include "skse64/GameCamera.h"  // PlayerCamera

#include "REL/Relocation.h"


namespace RE
{
	PlayerCamera* PlayerCamera::GetSingleton()
	{
		using func_t = function_type_t<decltype(&PlayerCamera::GetSingleton)>;
		func_t* func = unrestricted_cast<func_t*>(&::PlayerCamera::GetSingleton);
		return func();
	}


	void PlayerCamera::UpdateThirdPerson(bool a_weaponDrawn)
	{
		using func_t = function_type_t<decltype(&PlayerCamera::UpdateThirdPerson)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::PlayerCamera, UpdateThirdPerson, func_t*);
		return func(this, a_weaponDrawn);
	}
}
